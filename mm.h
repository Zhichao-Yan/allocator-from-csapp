/*
 * @Author: yan yzc53@icloud.com
 * @Date: 2023-11-06 11:29:31
 * @LastEditors: yan yzc53@icloud.com
 * @LastEditTime: 2023-11-06 11:49:34
 * @FilePath: /malloc-free/mm.h
 * @Description: 
 * @QQ: 1594047159@qq.com
 * Copyright (c) 2023,All Rights Reserved. 
 */
#include <unistd.h>
extern int mm_init(void);
extern void *mm_malloc (size_t size);
extern void mm_free (void *ptr);
/* $end mallocinterface */

extern void *mm_realloc(void *ptr, size_t size);
extern void *mm_calloc (size_t nmemb, size_t size);
extern void mm_checkheap(int verbose);