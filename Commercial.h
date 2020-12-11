//
// Created by Hikaru Purba on 12/9/20.
//
#ifndef EXTRACREDITLAB9_COMMERCIAL_H
#define EXTRACREDITLAB9_COMMERCIAL_H

#include "Property.h"
using namespace std;

class Commercial : public Property {
private:
    bool discounted;
    double discountRate;
public:
    Commercial(const bool rental, const int estimatedValue, const string& propertyId, const bool discounted, const double discountRate);
    ~Commercial();

    const string ToString();
    const double getTaxes();
};
#endif //EXTRACREDITLAB9_COMMERCIAL_H