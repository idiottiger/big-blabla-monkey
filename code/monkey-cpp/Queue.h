#ifndef __QUEUE_H__
  #define __QUEUE_H__
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #define DEFAULT_QUEUE_ITEM_NUM 4
  #define DEFAULT_INCREASE_FACTOR 0.75
  #define ErrorMsg(x) printf("Error msg: %s",x)


  template <class T>
    class Queue
    {
    public:
      Queue(void);
      ~Queue();
      void push(const T& item);
      T pop();
      bool isEmpty() const;
      int size() const{
        return m_size;
      };
      int length() const{
        return m_length;
      };
      void clear();
      T* operator[] (int index);
    private:
      T* m_data;
      int m_size;
      int m_length;
      void increaseMemory();
    };


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

      template <class T>
      T* Queue<T>::operator[] (int index){
        if(index>=0 && index <m_length){
          return &m_data[index];
        }
        return 0;
      }
#endif