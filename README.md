# MKT-Redirect

Small C++14 project for redirecting/forwarding logic for Mario Kart Tour. This README covers prerequisites, build notes (native + Android), and where to customize paths and the target IP.


## I WILL NOT GIVE SUPPORT ON USAGE - Aswell as this, This should be used as a base (it's shit and not tested), not a final product - if you use it credit me please :)

## Overview

This repository builds a native C++14 binary that implements redirect/forward behavior. The project supports building for Windows (Visual Studio) and Android using the Android NDK + CMake.

## Key notes (important)

- You MUST have Android NDK and CMake installed to build the Android target.
- Update the paths in `build.bat` to match your local installations before running it.
- Edit `redirector.cpp` to set the target node IP: find the line that reads `node = "ip"` and replace `"ip"` with the desired IP address (for example `"192.0.2.10"`).

## Prerequisites

- Windows 10/11 (for Visual Studio builds)
- Visual Studio 2022 (C++ development workload)
- C++14 toolset
- CMake (3.16+ recommended)
- Android NDK (r21+ recommended) if building Android target

## Build (Windows - Visual Studio)

1. Open the solution or project folder in Visual Studio 2022.  
2. Select configuration (Debug/Release) and platform (x86/x64).  
3. Build via __Build > Build Solution__.

## Build (Android - CMake + NDK)

1. Install Android NDK and CMake.  
2. Set `ANDROID_NDK_HOME` (or `NDK_ROOT`) environment variable to your NDK install path.  
3. Run `build.bat` or invoke CMake manually.
4. Open `redirector.cpp` and find the line that sets the server IP. It looks like: **node = "127.0.0.1";**
5. Then rebuild the project.

## Usage

After building, put the .so file in the lib/arm-??a folder and use Uber APK Signer and APKTool to build it into an APK - I will not give support on this

