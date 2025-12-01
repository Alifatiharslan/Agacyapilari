#include "Node.h"
// Node sınıfının tanımı bu başlık dosyasında bulunduğu için dahil ediyoruz.


// ----------------------------------------------------------------------
// Node::Node(int value)
// Bu constructor, bir düğüm oluşturur ve:
//  - data'ya verilen değeri atar
//  - left ve right işaretçilerinin başlangıçta boş olmasını sağlar
// Böylece yeni oluşturulan düğüm ağaca bağlanmaya hazır hale gelir.
// ----------------------------------------------------------------------
Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}
