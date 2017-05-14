#Android Blob Utility
=============================
by JackpotClavin

####About
=============================

The Android Blob Utility is a program designed to make developing AOSP-based
ROMs easier. What it does is it allows the developer to pick
proprietary files, type in the files' absolute paths, and this program will spit
back every library that is needed in order to get that library or daemon
to run on an AOSP ROM.

####How does it work?
=============================

First, the developer must dump their entire stock ROM's
software to their computer, so that typing the command:
`$ ls /path-to-build.prop/build.prop` will yield their device's build.prop. This is just meant to ensure that you have the
correct path. This dupm can be can be obtained by doing `adb pull /system /path-to-destination/` with the device connected to
the computer, replacing `/path-to-destination/` to wherever you want to store the dump.  
Next, you are to compile this program with the `make` command. Once you run it,
the program will prompt you to enter whatever the SDK version of your /system
dump happens to be (check your /system/build.prop); for instance if your
/system dump is Android 4.3, type in `18` (use the following site for
[guidelines](https://developer.android.com/guide/topics/manifest/uses-sdk-element.html#ApiLevels)).  
Third, the program will ask you for the location of your /system dump; so if
the build.prop file is under `/home/android/dump/build.prop`, you can just type
`/home/android/dump` and press enter. The program will prompt you for the
manufacturer and device name. In the case of my Verizon LG G2, when
prompted for the manufacturer(vendor) and device name, I typed in `lge`, and
`vs980`, respectively.  
For the fourth step, getting the necessary blobs,
this program will prompt you to enter the amount of blob files you want this
program to process. If you want to only process one blob, type `1` and hit
enter. After you enter the amount of blobs you want this program to process, you
type the absolute path to the actual blob (see the [example program usage](https://github.com/JackpotClavin/Android-Blob-Utility/blob/master/Example_Usage.txt)),
and this program will print out all of the proprietary blobs that are mentioned
in that particular blob, that aren't in the emulator's /system
dump. This means that those files are either have to be built from source, or
are proprietary and must be copied into the ROM's build. This program will also
format the blobs so that it is ready to be placed into a vendor-blobs.mk file
in your vendor folder in the root of the ROM's source tree.

####Features
==============================

What makes this program great is that it doesn't just get the shared libraries
necessary to appease the linker, but it goes another step, also catching the
blobs that may slip past the linker because they are only called in the actual code
of the blob. Simply copying the shared libraries just appeases the linker, but
the blob still may not run properly as the blob may want additional libraries.

This program also searches recursively, so each and every blob that is found is
also processed through the algorithm, to see which blobs *that*
library also needs to run, so we cover all of the bases in order to get a
proprietary library or daemon to run.

The following example was copied from LG G2. Running this program with the two
main proprietary files related to the camera `/system/bin/mm-qcamera-daemon` and
`/system/lib/hw/camera.msm8974.so`, this program nicely printed out *every*
proprietary file needed to get the camera working, and formatted it so that anyone
can easily copy the program's output to a vendor-blobs.mk file, instead of
having to continuously push files until the linker is satisfied, or having to find
libraries that aren't shared libraries, but are called in the actual code (of
the proprietary file).  
Example program usage can be found in the [Example_Usage.txt](https://github.com/JackpotClavin/Android-Blob-Utility/blob/master/Example_Usage.txt)
in this folder.

# How to add an API

1. Get the Android system image for Android emulator, from the Android Studio SDK manager or with the direct link (example for the SDK 26 : https://dl.google.com/android/repository/sys-img/google_apis/x86-26_r09.zip )

2. Unizip it and go inside the folder
```
unzip x86-26_r09.zip
cd x86
```

3. You need to calculate the offset of the *system.img* : **(sector size)** x **(partition start)**. You can use fidsk to get this informations :

```
fdisk -l system.img

Disk system.img: 2.5 GiB, 2686451712 bytes, 5246976 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: 7983C953-C727-45A6-8D7F-FF1686F68709
Device      Start     End Sectors  Size Type
system.img1  2048 5244927 5242880  2.5G Linux filesystem

## Now calculate offset :
512 x 2048 = 1048576
```

4. Create a directory to mount the system image and mount it with options *loop* and *offset*

```
mkdir android_system_mount
mount -o loop,offset=1048576 system.img android_system_mount
```

5. Now you can get the list of all files inside the system image

```
### Go to the system mount directory
cd android_system_mount

### List the files and save the liste to a text file. Change the path to the emulator_systems directory inside Android Blob utility
find . -type d \( -path ./.git -o -path ./log -o -path ./public -o -path ./tmp \) -prune -o ! -type d -print > /path/where/is/android_blob_utility/emulator_systems/sdk_26.txt

### Same command but with multiline
find . -type d \( \
    -path ./.git -o \
    -path ./log -o \
    -path ./public -o \
    -path ./tmp \ 
    \) -prune -o ! -type d -print > /path/where/is/android_blob_utility/emulator_systems/sdk_26.txt
```

# Todo
- precise to remove some files at the end of *How to add an API*, I think there is only /system/* files list.
- Find a better command for listing all file inside system partition.

# Contributor

Thank a lot to :
- @JackpotClavin : https://github.com/JackpotClavin/Android-Blob-Utility
- @munchycool : https://github.com/munchycool/Android-Blob-Utility
- @imasaru : https://github.com/imasaru/Android-Blob-Utility
- @coc0a : https://github.com/coc0a/Android-Blob-Utility/commit/3be1c04f7edaf39a829f569479151ef70edc5f64