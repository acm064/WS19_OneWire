/**
  ******************************************************************************
  * @file    	SensorListe.c 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task		WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	
	
#include "SensorListe.h"
#include <stdio.h>
	

   
struct sensorListElement* getLast(struct sensorListElement *listHead)
{
	struct sensorListElement *listPointer = listHead;    
    while (listPointer->next != NULL)
    {
		listPointer = listPointer->next;
    }
    return listPointer;
}

 
 
uint8_t removeLast(struct sensorListElement *listHead)
{
    struct sensorListElement *listPointer = listHead;  
    if (listPointer->next != NULL)
    {
		while (listPointer->next->next != NULL)
		{
			listPointer = listPointer->next;
		}
		listPointer->next = NULL;
		return 0;
    }
    else
    {
		return 1;
    }
}

 
 
uint8_t addToList(struct sensorListElement *nextSensorListElement, struct sensorListElement *listHead)
{
    uint8_t counter = 0;
    struct sensorListElement *listPointer = getLast(listHead);
    listPointer->next = nextSensorListElement;
    counter ++;
    printf("counter: %d \n", counter);
    return 0;
}

 
 
uint8_t removeFromList(struct sensorListElement *nextSensorListElement, struct sensorListElement *listHead)
{
    struct sensorListElement *listPointer = listHead;    
    while (listPointer->next != nextSensorListElement)
    {
		if (listPointer->next->next != NULL)
		{
			listPointer->next = listPointer->next->next;
			return 0;
		}
		else
		{
			listPointer->next = NULL;
			return 0;
		}
    }
    return 1;
}









