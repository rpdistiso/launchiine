#ifndef __MEMORY_H
#define __MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdint>
#include <malloc.h>

void libgui_memoryInitialize(void);

void libgui_memoryRelease(void);

void *MEM2_alloc(uint32_t size, uint32_t align);

void MEM2_free(void *ptr);

void *MEM1_alloc(uint32_t size, uint32_t align);

void MEM1_free(void *ptr);

void *MEMBucket_alloc(uint32_t size, uint32_t align);

void MEMBucket_free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif // __MEMORY_H
