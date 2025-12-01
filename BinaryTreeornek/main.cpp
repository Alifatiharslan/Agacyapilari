#include <iostream>              // Giriş/çıkış işlemleri için
#include "BinaryTree.h"          // BinaryTree sınıfını kullanmak için
using namespace std;

int main() {
    BinaryTree tree;             // Boş bir Binary Search Tree oluşturulur
    int n, val, target;

    cout << "Kac sayi eklemek istiyorsunuz?: ";
    cin >> n;                    // Kullanıcı kaç sayı gireceğini belirler

    cout << "Sayilari girin:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;              // Her sayı kullanıcıdan alınır
        tree.insert(val);        // BST'ye eklenir
    }

    cout << "\nBST inorder: ";
    tree.printInorder();         // BST sıralı olarak ekrana yazdırılır (inorder → küçükten büyüğe)

    cout << "Hedef toplam sayiyi girin: ";
    cin >> target;               // Kullanıcı hedef toplamı girer

    if (!tree.findPairWithSum(target))     // İki elemanın toplamı hedefe eşit mi bakılır
        cout << "Boyle bir pair yok.\n";   // Yoksa mesaj verilir

    return 0;                    // Program biter
}
