//TransparencyWindowLibrary for Windows dll
#pragma once
#include <string>

class TransparencyWindowLibraryWindows
{
public:
    void createWindow(std::string windowName, bool transparent, bool clickthrough);
    void drawImage(std::string image, int x, int y);
    bool checkKeyPress(int key);
};

