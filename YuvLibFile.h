#ifndef __YUV_LIB_FILE_H__
#define __YUV_LIB_FILE_H__

#include "YuvLibLog.h"

#define FILE_NAME_SIZE  256

int YUV_ReadFromFile(const char *pFileName,
                     char* pData,
                     int needCount);

int YUV_WriteToFile(const char *pFileName,
                    char* pData, 
                    int needCount);

int YUV_CreateFileName(char* pFileName,
                       const char* prefix,
                       const char* suffix,
                       const int   width,
                       const int   height);

int YUV_CreateFileNameFrame(char* pFileName,
                       const char* prefix,
                       const int   width,
                       const int   height);

#endif

