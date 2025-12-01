#include <iostream>          // Kullanıcıdan veri almak ve ekrana çıktı vermek için
#include "BinaryTree.h"      // BinaryTree sınıfını kullanabilmek için dahil ediyoruz
using namespace std;


// ======================================================================
// main Fonksiyonu
// Programın başlangıç noktasıdır. Bu örnekte:
//  - Kullanıcıdan kaç sayı gireceği alınır
//  - Kullanıcıdan alınan sayılar Binary Search Tree yapısına eklenir
//  - Ağaç üç farklı traversal yöntemiyle ekrana yazdırılır:
//        * Inorder  → Sol – Kök – Sağ (küçükten büyüğe sıralı)
//        * Preorder → Kök – Sol – Sağ
//        * Postorder→ Sol – Sağ – Kök
// ======================================================================
int main() {
    BinaryTree tree;           // Boş bir Binary Search Tree oluşturulur

    int n;
    cout << "kac adet sayi keleyceksiniz: ";
    cin >> n;                  // Kullanıcıdan eleman sayısı alınır

    cout << n << " sayiyi giriniz: ";

    // Kullanıcıdan n tane sayı alıp ağaca ekliyoruz
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;              // Kullanıcının girdiği sayı
        tree.insert(x);        // BST kuralına göre ağaca eklenir
    }

    // INORDER TRAVERSAL → Küçükten büyüğe sıralı yazdırır
    cout << "\n inorder: " << endl;
    tree.printInorder();

    // PREORDER TRAVERSAL → Ağacın yapısını keşfetmek için kullanılır
    cout << "preorder " << endl;
    tree.printPreorder();

    // POSTORDER TRAVERSAL → Silme algoritmalarında sık kullanılır
    cout << "postorder " << endl;
    tree.printPostorder();

    return 0;                  // Program başarıyla biter
}
//Kullanıcının girdiği sayılarla bir Binary Search Tree oluşturur ve ağacı üç farklı traversal yöntemiyle ekrana yazdırır.