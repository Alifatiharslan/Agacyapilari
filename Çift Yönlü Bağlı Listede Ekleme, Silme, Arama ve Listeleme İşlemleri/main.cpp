#include <iostream>              // Girdi ve çıktı işlemleri için gerekli kütüphane
#include "LinkedList.h"          // Doubly Linked List sınıfı burada tanımlı
using namespace std;

int main() {
    LinkedList list;             // LinkedList sınıfından bir liste nesnesi oluşturulur
    int choice, value;           // Kullanıcıdan alınacak seçim ve değer değişkenleri

    while (true) {               // Kullanıcı çıkış yapana kadar çalışan sonsuz döngü
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Basa ekle\n";         // 1 → Listenin başına eleman ekleme
        cout << "2. Sona ekle\n";         // 2 → Listenin sonuna eleman ekleme
        cout << "3. Bastan sil\n";        // 3 → Listenin başındaki düğümü sil
        cout << "4. Listeyi yazdir\n";    // 4 → Tüm listeyi ekrana yaz
        cout << "5. Deger ara\n";         // 5 → Listede değer arama
        cout << "6. Cikis\n";             // 6 → Programı sonlandır
        cout << "Seciminiz: ";
        cin >> choice;                    // Kullanıcı seçimini al

        switch (choice) {                 // Girilen seçeneğe göre ilgili işlem yapılır

            case 1:                       // Kullanıcı 1'e bastıysa → Başa ekle
                cout << "Basa eklenecek degeri girin: ";
                cin >> value;             // Kullanıcı değeri giriyor
                list.push_front(value);   // Değer listenin başına eklenir
                list.print_list();        // Güncel liste yazdırılır
                break;

            case 2:                       // Kullanıcı 2'ye bastıysa → Sona ekle
                cout << "Sona eklenecek degeri girin: ";
                cin >> value;
                list.push_back(value);    // Değer listenin sonuna eklenir
                list.print_list();        // Liste yazdırılır
                break;

            case 3:                       // Kullanıcı 3'e bastıysa → Baştan sil
                list.pop_front();         // Baş düğüm listeden kaldırılır
                cout << "Bas ogesi silindi.\n";
                list.print_list();        // Liste yeni hâliyle yazdırılır
                break;

            case 4:                       // Kullanıcı 4'e bastıysa → Listeyi yazdır
                cout << "Liste: ";
                list.print_list();        // Tüm düğümler ekrana yazılır
                break;

            case 5:                       // Kullanıcı 5'e bastıysa → Arama işlemi
                cout << "Aranacak degeri girin: ";
                cin >> value;
                list.Search(value);       // Belirtilen değer listede aranır
                break;

            case 6:                       // Kullanıcı 6'ya bastıysa → Programdan çık
                cout << "Program sonlandiriliyor.\n";
                return 0;                 // Programı bitir

            default:                      // Geçersiz bir değer girilirse
                cout << "Gecersiz secim!\n";
        }
    }

}
/*
Kısaca Bu main.cpp ne işe yarıyor?

Kullanıcıya bir menü gösteriyor.

Kullanıcı seçimine göre LinkedList sınıfındaki fonksiyonları çalıştırıyor.

Başa ekleme, sona ekleme, baştan silme, listeleme, arama işlemleri yapılıyor.

Program 6 tuşlanana kadar devam ediyor.
*/