// ================================================================
// PROJE ADI: Bağlı Listede (Linked List) Ekleme, Silme ve Arama İşlemleri
// AÇIKLAMA: Bu program, kullanıcının bağlı liste üzerinde
//           başa ekleme, sona ekleme, baştan silme, listeleme
//           ve eleman arama işlemlerini menü tabanlı olarak yapmasına izin verir.
// ================================================================

#include <iostream>           // Girdi / çıktı fonksiyonları için
#include "LşnkedList.h"       // LinkedList sınıfının tanımlı olduğu header dosyası
using namespace std;          // std:: yazmayı kaldırmak için

int main() {

    LşnkedList list;          // LinkedList sınıfından bir nesne oluşturulur
    int choice, value;        // Menü seçimi ve kullanıcıdan alınacak değer

    while (true) {            // Sonsuz döngü — kullanıcı çıkış seçeneğini seçene kadar devam eder

        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Basa ekle\n";          // Listenin başına eleman ekler
        cout << "2. Sona ekle\n";          // Listenin sonuna eleman ekler
        cout << "3. Bastan sil\n";         // Listenin başındaki elemanı siler
        cout << "4. Listeyi yazdir\n";     // Tüm listeyi ekrana yazdırır
        cout << "5. Deger ara\n";          // Listenin içinde bir değer arar
        cout << "6. Cikis\n";              // Programı sonlandırır
        cout << "Seciminiz: ";
        cin >> choice;                     // Kullanıcı tercih yapar

        switch (choice) {                  // Kullanıcının seçimine göre işlem yapılır

            case 1:                        // 1 → Başa ekleme işlemi
                cout << "Basa eklenecek degeri girin: ";
                cin >> value;
                list.push_front(value);    // push_front: başa yeni düğüm ekler
                list.print_list();         // Güncel listeyi göster
                break;

            case 2:                        // 2 → Sona ekleme işlemi
                cout << "Sona eklenecek degeri girin: ";
                cin >> value;
                list.push_back(value);     // push_back: sona yeni düğüm ekler
                list.print_list();
                break;

            case 3:                        // 3 → Baştaki düğümü silme
                list.pop_front();          // pop_front: ilk düğümü listeden kaldırır
                cout << "Bas ogesi silindi.\n";
                list.print_list();
                break;

            case 4:                        // 4 → Listeyi ekrana yazdırma
                cout << "Liste: ";
                list.print_list();
                break;

            case 5:                        // 5 → Eleman arama işlemi
                cout << "Aranacak degeri girin: ";
                cin >> value;
                list.Search(value);        // Arama fonksiyonu çağrılır
                break;

            case 6:                        // 6 → Programı sonlandır
                cout << "Program sonlandiriliyor.\n";
                return 0;

            default:                        // Geçersiz seçim yapıldığında
                cout << "Gecersiz secim!\n";
        }
    }

    return 0;
}
