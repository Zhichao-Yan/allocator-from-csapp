/*
 * @Author: yan yzc53@icloud.com
 * @Date: 2023-11-06 16:15:36
 * @LastEditors: yan yzc53@icloud.com
 * @LastEditTime: 2023-11-06 16:24:42
 * @FilePath: /malloc-free/main.c
 * @Description: 
 * @QQ: 1594047159@qq.com
 * Copyright (c) 2023,All Rights Reserved. 
 */
#include <stdio.h>
#include <string.h>
#include "memlib.h"
#include "mm.h"
int main()
{
    mem_init();
    int *arr = (int*)mm_malloc(sizeof(int) * 3);
    arr[0] = 100;
    arr[1] = 1000;
    arr[2] = 10000;
    char *str= (char*)mm_malloc(sizeof(char) * 15);
    strcpy(str,"helloworld");
    mm_checkheap(1);
    mm_free(arr);
    double *d = (double*)mm_malloc(sizeof(double) * 2);
    mm_checkheap(1);
    mm_free(str);
    mm_free(d);
    mem_deinit();
}