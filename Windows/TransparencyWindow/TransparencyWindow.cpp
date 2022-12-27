// TransparencyWindow.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

int windowHandle;


__declspec(dllexport) void createWindow(std::string windowName, bool transparent, bool clickthrough) {
	windowHandle = glfwInit();
	std::cout << windowHandle << std::endl;
}

__declspec(dllexport) void drawImage(std::string image, int x, int y) {

}

__declspec(dllexport) bool checkKeyPress(int key) {
	return false;
}
