/*
 * Copyright (C) 2014  Xiao-Long Chen <chenxiaolong@cxl.epac.to>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <jni.h>
#include "libmountpoint.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobjectArray JNICALL Java_com_github_chenxiaolong_dualbootpatcher_freespace_FreeSpaceFragment_getMountPoints(
        JNIEnv *env, jclass clazz) {
    std::vector<std::string> mountpoints = get_mount_points();

    jobjectArray ret = (jobjectArray) env->NewObjectArray(mountpoints.size(),
            env->FindClass("java/lang/String"), NULL);

    for (unsigned int i = 0; i < mountpoints.size(); i++) {
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(mountpoints[i].c_str()));
    }

    return ret;
}

#ifdef __cplusplus
}
#endif