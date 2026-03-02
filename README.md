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


