//
// Created by Hikaru Purba on 12/9/20.
//

#ifndef EXTRACREDITLAB9_PROPERTY_H
#define EXTRACREDITLAB9_PROPERTY_H

#include <iostream>
#include <string>
using namespace std;

class Property {
protected:
    bool rental;
    double estimatedValue;
    string propertyId;

public:
    Property(bool rental, int estimatedValue, const string& propertyId);
    ~Property();

    bool isRental() const;
    int getEstimatedValue() const;
    string getPropertyId() const;
    virtual const string ToString();
    virtual const double getTaxes();
};


#endif //EXTRACREDITLAB9_PROPERTY_H