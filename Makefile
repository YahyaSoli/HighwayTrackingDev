CC = gcc
CXX = g++
CFLAGS = -g -Wall -I./include -I/usr/include/hdf5/serial -I./include/sdf -I./darknet/include -DMULTITHREADED
CXXFLAGS = -g -Wall -std=c++11 -I./include -I/usr/include/hdf5/serial -I./include/sdf -I./darknet/include -DMULTITHREADED
LDFLAGS = -lm -lpthread -lstdc++ -lhdf5_serial -lstdc++ libdarknet.a -lstdc++ -L/usr/local/cuda/lib64 -lcuda -lcudart -lcublas -lcurand -lmvec `pkg-config --libs opencv4 2> /dev/null || pkg-config --libs opencv`
CXXLDFLAGS = -lm -lpthread -lstdc++ -lhdf5_serial -lstdc++ libdarknet.a -lstdc++ -L/usr/local/cuda/lib64 -lcuda -lcudart -lcublas -lcurand -lmvec `pkg-config --libs opencv4 2> /dev/null || pkg-config --libs opencv`

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Include FIFO source and Darknet detector
SRCS = $(wildcard $(SRC_DIR)/*.c) include/sdf/fifo.c
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))
TARGET = $(BIN_DIR)/highway_tracker

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: include/sdf/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) 