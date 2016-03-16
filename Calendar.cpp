//
// Created by yifat biezuner on 15/03/2016.
//

#include "Calendar.h"
#include <iostream>
using namespace std;
#define MEX_ARRAY_SIZE 30
#define ARRAY_FULL 0
Calendar::Calendar() { }
void Calendar::setDate(int num, MyDate& my_date) {
    m_dates[num] = &my_date;
}
void Calendar::printCell(const int num) const {
    cout<<num<<" : ";
    if(!isFree(num)){
        (*m_dates[num]).print();
    }else{
        cout<<"this cell is empty"<<endl;
    }
}
bool Calendar::isFree(int num)const {
    if(0<=num&&num<=MEX_ARRAY_SIZE){
        return m_dates[num]== nullptr;
    }
    return false;
}
int Calendar::firstFree(){
    for (int i = 0; i <MEX_ARRAY_SIZE+1 ; ++i) {
        if(isFree(i)){ return i+1;}
    }
    return ARRAY_FULL;
}
void Calendar::fillAllWithVal(MyDate &my_date) {
    for (int i = 0; i <MEX_ARRAY_SIZE+1 ; ++i) {
        setDate(i,my_date);
    }
}
void Calendar::deleteAll() {
    for (int i = 0; i < MEX_ARRAY_SIZE; ++i) {
        deleteDate(i);
    }
}
void Calendar::deleteDate(int num) {
//    delete m_dates[num];
    m_dates[num]= nullptr;
}
bool Calendar::insert(MyDate &my_date) {
    int firstFreeCell = firstFree();
    if(firstFreeCell!=ARRAY_FULL){
        setDate(firstFreeCell-1,my_date);
        return true;
    }
    return false;
}
void Calendar::print() {
    if(firstFree()==1){
        cout<<"Empty Calendar"<<endl;
    }else{
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            printCell(i);
        }
    }
}
