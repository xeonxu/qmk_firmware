#ifndef CONFIG_SHELA_H
#define CONFIG_SHELA_H

#include "../../config.h"

#undef TAPPING_TERM
#define TAPPING_TERM 230

#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 2000

/* bootmagic salt key */
#define BOOTMAGIC_KEY_SALT              KC_Z

#undef VENDOR_ID
#undef PRODUCT_ID
#undef DEVICE_VER
#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xCAFE
#define DEVICE_VER      0x0104
#define MANUFACTURER    q.m.k
#define PRODUCT         Noe HHKB mod
#define DESCRIPTION     Noe q.m.k keyboard firmware for HHKB

#endif
