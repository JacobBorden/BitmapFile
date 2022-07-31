#include "bitmap_file.h"

Bitmap::File::File()
{
}

Bitmap::File::File(std::string filename)
{
    Bitmap::File::Open(filename);
}

Bitmap::File::~File()
{
}

bool Bitmap::File::Save()
{
    bool savedSuccessfully = false;
    if (Bitmap::File::isValid)
    {
        DWORD bytesSaved;
        HANDLE fileHandle = CreateFileA((LPCSTR)&bitmapFilename[0], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        savedSuccessfully = WriteFile(fileHandle, (LPSTR)&bitmapFileHeader, sizeof(BITMAPFILEHEADER), &bytesSaved, NULL);
        if (savedSuccessfully)
            savedSuccessfully = WriteFile(fileHandle, (LPSTR)&bitmapInfo.bmiHeader, sizeof(BITMAPINFOHEADER), &bytesSaved, NULL);
        if (savedSuccessfully)
            savedSuccessfully = WriteFile(fileHandle, (LPSTR)&bitmapData[0], bitmapFileHeader.bfSize - bitmapFileHeader.bfOffBits, &bytesSaved, NULL);
        if (savedSuccessfully)
            savedSuccessfully = CloseHandle(fileHandle);
    }
    return savedSuccessfully;
}

bool Bitmap::File::SaveAs(std::string filename)
{
    bool savedSuccessfully = false;
    if (Bitmap::File::isValid)
    {
        Bitmap::File::bitmapFilename = filename;
        DWORD bytesSaved;
        HANDLE fileHandle = CreateFileA((LPCSTR)&bitmapFilename[0], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        savedSuccessfully = WriteFile(fileHandle, (LPSTR)&bitmapFileHeader, sizeof(BITMAPFILEHEADER), &bytesSaved, NULL);
        if (savedSuccessfully)
            savedSuccessfully = WriteFile(fileHandle, (LPSTR)&bitmapInfo.bmiHeader, sizeof(BITMAPINFOHEADER), &bytesSaved, NULL);
        if (savedSuccessfully)
            savedSuccessfully = WriteFile(fileHandle, (LPSTR)&bitmapData[0], bitmapFileHeader.bfSize - bitmapFileHeader.bfOffBits, &bytesSaved, NULL);
        if (savedSuccessfully)
            savedSuccessfully = CloseHandle(fileHandle);
    }
    return savedSuccessfully;
}

bool Bitmap::File::Open(std::string filename)
{
    bool openedSuccessfully = false;
    Bitmap::File::bitmapFilename = filename;
    DWORD bytesRead;
    HANDLE fileHandle = CreateFileA((LPCSTR)&bitmapFilename[0], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    openedSuccessfully = ReadFile(fileHandle, (LPSTR)&bitmapFileHeader, sizeof(BITMAPFILEHEADER), &bytesRead, NULL);
    if (openedSuccessfully)
        openedSuccessfully = ReadFile(fileHandle, (LPSTR)&bitmapInfo.bmiHeader, sizeof(BITMAPINFOHEADER), &bytesRead, NULL);
    if (openedSuccessfully)
        openedSuccessfully = ReadFile(fileHandle, (LPSTR)&bitmapData[0], bitmapFileHeader.bfSize - bitmapFileHeader.bfOffBits, &bytesRead, NULL);
    if (openedSuccessfully)
        openedSuccessfully = CloseHandle(fileHandle);
    if (openedSuccessfully)
        Bitmap::File::isValid = true;
    return openedSuccessfully;
}

void Bitmap::File::Rename(std::string filename)
{
    Bitmap::File::bitmapFilename = filename;
}

std::string Bitmap::File::Filename()
{
    return Bitmap::File::bitmapFilename;
}

bool Bitmap::File::IsValid()
{
    return Bitmap::File::isValid;
}