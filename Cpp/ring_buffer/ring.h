#ifndef PRACTICECPP_RING_H
#define PRACTICECPP_RING_H

//#include <iostream>

template<typename T>
class ring {
private:
    int m_pos;
    int m_size;
    T *m_values;

public:
    class iterator; // instead of nested iterator class we use something like forward declaration

    ring(int size) : m_pos(0), m_size(size), m_values(nullptr) { //constructor
        m_values = new T[size];
    }
    ~ring(){
      delete [] m_values;
    }

    int size() {
      return m_size;
    }

    iterator begin() {
      return iterator(0, *this);
    }

    iterator end() {
      return iterator(m_size, *this);
    }

    void add(T value) {
      m_values[m_pos++] = value;
      if(m_pos==m_size){
        m_pos=0; // we have reached the end of the buffer, rewind to beginning
      }
    }

    T &get(int pos){
      return m_values[pos];
    }

};

// we only need ring<T> and not iterator<T>
template<typename T>
class ring<T>::iterator {
private:
    int m_pos;
    ring &m_ring;
public:
    iterator(int pos, ring &this_ring) : m_pos(pos), m_ring(this_ring) {

    }

    iterator &operator++(int){ // implement postfix ++operator for our template
      m_pos++;
      return *this;
    }

    T &operator*(){
     return m_ring.get(m_pos);
    }

    bool operator!=(const iterator &other){
      return m_pos!=other.m_pos;
    }
};
#endif //PRACTICECPP_RING_H
