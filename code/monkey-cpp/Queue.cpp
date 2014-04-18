#include "Queue.h"

#define DEFAULT_QUEUE_ITEM_NUM 4
#define DEFAULT_INCREASE_FACTOR 0.75
#define ErrorMsg(x) printf("Error msg: %s",x)


template <class T>
Queue<T>::Queue(void)
:m_size(DEFAULT_QUEUE_ITEM_NUM),m_length(0){
  m_data = new T[DEFAULT_QUEUE_ITEM_NUM];
  if(m_data == 0){
    ErrorMsg("creat memory ");
    exit(1);
  }
}

template <class T>
Queue<T>::~Queue(){
  clear();
}

template <class T>
void Queue<T>::push(const T& item){
  increaseMemory();
  m_data[m_length++] = item;
}

template <class T>
void Queue<T>::increaseMemory(){
  if(m_length+1 > m_size){
    int new_size = m_size + m_size * DEFAULT_INCREASE_FACTOR;
    T* new_data = new T[new_size];
    if(new_data == 0){
      ErrorMsg("increase memory ");
      exit(1);
    }
    memcpy(new_data,m_data,sizeof(T)*m_size);
    delete[] m_data;
    m_data = new_data;
    m_size = new_size;    
  }
}

template <class T>
T Queue<T>::pop(){
  if(!isEmpty()){
    return m_data[--m_length];
  }
  return 0;
}

template <class T>
bool Queue<T>::isEmpty() const{
  return m_length == 0;
}

template <class T>
void Queue<T>::clear() {
  delete[] m_data;
}