// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private :
  struct ITEM {
    T data;
    ITEM * next;
    ITEM* prev;
};
  TPQueue :: ITEM * create(const T &);
  ITEM* head;
  ITEM* tail;
 public:
  TPQueue():head(nullptr), tail(nullptr) {}
  void push(const T&);
  T pop();
};

struct SYM {
  char ch;
  int prior;
};
template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& data) {
  ITEM * item = new ITEM;
  item -> data = data;
  item -> next = nullptr;
  item -> prev = nullptr;
  return item;
}
template < typename T >
void TPQueue <T>::push(const T& data) {
  ITEM * temp = head;
  ITEM * item = create(data);
  while (temp && temp -> data.prior >= data.prior )
    temp = temp -> next ;
  if (!temp && head) {
    tail -> next = item;
    tail -> next -> prev = tail;
    tail = item;
  } else if (!temp && !head) {
      head = tail = item;
  } else if (!temp -> prev) {
    temp -> prev = item;
    item -> next = temp;
    head = item;
  } else {
      temp -> prev -> next = item;
      item -> prev = temp -> prev;
      item -> next = temp;
      temp -> prev = item;
  }
}
template < typename T >
T TPQueue<T>::pop() {
  ITEM * temp = head -> next;
  if (temp)
    temp -> prev = nullptr;
  T data = head -> data;
  delete head;
  head = temp;
  return data;
}
#endif  // INCLUDE_TPQUEUE_H_
