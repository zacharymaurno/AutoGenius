#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include "Car.h"
#include "MaxHeap.h"

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

    cout << "        _______\n"
            "       //  ||\\ \\\n"
            " _____//___||_\\ \\___\n"
            " )  _          _    \\\n"
            " |_/ \\________/ \\___|\n"
            "___\\_/________\\_/______" << endl;
    cout << endl;

    parseFile("car_data.txt", price, frame, color);

    return 0;
}

void printMap(string frame){
    vector<Car> bestCars;

    for(int i = 0; i < cars[frame].size(); i++) {
        if (bestCars.size() < 3) {
            bestCars.push_back(cars[frame].at(i));
        }
        else if (cars[frame].at(i).totalScore >= bestCars[0].totalScore){
            bestCars[2] = bestCars[1];
            bestCars[1] = bestCars[0];
            bestCars[0] = cars[frame].at(i);

        }
        else if (cars[frame].at(i).totalScore >= bestCars[1].totalScore){
            bestCars[2] = bestCars[1];
            bestCars[1] = cars[frame].at(i);
        }
        else if (cars[frame].at(i).totalScore >= bestCars[2].totalScore){
            bestCars[2] = cars[frame].at(i);
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
        cars[frame].push_back(tempCar);
    }
    cout << "Based on your preferences these are our top recommendations: " << endl;
    printMap(frameUser);
    heap.print();

}