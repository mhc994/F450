#include "stm32f4xx_hal.h"

#pragma pack(1)

struct AHRSDataStruct
{
	int8_t acceX;
	int8_t acceY;
	int8_t acceZ;
	int16_t gyroX;
	int16_t gyroY;
	int16_t gyroZ;
	int16_t yaw;
	int16_t pitch;
	int16_t roll;
	int16_t height;
	int16_t baro;
};

#pragma pack()

extern uint8_t USART2RxBuffer[128];
extern uint8_t USART3RxBuffer[128];
extern uint16_t rcChannels[18];
extern float PWMOutput[4];


extern __IO struct AHRSDataStruct AHRSData;
 
extern __IO float pitchAngleP,rollAngleP,yawAngleP;
extern __IO float pitchAngleI,rollAngleI,yawAngleI;
extern __IO float pitchAngleD,rollAngleD,yawAngleD;
extern __IO float pitchAngleSP,rollAngleSP,yawAngleSP;
extern __IO float pitchAngleErr,rollAngleErr,yawAngleErr;
extern __IO float pitchAngleLastErr,rollAngleLastErr,yawAngleLastErr;
extern __IO float pitchAngleErrInte,rollAngleErrInte,yawAngleErrInte;
extern __IO float pitchAngleAdjust,rollAngleAdjust,yawAngleAdjust;

extern __IO float throttle; 

extern __IO float pwm1,pwm2,pwm3,pwm4;

extern __IO int32_t sysClock; //timer6 0.1ms   max:1 000 000 000

extern __IO uint8_t AHRSReceived;
extern __IO uint8_t rcReceived;
extern __IO uint8_t shouldUpdateControl;

extern __IO int32_t lastUpdateControlTime;

#define constrain(num,min,max) num=(num<min?min:(num>max?max:num))


