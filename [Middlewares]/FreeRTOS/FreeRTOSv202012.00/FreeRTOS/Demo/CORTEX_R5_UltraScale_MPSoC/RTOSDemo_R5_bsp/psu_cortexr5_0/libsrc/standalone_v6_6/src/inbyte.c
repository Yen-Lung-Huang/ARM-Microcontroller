<<<<<<< HEAD
#include "xparameters.h"
#include "xuartps_hw.h"

#ifdef __cplusplus
extern "C" {
#endif
char inbyte(void);
#ifdef __cplusplus
}
#endif 

char inbyte(void) {
	 return XUartPs_RecvByte(STDIN_BASEADDRESS);
}
=======
#include "xparameters.h"
#include "xuartps_hw.h"

#ifdef __cplusplus
extern "C" {
#endif
char inbyte(void);
#ifdef __cplusplus
}
#endif 

char inbyte(void) {
	 return XUartPs_RecvByte(STDIN_BASEADDRESS);
}
>>>>>>> 16c66438 (Upload from PC.)
