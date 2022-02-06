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

/* #define DEBUG */

#define PARTITION_DUMP_ROOT "/mnt/android/partition_dump"

#define PARTITION "vendor"

#define EXCLUCE_LIST_FILE "exclude.txt"

const char *blob_directories[] = {
    "/lib64/egl/",
    "/lib/egl/",
    "/lib64/hw/",
    "/lib/hw/",
    "/lib64/",
    "/lib/",
    "/bin/",
    "/bin/hw/",
    "/lib/camera/",
    "/lib64/camera/",
    "/lib64/camera/components/",
    "/lib/vndk/",
    "/lib64/vndk/",
    NULL
};

const char *lib_beginning = "lib";
const char *egl_beginning = "egl";

const char *lib_ending = ".so";

#endif /* _ANDROID_BLOB_UTILITY_H_ */
