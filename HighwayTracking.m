
disp('Downloading Highway Pre-Recorded Data...');
if ~exist('highwayRecordedData','var')
    highwayRecordedData = downloadDataset();
end
disp('Download Done!')

%% Introduction

%% Step 1 - Specify what you want to track 

% Create a target specification for a car driving on a highway
carSpec = trackerTargetSpec('automotive','car','highway-driving');
carSpec.MaxSpeed = 30;
disp('Car spec created is: \n');
disp(carSpec);
% Create target specification for a truck driving on a highway
truckSpec = trackerTargetSpec('automotive','truck','highway-driving');
truckSpec.MaxSpeed = 20;
disp('Truck spec created is: \n');
disp(truckSpec);

%% Step 2 - Specify what sensors you have
% Create radar sensor specification
radarSpec = trackerSensorSpec('automotive','radar','clustered-points');

% Configure its properties
radarSpec.MaxNumMeasurements = 30;
radarSpec.MountingLocation = [4.68465 0.01270 -0.11430];
radarSpec.MountingAngles = [0 -1 0.2];
radarSpec.FieldOfView = [100 15];
radarSpec.MaxRange = 120;
radarSpec.MaxRangeRate = 85;
radarSpec.DetectionProbability = 0.9;
radarSpec.NumFalsePositivesPerScan = 6;
radarSpec.NumNewTargetsPerScan = 2;
disp('Radar spec: \n');
disp(radarSpec);

% Define Specification for Camera Sensor
% Create camera sensor specification
cameraSpec = trackerSensorSpec('automotive','camera','bounding-boxes');

% Configure its properties
cameraSpec.MaxNumMeasurements = 20;
cameraSpec.MountingLocation = [2.1398 -0.3180 1.2014]; 
cameraSpec.MountingAngles = [0 2 0.2];
cameraSpec.WidthAccuracy = 10;
cameraSpec.CenterAccuracy = 10;
cameraSpec.HeightAccuracy = 5;
cameraSpec.MaxRange = 120;
cameraSpec.DetectionProbability = 0.95;
cameraSpec.EgoOriginHeight = 0.4826;
cameraSpec.Intrinsics = [1176.29501,    0.     ,  520.32287;
                            0      , 1176.28913,  389.60511;
                            0.     ,    0.     ,    1     ];
cameraSpec.ImageSize = [768 1024];
cameraSpec.NumFalsePositivesPerImage = 1e-2;
cameraSpec.NumNewTargetsPerImage = 1e-2;
disp('Camera spec:\n');
disp(cameraSpec);

% Define Specification for Lidar Sensor
% Create lidar sensor specification
lidarSpec = trackerSensorSpec('automotive','lidar','bounding-boxes');

% Configure its properties
lidarSpec.MaxNumMeasurements = 20;
lidarSpec.MountingLocation = [2.12090 0.01270 1.10712];
lidarSpec.MountingAngles = [0 2 0.2];
lidarSpec.ElevationLimits = [-25 25];
lidarSpec.AzimuthLimits = [-90 90];
lidarSpec.MaxRange = 150;
lidarSpec.DetectionProbability = 0.9;
lidarSpec.DimensionAccuracy = 0.25;
lidarSpec.CenterAccuracy = 0.25;
lidarSpec.OrientationAccuracy = 5;
lidarSpec.DetectionProbability = 0.9;
lidarSpec.NumFalsePositivesPerScan = 2;
lidarSpec.NumNewTargetsPerScan = 1;
disp('LiDAR spec: \n');
disp(lidarSpec);

%% Step 3 - Configure the tracker
% Multi-object JIPDA tracker

% Target specifications as a cell array of all targets 
targetSpecifications = {carSpec, truckSpec};

% Choose a combination of sensors for fusion.
UseRadar = true;
UseLidar = true;
UseCamera = true;

% A logical array to select the right specifications
sensorFlags = [UseRadar, UseLidar, UseCamera];

% Sensor specifications as a cell array of all sensors
sensorSpecifications = {radarSpec, lidarSpec, cameraSpec};
sensorSpecifications = sensorSpecifications(sensorFlags);

% Define a tracker that can track the target using the defined sensors.
tracker = multiSensorTargetTracker(targetSpecifications, sensorSpecifications, 'jipda');

