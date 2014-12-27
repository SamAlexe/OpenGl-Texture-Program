#ifndef __BITMAP_H__
#define __BITMAP_H__


struct BitMapFile
{
   int width;
   int height;
   unsigned char *data;
};

class BitMap
{
    public:
    BitMapFile *getBMPData(string filename);
    
};

#endif 
