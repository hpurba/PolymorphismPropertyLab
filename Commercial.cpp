//
// Created by Hikaru Purba on 12/9/20.
//
#include <iomanip>
#include "Commercial.h"
using namespace std;

Commercial::Commercial(const bool rental, const int estimatedValue, const string& propertyId, const bool discounted,
                       const double discountRate) : Property(rental, estimatedValue, propertyId) {
    this->rental = rental;
    this->estimatedValue = estimatedValue;
    this->propertyId = propertyId;
    this->discounted = discounted;
    this->discountRate = discountRate;
}

const string Commercial::ToString(){
    cout << fixed;
    cout << setprecision(2);

    std::stringstream ss;

    string rentalString = "Rental. ";
    if(rental == false) {
        rentalString = "NOT rental. ";
    }

    // print out the property
    ss << "Address: " << propertyId << ". " << rentalString << "Estimated value: " << estimatedValue << ". A Commercial Property. ";

    string discountString = "NOT in a discount zone.";
    if(discounted == true) {
        discountString = "In a discount zone with discount of: ";
        ss << discountString;
        ss << discountRate << "%.";
    }
    else {
        ss << discountString;
    }
    ss << endl;
    return ss.str();
}

const double Commercial::getTaxes(){
    double tax = 0;
    if (rental){
        tax = 0.012 * estimatedValue;
    }
    else {
        tax = 0.01 * estimatedValue;
    }

    if (discounted){
        return tax - (tax * discountRate);
    }
    else {
        return tax;
    }
}

Commercial::~Commercial() {}