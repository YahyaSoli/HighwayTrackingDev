#!/bin/bash

echo "Testing Darknet YOLO integration..."

# Check if required files exist
echo "Checking required files..."
if [ ! -f "yolov4.cfg" ]; then
    echo "❌ yolov4.cfg not found"
    exit 1
fi

if [ ! -f "yolov4.weights" ]; then
    echo "❌ yolov4.weights not found"
    exit 1
fi

if [ ! -f "coco.names" ]; then
    echo "❌ coco.names not found"
    exit 1
fi

if [ ! -f "darknet/libdarknet.a" ]; then
    echo "❌ darknet/libdarknet.a not found - please build darknet first"
    echo "Run: cd darknet && make"
    exit 1
fi

echo "✅ All required files found"

# Build the project
echo "Building project..."
make clean
make all

if [ $? -ne 0 ]; then
    echo "❌ Build failed"
    exit 1
fi

echo "✅ Build successful"

# Test the main program
echo "Testing main program with Darknet..."
echo "14" | ./bin/highway_tracker

echo "✅ Darknet integration test completed" 