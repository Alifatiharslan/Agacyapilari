#ifndef BINARYTREE2_BINARYTREE_H          // Header guard → Dosyanın birden fazla eklenmesini engeller
#define BINARYTREE2_BINARYTREE_H

#include "Node.h"                         // Node sınıfını kullanabilmek için dahil ediyoruz


// ======================================================================
// BinaryTree Sınıfı
// Bu sınıf, ikili arama ağacını (Binary Search Tree - BST) temsil eder.
// Temel görevleri:
//  - Ağaca eleman eklemek (insert)
//  - Ağacı üç farklı traversal yöntemiyle dolaşmak:
//        * inorder   (Sol → Kök → Sağ)
//        * preorder  (Kök → Sol → Sağ)
//        * postorder (Sol → Sağ → Kök)
// ======================================================================
class BinaryTree {
private:
    Node *root;                           // Ağacın kök düğümünü tutar (başlangıç noktası)

    // --- Ağaç içinde kullanılan özel fonksiyonlar ---
    Node* insert(Node* node, int value);  // Recursive olarak düğüm ekleme
    void inorde(Node* node);              // Inorder dolaşma fonksiyonu
    void preorder(Node* node);            // Preorder dolaşma fonksiyonu
    void posto(Node* node);               // Postorder dolaşma fonksiyonu

public:
    BinaryTree();                          // Constructor → root başlangıçta nullptr yapılır
    void insert(int value);                // Kullanıcı tarafından çağrılan ekleme fonksiyonu

    // --- Ağaç çıktısını kullanıcıya gösteren fonksiyonlar ---
    void printPreorder();                  // Preorder yazdır
    void printInorder();                   // Inorder yazdır
    void printPostorder();                 // Postorder yazdır
};

#endif //BINARYTREE2_BINARYTREE_H         // Header guard sonu
