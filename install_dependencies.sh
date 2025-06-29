#!/bin/bash

echo "Installing dependencies for C++ YOLO detector..."

# Update package list
sudo apt update

# Install OpenCV development libraries
echo "Installing OpenCV..."
sudo apt install -y libopencv-dev

# Install cJSON library
echo "Installing cJSON..."
sudo apt install -y libcjson-dev

# Install additional build tools
echo "Installing build tools..."
sudo apt install -y build-essential cmake pkg-config

# Install HDF5 (if not already installed)
echo "Installing HDF5..."
sudo apt install -y libhdf5-dev

echo "Dependencies installed successfully!"
echo ""
echo "To build the project:"
echo "  make clean"
echo "  make all"
echo ""
echo "To build only the YOLO detector:"
echo "  make yolo"
echo ""
echo "To test the C++ YOLO detector:"
echo "  ./bin/yolo_detector" 