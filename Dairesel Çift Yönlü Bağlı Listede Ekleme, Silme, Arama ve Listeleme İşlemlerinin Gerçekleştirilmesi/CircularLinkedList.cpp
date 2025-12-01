#include <iostream>              // Ekran çıktısı için
#include "LinkedList.h"          // Node ve LinkedLiS sınıf tanımları
using namespace std;

LinkedLiS::LinkedLiS() {
    head=nullptr;                // Listenin başı boş
    tail=nullptr;                // Listenin sonu boş
}

LinkedLiS::~LinkedLiS() {
    // BU SÜRÜMDE DEST. BOŞ → İstersen tüm node'ları burada free edebiliriz
}

void LinkedLiS::push_front(int value) {
    Node* newNode = new Node(value);    // Yeni düğüm oluştur

    if (head==nullptr) {                // Liste tamamen boşsa
        head=newNode;                   // Hem head hem tail yeni düğüm olur
        tail=newNode;
        head->next=tail;                // Circular bağlantılar
        tail->prev=head;
        return;
    }

    // Liste boş değilse → Başa ekleme işlemi
    newNode->next=head;                 // Yeni düğüm eski head'i gösterir
    newNode->prev=tail;                 // Yeni düğüm son düğüme bağlanır
    tail->next=newNode;                 // Eski tail'in next'i newNode olur
    head->prev=newNode;                 // Eski head’in prev’i newNode olur
    head=newNode;                       // Yeni head güncellenir
}

void LinkedLiS::push_back(int value) {
    Node* newNode = new Node(value);

    if (head==nullptr) {                // Eğer liste boşsa
        head=newNode;
        tail=newNode;
        head->next=tail;                // Circular bağlantılar
        tail->prev=head;
        return;
    }

    // Liste doluysa → sona ekleme
    newNode->next=head;                 // Yeni düğüm head’e bağlanır
    newNode->prev=tail;                 // Yeni düğüm tail’in arkasına eklenir
    tail->next=newNode;                 // Eski tail’in next’i artık newNode
    head->prev=newNode;                 // Head’in prev’i newNode olur
    tail=newNode;                       // Yeni tail güncellenir
}

void LinkedLiS::insert_after(int aftervalue, int newvalue) {
    if (!head) {                        // Liste boşsa işlem yapılamaz
        std::cout << "Liste bos\n";
        return;
    }

    Node* temp = head;
    bool found = false;

    // Liste dairesel olduğu için do-while ile dolaşılır
    do {
        if (temp->data == aftervalue) { // Eklenecek yer bulundu
            found = true;
            Node* newNode = new Node(newvalue);

            newNode->next = temp->next; // Yeni düğüm araya sıkıştırılır
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;

            if (temp == tail) tail = newNode; // Eğer sona ekleniyorsa tail güncellenir
            break;
        }

        temp = temp->next;              // Bir sonraki düğüme geç

    } while (temp != head);             // Tekrar başa gelince dur

    if (!found) {
        std::cout << "Deger bulunamadi\n";
    }
}

void LinkedLiS::pop_front() {
    if (head==nullptr) {                // Liste boş
        return;
    }

    if (head==tail) {                   // Tek eleman varsa
        delete head;
        head=tail=nullptr;
        return;
    }

    Node* temp=head;                    // Silinecek düğüm
    head=head->next;                    // Yeni head belirlenir
    tail->next=head;                    // Circular bağlantı korunur
    head->prev=tail;

    delete temp;                        // Eski head silinir
}

void LinkedLiS::delete_Node(int value) {
    if (!head) return;                  // Liste boşsa çık

    Node* temp = head;
    Node* prev = tail;                  // Dairesel listede prev = tail baştan başlar
    bool found = false;

    // Tek elemanlı liste kontrolü
    if (head == tail) {
        if (head->data == value) {      // Eğer tek eleman silinecekse
            delete head;
            head = tail = nullptr;
        } else {
            std::cout << "Deger bulunamadi\n";
        }
        return;
    }

    // Tüm listeyi dolaş
    while (true) {
        if (temp->data == value) {      // Silinecek değer bulundu
            found = true;

            prev->next = temp->next;    // Önceki düğümün next’i ayarlanır
            temp->next->prev = prev;    // Sonraki düğümün prev’i ayarlanır

            if (temp == head) head = temp->next;   // Eğer baş düğümse head güncellenir
            if (temp == tail) tail = prev;         // Eğer son düğümse tail güncellenir

            delete temp;
            break;
        }

        if (temp == tail) break;        // Dairesel listeyi tamamen dolaştıysa dur

        prev = temp;                    // Bir önceki düğüm kaydedilir
        temp = temp->next;              // Bir sonraki düğüme geçilir
    }

    if (!found)
        std::cout << "Deger bulunamadi\n";
}

void LinkedLiS::print_list() {
    if (!head) {                        // Liste boşsa yazdırılacak hiçbir şey yok
        std::cout << "Liste bos\n";
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " "; // Veri yazdır
        temp = temp->next;              // Sonraki düğüme geç
    } while (temp != head);             // Başa dönene kadar döngü devam eder

    std::cout << std::endl;
}

void LinkedLiS::Search(int value) {
    if (head==nullptr) {                // Liste boşsa arama yapılamaz
        cout<<"liste bos"<<endl;
        return;
    }

    Node* temp=head;

    if (temp->data==value) {            // Baş düğümde değer bulundu
        cout<<"deger bulundu"<<endl;
        return;
    }

    temp=temp->next;

    while (temp!=head) {                // Tüm listeyi dolaş
        if (temp->data==value) {
            cout<<"deger bulundu"<<endl;
            return;
        }
        temp=temp->next;
    }

    cout<<"deger bulunamadi"<<endl;     // Değer listede yoksa
}
/*
Bu kod, Circular Doubly Linked List üzerinde:

Başa ekleme

Sona ekleme

Araya ekleme

Baştan silme

Değere göre silme

Listeyi yazdırma

Arama

işlemlerini tam daire biçimli çift yönlü bağlı liste mantığı ile yapıyor.*/