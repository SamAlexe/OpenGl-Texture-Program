#include "bitmap.h"

// Routine to read a bitmap file.
// Works only for uncompressed bmp files of 24-bit color.
BitMapFile *BitMap::getBMPData(string filename)
{
   BitMapFile *bmp = new BitMapFile;
   unsigned int size, offset, headerSize;
   // Read input file name.
   ifstream infile(filename.c_str(), ios::binary);
   // Get the starting point of the image data.
   infile.seekg(10);
   infile.read((char *) &offset, 4); 
   // Get the header size of the bitmap.
   infile.read((char *) &headerSize,4);
   // Get width and height values in the bitmap header.
   infile.seekg(18);
   infile.read( (char *) &bmp->width, 4);
   infile.read( (char *) &bmp->height, 4);
   // Allocate buffer for the image.
   size = bmp->width * bmp->width * 24;
   bmp->data = new unsigned char[size];
   // Read bitmap data.
   infile.seekg(offset);
   infile.read((char *) bmp->data , size);
   // Reverse color from bgr to rgb.
   int temp;
   for (int i = 0; i < size; i += 3)
   { 
      temp = bmp->data[i];
      bmp->data[i] = bmp->data[i+2];
      bmp->data[i+2] = temp;
   }
   return bmp;
}
