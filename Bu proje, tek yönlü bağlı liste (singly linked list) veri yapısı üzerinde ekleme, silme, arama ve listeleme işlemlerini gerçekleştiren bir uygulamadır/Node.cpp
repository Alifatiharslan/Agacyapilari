#include "LşnkedList.h"
// Header dosyasındaki sınıf tanımlarını içe aktarıyoruz.
// LinkedList sınıfının fonksiyonlarının tanımı burada yapılır.


// =====================================================================
// Constructor – Liste başlangıçta boştur, head = nullptr yapılır
// =====================================================================
LşnkedList::LşnkedList() {
    head = nullptr;  // Listenin başlangıç düğümü yok -> liste boş
}


// =====================================================================
// Destructor – Tüm düğümleri sırayla siler ve bellek sızıntısını önler
// =====================================================================
LşnkedList::~LşnkedList() {
    Node* temp;
    while (head) {           // head NULL olana kadar listeyi dolaş
        temp = head;         // Silinecek düğüm
        head = head->next;   // Bir sonraki düğüme geç
        delete temp;         // Düğümü sil
    }
}


// =====================================================================
// push_front(int value)
// Yeni düğümü listenin başına ekler
// =====================================================================
void LşnkedList::push_front(int value) {
    Node* NewNode = new Node(value); // Yeni düğüm oluştur
    NewNode->next = head;            // Yeni düğüm eski baş düğümü işaret eder
    head = NewNode;                  // Yeni düğüm artık listenin başıdır
}


// =====================================================================
// push_back(int value)
// Listenin SONUNA eleman ekler
// =====================================================================
void LşnkedList::push_back(int value) {
    Node* NewNode = new Node(value);

    if (head == nullptr) {   // Eğer liste boşsa yeni düğüm baş olur
        head = NewNode;
        return;
    }

    Node* temp = head;

    while (temp->next) {     // Listenin sonuna kadar ilerle
        temp = temp->next;
    }

    temp->next = NewNode;    // Son düğümün next pointer’ı yeni düğümü gösterir
}


// =====================================================================
// insert_after(int aftervalue, int newvalue)
// Listenin içinde verilen değeri bulur ve hemen ARKASINA yeni düğüm ekler
// =====================================================================
void LşnkedList::insert_after(int aftervalue, int newvalue) {
    Node* temp = head;

    // aftervalue değerini buluncaya kadar ilerle
    while (temp != nullptr && temp->data != aftervalue) {
        temp = temp->next;
    }

    if (temp == nullptr) {   // Değer bulunmazsa
        std::cout << aftervalue << " bulunamadi" << std::endl;
        return;
    }

    Node* NewNode = new Node(newvalue); // Yeni düğüm oluştur
    NewNode->next = temp->next;         // Yeni düğüm, temp'in sonraki düğümünü işaret eder
    temp->next = NewNode;               // temp düğümünün arkasına eklenir
}


// =====================================================================
// pop_front()
// Listenin BAŞINDAKİ düğümü siler
// =====================================================================
void LşnkedList::pop_front() {
    if (head == nullptr) {             // Liste boşsa silinecek bir şey yok
        std::cout << "Liste bos" << std::endl;
        return;
    }

    Node* temp = head;                 // Baş düğümü geçici değişkende tut
    head = head->next;                 // Baş düğümü bir sonraki düğüme kaydır
    delete temp;                       // İlk düğümü sil
}


// =====================================================================
// delete_Node(int value)
// Verilen değere sahip düğümü siler
// =====================================================================
void LşnkedList::delete_Node(int value) {
    if (head == nullptr) {             // Liste boşsa silme işlemi yapılamaz
        std::cout << "Liste bos" << std::endl;
        return;
    }

    // Eğer silinecek değer listenin başındaysa
    if (head->data == value) {
        Node* temp = head;
        head = head->next;             // Baş düğüm bir sonrakine kayar
        delete temp;
        std::cout << value << " silindi" << std::endl;
        return;
    }

    Node* current = head;

    // Silinecek düğümden bir önceki düğümü bul
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {    // Değer bulunamazsa
        std::cout << value << " listede yok" << std::endl;
        return;
    }

    Node* temp = current->next;        // Silinecek düğüm
    current->next = temp->next;        // Bağlantıyı ileri atlat
    delete temp;                       // Sil
    std::cout << value << " silindi" << std::endl;
}


// =====================================================================
// print_list()
// Listedeki tüm değerleri sırasıyla ekrana yazdırır
// =====================================================================
void LşnkedList::print_list() {
    Node* temp = head;

    while (temp != nullptr) {          // Listenin sonuna kadar ilerle
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}


// =====================================================================
// Search(int value)
// Verilen değeri listede arar
// =====================================================================
void LşnkedList::Search(int value) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == value) {     // Değer bulundu
            std::cout << value << " deger listede var" << std::endl;
            return;
        }
        temp = temp->next;
    }

    std::cout << value << " deger listede yok" << std::endl;
}
