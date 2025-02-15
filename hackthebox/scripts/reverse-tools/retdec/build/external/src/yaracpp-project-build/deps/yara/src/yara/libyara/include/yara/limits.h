/*
Copyright (c) 2013. The YARA Authors. All Rights Reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef YR_LIMITS_H
#define YR_LIMITS_H

#if defined(_WIN32) || defined(__CYGWIN__)
#include <windows.h>
#endif

#include "utils.h"

// MAX_THREADS is the number of threads that can use a YR_RULES
// object simultaneously.

#ifndef MAX_THREADS
#define MAX_THREADS 32
#endif


#ifndef MAX_PATH
#define MAX_PATH 1024
#endif

#define MAX_COMPILER_ERROR_EXTRA_INFO   256
#define MAX_ATOM_LENGTH                 4
#define MAX_LOOP_NESTING                4
#define MAX_ARENA_PAGES                 32
#define MAX_INCLUDE_DEPTH               16
#define MAX_STRING_MATCHES              1000000
#define MAX_FUNCTION_ARGS               128
#define MAX_FAST_RE_STACK               300
#define MAX_OVERLOADED_FUNCTIONS        10
#define MAX_HEX_STRING_TOKENS           10000
#define MAX_MATCH_DATA                  4096

#define LOOP_LOCAL_VARS                 4
#define STRING_CHAINING_THRESHOLD       200
#define LEX_BUF_SIZE                    65536


// Maximum allowed split ID, also limiting the number of split instructions
// allowed in a regular expression. This number can't be increased
// over 255 without changing RE_SPLIT_ID_TYPE.
#define RE_MAX_SPLIT_ID                 128

// Maximum stack size for regexp evaluation
#define RE_MAX_STACK                    1024

// Maximum code size for a compiled regexp
#define RE_MAX_CODE_SIZE                32768

// Maximum input size scanned by yr_re_exec
#define RE_SCAN_LIMIT                   4096

// Maximum number of fibers
#define RE_MAX_FIBERS                   1024

// Maximum number of levels in regexp's AST
#define RE_MAX_AST_LEVELS               9000

#endif
