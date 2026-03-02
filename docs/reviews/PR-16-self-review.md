# PR 9 - Add CLI Build Instructions to Documentation

## Steps Taken:

- Completed #11 - Add instructions for prerequisites
- Merged #11 into this (#9) to continue the README updates
- Added instructions for Ninja build tool
- [Attempted CLI build using CMake & Ninja](#cmake-with-ninja)
- [Attempted CLI build using CMake](#cmake-without-ninja)

### CMake with Ninja

Running CMake without the dozens of linked paths provided by Qt has been
unsuccessful, so far.
```
PS C:\Users\vboxuser\Documents\GitHub\PANDA> cmake -G "Ninja" `
>> -DCMAKE_C_COMPOLER="E:\Qt\Tools\mingw1310_64\bin\x86_64-w64-mingw32-gcc.exe" `
>> -DCMAKE_CXX_COMPILER="E:\Qt\Tools\mingw1310_64\bin\x86_64-w64-mingw32-g++.exe" `
>> -DCMAKE_PREFIX_PATH="E:\Qt\6.8.3\mingw_64" `
>> -S . -B .\build
-- The CXX compiler identification is unknown
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - failed
-- Check for working CXX compiler: E:/Qt/Tools/mingw1310_64/bin/x86_64-w64-mingw32-g++.exe
-- Check for working CXX compiler: E:/Qt/Tools/mingw1310_64/bin/x86_64-w64-mingw32-g++.exe - broken
CMake Error at C:/Program Files/CMake/share/cmake-4.3/Modules/CMakeTestCXXCompiler.cmake:73 (message):
  The C++ compiler

    "E:/Qt/Tools/mingw1310_64/bin/x86_64-w64-mingw32-g++.exe"

  is not able to compile a simple test program.

  It fails with the following output:

    Change Dir: 'C:/Users/vboxuser/Documents/GitHub/PANDA/build/CMakeFiles/CMakeScratch/TryCompile-0zdlhb'

    Run Build Command(s): C:/PROGRA~1/CMake/bin/ninja.exe -v cmTC_4139d
    [1/2] E:\Qt\Tools\mingw1310_64\bin\x86_64-w64-mingw32-g++.exe    -o CMakeFiles\cmTC_4139d.dir\testCXXCompiler.cxx.obj -c C:\Users\vboxuser\Documents\GitHub\PANDA\build\CMakeFiles\CMakeScratch\TryCompile-0zdlhb\testCXXCompiler.cxx
    FAILED: [code=1] CMakeFiles/cmTC_4139d.dir/testCXXCompiler.cxx.obj
    E:\Qt\Tools\mingw1310_64\bin\x86_64-w64-mingw32-g++.exe    -o CMakeFiles\cmTC_4139d.dir\testCXXCompiler.cxx.obj -c C:\Users\vboxuser\Documents\GitHub\PANDA\build\CMakeFiles\CMakeScratch\TryCompile-0zdlhb\testCXXCompiler.cxx
    ninja: build stopped: subcommand failed.





  CMake will not be able to correctly generate this project.
Call Stack (most recent call first):
  CMakeLists.txt:3 (project)


-- Configuring incomplete, errors occurred!
PS C:\Users\vboxuser\Documents\GitHub\PANDA> cmake -G "Ninja" `
>> -DCMAKE_C_COMPOLER="E:\Qt\Tools\mingw1310_64\bin\gcc.exe" `
>> -DCMAKE_CXX_COMPILER="E:\Qt\Tools\mingw1310_64\bin\g++.exe" `
>> -DCMAKE_PREFIX_PATH="E:\Qt\6.8.3\mingw_64" `
>> -S . -B .\build
```

### CMake without Ninja

It looks like there's something wrong with the provided g++, but I know
that g++ is fine since the project compiles perfectly well using it with
QtCreator...

```
PS C:\Users\vboxuser\Documents\GitHub\PANDA> cmake `
>> -DCMAKE_C_COMPOLER="E:\Qt\Tools\mingw1310_64\bin\gcc.exe" `
>> -DCMAKE_CXX_COMPILER="E:\Qt\Tools\mingw1310_64\bin\g++.exe" `
>> -DCMAKE_PREFIX_PATH="E:\Qt\6.8.3\mingw_64" `
>> -S . -B .\build
-- The CXX compiler identification is unknown
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - failed
-- Check for working CXX compiler: E:/Qt/Tools/mingw1310_64/bin/g++.exe
-- Check for working CXX compiler: E:/Qt/Tools/mingw1310_64/bin/g++.exe - broken
CMake Error at C:/Program Files/CMake/share/cmake-4.3/Modules/CMakeTestCXXCompiler.cmake:73 (message):
  The C++ compiler

    "E:/Qt/Tools/mingw1310_64/bin/g++.exe"

  is not able to compile a simple test program.

  It fails with the following output:

    Change Dir: 'C:/Users/vboxuser/Documents/GitHub/PANDA/build/CMakeFiles/CMakeScratch/TryCompile-iaau03'

    Run Build Command(s): C:/PROGRA~1/CMake/bin/ninja.exe -v cmTC_a3721
    [1/2] E:\Qt\Tools\mingw1310_64\bin\g++.exe    -o CMakeFiles\cmTC_a3721.dir\testCXXCompiler.cxx.obj -c C:\Users\vboxuser\Documents\GitHub\PANDA\build\CMakeFiles\CMakeScratch\TryCompile-iaau03\testCXXCompiler.cxx
    FAILED: [code=1] CMakeFiles/cmTC_a3721.dir/testCXXCompiler.cxx.obj
    E:\Qt\Tools\mingw1310_64\bin\g++.exe    -o CMakeFiles\cmTC_a3721.dir\testCXXCompiler.cxx.obj -c C:\Users\vboxuser\Documents\GitHub\PANDA\build\CMakeFiles\CMakeScratch\TryCompile-iaau03\testCXXCompiler.cxx
    ninja: build stopped: subcommand failed.





  CMake will not be able to correctly generate this project.
Call Stack (most recent call first):
  CMakeLists.txt:3 (project)


-- Configuring incomplete, errors occurred!
```

