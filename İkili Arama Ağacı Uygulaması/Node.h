#ifndef BINARYTREE_NODE_H             // Header guard → Dosyanın birden fazla dahil edilmesini önler
#define BINARYTREE_NODE_H

// ===============================================================
// Node Sınıfı
// İkili ağaçtaki (Binary Tree / Binary Search Tree) temel yapı taşıdır.
// Her düğüm 3 bilgi içerir:
//   • data  → düğümde saklanan veri
//   • left  → sol çocuk düğüm pointer'ı
//   • right → sağ çocuk düğüm pointer'ı
// Bu yapı sayesinde her node bir alt ağaç oluşturabilir.
// ===============================================================
class Node {
public:
    int data;                 // Bu düğümün tuttuğu tam sayı değer
    Node* left;               // Sol alt düğümü gösterir (nullptr olabilir)
    Node* right;              // Sağ alt düğümü gösterir (nullptr olabilir)

    // Constructor — Yeni bir düğüm oluşturmak için çağrılır.
    // value: Düğümün veri kısmını belirler.
    // left ve right başlangıçta nullptr yapılır, yani düğümün çocukları yoktur.
    Node(int value);
};

#endif // BINARYTREE_NODE_H           // Header guard bitişi
