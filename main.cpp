// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

int partition(vector<Property *> &vector, int low, int high);

void quicksort(vector<Property *> &vector, int i, int i1);

using namespace std;

int main () {
    vector<Property*> properties;
    string inputFileName;
    string line;

    cout << "starting..." << endl;
    cout << "Where should I read the data from: ";
    cin >> inputFileName;
    cout << endl << endl;

    ifstream myfile(inputFileName.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            stringstream ss(line);
            string propertyType;
            ss >> propertyType; // gets the property type

            // Residential Property Case
            if(propertyType == "Residential") {
                string rentalStr;
                bool rental = false;
                string estimatedPropertyValueStr;
                double estimatedPropertyValue;
                string occupiedStr  = "no";
                bool occupied = false;
                string propertyID;

                // Rental or not
                ss >> rentalStr;
                if (rentalStr == "yes") {
                    rental = true;
                }

                // Property Value
                ss >> estimatedPropertyValueStr;
                estimatedPropertyValue = atof(estimatedPropertyValueStr.c_str());

                // Occupied(yes) or vacant(no)
                ss >> occupiedStr;
                if (occupiedStr == "yes") {
                    occupied = true;
                }

                // one-word property ID
                ss >> propertyID;

                // Adds a residential property to the
                properties.push_back(new Residential(rental, estimatedPropertyValue, propertyID, occupied));
            }
            // Commercial Property Case
            else {
                string rentalStr;
                bool rental = false;
                string estimatedPropertyValueStr;
                double estimatedPropertyValue;
                string taxesDiscountedStr = "no";
                bool taxesDiscounted = false;
                string discountRateStr;
                double discountRate;
                string propertyID;

                // Rental or not
                ss >> rentalStr;
                if (rentalStr == "yes") {
                    rental = true;
                }

                // Property Value
                ss >> estimatedPropertyValueStr;
                estimatedPropertyValue = atof(estimatedPropertyValueStr.c_str());

                // Occupied(yes) or vacant(no)
                ss >> taxesDiscountedStr;
                if (taxesDiscountedStr == "yes") {
                    taxesDiscounted = true;
                }

                // Discount Rate
                ss >> discountRateStr;
                discountRate = atof(discountRateStr.c_str()) / 100;

                // one-word property ID
                ss >> propertyID;

                // Adds a residential property to the
                properties.push_back(new Commercial(rental, estimatedPropertyValue, propertyID, taxesDiscounted, discountRate));
            }
        }
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }

    // Print out all properties
    cout << "All properties:" << endl;
    for(unsigned int i = 0; i < properties.size(); i ++) {
        cout << properties[i]->ToString();
    }
    cout << endl;

    // TAX REPORT
    cout << "TAX REPORT:" << endl;
    for(unsigned int i = 0; i < properties.size(); i ++) {
        cout << fixed;
        cout << setprecision(2);
        double propertyValue =  properties[i]->getEstimatedValue();
        double propertyTax = properties[i]->getTaxes();
        cout << "** Taxes due on property at: " << properties[i]->getPropertyId() << endl;
        cout << "  This property has an estimated value of: " << propertyValue << endl;
        cout << "  Taxes due on this property are: " << propertyTax << endl << endl;
    }

    // Writing Report to File
    string writeFilePath;
    cout << "Where should I write the report (just press return to skip): ";
    cin >> writeFilePath;

    ofstream myoutputFile(writeFilePath);
    if (myoutputFile.is_open())
    {
        // Print out all properties
        myoutputFile << "All properties:" << endl;
        for(unsigned int i = 0; i < properties.size(); i ++) {
            myoutputFile << properties[i]->ToString();
        }
        myoutputFile << endl;

        myoutputFile << "TAX REPORT:" << endl;
        for(unsigned int i = 0; i < properties.size(); i ++) {
            myoutputFile << fixed;
            myoutputFile << setprecision(2);
            double propertyValue =  properties[i]->getEstimatedValue();
            double propertyTax = properties[i]->getTaxes();
            myoutputFile << "** Taxes due on property at: " << properties[i]->getPropertyId() << endl;
            myoutputFile << "  This property has an estimated value of: " << propertyValue << endl;
            myoutputFile << "  Taxes due on this property are: " << propertyTax;
            if(i != (properties.size() - 1)){
                myoutputFile << endl << endl;
            }
        }
        myoutputFile.close();
    }
    else {
        cout << "Unable to open file to write to.";
    }
    cout << endl << endl;

    // Quicksort the properties by taxes due
    int size = properties.size() - 1;
    quicksort(properties, 0, size);

    // SORTED VERSION OF TAX REPORT
    cout << "SORTED VERSION:" << endl << endl;
    // TAX REPORT
    cout << "TAX REPORT:" << endl;
    for(unsigned int i = 0; i < properties.size(); i ++) {
        cout << fixed;
        cout << setprecision(2);
        double propertyValue =  properties[i]->getEstimatedValue();
        double propertyTax = properties[i]->getTaxes();
        cout << "** Taxes due on property at: " << properties[i]->getPropertyId() << endl;
        cout << "  This property has an estimated value of: " << propertyValue << endl;
        cout << "  Taxes due on this property are: " << propertyTax;
        if(i != (properties.size() - 1)){
            cout << endl << endl;
        }
    }
    return 0;
}

void quicksort(vector<Property *> &properties, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(properties, left, right);
        quicksort(properties, left, (pivotIndex - 1));
        quicksort(properties, pivotIndex, right);
    }
}

int partition(vector<Property *> &properties, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    double pivotValue = properties[pivotIndex]->getTaxes();
    int i = left, j = right;
    Property* temp;
    while(i <= j) {
        while(properties[i]->getTaxes() < pivotValue) {
            i++;
        }
        while(properties[j]->getTaxes() > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = properties[i];
            properties[i] = properties[j];
            properties[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
