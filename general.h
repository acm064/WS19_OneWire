/**
  ******************************************************************************
  * @file    	general.h 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task		WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */



#ifndef general
#define general



#include <stdint.h>



//Definitionen für IO Ports
#define PG0				0
#define PG1				1

#define PORT			GPIOG

//commands
#define READ_ROM		0x33
#define SEARCH_ROM		0xF0
#define SKIP_ROM		0xCC
#define MATCH_ROM		0x55
#define CONVERT_T		0x44
#define READ_SCRATCHPAD	0xBE





#endif








