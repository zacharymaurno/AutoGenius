#include <string>
#ifndef AUTOGENIUS_CAR_H
#define AUTOGENIUS_CAR_H


using namespace std;

class Car {
private:
    string make;
    string model;
    string frame;
    int year;
    int mileage;
    string color;
    int price;
    double safetyFactor;
    double totalScore = 0;
public:
    Car(string make,string model,string frame, int year, int mileage, string color, int price);
    void getTotalScore(string preferredFrame, string preferredColor, int maxPrice);
    void bruteForce();
    void dijkstra();

};

#endif //AUTOGENIUS_CAR_H