% Fine-tune the tracker to allow an assignment when Mahalanobis distance
% between a track and measurement is less than 7.
tracker.MaxMahalanobisDistance = 7;
disp('Tracker is: \n')
disp(tracker);
%% Step 4 - Understand Data Format
trackerDataFormats = dataFormat(tracker);
disp('Tracker Data Formats is: \n');
disp(trackerDataFormats{1});

%%
% Only display when the sensor is used according to checkbox
if numel(trackerDataFormats) > 2
    disp(trackerDataFormats{2});
end

%%
% Only display when the sensor is used according to checkbox
if numel(trackerDataFormats) > 3 
    disp(trackerDataFormats{3});
end
%%
% Ego motion format display
disp('Ego motion format: \n');
disp(trackerDataFormats{end});

%% Step 5 - Update the tracker

% Create a viewer to visualize raw sensor data, object-level detections for each sensor, and tracks. 
viewer = HelperAutomotiveSpecTrackingViewer.createViewer...
    (radarSpec, lidarSpec, cameraSpec, sensorFlags);

% The loop is executed at every odometry update. This ensures ego motion is
% up to date. The tracks are updated when either sensor is reporting. In
% the example, we will run about 20 seconds of recorded data.
timestamps = highwayRecordedData.Odometry.Timestamps(1:2000);

% Last odometry data captured used to ego motion estimation
lastOdometry.Vehicle = highwayRecordedData.Odometry.Vehicle(1);
lastOdometry.Timestamp = highwayRecordedData.Odometry.Timestamps(1);

% Initialize ego motion
egoMotion = struct('Time',timestamps(1),...
    'EgoPositionalDisplacement',[0 0 0],...
    'EgoRotationalDisplacement',[0 0 0]);

% Loop over all tracker events
for i = 2:numel(timestamps)
    % Stream data since last timestamp
    sensorData = streamData(highwayRecordedData, timestamps(i-1), timestamps(i));
    
    % Update ego motion
    [egoMotion, lastOdometry] = estimateEgoMotion(egoMotion, lastOdometry, sensorData.Odometry);
    
    % Object detection on radar point cloud. Vehicle odometry is used to
    % filter static returns
    radarDetectionData = detectRadarClusters(radarSpec, sensorData.Radar, sensorData.Odometry);
    
    % Object detection on camera images using YOLO detection
    cameraDetectionData = detectImageBoundingBoxes(cameraSpec, sensorData.Camera);
    
    % Object detection on lidar point cloud using Voxel RCNN
    lidarDetectionData = detectLidarBoundingBoxes(lidarSpec, sensorData.Lidar);
    
    % Collect sensor data in the order of sensor specifications
    sensorDetectionData = {radarDetectionData, lidarDetectionData, cameraDetectionData};

    % Update tracker with sensors used and ego motion
    tracks = tracker(sensorDetectionData{sensorFlags}, egoMotion);
    
    % If the tracker was updated, reset ego motion with 0
    % displacement at latest detection time.
    egoMotion = resetEgoMotion(egoMotion, sensorDetectionData{sensorFlags});

    % Visualize the data and estimates using helper
    HelperAutomotiveSpecTrackingViewer.updateViewer...
        (viewer, tracks, radarSpec, lidarSpec, cameraSpec, ...
        sensorDetectionData, sensorData, sensorFlags);
end

%% Supporting Functions
%% Radar Object Detection

function radarClusters = detectRadarClusters(radarSpec, currentRadarData, currentOdomData)
% This is a supporting function for the automotive tracking example for
% clustering radar point clouds. 

% The format of radar clusters defined by the sensor specification.
radarClusters = dataFormat(radarSpec);

if isempty(currentRadarData.Timestamps) || isempty(currentOdomData.Timestamps)
    radarClusters.Time = zeros(0,1);
    return;
end

% If detections are already loaded, just return them. Otherwise, use DBSCAN
% for clustering defined below.
if isfield(currentRadarData,'Detections')
    radarClusters = currentRadarData.Detections(end);
    return;
end

persistent dbscan

if isempty(dbscan)
    dbscan = clusterDBSCAN;
    dbscan.Epsilon = [5 2 10];
    dbscan.MinNumPoints = 2;
end


% Radar point cloud
radarPtCloud = currentRadarData.PointClouds(end);

% Compute sensor velocity in the global frame
sensorLoc = radarSpec.MountingLocation(:);
odomData = currentOdomData.Vehicle(end);
sensorVel = [odomData.Speed;0;0] + cross([0;0;odomData.YawRate],sensorLoc);

