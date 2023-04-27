#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include "Car.h"
#include "MaxHeap.h"
#include "b-tree.h"
#include <iterator>


map<string, vector<Car>> cars;
void parseFile(string fileName, int priceUser, string frameUser, string colorUser);

int main() {
    int price;
    string frame;
    string color;
    cout << "Please enter your maximum price: ";
    cin >> price;
    cout << "Please enter your desired frame: ";
    cin >> frame;
    cout << "Please enter your desired color: ";
    cin >> color;
    cout << endl;

    parseFile("car_data.txt", price, frame, color);

    return 0;
}

void getTopGraph(){
    vector<Car> bestCars;
    map<string, vector<Car>>::iterator itr;

    for(itr = cars.begin(); itr != cars.end(); itr++){
        for(int i = 0; i < itr->second.size(); i++) {
            if (bestCars.size() < 3) {
                bestCars.push_back(itr->second[i]);
            }
            else if (itr->second[i].totalScore > bestCars[0].totalScore){
                bestCars[0] = itr->second[i];
            }
            else if (itr->second[i].totalScore > bestCars[1].totalScore){
                bestCars[1] = itr->second[i];
            }
            else if (itr->second[i].totalScore > bestCars[2].totalScore){
                bestCars[2] = itr->second[i];
            }
        }
    }
    cout << "Graph:" << endl;
    for(int i = 0; i < bestCars.size(); i++){
        cout << (i+1) << ". ";
        bestCars[i].PrintInfo();
    }
    cout << endl;
}

void parseFile(string fileName, int priceUser, string frameUser, string colorUser) {
    string line;
    ifstream file(fileName);
    MaxHeap heap;
    BTree tree;

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
        tempCar.getTotalScore(frameUser, colorUser, priceUser);
        heap.insert(tempCar);
        cars[make].push_back(tempCar);
    }
    cout << "Based on your preferences these are our top recommendations: " << endl;
    getTopGraph();
    heap.print();

}