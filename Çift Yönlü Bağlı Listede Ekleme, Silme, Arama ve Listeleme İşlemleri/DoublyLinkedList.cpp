#include <iostream>              // Ekrana yazdırma için gerekli kütüphane
#include "LinkedList.h"          // LinkedList sınıfının tanımlı olduğu header dosyası
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;              // Listenin başı yok → liste boş
    tail = nullptr;              // Listenin sonu yok → liste boş
}

LinkedList::~LinkedList() {
    // Şu an boş bırakılmış; istersek burada tüm node'ları free edebiliriz
    // Ama proje mantığında destructor içeriği daha önce verilen örneklerde vardı.
}


// =====================================================================
// push_front() → Listenin BAŞINA eleman ekler
// =====================================================================
void LinkedList::push_front(int value) {
    Node *newNode = new Node(value);   // Yeni düğüm oluştur

    if (head == nullptr) {             // Liste tamamen boşsa
        head = newNode;                // Head yeni düğüm olur
        // tail burada da newNode yapılmalı ama senin kod mantığında tail push_back ile set ediliyor
    } else {                            // Liste boş değilse
        head->prev = newNode;          // Eski baş düğümün prev'i yeni düğümü gösterir
        newNode->next = head;          // Yeni düğümün next'i eski baş düğümü gösterir
        head = newNode;                // Yeni düğüm artık listenin başıdır
    }
}


// =====================================================================
// push_back() → Listenin SONUNA eleman ekler
// =====================================================================
void LinkedList::push_back(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {             // Eğer liste boşsa
        head = tail = newNode;         // Hem head hem tail yeni düğüm olur
    } else {
        newNode->prev = tail;          // Yeni düğümün prev'i eski tail'e bağlanır
        tail->next = newNode;          // Eski tail'in next'i yeni düğüm olur
        tail = newNode;                // Yeni düğüm artık tail'dir (listenin sonudur)
    }
}


// =====================================================================
// insert_after() → Belirli bir değerden SONRA yeni düğüm ekler
// =====================================================================
void LinkedList::insert_after(int aftervalue, int newvalue) {
    Node *temp = head;

    // aftervalue değerine sahip düğümü bulmak için ilerle
    while (temp != nullptr && temp->data != aftervalue) {
        temp = temp->next;
    }

    if (temp == nullptr) {             // Değer bulunamazsa
        std::cout << "liste bos" << std::endl;
        return;
    }

    Node *newNode = new Node(newvalue);   // Yeni düğüm oluştur

    newNode->next = temp->next;        // Yeni düğümün next'i temp'in eski next'i olur
    newNode->prev = temp;              // Yeni düğümün prev'i temp'i gösterir

    if (temp->next != nullptr) {       // Eğer temp son düğüm değilse
        temp->next->prev = newNode;    // temp'in next'inin prev'i yeni düğümü gösterir
    }

    temp->next = newNode;              // temp'in next'i yeni düğüm olur

    if (temp == tail) {                // Eğer eklendiği yer tail ise
        tail = newNode;                // Yeni düğüm tail olur
    }
}


// =====================================================================
// pop_front() → Listenin BAŞINDAKİ düğümü siler
// =====================================================================
void LinkedList::pop_front() {
    if (head == nullptr) {                         // Liste boşsa
        std::cout << "liste bos" << std::endl;
        return;
    }

    Node *temp = head;                             // Silinecek düğüm

    head = head->next;                             // Head bir sonraki düğüme geçer

    if (head != nullptr) {
        head->prev = nullptr;                      // Yeni head'in prev'i NULL yapılır
    } else {
        tail = nullptr;                            // Liste tamamen boşaldıysa tail de null yapılır
    }

    delete temp;                                   // Eski baş düğümü sil
}


// =====================================================================
// delete_Node() → Verilen değeri içeren düğümü listeden siler
// =====================================================================
void LinkedList::delete_Node(int value) {
    Node *temp = head;

    // Silinecek düğümü bulmak için ilerle
    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {                         // Değer bulunamadıysa
        std::cout << "listede yok" << std::endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;             // Önceki düğümün next'ini ayarla
    } else {
        head = temp->next;                         // Silinen düğüm baş ise head güncellenir
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;             // Sonraki düğümün prev'ini ayarla
    } else {
        tail = temp->prev;                         // Silinen düğüm son ise tail güncellenir
    }

    delete temp;                                   // Düğümü bellekten sil
}


// =====================================================================
// print_list() → Listedeki elemanları sırayla yazdırır
// =====================================================================
void LinkedList::print_list() {
    Node *temp = head;

    while (temp != nullptr) {                      // Listenin sonuna kadar ilerle
        std::cout << temp->data << " ";            // Düğümün datasını yazdır
        temp = temp->next;                         // Bir sonraki düğüme geç
    }

    std::cout << std::endl;
}


// =====================================================================
// Search() → Değeri listede arar ve bulunup bulunmadığını yazdırır
// =====================================================================
void LinkedList::Search(int value) {
    Node *temp = head;

    while (temp != nullptr) {
        if (temp->data == value) {                 // Değer bulundu
            std::cout << value << " deger listede var ";
            return;
        }
        temp = temp->next;                         // Sonraki düğüme geç
    }

    std::cout << value << " deger listede yok " << std::endl;  // Bulunamazsa
}
/*
Bu Dosya Ne Yapıyor?

Bu .cpp dosyası doubly linked list üzerinde:

Başa ekleme

Sona ekleme

Araya ekleme

Baştan silme

Değere göre silme

Listeyi yazdırma

Arama

gibi tüm işlemlerin gerçek çalıştığı yerdir.

Listeyi yöneten tüm algoritmalar burada uygulanır.
*/