#include "virtual_to_physical.h"

int main(void) {

   void *buffer = create_buffer();

   unsigned int page_frame_number = get_page_frame_number_of_address(buffer);
   printf("Page frame: 0x%x\n", page_frame_number);

   unsigned int distance_from_page_boundary = (unsigned long)buffer % getpagesize();

   uint64_t physical_address = (page_frame_number << PAGE_SHIFT) + distance_from_page_boundary;
   printf("Physical address: %lld\n", physical_address);
   
   printf("Buffer: %s\n", buffer);
   
   free(buffer);

   return 0;
}
