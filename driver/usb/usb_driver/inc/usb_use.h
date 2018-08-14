
#ifndef	__USB32_H
#define __USB32_H

//#include "sys.h"
//#include "delay.h"

#include "sys.h"
#include "delay.h"

#include "string.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"

void usb_use_init(void);
void usb_print(char *p);
void usb_use_dis(void);
void usb_port_set(u8 enable);
//void usb_print_yoko(char *q);

#endif 


