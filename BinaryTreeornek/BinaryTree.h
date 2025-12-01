#ifndef BINARYTREEORNEK_BINARYTREE_H     // Header guard → Dosyanın birden fazla eklenmesini engeller
#define BINARYTREEORNEK_BINARYTREE_H

#include "Node.h"                        // Node yapısını kullanmak için dahil edilir
#include <vector>                        // inorder verilerini vector'de tutmak için
using namespace std;

class BinaryTree {
private:
    Node *root;                          // Ağacın kök düğümü

    Node* insert(Node* node, int value); // Recursive ekleme fonksiyonu
    void inorder(Node* node, vector<int>& elements);
    // Inorder traversal (sol–kök–sağ) ve değerleri toplar

public:
    BinaryTree();                        // Constructor → root başlangıçta nullptr yapılır
    void insert(int value);              // Ağaca dışarıdan ekleme yapan fonksiyon

    bool findPairWithSum(int target);    // Two-sum: hedef toplamı veren iki eleman var mı kontrol eder
    void printInorder();                 // Ağacın inorder çıktısını ekrana yazdırır
};

#endif //BINARYTREEORNEK_BINARYTREE_H     // Header guard bitişi
