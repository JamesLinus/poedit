/*
 *  This file is part of Poedit (http://www.poedit.net)
 *
 *  Copyright (C) 2007 Vaclav Slavik
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE. 
 *
 *  $Id$
 *
 *  Simple interface for accessing NSUserDefaults
 *
 */

#ifndef _OSX_USERDEFAULTS_H_
#define _OSX_USERDEFAULTS_H_

// FIXME: This is a hack to work around Automake's lack of support for ObjC++.
//        Remove it after switching build system to Bakefile.
#ifdef __cplusplus
extern "C" {
#endif
void UserDefaults_SetBoolValue(const char *key, int value);
int UserDefaults_GetBoolValue(const char *key);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/**
    This class implements setting and reading of config values in NSUserDefaults
    storage (aka plist files in ~/Library/Preferences).
 */
class UserDefaults
{
public:
    static void SetBoolValue(const char *key, bool value)
        { UserDefaults_SetBoolValue(key, (int)value); }
    static bool GetBoolValue(const char *key)
        { return (bool)UserDefaults_GetBoolValue(key); }
};

#endif // __cplusplus

#endif
