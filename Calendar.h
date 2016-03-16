//
// Created by yifat biezuner on 13/03/2016.
//

#ifndef CALENDAR_H
#define CALENDAR_H

#include "MyDate.h"
#define ARRAY_SIZE 30

class Calendar {
private:
    MyDate *m_dates[ARRAY_SIZE];
public:
    Calendar();
    void setDate (int num, MyDate &my_date);
    void printCell (const int num)const;
    bool isFree(int num)const;
    int firstFree();
    void fillAllWithVal(MyDate &my_date);
    void deleteAll();
    bool insert(MyDate& my_date);
    int oldest();
    int datesNum(MyDate& _mydate);
    void deleteDate(int num);
    void print();
};

#endif //CALENDAR_H
