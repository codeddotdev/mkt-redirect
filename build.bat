@echo off
REM Edit these two variables to match your environment - should look like this
set NDK_DIR=C:\Users\coded\Downloads\android-ndk-r27d-windows\android-ndk-r27d
set CMAKE_EXE=C:\Program Files\CMake\bin\cmake.exe

REM Configure and build for Android (adjust ANDROID_ABI/ANDROID_PLATFORM as needed)
"%CMAKE_EXE%" -S . -B build -DCMAKE_TOOLCHAIN_FILE="%NDK_DIR%\build\cmake\android.toolchain.cmake" -DCMAKE_MAKE_PROGRAM="%NDK_DIR%\prebuilt\windows-x86_64\bin\make.exe" -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-24 -G "MinGW Makefiles"
"%CMAKE_EXE%" --build build
