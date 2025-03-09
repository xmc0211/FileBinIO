// MIT License
//
// Copyright (c) 2025 xmc0211
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FILEBINIO_H
#define FILEBINIO_H

#include <windows.h>

enum FB_RESULTS {
    FB_SUCCESS = 0x0, 
    FB_ERROR = 0x1, 
    FB_FILE_NOT_EXIST = 0x2, 
    FB_OUT_OF_RANGE = 0x4, 
    FB_INVAILD_POINTER = 0x8
};

const UINT FB_UI_INF = UINT_MAX;
const ULONG FB_UL_INF = ULONG_MAX;
const ULONGLONG FB_ULL_INF = ULLONG_MAX;

template <typename _Tp>
_Tp FBMax(_Tp x, _Tp y);

template <typename _Tp>
_Tp FBMin(_Tp x, _Tp y);


//LARGE_INTEGER转ULONG
ULONG FBLIntToUl(LARGE_INTEGER x);

//ULONG转LARGE_INTEGER
LARGE_INTEGER FBUlToLInt(ULONG x);

// 获取文件字节数（单位：字节）
LARGE_INTEGER FBGetFileSize(const char* filePath);

// 按字节读文件（磁盘）
DWORD FBReadFile(const char* lpcFilePath, // 文件路径
    UCHAR* lpcData, // 接收数据段指针
    LPDWORD lpdwBytesRead, // 接收读取字节数指针 
    LONG uiRstart, // 读取起始地址
    DWORD uiRsize = FB_UL_INF // 读取总大小（FB_UI_INF表示到末尾）
);

// 按字节写文件（磁盘）
DWORD FBWriteFile(const char* lpcFilePath, // 文件路径
    UCHAR* lpcData, // 写入数据段指针
    LPDWORD lpdwBytesWrite, // 接收写入字节数指针 
    LONG uiWstart, // 写入起始地址
    DWORD uiWsize // 写入总大小
);

#endif
