#include "virtual_to_physical.h"

void* create_buffer(void) {
   size_t buf_size = strlen(ORIG_BUFFER) + 1;

   void *buffer = malloc(buf_size);
   if(buffer == NULL) {
      fprintf(stderr, "Failed to allocate memory for buffer\n");
      exit(1);
   }

   if(mlock(buffer, buf_size) == -1) {
      fprintf(stderr, "Failed to lock page in memory: %s\n", strerror(errno));
      exit(1);
   }

   strncpy(static_cast<char*>(buffer), ORIG_BUFFER, strlen(ORIG_BUFFER));

   return buffer;
}

unsigned long get_page_frame_number_of_address(void *addr) {
   FILE *pagemap = fopen("/proc/self/pagemap", "rb");

   unsigned long offset = (unsigned long)addr / getpagesize() * PAGEMAP_LENGTH;
   if(fseek(pagemap, (unsigned long)offset, SEEK_SET) != 0) {
      fprintf(stderr, "Failed to seek pagemap to proper location\n");
      exit(1);
   }

   unsigned long page_frame_number = 0;
   fread(&page_frame_number, 1, PAGEMAP_LENGTH-1, pagemap);

   page_frame_number &= 0x7FFFFFFFFFFFFF;

   fclose(pagemap);

   return page_frame_number;
}

