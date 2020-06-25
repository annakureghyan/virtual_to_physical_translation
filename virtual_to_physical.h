#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>


#define ORIG_BUFFER "Hello, World!"
#define NEW_BUFFER "Hello, Linux!"
#define PAGE_SHIFT 12
#define PAGEMAP_LENGTH 8


void* create_buffer(void);
unsigned long get_page_frame_number_of_address(void *addr);
