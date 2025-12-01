// ======================================================================
// PROJE ADI: Bağlı Liste (Linked List) Veri Yapısı
// DOSYA: LşnkedList.h
// AÇIKLAMA: Bu dosya, Node sınıfını ve LşnkedList sınıfının metod
//           tanımlarını içerir. Ekleme, silme, arama ve yazdırma
//           işlemleri burada bildirilir.
// ======================================================================

#ifndef LINKEDLIST_H      // Header dosyasının iki kez dahil edilmesini önler
#define LINKEDLIST_H

#include <iostream>        // Input/output işlemleri için gerekli

// ======================================================================
// NODE SINIFI
// Tek yönlü bağlı liste (singly linked list) düğüm yapısı.
// Her düğüm bir veri (data) ve bir sonraki düğümü gösteren işaretçi (next)
// içerir.
// ======================================================================
class Node {
public:
    int data;              // Düğümün tuttuğu değer
    Node* next;            // Bir sonraki düğüme işaret eden pointer

    // Constructor — yeni bir düğüm oluştururken veri atanır,
    // next başlangıçta nullptr yapılır.
    Node(int val) : data(val), next(nullptr) {}
};


// ======================================================================
// LşnkedList SINIFI
// Bu sınıf; başa ekleme, sona ekleme, araya ekleme,
// baştan silme, belli düğümü silme, listeyi yazdırma ve değer arama
// gibi işlemleri gerçekleştiren bağlı listeyi yönetir.
// ======================================================================
class LşnkedList {

private:
    Node* head;            // Listenin ilk düğümünü işaret eden pointer

public:

    LşnkedList();          // Yapıcı fonksiyon (liste başlangıçta boştur)
    ~LşnkedList();         // Yıkıcı fonksiyon (bellek temizliği)

    void push_front(int value);                 // Listenin başına eleman ekler
    void push_back(int value);                  // Listenin sonuna eleman ekler
    void insert_after(int aftervalue, int newvalue); // Belirli bir değerin arkasına ekler
    void pop_front();                           // Listenin başındaki elemanı siler
    void delete_Node(int value);                // Değerine göre düğüm siler
    void print_list();                          // Listeyi ekrana yazdırır
    void Search(int value);                     // Listenin içinde değer arar
};

#endif // LINKEDLIST_H
