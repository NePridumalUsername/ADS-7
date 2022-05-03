// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<class T>
class TPQueue {
 private:
    struct ITEM {
        T data;
        ITEM *next = nullptr;
    };
    ITEM *head;
    ITEM *tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    void push(const T& data);
    T pop();
};

template<typename T>
void TPQueue<T>::push(const T& data) {
    if (tail && head) {
        ITEM *place = head;
        while (place && (data.prior <= place->data.prior)) {
            place = place->next;
        }
        if (place) {
            ITEM *displaced = new ITEM{place->data, place->next};
            *place = ITEM{data, displaced};
            if (place == tail) tail = displaced;
        } else {
            place = new ITEM{data};
            tail->next = place;
            tail = place;
        }
    } else {
        head = new ITEM{data};
        tail = head;
    }
}

template<typename T>
T TPQueue<T>::pop() {
    if (head) {
        ITEM *temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        return data;
    } else {
        return *new T{0};
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
