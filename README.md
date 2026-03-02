# PANDA Loader - Zoo Tycoon Mod Loader

PANDA Loader is a mod loader designed to enhance your experience with Zoo Tycoon 
by making the management and loading of mods easy and efficient. 

PANDA = Project and Animal Loader.

## Planned Features

- [ ] Quickly enable, disable, and delete your Zoo Tycoon mods.
- [ ] Combine mods into bundles for optimized load-times.
- [ ] Separate mods from bundles into single files, remove parts of a mod you do not want.

## Prerequisites

- **Windows OS**
- [C++ Toolchain](#microsoft-c++-redistributables)
- [CMake](#cmake)
- [Qt Build Tools](#qt-build-tools)
- [QtCreator IDE](#qtcreator-ide) - *Optional, but strongly recommended*

### Microsoft C++ Redistributables

These are most easily installed by visiting 
[VisualStudio](https://visualstudio.microsoft.com/vs/community/), and downloading the 
community edition.

Once that is downloaded, you'll need to open it and install 
C++ Buildtools and .NET Desktop Buildtools, preferably including all the 
most recent SDKs, clang tools, and debug options for each.

### CMake

Download the binary Windows x64 installer for CMake [here](https://cmake.org/download/).

Alternatively, if you have chocolatey, you can run the following command in PowerShell to
install CMake:

```
choco install cmake
```

After installation, verify valid installation with the following command:

```
cmake --version
```

The output should look something like the following:

```
cmake version 4.3.0-rc1

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

### Qt Build Tools

This project uses C++ implementations from Qt 6.8.X for just about everything.

The Qt Online Installer can be found [here](https://download.qt.io/official_releases/online_installers/), 
or downloaded with:

```
curl -O https://download.qt.io/official_releases/online_installers/qt-online-installer-windows-x64-online.exe
```

Run the installer and select Qt 6.8.x (As close to 6.8.2) as you can get, I had to go with 6.8.3 which
has worked well.

### QtCreator IDE

While it is technically possible to build and run PANDA through CLI, the project has historically 
been developed with the QtCreator IDE's built-in project build / configuration / testing GUI
functionality.

This is because there are many different toolkits and packages being used, which QtCreator can 
automatically scan and set proper CMake flags for, rather than the user having to manually 
keep track of the path for every single referenced toolkit and library.

The QtCreator IDE can be downloaded from 
[this link](https://download.qt.io/official_releases/qtcreator/18.0/18.0.2/qt-creator-opensource-windows-x86_64-18.0.2.exe).

Once downloaded, complete the following steps:
1. Run the installation tool.
2. Create an account with Qt and sign in (free).
3. In the **customize** menu, select:
    - Qt Creator 18.0.2
    - CDB Debugger Support
    - Debugging Tools for Windows
4. Follow the remaining instructions provided by the GUI and complete the installation.

