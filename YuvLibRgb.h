#ifndef __YUV_LIB_RGB_H__
#define __YUV_LIB_RGB_TH__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void YUV_Rgb_CreateBuffer(char* pRgb,
                          const int width,
                          const int height,
                          const int pixel,
                          const int block);

int YUV_RgbToNv12(const unsigned char I[],
                  int step,
                  const int image_width, 
                  const int image_height,
                  unsigned char J[]);
              
int YUV_RgbToUyvy(unsigned char* pRGB,
                  unsigned char* pYUV,
                  int width,
                  int height);

int YUV_RgbaToUyvy(unsigned char* pRGB,
                   unsigned char* pYUV,
                   int width,
                   int height);

#endif

