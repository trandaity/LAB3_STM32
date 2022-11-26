/*
 * global.h
 *
 *  Created on: Nov 23, 2022
 *      Author: trand
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define FIRST_LED 	0
#define SECOND_LED 	1
#define THIRD_LED	2
#define FOURTH_LED	3
#define FIFTH_LED 	4

extern int redValue;
extern int ylwValue;
extern int grnValue;

extern int incresesRED;
extern int increaseYLW;
extern int increaseGRN;

extern int setStatus;

extern int firstLaneCounter;
extern int secondLaneCounter;

extern int firstLaneStatus;
extern int secondLaneStatus;

extern int index_led;
extern int led_buffer[5];

#endif /* INC_GLOBAL_H_ */
