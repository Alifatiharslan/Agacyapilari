#ifndef BINARYTREE_BINARYTREE_H     // Header guard → Dosyanın birden fazla kez eklenmesini engeller
#define BINARYTREE_BINARYTREE_H

#include "Node.h"                    // Node sınıfının tanımı burada olduğu için dahil ediliyor


// ======================================================================
// BinaryTree Sınıfı
// Bu sınıf, ikili arama ağacı (Binary Search Tree) yapısını yönetir.
// Temel işlevleri:
//  - Ağaca eleman ekleme
//  - Inorder, preorder ve postorder dolaşma (traversal)
//  - Kök (root) düğümü yönetme
// ======================================================================
class BinaryTree {
private:
    Node* root;                      // Ağacın kök düğümü (başlangıç noktası)

    // --- Özel (private) fonksiyonlar ---
    // Bu fonksiyonlar dışarıdan doğrudan çağrılmaz, iç mantıkta kullanılır.

    Node* insert(Node* node, int value);   // Recursive ekleme fonksiyonu
    void inorder(Node* node);              // Sol → Kök → Sağ (Artan sıralama)
    void preorde(Node* node);              // Kök → Sol → Sağ
    void postord(Node* node);              // Sol → Sağ → Kök

public:
    // --- Genel erişilebilir fonksiyonlar ---
    BinaryTree();                  // Yapıcı → root başlangıçta NULL yapılır
    void insert(int value);        // Kullanıcıya sunulan ekleme fonksiyonu

    // Ağacı farklı traversal yöntemleri ile yazdırma
    void printInorder();           // Küçükten büyüğe sıralı yazdırır
    void printPreorder();          // Ağaç yapısını kökten itibaren dolaşır
    void printPostorder();         // Silme işlemlerinde kullanılan traversal
};

#endif //BINARYTREE_BINARYTREE_H      // Header guard bitişi
