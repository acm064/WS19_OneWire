/**
  ******************************************************************************
  * @file    	SensorListe.h 
  * @author  	Jonathan Backes (Matr.-Nr. 2394482), Tobias Hardjowirogo (Matr.-Nr. 2387188)
  * @task			WS19_A4 1-Wire Kommunikation       	  
  * @version 	V1.1
  * @date    	09.12.2019
  * @brief   	
  ******************************************************************************
  */
	
	#include <stdint.h>
  #include <stddef.h>
	
	#ifndef	SensorListe
	#define SensorListe
	
  typedef struct sensorListElement
  {
    uint64_t romCode;
    int32_t temperature;
    struct sensorListElement *next;
  } sensorListe;

  struct sensorListElement* getLast(struct sensorListElement *listHead);

  uint8_t removeLast(struct sensorListElement *listHead);

  uint8_t addToList(struct sensorListElement *nextSensorListElement, struct sensorListElement *listHead);

  uint8_t removeFromList(struct sensorListElement *nextSensorListElement, struct sensorListElement *listHead);
	
	
	
	#endif
	
	
	
	