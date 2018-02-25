TARGET = thread

CC = gcc
IDIR = ../include
DDIR = ../dist

CFLAGS = -g -I$(IDIR)

DEPS = $(wildcard $(IDIR)/*.h)
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $^ -pthread

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean dist

clean:
	$(RM) *.o

dist: $(TARGET) clean
	mv $(TARGET) $(DDIR)
