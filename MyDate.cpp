/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyDate.cpp
 * Author: yifatbiezuner
 * 
 * Created on 08 March 2016, 17:41
 */

#include "MyDate.h"
#define min_year 1900
#define max_year 2100
#define FEBRUARY_SHIFT 2
#define FEBRUARY_LENGTH 28
#define MONTH_NUM 12
#define ZERO_MIN 0
#define MAX_MONTH_DAYS 30
#define MIN_DAYS_NUM 1
#define MAX_COMMENT_LENGTH 20
#define MAX_SHIFT_DAYS 365
#define FEBRUARY 2

MyDate::MyDate() {
}

MyDate::MyDate(const MyDate& orig) {
}

MyDate::~MyDate() {
}

bool MyDate::isValidMonth(int month) {
   if(ZERO_MIN<month&&month<=MONTH_NUM){
       return true;
   }
//    std::cout<< "the month is invalid"<<std::endl;
    return false;
}
bool MyDate::isValidYear(int year) {
    if(min_year<=year&&year<=max_year){
        return true;
    }
//    std::cout<< "the year is invalid"<<std::endl;
    return false;
}
bool MyDate::isValidDay(int day,int month) {
    bool dayValid = day<MIN_DAYS_NUM|| day>MAX_MONTH_DAYS;
    if((dayValid)||(!isValidFebruary(day,month))){
        return false;
    }
    return true;
}

bool MyDate::setDay(int day){
    if(isValidDay(day,m_month)){
       m_day=day;
        return true;
    }
    return false;
}
bool MyDate::setMonth(int month){
    if(isValidMonth(month)){
       m_month=month;
        return true;
    }
    return false;
}
bool MyDate::setYear(int year){
    if(isValidYear(year)){
       m_year=year; 
       return true;
    } 
    return false;
}
void MyDate::changeComment(char* str) {
    if(strlen(str)<=MAX_COMMENT_LENGTH){
         m_comment = new char[strlen(str) + 1];
        stpcpy(m_comment, str);
    }
}
bool MyDate::set(int day, int month, int year){
    if(isValidDay(day,month)&&
        isValidMonth(month)&&
        isValidYear(year)){
        m_day=day;
        m_month=month;
        m_year=year;
        return true;
    }
    return false;
}
/**
 * Get month and change the date according to the month
 * @param month
 * @return if the new date is valid or not(according to the year)
 */
bool MyDate::changeMonth(int month){
    int tempCalc = (m_month+month);
    m_month= tempCalc%MONTH_NUM;
    if(m_month<=0){m_month = (MONTH_NUM+m_month);}
    tempCalc=(tempCalc<=0)?-1:(tempCalc/MONTH_NUM);
    return setYear(m_year+tempCalc);
}

bool MyDate::isBefore(MyDate& dateCompare)const{
    bool beforeInYears = m_year<dateCompare.m_year;
    bool beforeInMonths = m_year==dateCompare.m_year&&m_month<dateCompare.m_month;
    bool beforeInDays =  m_year==dateCompare.m_year&&m_month==dateCompare.m_month&&m_day<dateCompare.m_day;
    return  (beforeInYears||beforeInMonths||beforeInDays);
}

bool MyDate::changeDate(int day){
    int tempCalc = m_day+day;
    int monthChange = -1;
    bool returnVal = true;
    bool isCurrentBeforeFeb;
    int prevDay = m_day;
    int prevMonth = m_month;
    int prevYear = m_year;
    MyDate febCheck;
    febCheck.set(FEBRUARY_LENGTH, FEBRUARY, m_year);
    bool isPrevBeforeFeb = isBefore(febCheck);

    //if go backward and more than current month days update the days and month
    if(tempCalc<0){
        tempCalc = (MAX_MONTH_DAYS+tempCalc);
        returnVal=changeMonth(monthChange);
    }

    //If the updated days to change |maxDaysNum then the day should be maxDaysNum else it will be the absolute modulo maxDaysNum
    if(tempCalc%MAX_MONTH_DAYS==0)m_day=MAX_MONTH_DAYS;
    else{m_day = abs(tempCalc%MAX_MONTH_DAYS);}
    //Calc the months change and update months if needed and update the return val
     if(tempCalc!=0) {
         monthChange =(tempCalc / MAX_MONTH_DAYS);
     }
    if(monthChange)returnVal=changeMonth(monthChange);

    //Check if the date is before February
     isCurrentBeforeFeb = isBefore(febCheck);

    //If the feb check is false and the year has been changed
    //update the feb check according current year
    if(day>0&&!isPrevBeforeFeb&&m_year!=febCheck.m_year){
        febCheck.setYear(m_year);
        isCurrentBeforeFeb =isBefore(febCheck);
        if(isCurrentBeforeFeb)isPrevBeforeFeb= true;
    }
    else if(day<0&&m_year!=febCheck.m_year&&isPrevBeforeFeb) {
        febCheck.setYear(m_year);
        isCurrentBeforeFeb = isBefore(febCheck);
        if(isCurrentBeforeFeb) isPrevBeforeFeb = false;
    }
    //Check if is invalid February
    if(!isValidFebruary(m_day,m_month)){
        if(day>0){
        m_day = m_day % FEBRUARY_LENGTH;
        m_month++;
        }else{
          m_day=(m_day - FEBRUARY_SHIFT);
        }
    }
    //Check if there was February between the months and if so call the function again with shift of 3 days
    else if(day>0&&isPrevBeforeFeb&&!isCurrentBeforeFeb||day<0&&!isPrevBeforeFeb&&isCurrentBeforeFeb) {
        tempCalc = day > 0 ? FEBRUARY_SHIFT : -FEBRUARY_SHIFT;
        returnVal = changeDate(tempCalc);
    }
    //if the updated date is invalid go back to the previous date
    if(!returnVal)set(prevDay, prevMonth, prevYear);
    return returnVal;
}
bool MyDate::delay(int shiftDays){
    if(0<=shiftDays&&shiftDays<=MAX_SHIFT_DAYS) {
        return changeDate(shiftDays);
    }
    return false;
}
bool MyDate::bringForward(int backDays) {
    if(0<=backDays&&backDays<=MAX_SHIFT_DAYS) {
        return changeDate(-backDays);
    }
    return false;
}
void  MyDate::printComment() const {
    if(m_comment){
        std::cout << m_comment << std::endl;
    }else{
        std::cout<<"Not initialized yet";
    }
}

