/*
 * @Author: yan yzc53@icloud.com
 * @Date: 2023-11-05 20:36:03
 * @LastEditors: yan yzc53@icloud.com
 * @LastEditTime: 2023-11-06 16:13:11
 * @FilePath: /malloc-free/memlib.c
 * @Description: 
 * @QQ: 1594047159@qq.com
 * Copyright (c) 2023,All Rights Reserved. 
 */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "memlib.h"
#define MAX_HEAP (20*(1<<20)) 

static char *mem_heap;      /* Points to first byte of heap */
static char *mem_brk;       /* Points to last byte of allocated heap plus 1 */
static char *mem_max_addr;  /* Max legal heap addr plus 1*/ 

/* initialize the memory system model 
 * which makes use of system malloc() function
 * to apply for array as a memory system model
 */
void mem_init(void)
{
    mem_heap = (char*)malloc(MAX_HEAP);
    mem_brk = mem_heap;
    mem_max_addr = mem_heap + MAX_HEAP;
}

/* same function as system sbrk() except that it cannot shrink */
void* mem_sbrk(int incr)
{
    char *old_brk = mem_brk;
    if((incr < 0) || (mem_brk + incr > mem_max_addr))
    {
        errno = ENOMEM;
        fprintf(stderr, "ERROR: mem_sbrk failed. Ran out of memory...\n");
        return (void*)-1;
    }
    mem_brk += incr;
    return (void*)old_brk;
}

/* destroy the memory system model */
void mem_deinit(void)
{
    free(mem_heap);
    mem_heap = mem_brk = mem_max_addr = 0;
    return;
}

/* returns the page size of the system */
size_t mem_pagesize(void)
{
    return (size_t)getpagesize();
}

/* returns the heap size in bytes */
size_t mem_heapsize() 
{
    return (size_t)((void *)mem_brk - (void *)mem_heap);
}

/* reset the simulated brk pointer to make an empty heap */
void mem_reset_brk(void)
{
    mem_brk = (char *)mem_heap;
}

/* return address of the first heap byte */
void *mem_heap_bottom()
{
    return (void *)mem_heap;
}

/* return address of last heap byte */
void *mem_heap_top()
{
    return (void *)(mem_brk - 1);
}