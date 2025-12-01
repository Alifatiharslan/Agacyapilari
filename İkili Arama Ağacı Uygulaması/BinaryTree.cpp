#include "BinaryTree.h"     // BinaryTree ve Node sınıf tanımları için
#include <iostream>         // Ekran çıktısı için
using namespace std;

// ======================================================================
// BinaryTree Constructor
// Ağacın başlangıçta boş olmasını sağlar → root = nullptr
// ======================================================================
BinaryTree::BinaryTree(): root(nullptr) {}


// ======================================================================
// insert(Node* node, int value)
// Recursive olarak ağaca eleman ekleyen fonksiyonun iç mekaniği.
// Eğer node boşsa yeni düğüm oluşturur.
// Eğer value < node->data ise sol tarafa ekler.
// Aksi halde sağ tarafa ekler.
// ======================================================================
Node* BinaryTree::insert(Node* node, int value) {

    if (node == nullptr) {                 // Uygun boş yer bulundu → yeni Node oluştur
        return new Node(value);
    }

    if (value < node->data) {              // Değer küçükse sol tarafa git
        node->left = insert(node->left, value);
    }
    else {                                 // Büyük veya eşitse sağ tarafa git
        node->right = insert(node->right, value);
    }

    return node;                           // Güncel düğümü geri döndür
}


// ======================================================================
// insert(int value)
// Kullanıcıya sunulan basit ekleme fonksiyonu.
// root üzerinden recursive inserta yönlendirme yapar.
// ======================================================================
void BinaryTree::insert(int value) {
    root = insert(root, value);
}


// ======================================================================
// inorder(Node* node)
// İNORDER TRAVERSAL: Left → Root → Right
// Ağacı küçükten büyüğe SIRALI şekilde yazdırır.
// ======================================================================
void BinaryTree::inorder(Node *node) {

    if (node == nullptr) {                 // Yaprak altına inildi → dur
        return;
    }

    inorder(node->left);                   // 1) Sol alt ağaç
    std::cout << node->data << " ";        // 2) Kök
    inorder(node->right);                  // 3) Sağ alt ağaç
}


// ======================================================================
// preorder(Node* node)
// PREORDER TRAVERSAL: Root → Left → Right
// Ağacın kökten başlayarak tüm yapısını gezmek için kullanılır.
// ======================================================================
void BinaryTree::preorde(Node *node) {

    if (node == nullptr) {
        return;
    }

    std::cout << node->data << " ";        // 1) Kök
    preorde(node->left);                   // 2) Sol
    preorde(node->right);                  // 3) Sağ
}


// ======================================================================
// postord(Node* node)
// POSTORDER TRAVERSAL: Left → Right → Root
// Genellikle ağaç silme veya alt ağaç işlemleri için kullanılır.
// ======================================================================
void BinaryTree::postord(Node *node) {

    if (node == nullptr) {
        return;
    }

    postord(node->left);                   // 1) Sol
    postord(node->right);                  // 2) Sağ
    std::cout << node->data << " ";        // 3) Kök
}


// ======================================================================
// printInorder()
// Kullanıcıya sunulan inorder ekrana yazma fonksiyonu
// ======================================================================
void BinaryTree::printInorder() {
    inorder(root);
    std::cout << "\n";
}


// ======================================================================
// printPreorder()
// Kullanıcıya sunulan preorder ekrana yazma fonksiyonu
// ======================================================================
void BinaryTree::printPreorder() {
    preorde(root);
    std::cout << "\n";
}


// ======================================================================
// printPostorder()
// Kullanıcıya sunulan postorder ekrana yazma fonksiyonu
// ======================================================================
void BinaryTree::printPostorder() {
    postord(root);
    std::cout << "\n";
}
