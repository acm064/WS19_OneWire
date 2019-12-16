/**
  ******************************************************************************
  * @file    	SensorConf.c 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task		WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	
	
#include "SensorConf.h"
#include "SensorListe.h"
#include "SensorComm.h"
	
	
	
uint8_t searchSensor()
{
	return 0;
}


uint8_t checkCRC(uint64_t * romNumber)
{
	return 0;
}


uint8_t createSensorListElement()
{
	return 0;
}


uint8_t pullFamilyCode()
{
	return 0;
}
	
	
/*
The least significant 8 bits of the ROM code contain the DS18B20’s 1-Wire family code: 28h. 
The next 48 bits contain a unique serial number. 
The most significant 8 bits contain a cyclic redundancy check (CRC) byte that is calculated from the first 56 bits of the ROM code.
*/







