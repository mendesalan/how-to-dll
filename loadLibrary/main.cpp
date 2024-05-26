#include<iostream>
#include<windows.h>

using namespace std;

 /* Function pointers */
typedef VOID (__stdcall *_Somef) (LPSTR);
typedef int (*Addition)(int,int);
typedef int (*Subtraction)(int,int);
typedef void(*holla)();

int main(int argc, char *argv[])
{
    HINSTANCE hInstLibrary = LoadLibrary("myDLL.dll"); //Load our dll in the process

    if(!hInstLibrary) /* OR if(!hInstLibrary == NULL) if not success to load, it diplays the error msg. */
    {
        cout << "couldnt load the myDLL.dll" << endl;
    }
    else
        cout << "myDLL.dll successfully loaded. " << endl;

   _Somef _SomeFunction = (_Somef)GetProcAddress(hInstLibrary, "SomeFunction");
   Addition _add = (Addition)GetProcAddress(hInstLibrary, "Add" );
   Subtraction _sub = (Subtraction)GetProcAddress(hInstLibrary, "Sub");
   holla _hello = (holla)GetProcAddress(hInstLibrary, "hello");

    if(!_SomeFunction || !_add || !_sub || !_hello)
    {
        cout << "Couldn't find the DLL functions." << endl;
    }
    else
    {
        cout << "DLL functions successfully found" << endl;

        cout << "Addition: " << _add(2, 2) << endl;

        cout << "Subtraction: " << _sub(4, 2) << endl;

        _hello();

        _SomeFunction((LPSTR)"Hello from DLL!");

        system("PAUSE");
    }

    FreeLibrary(hInstLibrary); //unload the DLL.
    return(0);
}
