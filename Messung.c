/**
  ******************************************************************************
  * @file    	Messung.c 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task		WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	
	
#include "Messung.h"
#include "SensorListe.h"
#include "SensorComm.h"
#include "general.h"
#include "Output.h"
	
	
	
void getTemperature()
{
	//ggf von hier aus pull temperature aufrufen/jeweils romcode uebergeben und anschließend ergebnis printen
}
	
	
/*
* Choose a Slave on the wire and make it start a temperature measurement. Then read the result.
*/
void pullTemperature(uint64_t *romCode)
{	
	//---------- Choose Slave ----------//
	setOpenDrainMode();
	
	reset();
	
	//Send Match ROM command (0x55)
	writeByte(MATCH_ROM);
	
	//Write ROM code (8 Bytes)
	//TODO!!!
	
	
	//---------- Activate Sensor ----------//
	//Send Convert T command (0x44)
	writeByte(CONVERT_T);
	
	setPushPullMode();
	
	//Delay: 750 ms
	wait(750000);
	
	
	//---------- Choose Slave ----------//
	setOpenDrainMode();
	
	reset();
	
	//Send Match ROM command (0x55)
	writeByte(MATCH_ROM);
	
	//Send ROM code (8 Bytes)
	//TODO!!!
	
	
	//---------- Read Result ----------//
	//Send Read Scratchpad command (0xBE)
	writeByte(READ_SCRATCHPAD);
	
	//Read 9 Bytes (entire Scratchpad incl. Checksum)
	//TODO!!!
	
	//TODO: vllt --> output?
}



void pullTempOneSensorAttached()
{	
	//---------- Choose Slave ----------//
	setOpenDrainMode();
	
	reset();
	
	//Send Skip ROM command (0xCC)
	writeByte(SKIP_ROM);
	
	
	//---------- Activate Sensor ----------//
	//Send Convert T command (0x44)
	writeByte(CONVERT_T);
	
	setPushPullMode();
	
	//Delay: 750 ms
	wait(750000);
	
	
	//---------- Choose Slave ----------//
	setOpenDrainMode();
	
	reset();
	
	//Send Skip ROM command (0xCC)
	writeByte(SKIP_ROM);
	
	
	//---------- Read Result ----------//
	//Send Read Scratchpad command (0xBE)
	writeByte(READ_SCRATCHPAD);
	
	//Read 9 Bytes (entire Scratchpad incl. Checksum)
	//TODO!!!
	
	//TODO: vllt --> output?
}











