#ifndef CONF_H_INCLUDED
#define CONF_H_INCLUDED

#define QUEUE_LINKED  (1)
#define QUEUE_ARRAY   (2)

//if you want queue array ,replace -QUEUE_ARRAY- by -QUEUE_LINKED-.
#define QUEUE_TYPE     QUEUE_LINKED

#if QUEUE_TYPE == QUEUE_ARRAY
//if you want to change the size ,replace 100 with your size.
#define ARRAY_SIZE    (100)
#endif
#if QUEUE_TYPE != QUEUE_ARRAY  && QUEUE_TYPE != QUEUE_LINKED

#error "ERROR IN DEFINING QUEUE_TYPE @Queue_Config.h "
#endif
#endif // CONF_H_INCLUDED
