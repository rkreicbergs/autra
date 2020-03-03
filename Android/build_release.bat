call ant release
call jarsigner -verbose -sigalg SHA512withECDSA -digestalg SHA-512 -keystore keystore/stoney-ecdsa.keystore bin/Autra-release-unsigned.apk rudolfs_kreicbergs
call jarsigner -verify -verbose -certs bin/Autra-release-unsigned.apk
call zipalign -v 4 bin/Autra-release-unsigned.apk Autra.apk

call adb uninstall lv.autra.autra2
call adb install -r Autra.apk
call adb shell am start -n lv.autra.autra2/.activity.Loader
