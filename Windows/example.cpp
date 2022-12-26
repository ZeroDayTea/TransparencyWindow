#include <iostream>
#include <string>

int main()
{
    std::cout << "This is an example program to showcase the functionality of the library under Windows" << std::endl;

	// load in the functions from the library dll
	HINSTANCE hGetProcIDDLL = LoadLibrary(TEXT("TransparencyWindowLibraryWindows.dll"));

    return 0;
}