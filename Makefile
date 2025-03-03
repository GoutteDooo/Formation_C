ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -lcs50

SRC_DIR = $(ROOT_DIR)/week4/recursive
BUILD_DIR = $(ROOT_DIR)

all: $(BUILD_DIR)

$(BUILD_DIR)/recursive: $(SRC_DIR)/recursive.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ $(LDLIBS) -o $@
