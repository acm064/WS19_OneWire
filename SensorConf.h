/**
  ******************************************************************************
  * @file    	SensorConf.h 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task		WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */



#include "stdint.h"



#ifndef SensorConf
#define SensorConf



uint8_t searchSensor(void);


uint8_t checkCRC(uint64_t * romNumber);


uint8_t createSensorListElement(void);


uint8_t pullFamilyCode(void);




#endif









