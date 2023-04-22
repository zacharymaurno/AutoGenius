#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include "Car.h"


map<string, vector<Car>> cars;
void parseFile(string fileName);

int main() {
    parseFile("cars_data.txt");
    int price;
    string frame;
    string color;
    cout << "Please enter your maximum price: ";
    cin >> price;
    cout << "Please enter your desired frame: ";
    cin >> frame;
    cout << "Please enter your desired color";
    cin >> color;


    return 0;
}

void parseFile(string fileName) {
    string line;
    ifstream file(fileName);

    while (getline(file, line)) { // Read each line of the file
        string make, model, mileage, year, color, price, frame;

        stringstream ss(line);
        getline(ss, make, ',');
        getline(ss, model, ',');
        getline(ss, frame, ',');
        getline(ss, mileage, ',');
        getline(ss, year, ',');
        getline(ss, color, ',');
        getline(ss, price, ',');

        Car tempCar(make, model, frame, stoi(year), stoi(mileage), color, stoi(price));
        cars[make].push_back(tempCar);
    }

}