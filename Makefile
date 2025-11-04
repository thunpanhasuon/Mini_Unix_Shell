CC=gcc 
CFLAGs= -Wall -Wextra -Wpedantic -std=c99

SRC_DIR = src 
OBJECT_DIR = build 
BIN_DIR = bin 


RELEASE = -g -O3 
DEBUG_FLAGs = -g -O0

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJECT_DIR)/%.o)
TARGET = $(BIN_DIR)/app

all: $(TARGET)

$(TARGET): $(OBJS) 
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o ^@ 

$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o ^@ 

ifeq ($(MODE), debug) 
	CFLAGs += $(DEBUG_FLAGs)
else 
	CFLAGs += $(RELEASE )
endif 

.PHONY: clean 
clean: 
	rm -f $(OBJECT_DIR) $(BIN_DIR) 
			
	

	
