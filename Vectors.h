#ifndef VECTORS_H_INCLUDED
#define VECTORS_H_INCLUDED
#define max 4
 typedef struct vEctor {
 int top;
 int *arr;
 int maxsize;
}Vector;

void Create(Vector *pv);
void push (Vector *pv, int element);
void pop(Vector *pv);
int GetTop(Vector *pv );
int GetSize(Vector *pv );
void Destroy(Vector *pv);

#endif // VECTORS_H_INCLUDED
