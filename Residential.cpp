//
// Created by Hikaru Purba on 12/9/20.
//
#include <iostream>
#include <iomanip>
#include "Residential.h"

using namespace std;

const string Residential::ToString(){
    cout << fixed;
    cout << setprecision(2);

    std::stringstream ss;

    string rentalString = "Rental. ";
    if(rental == false) {
        rentalString = "NOT rental. ";
    }

    string occupiedString = "Occupied.";
    if(occupied == false) {
        occupiedString = "NOT occupied.";
    }

    ss << "Address: " << propertyId << ". " << rentalString << "Estimated value: " << estimatedValue << ". A Residential Property. " << occupiedString << endl;
    return ss.str();
}

const double Residential::getTaxes(){
    if(occupied) {
        return 0.006 * estimatedValue;
    }
    else {
        return 0.009 * estimatedValue;
    }
}

Residential::Residential(const bool rental, const int estimatedValue, const string &propertyId, const bool occupied) : Property(rental, estimatedValue, propertyId) {
    this->rental = rental;
    this->estimatedValue = estimatedValue;
    this->propertyId = propertyId;
    this->occupied = occupied;
}