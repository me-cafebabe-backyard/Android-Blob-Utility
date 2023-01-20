/*
 * Android blob utility
 *
 * Copyright (C) 2014 JackpotClavin <jonclavin@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.
 */

#ifndef _ANDROID_BLOB_UTILITY_H_
#define _ANDROID_BLOB_UTILITY_H_

#define _GNU_SOURCE
#include <stdlib.h>

#define MAX_LIB_NAME 100
#define ALL_LIBS_SIZE 102400 /* 20KB */

#define EXCLUCE_FILE_LIST_FILE "exclude-files.txt"
#define EXCLUCE_PATH_LIST_FILE "exclude-paths.txt"

// Type of libs to search for
#define LIB32
#define LIB64
//#define ADSP
//#define QTI_CAMX

const char *blob_directories[] = {
    "/bin/",
#ifndef NON_TREBLE
    "/bin/hw/",
#endif

#ifdef LIB32
    "/lib/",
    "/lib/hw/",
    "/lib/vndk/",
    "/lib/egl/",
    "/lib/soundfx/",
#endif // LIB32

#ifdef LIB64
    "/lib64/",
    "/lib64/hw/",
    "/lib64/vndk/",
    "/lib64/egl/",
    "/lib64/soundfx/",
#endif // LIB64

#ifdef ADSP
#ifdef NON_TREBLE
    "/vendor/lib/rfsa/adsp/",
#else
    "/lib/rfsa/adsp/",
    "/lib64/rfsa/adsp/",
#endif // NON_TREBLE
#endif // ADSP

#ifdef QTI_CAMX
#ifdef LIB32
    "/lib/camera/",
    "/lib/camera/components/",
#endif // LIB32
#ifdef LIB64
    "/lib64/camera/",
    "/lib64/camera/components/",
#endif // LIB64
#endif // QTI_CAMX

#ifdef NON_TREBLE
    "/vendor/bin/",
#ifdef LIB32
    "/vendor/lib/",
    "/vendor/lib/egl/",
    "/vendor/lib/hw/",
    "/vendor/lib/soundfx/",
#endif // LIB32
#ifdef LIB64
    "/vendor/lib64/",
    "/vendor/lib64/egl/",
    "/vendor/lib64/hw/",
    "/vendor/lib64/soundfx/",
#endif // LIB64
#endif
    NULL
};

#define IGNORE_SPECIFIC_WILDCARDS
#ifdef IGNORE_SPECIFIC_WILDCARDS
const char *ignore_wildcards_beginning[] = {
    "libactuator_",
    "libchromatix_",
    "libmmcamera_",
    NULL
};
const char *ignore_wildcards_end[] = {
    "libactuator_%s.so",
    "libchromatix_%s.so",
    "libmmcamera_%s.so",
    "libmmcamera_%s_eeprom.so",
    "_eeprom.so",
    ".%s.so",
    NULL
};
#endif

const char *lib_beginning = "lib";
const char *egl_beginning = "egl";

const char *lib_ending = ".so";

#endif /* _ANDROID_BLOB_UTILITY_H_ */
