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


//LARGE_INTEGERתULONG
ULONG FBLIntToUl(LARGE_INTEGER x);

//ULONGתLARGE_INTEGER
LARGE_INTEGER FBUlToLInt(ULONG x);

// ��ȡ�ļ��ֽ�������λ���ֽڣ�
LARGE_INTEGER FBGetFileSize(const char* filePath);

// ���ֽڶ��ļ������̣�
DWORD FBReadFile(const char* lpcFilePath, // �ļ�·��
    UCHAR* lpcData, // �������ݶ�ָ��
    LPDWORD lpdwBytesRead, // ���ն�ȡ�ֽ���ָ�� 
    LONG uiRstart, // ��ȡ��ʼ��ַ
    DWORD uiRsize = FB_UL_INF // ��ȡ�ܴ�С��FB_UI_INF��ʾ��ĩβ��
);

// ���ֽ�д�ļ������̣�
DWORD FBWriteFile(const char* lpcFilePath, // �ļ�·��
    UCHAR* lpcData, // д�����ݶ�ָ��
    LPDWORD lpdwBytesWrite, // ����д���ֽ���ָ�� 
    LONG uiWstart, // д����ʼ��ַ
    DWORD uiWsize // д���ܴ�С
);

#endif
