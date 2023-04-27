#ifndef AUTOGENIUS_MAXHEAP_H
#define AUTOGENIUS_MAXHEAP_H
#include "Car.h"
#include <vector>

class MaxHeap{
    vector<Car> cars;
public:
    //MaxHeap();
    void insert(Car car);
    void print();
};
/*
MaxHeap::MaxHeap() {
    cars.clear();
}*/

void MaxHeap::insert(Car car) {
    cars.push_back(car);
    int i = cars.size()-1;
    while(i > 0 && cars[(i - 1) / 2].totalScore < cars[i].totalScore) {
        swap(cars[(i - 1) / 2], cars[i]);
        i = (i - 1) / 2;
    }
}

void MaxHeap::print() {
    cout << "Max Heap:" << endl;
    for(int i = 0; i < 3; i++){
        cout << (i+1) << ". ";
        cars[i].PrintInfo();
    }
}

#endif //AUTOGENIUS_MAXHEAP_H
