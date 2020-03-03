@echo off

rem GOTO RUN_APK
rem GOTO DEPLOY_APK
GOTO BUILD_APK
rem GOTO BUILD_SO

echo --------------------------------------
echo   STEP 1: Build AutraLib.lib + tests
echo --------------------------------------

call "%VS120COMNTOOLS%\vsvars32.bat"
if %ERRORLEVEL% GEQ 1 EXIT /B 1

call msbuild /p:Configuration=Release /p:Platform=x64 AutraLib\Build\VS2013\AutraLib.sln /verbosity:m
if %ERRORLEVEL% GEQ 1 EXIT /B 1

echo --------------------------------------
echo   STEP 2: Run tests
echo --------------------------------------

cd AutraLib\Build\VS2013\x64\Release
AutraTests.exe
if %ERRORLEVEL% GEQ 1 EXIT /B 1
cd ..\..\..\..\..\

:BUILD_SO
echo --------------------------------------
echo   STEP 3: Build libAutra.so
echo --------------------------------------

cd Android\jni
call ndk-build
if %ERRORLEVEL% GEQ 1 EXIT /B 1
cd ..\..\

:BUILD_APK
echo --------------------------------------
echo   STEP 4: Build APK
echo --------------------------------------

cd Android
call ant clean
if %ERRORLEVEL% GEQ 1 EXIT /B 1
call android.bat update project -p . -t android-15
if %ERRORLEVEL% GEQ 1 EXIT /B 1
call ant debug
if %ERRORLEVEL% GEQ 1 EXIT /B 1
cd ..

:DEPLOY_APK
echo --------------------------------------
echo   STEP 5: Deploy APK
echo --------------------------------------

call adb uninstall lv.autra.autra2
call adb install -r Android/bin/Autra-debug.apk
if %ERRORLEVEL% GEQ 1 EXIT /B 1

:RUN_APK
echo --------------------------------------
echo   STEP 6: Run APK
echo --------------------------------------

adb shell am start -n lv.autra.autra2/.activity.Loader
if %ERRORLEVEL% GEQ 1 EXIT /B 1
