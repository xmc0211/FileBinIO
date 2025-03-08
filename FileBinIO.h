//FileBinIO.h by XMC
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
