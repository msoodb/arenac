
NAME		= lltfim
SRC_DIR		= src
BIN_DIR		= bin
TEST_DIR	= tests
INC_DIR_SRC	= src
#INC_DIR_LIB	= lib

CC 	= cc
CFLAGS	=-std=c89    
CFLAGS += -Wall    
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef  
CFLAGS += -Wold-style-definition
CFLAGS += -I$(INC_DIR_SRC)
LIBS 	= -lcheck -lsubunit -lm -lrt -lpthread
DFLAGS	= -g
OUTPUT_OPTION 	= -MMD -MP -o $@

EXECUTABLE	= $(BIN_DIR)/$(NAME)
SOURCES		= $(wildcard $(SRC_DIR)/*.c)
OBJECTS		= $(SOURCES:.c=.o)
DEPS   		= $(SOURCES:.c=.d)

TESTS		= $(TEST_DIR)/$(NAME)
TEST_SOURCES	= $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS	= $(TEST_SOURCES:.c=.o)

all:	build $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(DFLAGS)

-include ${DEPS}

build:
	-@mkdir -p $(BIN_DIR)

test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) src/entry.h src/entry.c tests/test_entry.c $(LIBS) -o $(TEST_DIR)/test_entry
	-@./$(TEST_DIR)/test_entry

etags:
	-@etags -o $(SRC_DIR)/TAGS $(SOURCES)

clean:
	-@rm -rf $(BIN_DIR) $(OBJECTS)
	-@rm -rf $(TEST_OBJECTS) 

help:
	-@echo "make: make the executable"
	-@echo "make test: run test against"
	-@echo "make clean: remove objects and executables"
	-@echo "make etags: build the etags file"
	-@echo "make help: print this help"

