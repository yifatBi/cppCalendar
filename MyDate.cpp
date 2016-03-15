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
    if(!isValidFebruary(day,month)){
        std::cout<<"sorry dear February its a short month"<<std::endl;
    }else if(day<=MIN_DAYS_NUM||day>MAX_MONTH_DAYS){
        std::cout<< "the day is invalid"<<std::endl;
    }else{
        return true;
    }
    return false;
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
void MyDate::changeComment(char *str) {
    if(strlen(str)<=20){
         comment = new char[strlen(str)+1];
        stpcpy(comment,str);
    }
}
bool MyDate::set(int day, int month, int year){
    if(isValidDay(day,month)&&
        isValidMonth(month)&&
        isValidYear(year)){
        m_day=day;
        m_month=month;
        m_year=year;
        std::cout<< "All data is Valid"<<std::endl;
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

void MyDate::changeDate(int day){
    int tempCalc = m_day+day;
    int monthChange = -1;
    bool isCurrentBeforeFeb;
    MyDate febCheck;
    febCheck.set(FEBRUARY_LENGTH, 2, m_year);
    bool isPrevBeforeFeb = isBefore(febCheck);
    if(tempCalc<0){tempCalc = (MAX_MONTH_DAYS+tempCalc);changeMonth(-1);}
    //If the updated days to change |30 then the day should be 30 else it will be the absolute modulo 30
    if(tempCalc%MAX_MONTH_DAYS==0)m_day=MAX_MONTH_DAYS;
    else{m_day = abs(tempCalc%MAX_MONTH_DAYS);}
    //Calc the months change and update months if needed
     if(tempCalc!=0) {
         monthChange =(tempCalc / MAX_MONTH_DAYS);
     }
    if(monthChange)changeMonth(monthChange);

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
        changeDate(tempCalc);
    }
}
void MyDate::delay(int shiftDays){
    if(shiftDays<=365||shiftDays<=0) {
        changeDate(shiftDays);
    }else{
        std::cout<<"You chose invalid num" << std::endl;
    }
}
void MyDate::bringForward(int backDays) {
    if(backDays<=365||backDays<=0) {
        changeDate(-backDays);
    }else{
        std::cout<<"You chose invalid num" << std::endl;
    }
}

