// Copyright Microsoft. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and / or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

// winrtwrap.h: This header file contains functions that wrap Node.dll so that it can be consumed from store applications.
// If Node.h is referenced directly from a store app, there will be compiler errors because WINAPI_FAMILY in store apps is
// set to WINAPI_FAMILY_APP but a number of required definitions are within WINAPI_PARTITION_DESKTOP. e.g. Lots of this -
// "#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)…#endif". While API's defined are within WINAPI_PARTITION_DESKTOP,
// the "legacy" API's left over are still supported on OneCore but in API sets (not old school kernel32.dll, etc.).

#pragma once

namespace WinRTWrap
{
	// Summary:
	// This function calls in to the Start function with the same signature in Node.dll
	// Parameters:
	// argc: Number of arguments passed to application
	// argv: Char array of arguments passed to application
	int Start(int argc, char *argv[]);
}