//
// Created by Hikaru Purba on 12/9/20.
//

#ifndef EXTRACREDITLAB9_RESIDENTIAL_H
#define EXTRACREDITLAB9_RESIDENTIAL_H

#include "Property.h"
using namespace std;

class Residential : public Property {
private:
    bool occupied;
public:
    Residential(const bool rental, const int estimatedValue, const string &propertyId, const bool occupied);
    ~Residential();

    const string ToString();
    const double getTaxes();
};
#endif //EXTRACREDITLAB9_RESIDENTIAL_H