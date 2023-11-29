/*
 * @Author: yan yzc53@icloud.com
 * @Date: 2023-11-06 11:25:49
 * @LastEditors: yan yzc53@icloud.com
 * @LastEditTime: 2023-11-06 11:25:53
 * @FilePath: /malloc-free/memlib.h
 * @Description: 
 * @QQ: 1594047159@qq.com
 * Copyright (c) 2023,All Rights Reserved. 
 */

#include <unistd.h>

void mem_init(void);               
void *mem_sbrk(int incr);
void mem_deinit(void);
void mem_reset_brk(void); 
void *mem_heap_bottom();
void *mem_heap_top();
size_t mem_heapsize(void);
size_t mem_pagesize(void);