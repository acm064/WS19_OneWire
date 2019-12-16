/**
  ******************************************************************************
  * @file    	SensorComm.h 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task		WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	
	
#include "stdint.h"
	
	
	
#ifndef _SensorComm_H
#define _SensorComm_H
	
	
	
void writeOne(void);


void writeZero(void);


uint8_t readBit(void);


uint8_t readByte(void);


void writeByte(char);


int reset(void);


void wait(uint32_t);
	
	
void setOpenDrainMode(void);


void setPushPullMode(void);

	
	
#endif
		
		
		
		
		
		
		
