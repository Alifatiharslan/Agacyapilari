#include <iostream>                         // Ekrana yazdırmak için gerekli kütüphane
#include "BinaryTree.h"                     // BinaryTree sınıfını kullanmak için
using namespace std;

BinaryTree::BinaryTree(): root(nullptr) {}  // Başlangıçta ağaç boş (root = nullptr)

// --------------------------------------------------------------
// insert(Node*, value):
// BST kuralına göre uygun yere değer ekleyen recursive fonksiyon
// --------------------------------------------------------------
Node* BinaryTree::insert(Node* node, int value) {
    if (!node) return new Node(value);      // Boş yere geldiysek yeni düğüm oluştur

    if (value < node->data)                 // Değer küçükse sola ekle
        node->left = insert(node->left, value);
    else                                     // Büyük/eşitse sağa ekle
        node->right = insert(node->right, value);

    return node;                            // Güncellenen düğümü geri döndür
}

// Kullanıcının çağırdığı ekleme fonksiyonu
void BinaryTree::insert(int value) {
    root = insert(root, value);             // root üzerinden ekleme başlatılır
}

// --------------------------------------------------------------
// inorder traversal → SOL → KÖK → SAĞ
// Elemanlar sıralı şekilde vector'e doldurulur
// --------------------------------------------------------------
void BinaryTree::inorder(Node* node, vector<int>& elements) {
    if (!node) return;                      // Boş düğümde dur
    inorder(node->left, elements);          // Sol alt ağacı dolaş
    elements.push_back(node->data);         // Kökü ekle
    inorder(node->right, elements);         // Sağ alt ağacı dolaş
}

// İnorder sonucu ekrana yazdırılır
void BinaryTree::printInorder() {
    vector<int> elements;
    inorder(root, elements);                // Ağaç inorder gezilir
    for (int x: elements) {
        cout << x << " " << endl;           // Elemanları yazdır
    }
}

// --------------------------------------------------------------
// findPairWithSum(target):
// BST içindeki iki elemanın toplamı hedef sayıya eşit mi?
// Two-pointer tekniği kullanır (sıralı dizide tarama)
// --------------------------------------------------------------
bool BinaryTree::findPairWithSum(int target) {
    vector<int> elements;
    inorder(root, elements);                // Sıralı dizi elde edilir

    int left = 0;                           // Sol pointer
    int right = elements.size() - 1;        // Sağ pointer

    while (left < right) {
        int sum = elements[left] + elements[right];  // İki elemanın toplamı

        if (sum == target) {                // Çift bulundu
            cout << "pair found "
                 << elements[left] << " + "
                 << elements[right] << " = "
                 << target << endl;
            return true;
        }
        else if (sum < target) {            // Toplam küçük → sola ilerle
            left++;
        }
        else {                               // Toplam büyük → sağa ilerle
            right--;
        }
    }
    return false;                           // Çözüm yoksa false döndür
}
