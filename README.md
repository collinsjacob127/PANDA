# PANDA Loader - Zoo Tycoon Mod Loader

PANDA Loader is a mod loader designed to enhance your experience with Zoo Tycoon by making the management and loading of mods easy and efficient. 

PANDA = Project and Animal Loader.

## Planned Features

- Quickly enable, disable, and delete your Zoo Tycoon mods.
- Combine mods into bundles for optimized load-times.
- Separate mods from bundles into single files, remove parts of a mod you do not want.

## Prerequisites

- **Windows OS**
- [C++ Toolchain](#microsoft-c++-redistributables)
- [CMake](#cmake)
- [Qt Build Tools](#qt-build-tools)
- [QtCreator IDE](#qtcreator-ide) - *Optional, but strongly recommended*
- Copy of `Zoo Tycoon Complete Collection Disk 1.iso` - Installed
- Copy of `Zoo Tycoon Complete Collection Disk 2.iso` - Installed

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

## Build Instructions (CLI) - Defunct

**The CLI build instructions do not work, and are merely here as a reference in case anyone
would like to give it a shot.**

**Please look at the [IDE Build Instructions](#ide_build_instructions) for help 
building the project.**

This assumes that you have already downloaded and set up all prerequisites.

There is one additional prerequisite specifically for building the project:

### Ninja

Go to [Ninja Releases](https://github.com/ninja-build/ninja/releases) on GitHub,
and download the most recent version.

An easy way to get the extracted `ninja.exe` on your PATH is to simply copy it 
into CMake's `bin/` folder.


This will tell you where CMake is currently installed:

```
Get-Command cmake
```

This will extract `ninja-win.zip` (make sure you're in the same directory
as the compressed file):

```
C:\Users\vboxuser\Downloads> Expand-Archive -Path .\ninja-win.zip
```

Now, in an admin PowerShell instance, still in the parent directory of the 
zipped file and it's decompressed contents:

```
cp .\ninja-win\ninja.exe 'C:\Program Files\CMake\bin\'
ls 'C:\Program Files\CMake\bin\'
```

That should output the contents of `...\CMake\bin`, including `ninja.exe`.

If you now run the following command, you should see that ninja.exe has 
been successfully added to your path!

```
Get-Command ninja.exe
```

### Commands to Build PANDA on CLI

1. Traverse to project root:

```
cd C:\Users\<username>\Documents\GitHub\PANDA
```

2. Run the following command:

```
cmake -G "Ninja" `
-DCMAKE_C_COMPILER="<path_to_gcc.exe>" `
-DCMAKE_CXX_COMPILER="<path_to_g++.exe>" `
-DCMAKE_PREFIX_PATH="<path_to_mingw_64>" `
-S . -B ./build
```

## IDE Build Instructions

The Qt Development Framework has dozens of libraries & toolkits being linked as 
CMake arguments in a very delicate and dynamic manner. This makes working with 
Qt on a large scale project practically irrelevant.

Qt provides the QtCreator IDE to get arround the CLI issues, as the IDE can 
automate the build and test processes without hardly any issue.

To build the project with the QtCreator IDE, proceed with the following steps:

(This assumes you have installed the prerequisite toolkits and packages)

0. Clone the GitHub Repository

```
git clone git@github.com:collinsjacob127/PANDA.git
```

1. If you haven't already, be sure to link your previously installed Qt Toolkit (6.8.x)
to the QtCreator IDE.

A pop-up should appear in the bottom-right when you open the IDE, asking if you'd like to link.

2. Open the QtCreator IDE

    - In the *Welcome* page, select `Open Project...`
    - Navigate to the cloned repository, and select `CMakeLists.txt`
    - (In my case, this was `"C:\Users\vboxuser\Documents\GitHub\PANDA\CMakeLists.txt"`)
    - Press `Open`

3. Navigate to the `Projects` page.

4. If it asks you to select a toolkit, choose `Desktop Qt 6.8.X MinGW 64-bit`.

5. Back in Projects > Build Settings, change the Build type to `Release`

6. Click `Run CMake`, under the list of CMake arguments.

- The terminal on the right should display the build process, including any errors
that may (but shouldn't) occur.

7. To run *tests*, select `Tools > Tests > Run All Tests` from the top menu.

8. To run the PANDA program, now that you've configured the build settings properly,
you can simply click the `Play` (arrow) button in the bottom-left from the `Edit` page
at any time.

