call ant debug
call adb uninstall lv.autra.autra2
call adb install -r bin/Autra-debug.apk
call adb shell am start -n lv.autra.autra2/.activity.Loader
