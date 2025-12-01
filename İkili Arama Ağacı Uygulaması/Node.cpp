#include "Node.h"
// Node sınıfının tanımını içeren header dosyası dahil edilir.
// Böylece burada constructor’un gerçek uygulanmasını yapabiliriz.


// ======================================================================
// Node Constructor
// Bir düğüm oluşturulduğunda:
//  - data = value  → düğümün tuttuğu değer
//  - left = nullptr → sol çocuk başlangıçta boş
//  - right = nullptr → sağ çocuk başlangıçta boş
//
// Bu yapıyla ikili arama ağacının her bir düğümü oluşturulmuş olur.
// ======================================================================
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}
