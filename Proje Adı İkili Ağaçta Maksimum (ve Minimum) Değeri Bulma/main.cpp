#include <bits/stdc++.h>        // Tüm temel kütüphaneleri içerir
using namespace std;

/////////////////////////////////////////////////////////////
// ========== BÖLÜM 1 — NODE SINIFI (AYIRCAKSAN Node.h) ==========
// Bu sınıf binary tree içinde kullanılacak düğüm yapısını tanımlar.
/////////////////////////////////////////////////////////////

class Node {
public:
    int data;                  // Düğümün tuttuğu veri
    Node* left;                // Sol çocuk pointer'ı
    Node* right;               // Sağ çocuk pointer'ı

    // Constructor — yeni düğüm oluşturulduğunda veri atanır
    Node(int data) {
        this->data = data;
        this->left = NULL;     // Başlangıçta sol çocuk yok
        this->right = NULL;    // Başlangıçta sağ çocuk yok
    }
};

/////////////////////////////////////////////////////////////
// ======= BÖLÜM 2 — FIND MAX (AYIRCAKSAN Tree.cpp / Tree.h) =====
// Bu fonksiyon binary tree içindeki en büyük değeri bulur.
// DFS (Depth First Search) mantığıyla rekürsif çalışır.
/////////////////////////////////////////////////////////////

int findMax(Node* root) {

    // Eğer düğüm NULL ise INT_MIN döndür.
    // Böylece maksimum kıyaslamasında etkisiz eleman olur.
    if (root == NULL)
        return INT_MIN;

    int res = root->data;         // Şu anki düğümün değeri
    int leftMax = findMax(root->left);   // Sol alt ağacın maksimumu
    int rightMax = findMax(root->right); // Sağ alt ağacın maksimumu

    // En büyük değeri belirle
    if (leftMax > res)  res = leftMax;
    if (rightMax > res) res = rightMax;

    return res;                   // Bulunan maksimum değeri döndür
}

/////////////////////////////////////////////////////////////
// ======= BÖLÜM 3 — FIND MIN (AYIRCAKSAN Tree.cpp / Tree.h) =====
// Bu fonksiyon binary tree içindeki en küçük değeri bulur.
/////////////////////////////////////////////////////////////

int findMin(Node* root) {

    // Eğer düğüm NULL ise INT_MAX döndür.
    // Böylece minimum kıyaslamasında etkisiz eleman olur.
    if (root == NULL)
        return INT_MAX;

    int res = root->data;        // Şu anki düğümün değeri
    int leftMin = findMin(root->left);  // Sol alt ağacın minimumu
    int rightMin = findMin(root->right);// Sağ alt ağacın minimumu

    // En küçük değeri belirle
    if (leftMin < res)  res = leftMin;
    if (rightMin < res) res = rightMin;

    return res;                  // Bulunan minimum değeri döndür
}

/////////////////////////////////////////////////////////////
// ========== BÖLÜM 4 — MAIN FONKSİYONU (main.cpp) ==========
// Burada örnek bir binary tree oluşturup max ve min değer bulunur.
/////////////////////////////////////////////////////////////

int main() {

    // Ağaç yapısı oluşturuluyor:
    //            2
    //          /   \
    //         7     5
    //          \     \
    //           6     9
    //          / \    /
    //         1  11  4

    Node* root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);

    root->left->right = new Node(6);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(11);

    root->right->right = new Node(9);
    root->right->right->left = new Node(4);

    cout << "Maximum value in tree = " << findMax(root) << endl;
    cout << "Minimum value in tree = " << findMin(root) << endl;

    return 0;
}

