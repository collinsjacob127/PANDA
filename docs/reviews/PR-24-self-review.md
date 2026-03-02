## Steps Taken

- Make PTestModLoader a friend class of PModLoader to allow access to private members for testing
- Add target include directories to CMakeLists.txt
- Create stubbed PTestLauncher test group in `/tests`: `PTestLauncher.cpp`