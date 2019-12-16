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
#include "TI_Lib.h"
#include "timer.h"
	
	
	
/*
* @brief 	Write a '1'
*/
void writeOne()
{
		//Bus auf "low" setzen
		GPIOG -> BSRRH = (1 << PG0);
		
		//6us warten
		wait(6);
	
		//Bus freigeben (auf "high" setzen)
		GPIOG -> BSRRL = (1 << PG0);
		
		//64us warten
		wait(64);
}



/*
* @brief	Write a '0'
*/
void writeZero()
{
		//Bus auf "low" setzen
		GPIOG -> BSRRH = (1 << PG0);
		
		//60us warten
		wait(60);
	
		//Bus freigeben (auf "high" setzen)
		GPIOG -> BSRRL = (1 << PG0);
		
		//10us warten
		wait(10);
}



/*
* @brief	Read a Bit 
*/
uint8_t readBit()
{
		//Bus auf "low" setzen
		GPIOG -> BSRRH = (1 << PG0);
		
		//6us warten
		wait(6);
	
		//Bus freigeben (auf "high" setzen)
		GPIOG -> BSRRL = (1 << PG0);
		
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
int reset()
{
		//Bus auf "low" setzen
		GPIOG -> BSRRH = (1 << PG0);
		
		//480us warten
		wait(480);
			
		//Bus freigeben (auf "high" setzen)
		GPIOG -> BSRRL = (1 << PG0);
		
		//70us warten
		wait(70);
		
		//Buszustand abfragen
		int busZustand;
		busZustand = (GPIOG -> IDR & (1 << PG0));
	
		//410us warten
		wait(410);
	
		return busZustand;
}



/*
* @brief	Wait for a certain amount of microseconds using the method 'getTimeStamp' from timer 
* 				which counts the timer ticks. (84 MHz --> 84 000 000 ticks/second; 1 second --> 1000 000 microseconds) 
* @param	uSecs		Amount of microseconds to wait
*/
void wait(uint32_t uSecs)
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



void setOpenDrainMode()
{
		GPIOG -> OTYPER |= (0x1U << PG0);
}



void setPushPullMode()
{
		GPIOG -> OTYPER &= ~(0x1U << PG0);
}



/*
* Read the ROM-Code if one single Sensor is connected to the system. 
* Extract the FamilyCode, the SerialNumber and the CRC from the ROM-Code.
*/
void readRom() 
{
    uint64_t serial = 0;
    uint8_t arr[8];
    
    setOpenDrainMode();
    reset();
    writeByte(READ_ROM);

    
    //First Byte = FamilyCode (8 Bit)
    uint8_t familycode = readByte();
		
		//Reading the next 6 Byte for SerialNumber (48 Bit)
    int j = 0;    
    for(int i = 0; i < 48; i = i + 8)
		{
        arr[j] = readByte();   //Write bytewise in an array
        j++;
    }
    
		//Assemble the SerialNumber
    for(int i = 0; i < 6; i++)
		{
        serial = (((uint64_t) arr[i]) << i * 8) | serial; //Wird Byteweise verodert
        //printf("%X  : %X\n", serial, arr[i]);
    }
    
    //Last Byte = CRC (8 Bit)
    uint8_t crc = readByte();
    
    printf("familycode: %x\n", familycode);
    printf("serial: %012X\n", serial);
    printf("crc: %x\n", crc);
   
    //TODO: Fehlermeldung wenn kein Sensor angeschlossen
   
}





