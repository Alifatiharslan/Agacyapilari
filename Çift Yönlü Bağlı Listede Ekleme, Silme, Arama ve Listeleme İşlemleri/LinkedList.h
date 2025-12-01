//
// Created by yossu on 29.11.2025.
//  → Dosyanın otomatik oluşturulma bilgisi
//

#ifndef BAGLILISTELER2_LINKEDLIST_H     // Header guard – dosyanın iki kez eklenmesini önler
#define BAGLILISTELER2_LINKEDLIST_H

// =====================================================================
// NODE SINIFI
// Doubly Linked List düğüm yapısıdır. Her düğüm:
// - data: veri tutar
// - next: bir sonraki düğüme işaret eder
// - prev: bir önceki düğüme işaret eder
// =====================================================================
class Node {
public:
    int data;              // Düğümün tuttuğu tam sayı veri
    Node* next;            // Bir sonraki düğüme işaret eden pointer
    Node* prev;            // Bir önceki düğüme işaret eden pointer

    // Constructor – yeni bir node oluşturur, next ve prev başlangıçta null yapılır.
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};


// =====================================================================
// LINKEDLIST SINIFI (DOUBLY LINKED LIST)
// Bu sınıf çift yönlü bağlı listenin tüm işlemlerini gerçekleştirir:
// - Başa ekleme
// - Sona ekleme
// - Araya ekleme
// - Baştan silme
// - Veri silme
// - Yazdırma
// - Arama
// Liste hem head (baş) hem tail (son) pointer'ı tutar → O(1) ekleme avantajı sağlar
// =====================================================================

class LinkedList {
private:
    Node* head;            // Listenin ilk düğümünü işaret eder
    Node* tail;            // Listenin son düğümünü işaret eder (doubly list avantajı)

public:
    LinkedList();          // Constructor – başlangıçta head ve tail nullptr yapılır
    ~LinkedList();         // Destructor – listeyi bellekte temizler (memory leak önlenir)

    void push_front(int value);             // Listenin başına eleman ekler
    void push_back(int value);              // Listenin sonuna eleman ekler
    void insert_after(int aftervalue, int newvalue); // Belirli bir değerin ARKASINA yeni eleman ekler
    void pop_front();                       // Baş düğümü listeden siler
    void delete_Node(int value);            // Verilen değere sahip düğümü siler
    void print_list();                      // Listeyi baştan sona ekrana yazdırır
    void Search(int value);                 // Verilen değeri listede arar
};

#endif // BAGLILISTELER2_LINKEDLIST_H
//Bu dosya, çift yönlü bağlı liste için Node ve LinkedList sınıflarının tanımlarını içerir.