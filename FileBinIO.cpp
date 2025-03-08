//FileBinIO.cpp by XMC

#include "FileBinIO.h"

template <typename _Tp>
_Tp FBMax(_Tp x, _Tp y) {return x > y ? x : y; }

template <typename _Tp>
_Tp FBMin(_Tp x, _Tp y) { return x > y ? y : x; }


//LARGE_INTEGERתULONG
ULONG FBLIntToUl(LARGE_INTEGER x) {
    ULONG ulValue;
    ulValue = (ULONG)x.QuadPart;
    return ulValue;
}

//ULONGתLARGE_INTEGER
LARGE_INTEGER FBUlToLInt(ULONG x) {
    LARGE_INTEGER liValue{};
    liValue.QuadPart = (LONGLONG)x;
    return liValue;
}

// ��ȡ�ļ��ֽ�������λ���ֽڣ�
LARGE_INTEGER FBGetFileSize(const char* filePath) {
    LARGE_INTEGER fileSize;
    fileSize.QuadPart = 0;

    // ���ļ��Զ�ȡ���С
    HANDLE hFile = CreateFileA(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) return fileSize;

    // ��ȡ�ļ���С
    if (!GetFileSizeEx(hFile, &fileSize)) {
        // �ر��ļ����
        CloseHandle(hFile);
        return fileSize;
    }

    // �ر��ļ����
    CloseHandle(hFile);
    return fileSize;
}

// ���ֽڶ��ļ������̣�
DWORD FBReadFile(const char* lpcFilePath, // �ļ�·��
    UCHAR* lpcData, // �������ݶ�ָ��
    LPDWORD lpdwBytesRead, // ���ն�ȡ�ֽ���ָ�� 
    LONG uiRstart, // ��ȡ��ʼ��ַ
    DWORD uiRsize /* = FB_UL_INF */ // ��ȡ�ܴ�С��FB_UI_INF��ʾ��ĩβ��
) {
    LARGE_INTEGER liFileSize = FBGetFileSize(lpcFilePath);

    // �ж�����Ŀ��ܲ�����
    if (lpcData == NULL) return FB_INVAILD_POINTER;
    if (uiRsize != FB_UL_INF && 1UL * sizeof(UCHAR) * uiRsize > FBLIntToUl(liFileSize)) return FB_OUT_OF_RANGE;

    // �����ļ�����
    HANDLE hFile = CreateFileA(lpcFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) return FB_ERROR;

    // ��ȡ���ֽ���
    DWORD dwBytesRead;

    // ������ʼλ��
    if (SetFilePointer(hFile, uiRstart, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {
        CloseHandle(hFile);
        return FB_ERROR;
    }

    // ��ȡ�ļ����رվ��
    BOOL result = ReadFile(hFile, lpcData, FBMin <ULONG> (uiRsize, FBLIntToUl(liFileSize)), &dwBytesRead, NULL);
    CloseHandle(hFile);

    // �����ȡʧ��
    if (!result) return FB_ERROR;

    if (lpdwBytesRead != NULL) *lpdwBytesRead = dwBytesRead;
    return FB_SUCCESS;
}

// ���ֽ�д�ļ������̣�
DWORD FBWriteFile(const char* lpcFilePath, // �ļ�·��
    UCHAR* lpcData, // д�����ݶ�ָ��
    LPDWORD lpdwBytesWrite, // ����д���ֽ���ָ�� 
    LONG uiWstart, // д����ʼ��ַ
    DWORD uiWsize // д���ܴ�С
) {
    // �жϿ�ָ�벢����
    if (lpcData == NULL) return FB_INVAILD_POINTER;

    // �����ļ�����
    HANDLE hFile = CreateFileA(lpcFilePath, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) return FB_ERROR;

    // д����ֽ���
    DWORD dwBytesWrite;

    // ������ʼλ��
    if (SetFilePointer(hFile, uiWstart, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {
        CloseHandle(hFile);
        return FB_ERROR;
    }

    // д���ļ����رվ��
    BOOL result = WriteFile(hFile, lpcData, uiWsize, &dwBytesWrite, NULL);
    CloseHandle(hFile);

    // ����д��ʧ��
    if (!result) return FB_ERROR;

    if (lpdwBytesWrite != NULL) *lpdwBytesWrite = dwBytesWrite;
    return FB_SUCCESS;
}
