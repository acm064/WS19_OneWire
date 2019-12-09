/**
  ******************************************************************************
  * @file    	Output.h 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task			WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	
	
	#include "stdint.h"
	
	
	
	#ifndef Output
	#define Output
	
	
	
	void writeTemperature(int32_t);
	
	
	void writeRomCode(uint64_t *romCode);
	
	
	
	
	#endif
	
	
	