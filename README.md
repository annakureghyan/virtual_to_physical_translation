# Translate virtual address to physical address

The goal of this project is to write a program that translates virtual address to physical address

# Code description

void* create_buffer(void); // allocate some memory to manipulate and add some data to the memory

unsigned long get_page_frame_number_of_address(void * addr); use /proc/[pid]/pagemap to get page frame number of a given address

physcial_addr = (page_frame_number << PAGE_SHIFT) + distance_from_page_boundary_of_buffer // calculate the physical address of buffer

