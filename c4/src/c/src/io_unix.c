#ifdef __linux__

#include "io.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _io {
  FILE* fd;
  char* data;
  u64 size;
};

enum {
  IO_STRUCT_SIZE = sizeof(struct _io)
};

io_t io_create(void) {
  io_t io = malloc(IO_STRUCT_SIZE);
  if (io) {
    memset(io, 0, IO_STRUCT_SIZE);
  }
  return 0;
}

io_t   io_create_from_file(const char* filename) {
  io_t io = io_create();
  if (io) {
    io->fd = fopen(filename, "rb+");
    if (io->fd) {
      fseek(io->fd, 0, 2); // go till end
      io->size = ftell(io->fd);
      fseek(io->fd, 0, 0); // go back to start
      fread(io->data, io->size, io)
    }

    return io;
  }
  return 0;
}

io_t   io_dump_to_file(const char* filename) {

}

void   io_destroy(io_t io) {
  if (io) {
    
  }
}

u64    io_size(io_t io) {
  if (io) {
    return io->size;
  }
}

void*  io_read(io_t io, u64 bytes) {
  if (io) {

  }
}

void   io_write(io_t io, const void* data, u64 bytes) {

}


#endif