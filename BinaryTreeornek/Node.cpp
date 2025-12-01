#include "Node.h"                         // Node sınıfının tanımı buradan alınır

Node::Node(int value)
    : data(value),                       // Düğümün tuttuğu değer atanır
      left(nullptr),                     // Sol çocuk başlangıçta boş
      right(nullptr) {}                  // Sağ çocuk başlangıçta boş
