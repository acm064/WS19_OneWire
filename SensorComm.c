/**
  ******************************************************************************
  * @file    	SensorComm.c 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task			WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	
	
	#include "SensorComm.h"
	#include "general.h"
	
	
	
void writeOne()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PIN);
		
		//6us warten
		//TODO: Timer
	
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PIN);
		
		//64us warten
		//TODO: Timer
}



void writeZero()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PIN);
		
		//60us warten
		//TODO: Timer
	
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PIN);
		
		//10us warten
		//TODO: Timer
}



uint8_t readBit()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PIN);
		
		//6us warten
		//TODO: Timer
	
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PIN);
		
		//9us warten
		//TODO: Timer
	
		//Bit vom Bus lesen
	
		//55us warten
		
		return 0;
}



uint8_t readByte()
{

}



void reset()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PIN);
		
		//480us warten
			
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PIN);
		
		//70us warten
		
		//Buszustand abfragen
	
		//410us warten
}



