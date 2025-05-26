CC = gcc
CFLAGS = -Wall -Wextra -g -I/usr/include/hdf5/serial -I./include
LDFLAGS = -lhdf5_serial -lm

SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib

SRCS = src/main.c src/sensor_loader.c src/tracker_specs.c src/data_streamer.c src/ego_motion.c
OBJS = $(SRCS:.c=.o)
TARGET = highway_tracker

.PHONY: all clean directories

all: directories $(TARGET)

directories:
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) 