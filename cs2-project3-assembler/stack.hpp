//
//  stack.hpp
//  [Project 3] assembler


#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"

template <typename T>
class stack {
public:
    stack();                            // Default
    stack(const stack<T>&);             // Copy
    ~stack();                           // Destructor
    void swap(stack<T>&);               // Swap
    
    stack<T>& operator=(stack<T>);      // Assignment
    stack<T>& operator=(T);             // Assignment
    
    T operator[](int);                  // Subscript
    
    T gettos();
    
    bool isEmpty() const;
    bool isFull() const;
    
    void push(const T&);
    T pop();
    
    bool operator==(const stack<T>&) const;
    
    
    
private:
    node<T> *tos;
    int size;
};

// ============================================================================================
// ============================================================================================
// ============================================================================================

template <typename T>
T stack<T>::gettos() {
    return tos->data;
}

//-- Default Constructor --//
template <typename T>
stack<T>::stack() {
    tos = NULL;
    size = 0;
}

//-- Copy Constructor --//
template <typename T>
stack<T>::stack(const stack<T> &actual) {
    node<T> *bottom = nullptr, *temptos, *tempNode;
    temptos = actual.tos;
    tos = 0;
    
    while (temptos != 0) {
        tempNode = new node<T>(temptos->data);
        
        if (tos == 0)
            tos = tempNode;
        else
            bottom->next = tempNode;
        
        bottom = tempNode;
        temptos = temptos->next;
    }
}

//-- Destructor --//
template <typename T>
stack<T>::~stack() {
    
    while (tos != 0) {
        node<T> *tmp;
        tmp = tos;
        tos = tos->next;
        delete tmp;
    }
}

//-- Swap --//
template <typename T>
void stack<T>::swap(stack<T> &rhs) {
    node<T> *tmp = tos;
    tos = rhs.tos;
    rhs.tos=tmp;
}

//-- Assignment --//
template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs) {
    swap(rhs);
    return *this;
}

//-- Assignment --//
template <typename T>
stack<T>& stack<T>::operator=(T x) {
    push(x);
    size = 1;
    return *this;
}

//-- Subscript --//
template <typename T>
T stack<T>::operator[](int index) {
    if (isEmpty())
        exit(1);
    stack<T> stack(*this);
    stack.size = size;
    for (int i = stack.size; i > index + 1; --i){
        stack.pop();
    }
    return stack.tos->data;
}

//-- Empty? --//
template <typename T>
bool stack<T>::isEmpty() const {
    return tos == 0;
}

//-- Full? --//
template <typename T>
bool stack<T>::isFull() const {
    node<T> *temp = new(std::nothrow) node<T>();
    if (temp) {
        delete temp;
        return false;
    }
    return true;
}

//-- Push --//
template <typename T>
void stack<T>::push(const T& x) {
    if (!isFull()) {
        node<T> *tmp = new node<T>(x);
        tmp->next = tos;
        tos = tmp;
        ++size;
    }
}

//-- Pop --//
template <typename T>
T stack<T>::pop() {
    if (!isEmpty()) {
        T result = tos->data;
        node<T> *tmp = tos;
        tos = tos->next;
        --size;
        delete tmp;
        return result;
    }
    exit(1);
}

//-- Comparison --//
template <typename T>
bool stack<T>::operator==(const stack<T>& rhs) const {
    
    stack<T> l(*this), r(rhs);
    
    if ((l.isEmpty() && !r.isEmpty()) || (!l.isEmpty() && r.isEmpty()))
        return false;
    
    while (!l.isEmpty() && !r.isEmpty()) {
        if (l.pop() != r.pop())
            return false;
        if ((l.isEmpty() && !r.isEmpty()) || (!l.isEmpty() && r.isEmpty()))
            return false;
    }
    
    return true;
}


#endif
