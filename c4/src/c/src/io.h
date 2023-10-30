#ifndef C4_IO_H
#define C4_IO_H

#include "defs.h"

typedef struct _io* io_t;

io_t   io_create(void);
io_t   io_create_from_file(const char* filename);
io_t   io_dump_to_file(const char* filename);
void   io_destroy(io_t io);
u64    io_size(io_t io);
void*  io_read(io_t io, u64 bytes);
void   io_write(io_t io, const void* data, u64 bytes);

#endif //C4_IO_H