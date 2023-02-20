
#include "YuvLibFile.h"

int YUV_ReadFromFile(const char *pFileName,
                     char* pData,
                     int needCount)
{
    FILE * pFile = fopen(pFileName, "rb");
    if (pFile == NULL)
    {
        LOG_FORMAT("fopen(%s) ERROR!", pFileName);
        return -1;
    }

    while (needCount > 0)
    {
        int result = fread(pData, 1, needCount, pFile);
        if (result <= 0)
        {
            break;
        }
        needCount -= result;
        pData     += result;
    }

    fclose(pFile);
    return 0;
}

int YUV_WriteToFile(const char *pFileName,
                    char* pData,
                    int needCount)
{
    FILE * pFile = fopen(pFileName, "wb");
    if (pFile == NULL)
    {
        LOG_FORMAT("fopen(%s) ERROR!", pFileName);
        return -1;
    }

    while (needCount > 0)
    {
        int result = fwrite(pData, 1, needCount, pFile);
        if (result <= 0)
        {
            break;
        }
        needCount -= result;
        pData     += result;
    }

    fclose(pFile);
    return 0;
}

int YUV_CreateFileName(char* pFileName,
                       const char* prefix,
                       const char* suffix,
                       const int width,
                       const int height)
{
    sprintf(pFileName, "%s-%dx%d.%s", prefix, width, height, suffix);
}

int YUV_CreateFileNameFrame(char* pFileName,
                            const char* prefix,
                            const int width,
                            const int height)
{
    YUV_CreateFileName(pFileName, prefix, "frame", width, height);
}

