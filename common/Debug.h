#ifndef COMMON_DEBUG_H
#define COMMON_DEBUG_H

#include <stdio.h>
#include <errno.h>
#include "CommonDefinitions.h"


#ifdef NDEBUG
#define LOGD(M, ...)
#else
#define LOGD(M, ...) fprintf(stderr, "[DEBUG] %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define CLEAN_ERRNO() (errno == 0 ? "None" : strerror(errno))
#define LOGE(M, ...) fprintf(stderr, COLOR_RED "[ERROR] (%s:%d: errno: %s) " M "\n" \
                        COLOR_RESET , __FILE__, __LINE__, CLEAN_ERRNO(), ##__VA_ARGS__)
#define LOGW(M, ...) fprintf(stderr, COLOR_YELLOW "[WARN] (%s:%d: errno: %s) " M "\n" \
                        COLOR_RESET , __FILE__, __LINE__, CLEAN_ERRNO(), ##__VA_ARGS__)
#define LOGI(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n" \
                        , __FILE__, __LINE__, ##__VA_ARGS__)

#endif // COMMON_DEBUG_H