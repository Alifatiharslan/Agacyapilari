#include <iostream> // Giriş/Çıkış işlemleri (cout, cin)
#include <cstdlib>  // Rastgele sayı üretme fonksiyonları (rand, srand)
#include <ctime>    // time() fonksiyonu için (rastgele seed ayarlamak için)

using namespace std;

int main() {
    // 1. Kullanıcıdan bir tam sayı (n) alın.
    int n;
    cout << "Lütfen dizinin eleman sayısını (n) girin: ";
    cin >> n;  // Kullanıcının girdiği eleman sayısı

    // Geçersiz giriş kontrolü
    if (n <= 0) {
        cout << "Geçersiz eleman sayısı girdiniz. Program sonlandırılıyor." << endl;
        return 1;  // Hatalı giriş -> programı sonlandır
    }

    // --- Bellek Ayırma ---
    int *dinamikDizi = nullptr; // İşaretçi başlangıçta boş (nullptr)

    try {
        dinamikDizi = new int[n]; // 'new' ile n elemanlık dinamik dizi oluşturma
    } catch (const bad_alloc& e) {
        // Bellek ayırma başarısız olursa yakalanır
        cerr << "Hata: Bellek ayrılamadı. " << e.what() << endl;
        return 1;
    }

    srand(time(0)); // Rastgele sayı üreteci için seed belirleme

    // 3. Dinamik diziyi rastgele sayılarla doldur ve ekrana yazdır
    cout << "\nOluşturulan Dinamik Dizi Elemanları:" << endl;

    for (int i = 0; i < n; ++i) {
        dinamikDizi[i] = rand() % 100; // 0–99 arasında rastgele sayı
        cout << "Dizi[" << i << "] = " << dinamikDizi[i] << endl;
    }

    // --- Belleği Serbest Bırakma ---
    delete[] dinamikDizi; // Dizinin belleğini geri iade et
    dinamikDizi = nullptr; // Sarkan işaretçi (dangling pointer) oluşmaması için null yap

    cout << "\nAyırılan bellek delete[] operatörü ile sisteme geri iade edildi." << endl;
    cout << "Bellek sızıntısı (memory leak) önlenmiş oldu." << endl;

    return 0; // Program başarılı şekilde bitti
}
/*Bu kod:

Kullanıcıdan dizi boyutunu alıyor

dinamik bellek (new) kullanarak dizi oluşturuyor

Diziyi rastgele sayılarla dolduruyor

diziyi ekrana yazdırıyor

delete[] ile belleği geri veriyor

Bellek yönetimi açısından örnek bir uygulama.*/