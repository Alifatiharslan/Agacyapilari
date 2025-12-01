#ifndef BAGLILISTELER3_LINKEDLIST_H     // Header guard: dosyanın iki kez eklenmesini önler
#define BAGLILISTELER3_LINKEDLIST_H


// ===============================================================
// NODE SINIFI
// Dairesel çift yönlü bağlı listenin temel yapı taşıdır.
// Her düğüm 3 şey taşır:
// - data : veri
// - next : bir sonraki düğümü gösterir
// - prev : bir önceki düğümü gösterir
// ===============================================================
class Node {
public:
    int data;               // Düğümün tuttuğu veri
    Node* next;             // Sonraki düğüme pointer
    Node* prev;             // Önceki düğüme pointer

    // Constructor: yeni düğüm oluşturur ve bağlantıları null yapar
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


// ===============================================================
// LinkedLiS SINIFI (Circular Doubly Linked List)
// Bu sınıf dairesel çift yönlü bağlı listenin tüm işlemlerini içerir:
// • Başa ekleme (push_front)
// • Sona ekleme (push_back)
// • Araya ekleme (insert_after)
// • Baştan silme (pop_front)
// • Değere göre silme (delete_Node)
// • Listeyi yazdırma (print_list)
// • Arama (Search)
//
// head → listenin başını gösterir
// tail → listenin sonunu gösterir
// Circular yapı sayesinde tail->next = head ve head->prev = tail olur
// ===============================================================
class LinkedLiS {

private:

    Node* head;             // Listenin ilk düğümünü tutar
    Node* tail;             // Listenin son düğümünü tutar (dairesel yapıda önemli)

public:
    LinkedLiS();            // Constructor: listeyi boş şekilde başlatır
    ~LinkedLiS();           // Destructor: bellek temizliği için kullanılır

    void push_front(int value);                 // Listenin başına ekleme
    void push_back(int value);                  // Listenin sonuna ekleme
    void insert_after(int aftervalue, int newvalue); // Verilen değerden sonra ekleme
    void pop_front();                           // Baş düğümü silme
    void delete_Node(int value);                // Verilen değere sahip düğümü silme
    void print_list();                          // Listeyi ekrana yazdırma
    void Search(int value);                     // Listede değer arama

};

#endif //BAGLILISTELER3_LINKEDLIST_H       // Header guard bitişi
