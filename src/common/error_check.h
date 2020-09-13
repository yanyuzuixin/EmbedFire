/**
 * @file error_check.h
 * @author hjr (yanyuzuixin@163.com)
 * @brief 提供port层错误判断接口
 * @version 0.1
 * @date 2020-09-12
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#ifndef ERROR_CHECK_H
#define ERROR_CHECK_H

typedef enum {
    ERR_CODE_NONE = 0,
    ERR_CODE_INVALID_PARAM = 1,
    ERR_CODE_INVALID_RESULT = 2,
} ErrCode;

#define CHECK_FALSE_VOID(expr) \
    do {                        \
        if (!(expr)) {          \
            return;             \
        }                       \
    } while (0);

#define CHECK_FALSE_RET(expr, ret) \
    do {                        \
        if (!(expr)) {          \
            return ret;             \
        }                       \
    } while (0);

#endif
