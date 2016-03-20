//
// This class handle list of dates
// Created by Yifat Biezuner on 13/03/2016.
//

#ifndef CALENDAR_H
#define CALENDAR_H

#include "MyDate.h"
#define ARRAY_SIZE 30

class Calendar {
private:
    MyDate *m_dates[ARRAY_SIZE];
    //Check is the dates array is empty
    bool isEmpty()const;
    //Return the index of first val in the array
    int firstVal();
    //Return the index of last val in the array
    int lastVal();
public:
    Calendar();
    void setDate (int num, MyDate &my_date);
    void printCell (const int num)const;
    //check if have value in the given index in the dates array
    bool isFree(int num)const;
    // return the first index of free cell
    int firstFree();
    //Init the dates array with the given date
    void fillAllWithVal(MyDate &my_date);
    //Delete all pointers from the dates array
    void deleteAll();
    // Insert the val to the first empty cell return if complete successfuly
    bool insert(MyDate& my_date);
    // Return the index of the oldest date in the dates array
    int oldest();
    // Return the number of pointers to this date in the dates array 
    int datesNum(MyDate& _mydate);
    //Delete the value from the given index in the dates array (delete it a preserved word wo I used deleteDate)
    void deleteDate(int num);
    // Print all dates array values
    void print();
};

#endif //CALENDAR_H
