#include "Queue.h"
#include <iostream>
template <typename T>
void printQueueItem(const T& item){
  std::cout << item << std::endl;
}

int main(int argc, char const *argv[])
{
  Queue<int> que;
  que.push(10);
  que.push(12);
  que.push(13);
  que.push(14);
  que.push(15);
  que.push(16);
  que.push(17);
  for (int i = 0; i < 2; ++i)
  {
      printf("pop %d, size:%d, length:%d \n", que.pop(),que.size(),que.length());
  }
  printf("----------------------\n");
  que.push(20);
  que.push(26);
  que.push(22);
  que.push(29);
  int length = que.length();
   for (int i = 0; i < length ; ++i)
  {
     printf("item :%d \n", *que[i]);
  }

  printQueueItem<int>(100);
  printQueueItem<const char*>("hello world");
  return 0;
}