/*
 * priority_queue_config.h
 *
 *  Created on: Nov 4, 2022
 *      Author: mariam ahmed
 */

#ifndef PRIORITY_QUEUE_CONFIG_H_
#define PRIORITY_QUEUE_CONFIG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "STD_TYPES.h"
#define LINKED_INC_PQUEUE 3
#define LINKED_DEC_PQUEUE  4
#define ARRAY_INC_PQUEUE 5
#define ARRAY_DEC_PQUEUE 6

typedef uint16_t QueueEntry;


#define PQ_MAX_SIZE 10

#define PQ_TYPE (LINKED_DEC_PQUEUE)

#endif /* PRIORITY_QUEUE_CONFIG_H_ */
