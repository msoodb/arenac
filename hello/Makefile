
include makefile.config

TARGET	= hello
SOURCE	= $(wildcard *.c)
OBJS	= $(SOURCE:.c=.o)
DEPS	= $(SOURCE:.c=.d)
-include ${DEPS}

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

etags:
	etags *.c *.h

help:
	-@echo "make $(TARGET): make the executable"
	-@echo "make clean: clean"
	-@echo "make etags: build the etags file"
	-@echo "make help: print hellp"
clean:
	-@rm $(OBJS)

realclean:
	-@rm -f $(OBJS) $(DEPS) $(TARGET)