% Provide ego information on clusters for doppler compensation by the
% tracker.
radarClusters.EgoSpeed = odomData(end).Speed;
radarClusters.EgoAngularVelocity = [0 0 rad2deg(odomData(end).YawRate)];

% Compute doppler assuming stationary points
x = radarPtCloud.x';
y = radarPtCloud.y';
z = radarPtCloud.z';
pts = [x;y;z];
vel = repmat(-sensorVel,1,numel(x));
r = sqrt(x.^2 + y.^2 + z.^2);
staticrr = dot(pts,vel,1)./r;

% Compare with reported points
rr = radarPtCloud.radial_speed';

% Points with similar doppler are classified as static points and filtered
% out.
isStatic = abs(rr - staticrr) < 2.5;

% Dynamic points
x = x(~isStatic);
y = y(~isStatic);
z = z(~isStatic);
rr = rr(~isStatic);

% Clustering in Cartesian
[~,clusters] = dbscan(double([x;y;z]'));

% Spherical coordinates for final reporting
[az, el, r] = cart2sph(x, y, z);
az = rad2deg(az);
el = rad2deg(el);

% Unique and number of clusters
uqClusters = unique(clusters);
nClusters = numel(uqClusters);

% Assemble clusters in the format required by the tracker
nZeros = zeros(1,nClusters);
radarClusters.Time = radarPtCloud.Timestamp;
fields = {'Azimuth','Elevation','Range','RangeRate',...
    'AzimuthAccuracy','RangeAccuracy','ElevationAccuracy','RangeRateAccuracy'};
for i = 1:numel(fields)
    radarClusters.(fields{i}) = nZeros;
end

% Fill clustered detections into the output by taking their mean and
% accuracy per cluster.
for i = 1:nClusters
    inCluster = clusters == uqClusters(i);
    % Azimuth and error covariance
    azi = az(inCluster);
    azC = mean(azi);
    azCov = 4 + (azi - azC)*(azi - azC)';
    radarClusters.Azimuth(i) = azC;
    radarClusters.AzimuthAccuracy(i) = sqrt(azCov);
    
    % Elevation and error covariance
    eli = el(inCluster);
    elC = mean(eli);
    elCov = 10 + (eli - elC)*(eli - elC)';
    radarClusters.Elevation(i) = elC;
    radarClusters.ElevationAccuracy(i) = sqrt(elCov);
    
    % Range and error covariance
    ri = r(inCluster);
    rC = mean(ri);
    rCov = 1.25^2 + (ri - rC)*(ri - rC)';
    radarClusters.Range(i) = rC;
    radarClusters.RangeAccuracy(i) = sqrt(rCov);
    
    % Range-rate and error covariance
    rri = rr(inCluster);
    rrC = mean(rri);
    rrCov = 1.25^2 + (rri - rrC)*(rri - rrC)';
    radarClusters.RangeRate(i) = rrC;    
    radarClusters.RangeRateAccuracy(i) = sqrt(rrCov);
end

end

%% Lidar Object Detection

function lidarData = detectLidarBoundingBoxes(lidarData, currentLidarData)
% This is a supporting function for the automotive tracking example for
% bounding box detection on lidar point clouds. 

% The format of radar clusters defined by the sensor specification.
lidarData = dataFormat(lidarData);

if isempty(currentLidarData.Timestamps)
    lidarData.Time = zeros(0,1);
    return;
end

% If detections are already loaded, just return them. Otherwise, run a
% Voxel RCNN detector on it
if isfield(currentLidarData,'Detections')
    lidarData = currentLidarData.Detections(end);
    return;
end

% Load the detector and corresponding parameters. 
persistent detector params

if isempty(params)
    params = lidarParameters('HDL64E',1024);
    detector = voxelRCNNObjectDetector('kitti');
end

% Get the point cloud
ptCloud = currentLidarData.PointClouds{end};

% Organize the point cloud
ptCloud = pcorganize(ptCloud,params);

% Remove invalid points
ptCloud = removeInvalidPoints(ptCloud);

% Detect using Voxel RCNN detector
bboxes = detect(detector,ptCloud,'Threshold',0.5);

% Assemble on the lidar data format
lidarData.Time = currentLidarData.Timestamps(end);
lidarData.BoundingBox = double(bboxes');

end

%% Camera Object Detection


function cameraData = detectImageBoundingBoxes(cameraSpec, currentCameraData)
% This is a supporting function for the automotive tracking example for
% bounding box detection on camera images. 

% The format of camera bounding boxes defined by the sensor specification.
cameraData = dataFormat(cameraSpec);

if isempty(currentCameraData.Timestamps)
    cameraData.Time = zeros(0,1);
    return;
end

% If detections are already loaded, just return them. Otherwise, run a YOLO
% detector on the image. Images are assumed to be undistorted.
if isfield(currentCameraData,'Detections')
    cameraData = currentCameraData.Detections(end);
    return;
end

% Load YOLO detector 
persistent detector

if isempty(detector)
    % Create YOLOv4 Detector
    detector = yolov4ObjectDetector;
end

% Bounding box detection
img = currentCameraData.Images{end};
[boundingBoxes, ~, labels] = detect(detector, img, 'Threshold',0.7);

% Keep bounding boxes of cars and trucks
carTruckDetections = string(labels)=="car" | string(labels) == 'truck';
boundingBoxes = boundingBoxes(carTruckDetections,:);

% FIlter partially occluded boxes using a aspect ratio test
valid = boundingBoxes(:,3) > 0.75*boundingBoxes(:,4);
boundingBoxes = boundingBoxes(valid,:);

% Assemble camera data
cameraData.Time = currentCameraData.Timestamps(end);
cameraData.BoundingBox = double(boundingBoxes');

end

%% Ego Motion Estimation

function [egoMotion, lastOdometry] = estimateEgoMotion(egoMotion, lastOdometry, currentOdometry)

tLast = egoMotion.Time(end);
tCurrent = currentOdometry.Timestamps;
if tCurrent > tLast
    dT = tCurrent - tLast;
    egoMotion.Time = [egoMotion.Time tCurrent];
    s = lastOdometry.Vehicle.Speed;
    w = lastOdometry.Vehicle.YawRate;
    if abs(w) > 0
        dx = s/w*sin(w*dT);
        dy = s/w*(1 - cos(w*dT));
    else
        dx = s*dT;
        dy = 0;
    end
    egoMotion.EgoPositionalDisplacement(end+1,:) = [dx dy 0];
    egoMotion.EgoRotationalDisplacement(end+1,:) = [rad2deg(w*dT) 0 0];
end
lastOdometry = currentOdometry;
end

%% Reset Ego motion
function egoMotion = resetEgoMotion(egoMotion, varargin)
t = 0;
for i = 1:numel(varargin)
    if ~isempty(varargin{i}.Time)
        t = max(t,varargin{i}.Time);
        egoMotion.Time = t;
        egoMotion.EgoPositionalDisplacement = [0 0 0];
        egoMotion.EgoRotationalDisplacement = [0 0 0];
    end
end
end

%% Data Streaming and Loading 

function data = downloadDataset()
% Download dataset from supporting files
seqName = 'MultiSensorDrivingData_Seg7_Seq30';

datasetZipFile = matlab.internal.examples.downloadSupportFile('driving',['data/',seqName,'.zip']);
datasetFolder = fullfile(fileparts(datasetZipFile),seqName);
if ~exist(datasetFolder,'dir')
    unzip(datasetZipFile,datasetFolder);
end

% Path of the dataset
dataPath = fullfile(datasetFolder,'30');

% Load data into a struct
data = struct;

% Load radar data
data = loadRadarData(data, dataPath);

% Load camera data
data = loadCameraData(data, dataPath);

% Load lidar data
data = loadLidarData(data, dataPath);

% Load Vehicle Odometry Data
data = loadOdometryData(data, dataPath);
end


%% Load Radar Data
function data = loadRadarData(data, dataPath)
% Load radar data from a MAT file
s = load(fullfile(dataPath,'Radar','RadarData.mat'));

% Store it in the struct
data.Radar.PointClouds = [s.Data{:}];
data.Radar.Timestamps = cellfun(@(x)x.Timestamp, s.Data);

% If detections are present, load them too
detFileName = ['RadarDetectionsSeq',dataPath(end-1:end),'.mat'];
if exist(fullfile(pwd,detFileName),'file')
    s = load(fullfile(pwd,detFileName));
    data.Radar.Detections = s.RadarData;
end
end

%% Load Camera Data
function data = loadCameraData(data, dataPath)

% Path of camera data
cameraPath = fullfile(dataPath,'FrontCamera');

% Create camera d for undistorting the image. This must be done
% before object detection
k = [1176.29501,    0.     ,  520.32287;
    0      , 1176.28913,  389.60511;
    0.     ,    0.     ,    1     ];
d = [-0.21760;0.215736;0.001291;0.001232];

I = cameraIntrinsics([k(1,1) k(2,2)],...
    [k(1,3) k(2,3)],...
    [768 1024],'RadialDistortion',d(1:2),'TangentialDistortion',d(3:4));

% Loop over all images, undistort them, and store.
counter = 1;
recordedCameraData = cell(0,1);
while exist(fullfile(cameraPath,num2str(counter,"%04d.jpeg")),'file')
    im = imread(fullfile(cameraPath,num2str(counter,"%04d.jpeg")));
    im = undistortImage(im, I);
    recordedCameraData{counter,1} = im;
    counter = counter + 1;
end

% Store it in the struct
s = load(fullfile(cameraPath,'Timestamps.mat'));
data.Camera.Images = recordedCameraData;
data.Camera.Timestamps = s.Timestamps;

% If detections are present, load them too
detFileName = ['CameraDetectionsSeq',dataPath(end-1:end),'.mat'];
if exist(fullfile(pwd,detFileName),'file')
    s = load(fullfile(pwd,detFileName));
   data.Camera.Detections = s.CameraData;
end

end

%% Load Lidar Data
function data = loadLidarData(data, dataPath)
% Path of LS lidar
lidarPath = fullfile(dataPath,'Lidar2');

% Lidar axes is rotated by 90, make X forward to facilitate pre-trained
% deep learning detectors.
tform = rigidtform3d([0 0 -90],[0 0 0]);

% Loop over each file and load the data
counter = 1;
recordedLidarData = cell(0,1);
while exist(fullfile(lidarPath,num2str(counter,"%03d.pcd")),'file')
    pc = pcread(fullfile(lidarPath,num2str(counter,"%03d.pcd")));
    pc = pctransform(pc,tform);
    recordedLidarData{counter,1} = pc;
    counter = counter + 1;
end

% Store it in the struct
s = load(fullfile(lidarPath,'Timestamps.mat'));
data.Lidar.PointClouds = recordedLidarData;
data.Lidar.Timestamps = s.Timestamps;

% If detections are present, load them too
detFileName = ['LidarDetectionsSeq',dataPath(end-1:end),'.mat'];
if exist(fullfile(pwd,detFileName),'file')
    s = load(fullfile(pwd,detFileName));
   data.Lidar.Detections = s.LidarData;
end
end

%% Load Odometry Data
function data = loadOdometryData(data, dataPath)
odomPath = fullfile(dataPath,'VehicleOdometry','VehicleOdometry.mat');
s = load(odomPath);
data.Odometry.Vehicle = [s.odometry{:}];
data.Odometry.Timestamps = cellfun(@(x)x.Timestamp,s.odometry);
end

%% Stream Data
function currentData = streamData(data, t1, t2)
    % Radar data
    t = data.Radar.Timestamps;
    valid = t > t1 & t <= t2;
    currentData.Radar.PointClouds = data.Radar.PointClouds(valid);
    currentData.Radar.Timestamps = data.Radar.Timestamps(valid);
    if isfield(data.Radar,'Detections')
        currentData.Radar.Detections = data.Radar.Detections(valid);
    end

    % Lidar data
    t = data.Lidar.Timestamps;
    valid = t > t1 & t <= t2;
    currentData.Lidar.PointClouds = data.Lidar.PointClouds(valid);
    currentData.Lidar.Timestamps = data.Lidar.Timestamps(valid);
    if isfield(data.Lidar,'Detections')
        currentData.Lidar.Detections = data.Lidar.Detections(valid);
    end

    % Camera data
    t = data.Camera.Timestamps;
    valid = t > t1 & t <= t2;
    currentData.Camera.Images = data.Camera.Images(valid);
    currentData.Camera.Timestamps = data.Camera.Timestamps(valid);
    if isfield(data.Camera,'Detections')
        currentData.Camera.Detections = data.Camera.Detections(valid);
    end

    % Vehicle odometry data
    t = data.Odometry.Timestamps;
    valid = t > t1 & t <= t2;
    currentData.Odometry.Vehicle = data.Odometry.Vehicle(valid);
    currentData.Odometry.Timestamps = data.Odometry.Timestamps(valid);
end
%% 
% Copyright 2024 The MathWorks, Inc.