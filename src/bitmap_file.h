#pragma once
#ifndef BITMAP_FILE
#define BITMAP_FILE

#include <Windows.h>
#include <vector>
#include <string>

namespace Bitmap
{
    class File
    {
    public:
        BITMAPINFO bitmapInfo;
        BITMAPFILEHEADER bitmapFileHeader;
        std::vector<BYTE> bitmapData;

        File();
        File(std::string filename);
        ~File();
        bool Save();
        bool SaveAs(std::string filename);
        void Rename(std::string filename);
        bool Open(std::string filename);
        bool IsValid();
        std::string Filename();

    private:
        std::string bitmapFilename;
        bool isValid = false;
    };
}

#endif