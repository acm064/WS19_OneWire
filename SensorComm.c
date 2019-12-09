/**
  ******************************************************************************
  * @file    	SensorComm.c 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task			WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	The 'SensorComm' module provides the basic functions for communication via the 'one-wire bus'
	*						such as writing '1' or '0' as well as reading and writing bits and bytes.
  ******************************************************************************
  */
	
	
	
	#include "SensorComm.h"
	#include "general.h"
	#include "TI_memory_map.h"
	#include "timer.h"
	
	
	
/*
* @brief 	Write a '1'
*/
void writeOne()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PG0);
		
		//6us warten
		wait(6);
	
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PG0);
		
		//64us warten
		wait(64);
}



/*
* @brief	Write a '0'
*/
void writeZero()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PG0);
		
		//60us warten
		wait(60);
	
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PG0);
		
		//10us warten
		wait(10);
}



/*
* @brief	Read a Bit 
*/
uint8_t readBit()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PG0);
		
		//6us warten
		wait(6);
	
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PG0);
		
		//9us warten
		wait(9);
	
		//Bit vom Bus lesen
		//TODO
	
		//55us warten
		wait(55);
		
		return 0;
}



/*
* @brief	Read a Byte 
*/
uint8_t readByte()
{
		int readByte = 0;
	
		for(int i = 0 ; i < 8; i++)
		{
				readByte = readByte | readBit() << (i);
		}
		return readByte;
}



/*
* @brief	Write a Byte 
*/
void writeByte(char byte)
{
		int bit = 0;
	
		for(int i = 0; i < 8; i++)	
		{
				bit = byte >> i;
				bit &= 0x01;
        
        if(bit == 0)
				{
            writeZero();
        }
        else
				{
            writeOne();
        }
		}
}



/*
* @brief	Reset request
*/
void reset()
{
		//Bus auf "low" setzen
		GPIOG->BSRRH = (1<<PG0);
		
		//480us warten
		wait(480);
			
		//Bus freigeben (auf "high" setzen)
		GPIOG->BSRRL = (1<<PG0);
		
		//70us warten
		wait(70);
		
		//Buszustand abfragen
		int busZustand;
		busZustand = (GPIOG -> IDR & (0x01 << PG0));
	
		//410us warten
		wait(410);
}



/*
* @brief	Wait for a certain amount of microseconds using the method 'getTimeStamp' from timer 
* 				which counts the timer ticks. (84 MHz --> 84 000 000 ticks/second; 1 second --> 1000 000 microseconds) 
* @param	uSecs		Amount of microseconds to wait
*/
void wait(uint16_t uSecs)
{
		uint32_t firstTime = 0;
		uint32_t nextTime = 0;
		
		firstTime = getTimeStamp();
		
		//84 MHz --> 84 000 000 Ticks/Sekunde --> 84 Ticks/uSekunde
		while (((nextTime - firstTime)/84) < uSecs)
		{
				nextTime = getTimeStamp();
		}
		
	
}



