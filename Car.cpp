#include "Car.h"
#include <iostream>

Car::Car(string make, string model,string frame, int year, int mileage, string color, int price) {
    this->make = make;
    this->model = model;
    this->frame = frame;
    this->year = year;
    this->mileage = mileage;
    this->color = color;
    this->price = price;
}

void Car::getTotalScore(string preferredFrame, string preferredColor, int maxPrice){
    if(frame == preferredFrame){
        totalScore+= 10;
    }
    if(color == preferredColor){
        totalScore+= 10;
    }
    if(price < maxPrice){
        totalScore+= 10;
    }
    else if (price < 15000){
        totalScore += 7.5;
    }
    else if(price < 20000){
        totalScore += 5;
    }
    else{
        totalScore += 2.5;
    }
    if(year >= 2020){
        totalScore += 10;
    }
    else if(year >= 2017){
        totalScore += 7.5;
    }
    else if(year >= 2014){
        totalScore += 5;
    }
    else{
        totalScore += 2.5;
    }
    totalScore /= 4.0;
    cout << make << " " << model << " " << year << " " << mileage << " " << color << " " << price << " " << totalScore << endl;
}

void Car::bruteForce(){

}

void Car::dijkstra() {

}

