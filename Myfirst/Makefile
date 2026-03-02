CC = g++
CFLAGS = -std=c++17 -O2 -Wall

# Primary executables
TARGETS = sort bubble_sort

all: $(TARGETS)

sort: binary_insertion_sort.cpp
	$(CC) $(CFLAGS) $^ -o $@

bubble_sort: bubble_sort.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean
