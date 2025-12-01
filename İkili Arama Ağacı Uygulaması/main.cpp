#include <iostream>         // Giriş/çıkış işlemleri için gerekli kütüphane
#include "BinaryTree.h"     // BinaryTree sınıfının tanımı
using namespace std;

int main() {
    BinaryTree tree;        // BinaryTree sınıfından bir ikili arama ağacı nesnesi oluşturulur

    // Ağaca eleman ekleme (Binary Search Tree kuralına göre yerleştirilir)
    tree.insert(10);        // Kök olur (root = 10)
    tree.insert(9);         // 10'un soluna eklenir
    tree.insert(20);        // 10'un sağına eklenir
    tree.insert(19);        // 20'nin soluna eklenir
    tree.insert(30);        // 20'nin sağına eklenir
    tree.insert(40);        // 30'un sağına eklenir
    tree.insert(50);        // 40'ın sağına eklenir
    tree.insert(60);        // 50'nin sağına eklenir

    // INORDER TRAVERSAL → Sol – Kök – Sağ (Küçükten büyüğe sıralı yazdırır)
    std::cout << "Inorder: ";
    tree.printInorder();    // Ağacın değerleri sıralı şekilde ekrana yazdırılır

    // PREORDER TRAVERSAL → Kök – Sol – Sağ (Ağacın yapısını keşfetmek için kullanılır)
    std::cout << "Preorder: ";
    tree.printPreorder();   // Ağacın kökten başlayan dolaşımı

    // POSTORDER TRAVERSAL → Sol – Sağ – Kök (Genellikle silme işlemlerinde kullanılır)
    std::cout << "Postorder: ";
    tree.printPostorder();  // Ağacın postorder biçiminde yazdırılması

    return 0;               // Program başarıyla sonlanır
}
