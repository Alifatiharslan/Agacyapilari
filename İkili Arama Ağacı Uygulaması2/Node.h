#ifndef BINARYTREE2_NODE_H            // Header guard → Dosyanın birden fazla eklenmesini önler
#define BINARYTREE2_NODE_H


// ======================================================================
// Node Sınıfı
// Bu sınıf, ikili arama ağacındaki (Binary Tree / BST) tek bir düğümü temsil eder.
// Her düğümde üç bilgi bulunur:
//   - data: düğümün tuttuğu veri
//   - left: sol alt düğümü gösteren işaretçi
//   - right: sağ alt düğümü gösteren işaretçi
// ======================================================================
class Node {
public:
    int data;        // Düğümün içerdiği değer
    Node *left;      // Sol çocuk düğüm pointer'ı
    Node *right;     // Sağ çocuk düğüm pointer'ı

    // Constructor → Yeni bir Node oluşturur ve
    // data=value, left=nullptr, right=nullptr olarak ayarlar.
    Node(int value);
};

#endif //BINARYTREE2_NODE_H            // Header guard sonu
//Bu dosya, ikili arama ağacındaki düğümlerin veri ve bağlantı yapısını tanımlar.