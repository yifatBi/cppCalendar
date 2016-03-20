//
// This class is implementation of Calendar.h
// Created by yifat biezuner on 15/03/2016.
//

#include "Calendar.h"
#define MEX_ARRAY_SIZE 30
#define NOT_EXIST 0
using namespace std;
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
bool Calendar::isEmpty() const {
    for (int i = 0; i < MEX_ARRAY_SIZE; ++i) {
        if(!isFree(i)){
            return false;
        }
    }
    return true;
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
    return NOT_EXIST;
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
int Calendar::datesNum(MyDate &_mydate) {
    int dateCounter = 0;
    if(!isEmpty()){
        for (int i = 0; i < MEX_ARRAY_SIZE; ++i) {
           if(m_dates[i]==&_mydate){
               dateCounter++;
           }
        }
    }
    return dateCounter;
}
int Calendar::firstVal() {
    if(isEmpty()){
        return NOT_EXIST;
    }

    for (int i = 0; i < MEX_ARRAY_SIZE; ++i) {
        if(!isFree(i)){
            return i+1;
        }
    }
}
int Calendar::lastVal(){
    if(isEmpty()){
        return NOT_EXIST;
    }
    int firstIndex = firstVal();
    for (int i = (MEX_ARRAY_SIZE-1); i > firstIndex; --i) {
        if(!isFree(i)){
            return i+1;
        }
    }
}
int Calendar::oldest() {
    if(!isEmpty()){
       int indexCurrentOldest = (firstVal() - 1);
        int lastIndex= lastVal();
        for (int i = firstVal(); i < lastIndex; ++i) {
            //If have date in this cell check if before current oldest and update the oldest
            if(!isFree(i)) {
                if ((*m_dates[i]).isBefore(*m_dates[indexCurrentOldest])) {
                    indexCurrentOldest = i;
                }
            }
        }
        return (indexCurrentOldest+1);
    }
    return NOT_EXIST;
}
bool Calendar::insert(MyDate &my_date) {
    int firstFreeCell = firstFree();
    if(firstFreeCell != NOT_EXIST){
        setDate(firstFreeCell-1,my_date);
        return true;
    }
    return false;
}
void Calendar::print() {
    if(isEmpty()){
        cout<<"Empty Calendar"<<endl;
    }else{
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            printCell(i);
        }
    }
}
