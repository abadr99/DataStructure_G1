#ifndef CONF_H_INCLUDED
#define CONF_H_INCLUDED

#define QUEUE_LINKED  (1)
#define QUEUE_ARRAY   (2)

//if you want queue array ,replace -QUEUE_ARRAY- by -QUEUE_LINKED-.
#define QUEUE_TYPE     QUEUE_LINKED

#if QUEUE_TYPE == QUEUE_ARRAY
//if you want to change the size ,replace 100 with your size.
#define arraysize    (100)
#endif
#if QUEUE_TYPE != QUEUE_ARRAY  && QUEUE_TYPE != QUEUE_LINKED

#error "Error in defining QUEUE_TYPE "
#endif
#endif // CONF_H_INCLUDED
