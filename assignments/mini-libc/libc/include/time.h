
#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>

struct timespec
{
    uint64_t tv_sec;  // Seconds - >= 0
    long   tv_nsec; // Nanoseconds - [0, 999999999]
};
int nanosleep(const struct timespec *req, struct timespec *rem);
       
#ifdef __cplusplus
}
#endif

#endif
