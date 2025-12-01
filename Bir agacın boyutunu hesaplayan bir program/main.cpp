#include<bits/stdc++.h>        // Standart C++ kütüphanelerini tek seferde ekler
using namespace std;          // std:: yazma zorunluluğunu kaldırır

// Binary tree düğüm (node) yapısı
class Node {
public:
    int data;                 // Düğümün tuttuğu veri
    Node *left, *right;       // Sol ve sağ çocuk düğümlerin adresi

    // Constructor: yeni bir düğüm oluşturur
    Node(int x) {
        data = x;             // Düğümün değerini ayarla
        left = nullptr;       // Başlangıçta sol çocuk yok
        right = nullptr;      // Başlangıçta sağ çocuk yok
    }
};

// Ağacın boyutunu (toplam düğüm sayısı) bulan fonksiyon
int getSize(Node *root) {
    if (root == nullptr) {    // Eğer düğüm yoksa (boş alt ağaçsa)
        return 0;             // Boyut 0'dır
    }

    int left = getSize(root->left);   // Sol alt ağacın boyutunu rekürsif çağır
    int right = getSize(root->right); // Sağ alt ağacın boyutunu rekürsif çağır

    return left + right + 1;          // Sol + sağ + kendisi toplam düğüm sayısı
}

int main () {

    // Ağaç oluşturuluyor:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    Node *root = new Node(1);      // Root düğüm 1
    root->left = new Node(2);      // Sol çocuk 2
    root->right = new Node(3);     // Sağ çocuk 3
    root->left->left = new Node(4); // 2'nin sol çocuğu 4
    root->left->right = new Node(5); // 2'nin sağ çocuğu 5

    cout << getSize(root) << endl; // Ağacın toplam düğüm sayısını yazdır (5)

    return 0;                      // Program başarıyla bitti
}
