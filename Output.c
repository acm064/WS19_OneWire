/**
  ******************************************************************************
  * @file    	Output.c 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task			WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	
	#include "Output.h"
	#include "tft.h"
	
	
	
	void writeTemperature(int32_t temperature)
	{
			TFT_gotoxy(0, 0);
			//TFT_puts("%d /n", temperature);
	}
	
	
	void writeRomCode(uint64_t *romCode)
	{
			TFT_gotoxy(0, 2);
	}