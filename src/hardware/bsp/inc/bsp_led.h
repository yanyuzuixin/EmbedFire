#ifndef BSP_LED_H
#define BSP_LED_H

#include <stdint.h>

int32_t BSP_LedIint(void);
int32_t BSP_LedOn(uint16_t ledId);
int32_t BSP_LedOff(uint16_t ledId);

#endif /* BSP_LED_H */
