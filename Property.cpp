//
// Created by Hikaru Purba on 12/9/20.
//
#include "Property.h"
using namespace std;

Property::Property(const bool rental, const int estimatedValue, const string& propertyId) {
    this->rental = rental;
    this->estimatedValue = estimatedValue;
    this->propertyId = propertyId;
}

// GETTERS
bool Property::isRental() const {
    return rental;
}

int Property::getEstimatedValue() const {
    return estimatedValue;
}

string Property::getPropertyId() const {
    return propertyId;
}

// TO STRING FUNCTION
const string Property::ToString() {
    return 0;
}

// CALCULATES THE TAXES ON PROPERTY
const double Property::getTaxes() {
    return 0;
}

Property::~Property() {
}