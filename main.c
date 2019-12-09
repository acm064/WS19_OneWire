/**
  ******************************************************************************
  * @file    	main.c 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task			WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	Main program body
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

// #include "TI_Lib.h"
// #include "tft.h"
// #include "timer.h"

#include "SensorListe.h"
#include <malloc.h>

//--- For GPIOs -----------------------------
//Include instead of "stm32f4xx.h" for
//compatibility between Simulation and Board
//#include "TI_memory_map.h"



struct sensorListElement *listHead = NULL;


uint8_t testList() {
  uint8_t fehlerCode = 0;
  listHead = (struct sensorListElement*) malloc(sizeof(struct sensorListElement));
  listHead->temperature = 0;
  listHead->romCode = 0;
  listHead->next = NULL;
  struct sensorListElement *listPointer = listHead;

  for (int32_t i = 0; i < 10; i++)
  {
    struct sensorListElement *element = (struct sensorListElement*) malloc(sizeof(struct sensorListElement));
    element->romCode = i*5;
    element->temperature = i*2;
                "/usr/include/**",
                "/usr/include/**",
    element->next = NULL;
    fehlerCode = addToList(element, listHead);
    printf("FehlerCode: %d\n", fehlerCode);
  }

  while (listPointer->next =! NULL)
  {
    listPointer = listPointer->next;
    printf("Temperatur: %d\t RomCode: %d \n");
  }
  
  
  fehlerCode = removeLast(listHead);
  printf("FehlerCode: %d\n", fehlerCode);
  fehlerCode = removeLast(listHead);
  printf("FehlerCode: %d\n", fehlerCode);


  while (listPointer->next =! NULL)
  {
    listPointer = listPointer->next;
    printf("Temperatur: %d\t RomCode: %d \n");
  }

}

/**
  * @brief  Main program
  * @param  None
  */
int main(void)
{
	
  testList();

  return 0;

}


// EOF
