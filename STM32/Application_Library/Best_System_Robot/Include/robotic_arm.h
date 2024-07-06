/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ROBOTIC_ARM_H
#define ROBOTIC_ARM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "servo.h"
#include "sensor.h"
#include "timing_delays.h"

// Define an enum type to represent the state of the robotic arm
typedef enum {
    STATE_INIT,
    STATE_MOVE_TO_GRAB,
    STATE_GRAB_SHUTTLECOCK,
    STATE_MOVE_TO_SCAN,
    STATE_POSITION_FOR_SCANNING,
    STATE_REQUEST_FOR_SCANNING,
    STATE_WAIT_FOR_DEFECT_RESULT,
    STATE_PLACE_SHUTTLECOCK,
    STATE_KEEP_PLACEMENT,
    STATE_FINISH_PLACEMENT,
    STATE_SORT_SHUTTLECOCK,
    STATE_IDLE
} RoboticArmState_TypeDef;


// Declare the global objects with extern keyword
extern RoboticArmState_TypeDef roboticArmState;

extern bool defect_result_received;
extern bool defect_result;


/* FUNCTION (Prototype) DEFINITIONS */
void CheckButtonsAndStopMotors(void);
void UpdateRoboticArmState(void);


#ifdef __cplusplus
}
#endif

#endif /* ROBOTIC_ARM_H */

/*****END OF FILE*****/
