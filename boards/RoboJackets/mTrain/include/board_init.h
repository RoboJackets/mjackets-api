#ifndef __BOARD_INIT_H
#define __BOARD_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include  <unistd.h>

/* #include "usbd_core.h" */
/* #include "usbd_desc.h" */
/* #include "usbd_cdc.h" */
/* #include "usbd_cdc_interface.h" */
/* #include "qspi.h" */

extern void bsp_config(void);

void BoardClockConfig(void);


#ifdef __cplusplus
}
#endif

#endif // __BOARD_INIT_H