#include "BinaryTree.h"      // BinaryTree sınıfının bildirimlerini içeren header dosyası
#include <iostream>          // Ekrana çıktı vermek için
using namespace std;


// ======================================================================
// BinaryTree Constructor
// root başlangıçta nullptr yapılır. Böylece ağaç boş olarak başlar.
// ======================================================================
BinaryTree::BinaryTree() : root(nullptr) {}


// ======================================================================
// insert(Node*, value)
// Bu recursive fonksiyon, Binary Search Tree kuralına göre uygun
// konuma yeni düğümü yerleştirir.
//
// Kural:
//   - value < node->data → sol tarafa git
//   - value >= node->data → sağ tarafa git
// ======================================================================
Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr) {          // Uygun boş yer bulunduğunda
        return new Node(value);     // Yeni düğüm oluşturulur
    }

    if (value < node->data) {       // Daha küçükse sol alt ağaca eklenir
        node->left = insert(node->left, value);
    }
    else {                          // Büyükse sağ alt ağaca eklenir
        node->right = insert(node->right, value);
    }

    return node;                    // Güncellenmiş düğümü geri döndür
}


// ======================================================================
// insert(value)
// Kullanıcı tarafından çağrılan ana ekleme fonksiyonudur.
// Kökten başlayarak recursive insert çağrılır.
// ======================================================================
void BinaryTree::insert(int value) {
    root = insert(root, value);
}


// ======================================================================
// INORDER Traversal (SOL → KÖK → SAĞ)
// Ağacı küçükten büyüğe sıralı olarak yazdırır.
// ======================================================================
void BinaryTree::inorde(Node* node) {
    if (node == nullptr) {
        return;                     // Boş alt ağaçta işlem yok
    }

    inorde(node->left);             // Önce sol alt ağacı dolaş
    cout << node->data << " ";      // Sonra kökü yazdır
    inorde(node->right);            // En son sağ alt ağacı dolaş
}


// ======================================================================
// PREORDER Traversal (KÖK → SOL → SAĞ)
// Ağaç yapısını keşfetmek için kullanılır.
// ======================================================================
void BinaryTree::preorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    cout << node->data << " ";      // İlk önce kökü yazdır
    preorder(node->left);           // Sol alt ağacı dolaş
    preorder(node->right);          // Sağ alt ağacı dolaş
}


// ======================================================================
// POSTORDER Traversal (SOL → SAĞ → KÖK)
// Genellikle düğümleri silerken kullanılır.
// ======================================================================
void BinaryTree::posto(Node* node) {
    if (node == nullptr) {
        return;
    }

    posto(node->left);              // Sol alt ağaç
    posto(node->right);             // Sağ alt ağaç
    cout << node->data << " ";      // En son kökü yazdır
}


// ======================================================================
// printInorder()
// Kullanıcıya ağacı INORDER şekilde yazdıran fonksiyon
// ======================================================================
void BinaryTree::printInorder() {
    inorde(root);
    cout << endl;
}


// ======================================================================
// printPreorder()
// Kullanıcıya ağacı PREORDER şekilde yazdıran fonksiyon
// ======================================================================
void BinaryTree::printPreorder() {
    preorder(root);
    cout << endl;
}


// ======================================================================
// printPostorder()
// Kullanıcıya ağacı POSTORDER şekilde yazdıran fonksiyon
// ======================================================================
void BinaryTree::printPostorder() {
    posto(root);
    cout << endl;
}
//Bu dosya, ikili arama ağacına eleman ekleme ve inorder–preorder–postorder traversal işlemlerinin gerçek çalışan kodlarını içerir.