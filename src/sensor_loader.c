#include <hdf5.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sensor_loader.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb_image_write.h"

// Function to load odometry data from HDF5 file
OdometryData* load_odometry_data(const char* filename) {
    // Open the HDF5 file
    hid_t file_id = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    // Open the odometry group
    const char* odometry_path = "/highwayRecordedData/Odometry/Vehicle";
    hid_t odometry_group = H5Gopen(file_id, odometry_path, H5P_DEFAULT);
    if (odometry_group < 0) {
        fprintf(stderr, "Error: Cannot open odometry group\n");
        H5Fclose(file_id);
        return NULL;
    }

    // Allocate memory for OdometryData
    OdometryData* odometry_data = (OdometryData*)malloc(sizeof(OdometryData));
    if (!odometry_data) {
        fprintf(stderr, "Error: Failed to allocate memory for OdometryData\n");
        H5Gclose(odometry_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Open the speed dataset
    hid_t speed_dataset = H5Dopen(odometry_group, "Speed", H5P_DEFAULT);
    if (speed_dataset < 0) {
        fprintf(stderr, "Error: Cannot open speed dataset\n");
        free(odometry_data);
        H5Gclose(odometry_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Get the number of frames from the speed dataset
    hid_t space = H5Dget_space(speed_dataset);
    hsize_t dims[2];
    H5Sget_simple_extent_dims(space, dims, NULL);
    odometry_data->num_frames = dims[0];  // Assuming [N x 1] shape

    // Allocate memory for frames
    odometry_data->frames = (OdometryFrame*)malloc(sizeof(OdometryFrame) * odometry_data->num_frames);
    if (!odometry_data->frames) {
        fprintf(stderr, "Error: Failed to allocate memory for frames\n");
        H5Sclose(space);
        H5Dclose(speed_dataset);
        H5Gclose(odometry_group);
        H5Fclose(file_id);
        free(odometry_data);
        return NULL;
    }

    // Read speed data
    hobj_ref_t* speed_refs = malloc(sizeof(hobj_ref_t) * odometry_data->num_frames);
    H5Dread(speed_dataset, H5T_STD_REF_OBJ, H5S_ALL, H5S_ALL, H5P_DEFAULT, speed_refs);

    // Read yaw rate data
    hid_t yaw_dataset = H5Dopen(odometry_group, "YawRate", H5P_DEFAULT);
    hobj_ref_t* yaw_refs = malloc(sizeof(hobj_ref_t) * odometry_data->num_frames);
    H5Dread(yaw_dataset, H5T_STD_REF_OBJ, H5S_ALL, H5S_ALL, H5P_DEFAULT, yaw_refs);

    // Read timestamp data
    hid_t timestamp_dataset = H5Dopen(odometry_group, "Timestamp", H5P_DEFAULT);
    hobj_ref_t* timestamp_refs = malloc(sizeof(hobj_ref_t) * odometry_data->num_frames);
    H5Dread(timestamp_dataset, H5T_STD_REF_OBJ, H5S_ALL, H5S_ALL, H5P_DEFAULT, timestamp_refs);

    // Process each frame
    for (size_t i = 0; i < odometry_data->num_frames; i++) {
        // Read speed
        hid_t speed_obj = H5Rdereference(speed_dataset, H5R_OBJECT, &speed_refs[i]);
        float speed;
        H5Dread(speed_obj, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, &speed);
        odometry_data->frames[i].speed = speed;
        H5Dclose(speed_obj);

        // Read yaw rate
        hid_t yaw_obj = H5Rdereference(yaw_dataset, H5R_OBJECT, &yaw_refs[i]);
        float yaw_rate;
        H5Dread(yaw_obj, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, &yaw_rate);
        odometry_data->frames[i].yaw_rate = yaw_rate;
        H5Dclose(yaw_obj);

        // Read timestamp
        hid_t timestamp_obj = H5Rdereference(timestamp_dataset, H5R_OBJECT, &timestamp_refs[i]);
        double timestamp;
        H5Dread(timestamp_obj, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, &timestamp);
        odometry_data->frames[i].timestamp = timestamp;
        H5Dclose(timestamp_obj);
    }

    // Cleanup
    free(speed_refs);
    free(yaw_refs);
    free(timestamp_refs);
    H5Sclose(space);
    H5Dclose(speed_dataset);
    H5Dclose(yaw_dataset);
    H5Dclose(timestamp_dataset);
    H5Gclose(odometry_group);
    H5Fclose(file_id);

    return odometry_data;
}

// Function to free odometry data
void free_odometry_data(OdometryData* odometry_data) {
    if (odometry_data) {
        if (odometry_data->frames) {
            free(odometry_data->frames);
        }
        free(odometry_data);
    }
}

// Function to load camera data
CameraData* load_camera_data(const char* filename) {
    // Open the HDF5 file	
    hid_t file_id = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    // Open the camera group first
    const char* camera_group_path = "/highwayRecordedData/Camera";
    hid_t camera_group = H5Gopen(file_id, camera_group_path, H5P_DEFAULT);
    if (camera_group < 0) {
        fprintf(stderr, "Error: Cannot open camera group\n");
        H5Fclose(file_id);
        return NULL;
    }

    // Then open the Images dataset
    const char* camera_dataset_path = "Images";
    hid_t camera_dataset = H5Dopen(camera_group, camera_dataset_path, H5P_DEFAULT);
    if (camera_dataset < 0) {
        fprintf(stderr, "Error: Cannot open camera dataset\n");
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Open the Timestamps dataset
    const char* timestamps_dataset_path = "Timestamps";
    hid_t timestamps_dataset = H5Dopen(camera_group, timestamps_dataset_path, H5P_DEFAULT);
    if (timestamps_dataset < 0) {
        fprintf(stderr, "Error: Cannot open timestamps dataset\n");
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Get the number of frames
    hid_t space = H5Dget_space(camera_dataset);
    if (space < 0) {
        fprintf(stderr, "Error: Cannot get dataspace\n");
        H5Dclose(timestamps_dataset);
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    hsize_t dims[2];
    int ndims = H5Sget_simple_extent_dims(space, dims, NULL);
    if (ndims < 0) {
        fprintf(stderr, "Error: Cannot get dimensions\n");
        H5Sclose(space);
        H5Dclose(timestamps_dataset);
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    size_t num_frames = dims[1];  // Assuming [1 x N] shape

    // Allocate memory for CameraData
    CameraData* camera_data = (CameraData*)malloc(sizeof(CameraData));
    if (!camera_data) {
        fprintf(stderr, "Error: Failed to allocate memory for CameraData\n");
        H5Sclose(space);
        H5Dclose(timestamps_dataset);
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Allocate memory for frames and timestamps
    camera_data->num_frames = num_frames;
    camera_data->frames = (CameraImage*)malloc(sizeof(CameraImage) * num_frames);
    camera_data->timestamps = (double*)malloc(sizeof(double) * num_frames);

    if (!camera_data->frames || !camera_data->timestamps) {
        fprintf(stderr, "Error: Failed to allocate memory for frames or timestamps\n");
        free_camera_data(camera_data);
        H5Sclose(space);
        H5Dclose(timestamps_dataset);
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Read timestamps
    herr_t status = H5Dread(timestamps_dataset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, camera_data->timestamps);
    if (status < 0) {
        fprintf(stderr, "Error: Failed to read timestamps\n");
        free_camera_data(camera_data);
        H5Sclose(space);
        H5Dclose(timestamps_dataset);
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Read all references
    hobj_ref_t* refs = malloc(sizeof(hobj_ref_t) * num_frames);
    if (!refs) {
        fprintf(stderr, "Error: Failed to allocate memory for references\n");
        free_camera_data(camera_data);
        H5Sclose(space);
        H5Dclose(timestamps_dataset);
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    status = H5Dread(camera_dataset, H5T_STD_REF_OBJ, H5S_ALL, H5S_ALL, H5P_DEFAULT, refs);
    if (status < 0) {
        fprintf(stderr, "Error: Failed to read references\n");
        free(refs);
        free_camera_data(camera_data);
        H5Sclose(space);
        H5Dclose(timestamps_dataset);
        H5Dclose(camera_dataset);
        H5Gclose(camera_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Process each frame
    for (size_t i = 0; i < num_frames; i++) {
        // Dereference the image object
        hid_t img_dset = H5Rdereference(camera_dataset, H5R_OBJECT, &refs[i]);
        if (img_dset < 0) {
            fprintf(stderr, "Error: Failed to dereference image at index %zu\n", i);
            continue;
        }

        hid_t img_space = H5Dget_space(img_dset);
        if (img_space < 0) {
            fprintf(stderr, "Error: Failed to get image space at index %zu\n", i);
            H5Dclose(img_dset);
            continue;
        }

        int ndims = H5Sget_simple_extent_ndims(img_space);
        if (ndims != 3) {
            fprintf(stderr, "Error: Image at index %zu does not have 3 dimensions\n", i);
            H5Sclose(img_space);
            H5Dclose(img_dset);
            continue;
        }

        hsize_t img_dims[3];
        H5Sget_simple_extent_dims(img_space, img_dims, NULL);

        // Set image dimensions
        camera_data->frames[i].channels = img_dims[0];  // Should be 3 for RGB
        camera_data->frames[i].height = img_dims[1];
        camera_data->frames[i].width = img_dims[2];

        // Allocate memory for image data (CHW format)
        size_t img_size = camera_data->frames[i].channels * 
                         camera_data->frames[i].height * 
                         camera_data->frames[i].width;
        unsigned char* chw_data = malloc(img_size);
        if (!chw_data) {
            fprintf(stderr, "Error: Failed to allocate memory for CHW data at index %zu\n", i);
            H5Sclose(img_space);
            H5Dclose(img_dset);
            continue;
        }
        
        // Read image data
        status = H5Dread(img_dset, H5T_NATIVE_UCHAR, H5S_ALL, H5S_ALL, H5P_DEFAULT, chw_data);
        if (status < 0) {
            fprintf(stderr, "Error: Failed to read image data at index %zu\n", i);
            free(chw_data);
            H5Sclose(img_space);
            H5Dclose(img_dset);
            continue;
        }

        // Convert from CHW to HWC format
        camera_data->frames[i].data = malloc(img_size);
        if (!camera_data->frames[i].data) {
            fprintf(stderr, "Error: Failed to allocate memory for HWC data at index %zu\n", i);
            free(chw_data);
            H5Sclose(img_space);
            H5Dclose(img_dset);
            continue;
        }

        for (int h = 0; h < camera_data->frames[i].height; h++) {
            for (int w = 0; w < camera_data->frames[i].width; w++) {
                for (int c = 0; c < camera_data->frames[i].channels; c++) {
                    camera_data->frames[i].data[(w * camera_data->frames[i].height + h) * 3 + c] =
                        chw_data[c * camera_data->frames[i].height * camera_data->frames[i].width + 
                                h * camera_data->frames[i].width + w];
                }
            }
        }

        // Cleanup for this frame
        free(chw_data);
        H5Sclose(img_space);
        H5Dclose(img_dset);
    }

    // Cleanup
    free(refs);
    H5Sclose(space);
    H5Dclose(timestamps_dataset);
    H5Dclose(camera_dataset);
    H5Gclose(camera_group);
    H5Fclose(file_id);

    return camera_data;
}

// Function to free camera data
void free_camera_data(CameraData* camera_data) {
    if (camera_data) {
        if (camera_data->frames) {
            for (size_t i = 0; i < camera_data->num_frames; i++) {
                free(camera_data->frames[i].data);
            }
            free(camera_data->frames);
        }
        if (camera_data->timestamps) {
            free(camera_data->timestamps);
        }
        free(camera_data);
    }
}

// Function to save a camera image as PNG
void save_camera_image(const CameraImage* image, const char* filename) {
    if (!image || !image->data) {
        fprintf(stderr, "Error: Invalid image data\n");
        return;
    }

    // Save PNG using stb_image_write
    stbi_write_png(filename, 
                   image->height,  // Note: swapped width and height
                   image->width,   // Note: swapped width and height
                   image->channels, 
                   image->data, 
                   image->height * image->channels);  // Note: using height for stride
    printf("✅ Saved image as %s (%dx%dx%d)\n", 
           filename, 
           image->width, 
           image->height, 
           image->channels);
}

RadarData* load_radar_data(const char* filename) {
    // Open the HDF5 file
    hid_t file_id = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    // Open the radar group first
    const char* radar_group_path = "/highwayRecordedData/Radar";
    hid_t radar_group = H5Gopen(file_id, radar_group_path, H5P_DEFAULT);
    if (radar_group < 0) {
        fprintf(stderr, "Error: Cannot open radar group\n");
        H5Fclose(file_id);
        return NULL;
    }

    // Then open the PointClouds group
    const char* pointclouds_path = "PointClouds";
    hid_t pointclouds_group = H5Gopen(radar_group, pointclouds_path, H5P_DEFAULT);
    if (pointclouds_group < 0) {
        fprintf(stderr, "Error: Cannot open PointClouds group\n");
        H5Gclose(radar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Get dimensions from the x dataset (assuming all datasets have same dimensions)
    hid_t x_dataset = H5Dopen(pointclouds_group, "x", H5P_DEFAULT);
    if (x_dataset < 0) {
        fprintf(stderr, "Error: Cannot open x dataset\n");
        H5Gclose(pointclouds_group);
        H5Gclose(radar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Get dimensions
    hid_t space = H5Dget_space(x_dataset);
    hsize_t dims[2];
    H5Sget_simple_extent_dims(space, dims, NULL);
    size_t num_frames = dims[0]; // assume [N x 1]

    // Allocate memory for RadarData
    RadarData* radar_data = (RadarData*)malloc(sizeof(RadarData));
    if (!radar_data) {
        fprintf(stderr, "Error: Failed to allocate memory for RadarData\n");
        H5Sclose(space);
        H5Dclose(x_dataset);
        H5Gclose(pointclouds_group);
        H5Gclose(radar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Allocate memory for frames and timestamps
    radar_data->num_frames = num_frames;
    radar_data->frames = (RadarPointCloud*)malloc(sizeof(RadarPointCloud) * num_frames);
    radar_data->timestamps = (double*)malloc(sizeof(double) * num_frames);

    if (!radar_data->frames || !radar_data->timestamps) {
        fprintf(stderr, "Error: Failed to allocate memory for frames or timestamps\n");
        free_radar_data(radar_data);
        H5Sclose(space);
        H5Dclose(x_dataset);
        H5Gclose(pointclouds_group);
        H5Gclose(radar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Open all datasets
    const char* dataset_names[] = {"x", "y", "z", "snr", "radial_speed", "Noise", "RCS", "power", "Timestamp"};
    hid_t datasets[9];
    hid_t datatypes[9];
    for (int i = 0; i < 9; i++) {
        datasets[i] = H5Dopen(pointclouds_group, dataset_names[i], H5P_DEFAULT);
        if (datasets[i] < 0) {
            fprintf(stderr, "Error: Cannot open %s dataset\n", dataset_names[i]);
            // Cleanup already opened datasets
            for (int j = 0; j < i; j++) {
                H5Tclose(datatypes[j]);
                H5Dclose(datasets[j]);
            }
            H5Sclose(space);
            H5Dclose(x_dataset);
            H5Gclose(pointclouds_group);
            H5Gclose(radar_group);
            H5Fclose(file_id);
            free_radar_data(radar_data);
            return NULL;
        }

        // Get the native datatype
        datatypes[i] = H5Dget_type(datasets[i]);
        if (datatypes[i] < 0) {
            fprintf(stderr, "Error: Cannot get datatype for %s dataset\n", dataset_names[i]);
            // Cleanup
            for (int j = 0; j <= i; j++) {
                if (j < i) H5Tclose(datatypes[j]);
                H5Dclose(datasets[j]);
            }
            H5Sclose(space);
            H5Dclose(x_dataset);
            H5Gclose(pointclouds_group);
            H5Gclose(radar_group);
            H5Fclose(file_id);
            free_radar_data(radar_data);
            return NULL;
        }
    }

    // Process each frame
    for (size_t i = 0; i < num_frames; i++) {
        size_t num_points = 0;  // Declare num_points at the start of the loop
        // Get number of points for this frame from the first field (x)
        hid_t field_space = H5Dget_space(datasets[0]); // Use x dataset
        hsize_t start[2] = {i, 0};  // Start at frame i, first point
        hsize_t count[2] = {1, 1};  // Read one frame, one point initially
        H5Sselect_hyperslab(field_space, H5S_SELECT_SET, start, NULL, count, NULL);
        
        // Create a simple dataspace for the memory buffer
        hid_t mem_space = H5Screate_simple(2, count, NULL);
        
        // Read the reference
        hobj_ref_t ref;
        herr_t status = H5Dread(datasets[0], H5T_STD_REF_OBJ, mem_space, field_space, H5P_DEFAULT, &ref);
        
        if (status >= 0) {
            // Dereference to get the actual data
            hid_t ref_obj = H5Rdereference(datasets[0], H5R_OBJECT, &ref);
            if (ref_obj >= 0) {
                // Get the dataspace of the dereferenced object
                hid_t ref_space = H5Dget_space(ref_obj);
                hsize_t ref_dims[2];
                H5Sget_simple_extent_dims(ref_space, ref_dims, NULL);
                num_points = ref_dims[1]; // Get actual number of points
                
                // Set number of points
                radar_data->frames[i].num_points = num_points;
                
                // Allocate memory for point cloud data
                radar_data->frames[i].x = malloc(sizeof(float) * num_points);
                radar_data->frames[i].y = malloc(sizeof(float) * num_points);
                radar_data->frames[i].z = malloc(sizeof(float) * num_points);
                radar_data->frames[i].snr = malloc(sizeof(float) * num_points);
                radar_data->frames[i].radial_speed = malloc(sizeof(float) * num_points);
                radar_data->frames[i].noise = malloc(sizeof(float) * num_points);
                radar_data->frames[i].rcs = malloc(sizeof(float) * num_points);
                radar_data->frames[i].power = malloc(sizeof(float) * num_points);
                radar_data->frames[i].timestamp = malloc(sizeof(float) * num_points);
                
                if (!radar_data->frames[i].x || !radar_data->frames[i].y || !radar_data->frames[i].z ||
                    !radar_data->frames[i].snr || !radar_data->frames[i].radial_speed || !radar_data->frames[i].noise ||
                    !radar_data->frames[i].rcs || !radar_data->frames[i].power || !radar_data->frames[i].timestamp) {
                    fprintf(stderr, "Error: Failed to allocate memory for point cloud data at index %zu\n", i);
                    H5Sclose(ref_space);
                    H5Dclose(ref_obj);
                    H5Sclose(mem_space);
                    H5Sclose(field_space);
                    continue;
                }
                
                H5Sclose(ref_space);
                H5Dclose(ref_obj);
            } else {
                fprintf(stderr, "Warning: Failed to dereference object for frame %zu\n", i);
                H5Sclose(mem_space);
                H5Sclose(field_space);
                continue;
            }
        } else {
            fprintf(stderr, "Warning: Failed to read reference for frame %zu\n", i);
            H5Sclose(mem_space);
            H5Sclose(field_space);
            continue;
        }
        
        H5Sclose(mem_space);
        H5Sclose(field_space);

        // Read data for each field
        float** field_ptrs[] = {
            &radar_data->frames[i].x,
            &radar_data->frames[i].y,
            &radar_data->frames[i].z,
            &radar_data->frames[i].snr,
            &radar_data->frames[i].radial_speed,
            &radar_data->frames[i].noise,
            &radar_data->frames[i].rcs,
            &radar_data->frames[i].power,
            &radar_data->frames[i].timestamp
        };

        for (int f = 0; f < 9; f++) {
            // Create a new dataspace for this field
            field_space = H5Dget_space(datasets[f]);
            if (field_space < 0) {
                fprintf(stderr, "Error: Failed to get dataspace for %s dataset\n", dataset_names[f]);
                continue;
            }

            // Create a hyperslab selection for this frame
            start[0] = i;  // Start at frame i
            start[1] = 0;  // First point
            count[0] = 1;  // One frame
            count[1] = 1;  // One point initially
            H5Sselect_hyperslab(field_space, H5S_SELECT_SET, start, NULL, count, NULL);
            
            // Create a simple dataspace for the memory buffer
            mem_space = H5Screate_simple(2, count, NULL);
            
            // Get the appropriate memory type based on the dataset type
            H5T_class_t class = H5Tget_class(datatypes[f]);

            if (class == H5T_REFERENCE) {
                // Read the reference
                hobj_ref_t ref;
                status = H5Dread(datasets[f], H5T_STD_REF_OBJ, mem_space, field_space, H5P_DEFAULT, &ref);
                
                if (status >= 0) {
                    // Dereference to get the actual data
                    hid_t ref_obj = H5Rdereference(datasets[f], H5R_OBJECT, &ref);
                    if (ref_obj >= 0) {
                        // Get the dataspace of the dereferenced object
                        hid_t ref_space = H5Dget_space(ref_obj);
                        if (ref_space < 0) {
                            fprintf(stderr, "Error: Failed to get dataspace for dereferenced object\n");
                            H5Dclose(ref_obj);
                            H5Sclose(mem_space);
                            H5Sclose(field_space);
                            continue;
                        }

                        // Verify memory allocation
                        if (!*field_ptrs[f]) {
                            fprintf(stderr, "Error: Memory not allocated for %s field\n", dataset_names[f]);
                            H5Sclose(ref_space);
                            H5Dclose(ref_obj);
                            H5Sclose(mem_space);
                            H5Sclose(field_space);
                            continue;
                        }

                        // Read the actual data
                        status = H5Dread(ref_obj, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, *field_ptrs[f]);
                        if (status < 0) {
                            fprintf(stderr, "Warning: Failed to read data from dereferenced object for %s\n", dataset_names[f]);
                        }
                        
                        H5Sclose(ref_space);
                        H5Dclose(ref_obj);
                    } else {
                        fprintf(stderr, "Warning: Failed to dereference object for %s\n", dataset_names[f]);
                    }
                } else {
                    fprintf(stderr, "Warning: Failed to read reference for %s dataset\n", dataset_names[f]);
                }
            } else {
                fprintf(stderr, "Warning: Unexpected data type for %s dataset\n", dataset_names[f]);
            }
            
            // Cleanup
            H5Sclose(mem_space);
            H5Sclose(field_space);
        }
    }

    // Cleanup
    for (int i = 0; i < 9; i++) {
        H5Tclose(datatypes[i]);
        H5Dclose(datasets[i]);
    }
    H5Sclose(space);
    H5Dclose(x_dataset);
    H5Gclose(pointclouds_group);

    // Load timestamps
    const char* timestamps_path = "Timestamps";
    hid_t timestamps_dataset = H5Dopen(radar_group, timestamps_path, H5P_DEFAULT);
    if (timestamps_dataset < 0) {
        fprintf(stderr, "Error: Cannot open Radar Timestamps dataset\n");
        H5Gclose(radar_group);
        H5Fclose(file_id);
        free_radar_data(radar_data);
        return NULL;
    }

    // Read all timestamps at once
    herr_t status = H5Dread(timestamps_dataset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, radar_data->timestamps);
    if (status < 0) {
        fprintf(stderr, "Error: Failed to read Radar timestamps\n");
        H5Dclose(timestamps_dataset);
        H5Gclose(radar_group);
        H5Fclose(file_id);
        free_radar_data(radar_data);
        return NULL;
    }

    H5Dclose(timestamps_dataset);
    H5Gclose(radar_group);
    H5Fclose(file_id);

    return radar_data;
}

// Function to free radar data
void free_radar_data(RadarData* radar_data) {
    if (radar_data) {
        if (radar_data->frames) {
            for (size_t i = 0; i < radar_data->num_frames; i++) {
                free(radar_data->frames[i].x);
                free(radar_data->frames[i].y);
                free(radar_data->frames[i].z);
                free(radar_data->frames[i].snr);
                free(radar_data->frames[i].radial_speed);
                free(radar_data->frames[i].noise);
                free(radar_data->frames[i].rcs);
                free(radar_data->frames[i].power);
                free(radar_data->frames[i].timestamp);
            }
            free(radar_data->frames);
        }
        if (radar_data->timestamps) {
            free(radar_data->timestamps);
        }
        free(radar_data);
    }
}

// Function to load lidar data
LidarData* load_lidar_data(const char* filename) {
    // Open the HDF5 file
    hid_t file_id = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    // Open the lidar group
    const char* lidar_group_path = "/highwayRecordedData/Lidar";
    hid_t lidar_group = H5Gopen(file_id, lidar_group_path, H5P_DEFAULT);
    if (lidar_group < 0) {
        fprintf(stderr, "Error: Cannot open lidar group\n");
        H5Fclose(file_id);
        return NULL;
    }

    // Open the PointClouds dataset
    const char* pointclouds_path = "PointClouds";
    hid_t pointclouds_dataset = H5Dopen(lidar_group, pointclouds_path, H5P_DEFAULT);
    if (pointclouds_dataset < 0) {
        fprintf(stderr, "Error: Cannot open PointClouds dataset\n");
        H5Gclose(lidar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Get dimensions
    hid_t space = H5Dget_space(pointclouds_dataset);
    hsize_t dims[2];
    H5Sget_simple_extent_dims(space, dims, NULL);
    size_t num_frames = dims[1];  // Assuming [1 x N] shape

    // Allocate memory for LidarData
    LidarData* lidar_data = (LidarData*)malloc(sizeof(LidarData));
    if (!lidar_data) {
        fprintf(stderr, "Error: Failed to allocate memory for LidarData\n");
        H5Sclose(space);
        H5Dclose(pointclouds_dataset);
        H5Gclose(lidar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Allocate memory for frames and timestamps
    lidar_data->num_frames = num_frames;
    lidar_data->frames = (LidarPointCloud*)malloc(sizeof(LidarPointCloud) * num_frames);
    lidar_data->timestamps = (double*)malloc(sizeof(double) * num_frames);

    if (!lidar_data->frames || !lidar_data->timestamps) {
        fprintf(stderr, "Error: Failed to allocate memory for frames or timestamps\n");
        free_lidar_data(lidar_data);
        H5Sclose(space);
        H5Dclose(pointclouds_dataset);
        H5Gclose(lidar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Read all references
    hobj_ref_t* refs = malloc(sizeof(hobj_ref_t) * num_frames);
    if (!refs) {
        fprintf(stderr, "Error: Failed to allocate memory for references\n");
        free_lidar_data(lidar_data);
        H5Sclose(space);
        H5Dclose(pointclouds_dataset);
        H5Gclose(lidar_group);
        H5Fclose(file_id);
        return NULL;
    }

    herr_t status = H5Dread(pointclouds_dataset, H5T_STD_REF_OBJ, H5S_ALL, H5S_ALL, H5P_DEFAULT, refs);
    if (status < 0) {
        fprintf(stderr, "Error: Failed to read references\n");
        free(refs);
        free_lidar_data(lidar_data);
        H5Sclose(space);
        H5Dclose(pointclouds_dataset);
        H5Gclose(lidar_group);
        H5Fclose(file_id);
        return NULL;
    }

    // Process each frame
    for (size_t i = 0; i < num_frames; i++) {
        // Dereference the point cloud object
        hid_t pointcloud_obj = H5Rdereference(pointclouds_dataset, H5R_OBJECT, &refs[i]);
        if (pointcloud_obj < 0) {
            fprintf(stderr, "Error: Failed to dereference point cloud at index %zu\n", i);
            continue;
        }

        // Initialize the frame structure
        lidar_data->frames[i].location = NULL;
        lidar_data->frames[i].intensity = NULL;
        lidar_data->frames[i].count = 0;
        lidar_data->frames[i].num_points = 0;

        // Read Location data
        hid_t location_dataset = H5Dopen(pointcloud_obj, "Location", H5P_DEFAULT);
        if (location_dataset >= 0) {
            hid_t location_space = H5Dget_space(location_dataset);
            hsize_t location_dims[2];
            H5Sget_simple_extent_dims(location_space, location_dims, NULL);
            
            size_t num_points = location_dims[1];  // [3 x N] shape
            lidar_data->frames[i].num_points = num_points;
            
            // Allocate memory for location data
            lidar_data->frames[i].location = malloc(sizeof(float) * num_points * 3);
            float* temp_location = malloc(sizeof(float) * num_points * 3);
            if (lidar_data->frames[i].location && temp_location) {
                // Read the data as-is into temp_location
                herr_t status = H5Dread(location_dataset, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, temp_location);
                if (status < 0) {
                    fprintf(stderr, "Error: Failed to read location data for frame %zu\n", i);
                } else {
                    // Transpose from [3 x N] to (x, y, z, ...)
                    for (size_t p = 0; p < num_points; p++) {
                        lidar_data->frames[i].location[p * 3 + 0] = temp_location[0 * num_points + p]; // x
                        lidar_data->frames[i].location[p * 3 + 1] = temp_location[1 * num_points + p]; // y
                        lidar_data->frames[i].location[p * 3 + 2] = temp_location[2 * num_points + p]; // z
                    }
                }
                free(temp_location);
            }
            H5Sclose(location_space);
            H5Dclose(location_dataset);
        }

        // Read Intensity data
        hid_t intensity_dataset = H5Dopen(pointcloud_obj, "Intensity", H5P_DEFAULT);
        if (intensity_dataset >= 0) {
            hid_t intensity_space = H5Dget_space(intensity_dataset);
            hsize_t intensity_dims[2];
            H5Sget_simple_extent_dims(intensity_space, intensity_dims, NULL);
            
            size_t num_points = intensity_dims[1];  // [1 x N] shape
            if (num_points != lidar_data->frames[i].num_points) {
                fprintf(stderr, "Warning: Mismatch in number of points between Location and Intensity\n");
            }
            
            // Allocate memory for intensity data
            lidar_data->frames[i].intensity = malloc(sizeof(float) * num_points);
            if (lidar_data->frames[i].intensity) {
                H5Dread(intensity_dataset, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, lidar_data->frames[i].intensity);
            }
            H5Sclose(intensity_space);
            H5Dclose(intensity_dataset);
        }

        // Read x_limits
        hid_t x_limits_dataset = H5Dopen(pointcloud_obj, "XLimits", H5P_DEFAULT);
        if (x_limits_dataset >= 0) {
            H5Dread(x_limits_dataset, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, lidar_data->frames[i].x_limits);
            H5Dclose(x_limits_dataset);
        }

        // Read y_limits
        hid_t y_limits_dataset = H5Dopen(pointcloud_obj, "YLimits", H5P_DEFAULT);
        if (y_limits_dataset >= 0) {
            H5Dread(y_limits_dataset, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, lidar_data->frames[i].y_limits);
            H5Dclose(y_limits_dataset);
        }

        // Read z_limits
        hid_t z_limits_dataset = H5Dopen(pointcloud_obj, "ZLimits", H5P_DEFAULT);
        if (z_limits_dataset >= 0) {
            H5Dread(z_limits_dataset, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, lidar_data->frames[i].z_limits);
            H5Dclose(z_limits_dataset);
        }

        // Read color
        hid_t color_dataset = H5Dopen(pointcloud_obj, "Color", H5P_DEFAULT);
        if (color_dataset >= 0) {
            H5Dread(color_dataset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, lidar_data->frames[i].color);
            H5Dclose(color_dataset);
        }

        // Read normal
        hid_t normal_dataset = H5Dopen(pointcloud_obj, "Normal", H5P_DEFAULT);
        if (normal_dataset >= 0) {
            H5Dread(normal_dataset, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, lidar_data->frames[i].normal);
            H5Dclose(normal_dataset);
        }

        H5Oclose(pointcloud_obj);
    }

    // Load timestamps
    const char* timestamps_path = "Timestamps";
    hid_t timestamps_dataset = H5Dopen(lidar_group, timestamps_path, H5P_DEFAULT);
    if (timestamps_dataset < 0) {
        fprintf(stderr, "Error: Cannot open Lidar Timestamps dataset\n");
        H5Gclose(lidar_group);
        H5Fclose(file_id);
        free_lidar_data(lidar_data);
        return NULL;
    }

    // Read all timestamps at once
    status = H5Dread(timestamps_dataset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, lidar_data->timestamps);
    if (status < 0) {
        fprintf(stderr, "Error: Failed to read Lidar timestamps\n");
        H5Dclose(timestamps_dataset);
        H5Gclose(lidar_group);
        H5Fclose(file_id);
        free_lidar_data(lidar_data);
        return NULL;
    }

    // Cleanup
    free(refs);
    H5Sclose(space);
    H5Dclose(timestamps_dataset);
    H5Dclose(pointclouds_dataset);
    H5Gclose(lidar_group);
    H5Fclose(file_id);

    return lidar_data;
}

// Function to free lidar data
void free_lidar_data(LidarData* lidar_data) {
    if (lidar_data) {
        if (lidar_data->frames) {
            for (size_t i = 0; i < lidar_data->num_frames; i++) {
                free(lidar_data->frames[i].location);
                free(lidar_data->frames[i].intensity);
            }
            free(lidar_data->frames);
        }
        if (lidar_data->timestamps) {
            free(lidar_data->timestamps);
        }
        free(lidar_data);
    }
}