#ifndef BINARYTREEORNEK_NODE_H        // Header guard → Dosyanın birden fazla eklenmesini engeller
#define BINARYTREEORNEK_NODE_H

class Node {
public:
    int data;                        // Düğümün tuttuğu değer
    Node *left;                      // Sol çocuk düğüme işaret eden pointer
    Node *right;                     // Sağ çocuk düğüme işaret eden pointer

    Node(int value);                 // Constructor → Veri atanır, left/right nullptr yapılır
};

#endif //BINARYTREEORNEK_NODE_H        // Header guard bitişi
