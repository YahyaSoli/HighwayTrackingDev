# Highway Tracker

A C program for loading and analyzing sensor data from highway recordings. The program supports multiple sensor types including odometry, radar, lidar, and camera data.

## Project Structure

```
C_HighwayTracker/
├── src/                    # Source files
│   ├── main.c             # Main program
│   └── sensor_loader.c    # Sensor loading functions
├── include/               # Header files
│   ├── sensor_data.h      # Data structures
│   └── sensor_loader.h    # Function declarations
├── lib/                   # Third-party libraries
│   └── stb_image_write.h  # STB image library
├── build/                 # Build output directory
├── data/                  # Data files
│   └── rawdata_flat.mat  # Input data
├── Makefile              # Build configuration
└── README.md             # Project documentation
```

## Dependencies

- HDF5 library
- GCC compiler
- Make

## Building

To build the project, run:

```bash
make
```

This will create the executable in the `build` directory.

## Usage

1. Place your HDF5 data file in the `data` directory as `rawdata_flat.mat`
2. Run the program:
   ```bash
   ./build/highway_tracker
   ```
3. Use the interactive menu to:
   - View odometry data
   - View radar data
   - View lidar data
   - View and save camera images

## Features

- Load and parse HDF5 sensor data
- Interactive data inspection
- Save camera frames as PNG images
- Memory-efficient data handling
- Proper cleanup of resources

## Data Types

The program supports the following sensor data types:

1. **Odometry Data**
   - Speed
   - Yaw rate
   - Timestamps

2. **Radar Data**
   - Point cloud data (x, y, z)
   - Signal-to-noise ratio (SNR)
   - Radial speed
   - Radar cross-section (RCS)
   - Power
   - Timestamps

3. **Lidar Data**
   - Point cloud data (x, y, z)
   - Intensity
   - Spatial limits
   - Color and normal information
   - Timestamps

4. **Camera Data**
   - RGB images
   - Image dimensions
   - Timestamps

## License

This project is licensed under the MIT License - see the LICENSE file for details. # C_HighwayTracker
# C_HighwayTracker_Dev
