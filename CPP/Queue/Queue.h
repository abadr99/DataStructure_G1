#ifndef QUEUE_H_
#define QUEUE_H_

namespace DSA{ namespace DS { namespace QUEUE { namespace LINKED {
template < typename T >
struct Node_t
{

	T _Data;
	Node_t<T> *_pNextNode;
};
template < typename T >
class Queue
{
	private:
		Node_t<T> *_pReer;
		Node_t<T> *_pFront;
		uint32_t _Size;
	public:
		Queue();
		void Enqueue(T _Data );
		T Dequeue();
		T GetFirst();
		uint8_t IsFull();
		uint8_t IsEmpty();
		void Traverse(void (*_pFun)(T _Data) );
		void DestroyQueue();
		uint32_t GetSize();

};

}}}}//DSA::DS::QUEUE::LINKED

#endif /* QUEUE_H_ */