CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -lcs50

SRC_DIR = $(ROOT_DIR)/src
BUILD_DIR = $(ROOT_DIR)/build
INCLUDE_DIR = $(ROOT_DIR)/include

all: $(BUILD_DIR)/mon_programme

$(BUILD_DIR)/mon_programme: $(SRC_DIR)/mon_programme.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ $(LDLIBS) -o $@
