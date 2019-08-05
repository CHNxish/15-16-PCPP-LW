#ifndef _FATAL_ERROR_H_
#define _FATAL_ERROR_H_

#include <stdio.h>
#include <stdlib.h>
#define Error(str) FatalError(str)
#define FatalError(str) \
fprintf(stderr, "%s", str), exit(1);

#endif
