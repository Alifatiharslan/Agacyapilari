#include <iostream>                 // Giriş-çıkış işlemleri için gerekli kütüphane
#include "LinkedList.h"             // LinkedLiS sınıfının tanımlı olduğu header dosyası
using namespace std;

int main() {
    LinkedLiS list;                 // Dairesel çift yönlü bağlı liste nesnesi oluşturuluyor
    int secim, value, aftervalue;   // Menü seçimi ve kullanıcıdan alınacak değerler

    while (true) {                  // Sürekli çalışan menü döngüsü
        cout << "\n--- Dairesel Bagli Liste Menu ---\n";
        cout << "1 - Basa eleman ekle (push_front)\n";    // Listenin başına ekleme
        cout << "2 - Sona eleman ekle (push_back)\n";      // Listenin sonuna ekleme
        cout << "3 - Araya ekle (insert_after)\n";         // Belirli bir değerden sonra ekleme
        cout << "4 - Bastan sil (pop_front)\n";            // Listenin başındaki düğümü silme
        cout << "5 - Eleman sil (delete_Node)\n";          // Değere göre düğüm silme
        cout << "6 - Listeyi yazdir (print_list)\n";       // Listeyi ekrana yazdırma
        cout << "7 - Eleman ara (Search)\n";               // Listede değer arama
        cout << "0 - Cikis\n";                             // Programı sonlandırma
        cout << "Secim: ";
        cin >> secim;                                      // Kullanıcının menü seçimi alınır

        switch (secim) {                                   // Seçime göre işlem yapılır

            case 1:                                        // BAŞA ekleme işlemi
                cout << "Eklenecek deger: ";
                cin >> value;
                list.push_front(value);                    // push_front çağrılır
                break;

            case 2:                                        // SONA ekleme işlemi
                cout << "Eklenecek deger: ";
                cin >> value;
                list.push_back(value);                     // push_back çağrılır
                break;

            case 3:                                        // Araya ekleme işlemi
                cout << "Hangi degerden sonra ekleyeceksin? ";
                cin >> aftervalue;
                cout << "Eklenecek deger: ";
                cin >> value;
                list.insert_after(aftervalue, value);       // insert_after çağrılır
                break;

            case 4:                                        // Listenin başını silme işlemi
                list.pop_front();                           // pop_front çağrılır
                cout << "Bastan eleman silindi.\n";
                break;

            case 5:                                        // Değere göre silme işlemi
                cout << "Silinecek deger: ";
                cin >> value;
                list.delete_Node(value);                    // delete_Node çağrılır
                break;

            case 6:                                        // Listeyi yazdırma işlemi
                cout << "Liste: ";
                list.print_list();                          // Tüm düğümler ekrana yazdırılır
                break;

            case 7:                                        // Arama işlemi
                cout << "Aranacak deger: ";
                cin >> value;
                list.Search(value);                         // Search fonksiyonu çağrılır
                break;

            case 0:                                        // Programdan çıkış
                cout << "Cikis yapildi.\n";
                return 0;                                  // Program sonlanır

            default:                                       // Geçersiz menü seçimi
                cout << "Hatali secim!\n";
        }
    }

    return 0;                                               // Normal çıkış
}
/*Bu main dosyası, dairesel çift yönlü bağlı liste üzerinde aşağıdaki işlemleri yapman için bir kullanıcı menüsü oluşturuyor:

Baştan ekleme

Sondan ekleme

Araya ekleme

Baştan silme

Değere göre silme

Listeyi yazdırma

Arama

Çıkış

Her menü seçeneği, LinkedLiS sınıfındaki ilgili fonksiyonları çağırıyor.*/