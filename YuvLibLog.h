#ifndef __YUV_LIB_LOG_H__
#define __YUV_LIB_LOG_H__

#include<stdio.h>
#include<stdlib.h>

#if defined(_WINDOWS) || defined(WIN32)
#define __FUNC__    __FUNCTION__
#define FT_TS_LOG_FILE_NAME               "D:\\yuv2jpeg.log"
#else
#define __FUNC__    __func__
#define FT_TS_LOG_FILE_NAME               "/tmp/yuv2jpeg.log"
#endif

#define LOG_COMMAND(FMT, ...)   {char log_text[4096] = {0}; \
                                sprintf(log_text, "%s-%d:" FMT "\n", __FUNC__, __LINE__, ##__VA_ARGS__); \
                                printf("%s", log_text); }


#define LOG_FORMAT(FMT, ...)    LOG_COMMAND(FMT, ##__VA_ARGS__)
#define LOG_TEXT(text)          LOG_COMMAND("%s", text)
#define LOG_FLOAT(value)        LOG_COMMAND("%f", value)
#define LOG_INT(value)          LOG_COMMAND("%d", value)
#define LOG_HERE()              LOG_COMMAND("");


#define LOG_TO_FILE(FMT, ...)   {LOG_TEXT_ONLY(FMT, ##__VA_ARGS__) \
                                {FILE* log_fp = fopen(FT_TS_LOG_FILE_NAME, "a+"); \
				 fwrite(log_text, 1, strlen(log_text), log_fp); fclose(log_fp);}}

#define DEBUG_FORMAT(FMT, ...)  LOG_TO_FILE(FMT, ##__VA_ARGS__)
#define DEBUG_TEXT(text)        LOG_TO_FILE("%s", text)
#define DEBUG_FLOAT(value)      LOG_TO_FILE("%f", value)
#define DEBUG_INT(value)        LOG_TO_FILE("%d", value)
#define DEBUG_HERE()            LOG_TO_FILE("");

#define FILE_FORMAT             DEBUG_FORMAT
#define FILE_TEXT               DEBUG_TEXT
#define FILE_FLOAT              DEBUG_FLOAT
#define FILE_INT                DEBUG_INT
#define FILE_HERE               DEBUG_HERE

#endif

