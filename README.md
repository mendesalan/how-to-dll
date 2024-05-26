### how to dll is a simple setup showing how to write .dll and use them

how to compile myDLL: 
`g++ -shared -o myDLL.dll -DBUILD_DLL main.cpp`

Now with the myDLL.dll file put it in the loadLibrary or pass its absolute path.

*tip*: You can use the DLL export viwer program in order to see your dll exported functions.

how to compile the loadLibrary program:

`g++ -Wall main.cpp -o main`

Now all that you've to do is run the loadLibrary generated .exe
