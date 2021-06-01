# makefile variables
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

# "wildcard" function used to find all the .c files
# assigns them to C_SRCS
C_SRCS := \
  $(wildcard *.c) \
  $(wildcard src/*.c) \
  $(wildcard src/**/*.c)

# "wildcard" function used to find all the .h files
# assigns them to HDRS
HDRS := \
  $(wildcard *.h) \
  $(wildcard src/*.h) \
	$(wildcard src/**/*.h)

# finds .c files in rhe main ans src directory
# and replaces with .o files
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# command runs build command first
# and then displays message "All Done"
all: build
	@echo "All Done"

# command compiles and links .c and object files
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# saving the .o files in the main directory
# to a seprate directory names bin
bin/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#  saving the .o files in the src directory
# to a seprate directory named bin
bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# removes output and bin files
clean:
	rm -f $(TARGET)
	rm -rf bin

# command runs build first and then runs the executeable file
run: build
	./$(TARGET) secret.pmm key decrypt.ppm

#command displays source, header and object files
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"

#command tars entire directory
tar:
	tar -zcvf ahayes5_Lab2.tar.gz *
