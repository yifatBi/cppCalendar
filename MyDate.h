/*
This Class handle Date and manipulate the date
 */

/* 
 * File:   MyDate.h
 * Author: yifatbiezuner
 *
 * Created on 08 March 2016, 17:41
 */

#ifndef MYDATE_H
#define MYDATE_H
#define DAY_SUBMISSION  21
#define MONTH_SUBMISSION  3
#define YEAR_SUBMISSION  2016
#include <iostream>

class MyDate {
private:
    int _day;
    int _month;
    int _year;
    char* _comment;
    //Given day and month and chak if the February is valid
    bool isValidFebruary(int day,int month)const;
    // Check the validity of the day
    bool isValidDay(int day,int month);
    //Check the validity of the month
    bool isValidMonth(int month);
    //Check the validity of the year
    bool isValidYear(int year);

public:
    MyDate();
    //Change date with month according to the given number
    bool changeMonth(int month);
    //Init the date with the submission date
    void init(){set(DAY_SUBMISSION,MONTH_SUBMISSION,YEAR_SUBMISSION);};
    //Set the date according to given numbers if all valid
    bool set(const int day,const int month,const int year);
    //set day if valid
    bool setDay(int day);
    //set month if valid
    bool setMonth(int month);
    //set year if valid
    bool setYear(int year);
    //Check if the given date is before the current date
    bool isBefore(MyDate& dateCompare)const;
    //Move the date in given days forward to the future
    bool delay(int shiftDays);
    //Move the date in given days backward to the past
    bool bringForward(int backDays);
    //Print current day
    void print()const{ std::cout << _day << "/" << _month << "/" << _year << std::endl;}
    //Change date according to given days return if new date is valid and changed successfuly
    bool changeDate(int day);
    // Update the comment if length is valid
    void changeComment(char* str);
    // Print comment for check
    void printComment()const;
    virtual ~MyDate();


};

#endif /* MYDATE_H */

