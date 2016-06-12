#include<stdio.h>
#include<assert.h>
#include <stdbool.h>
#include"date.h"

// check a date is valid or not
bool is_valid(const struct date d){
  if ((d.month == 1||d.month == 3||d.month == 5||d.month == 7||d.month == 8||d.month == 10||d.month == 12)&&d.day < 32){
    return true;
  }
  else if ((d.month == 4||d.month == 6||d.month == 9||d.month == 11)&&d.day < 31){
    return true;
  }
  else if (d.year % 400 == 0&&d.month == 2&&d.day < 30){
    return true;
  }
  else if(d.year % 100 == 0&&d.month == 2&&d.day > 28){
    return false;
  }
  else if(d.year % 4 == 0&&d.month == 2&&d.day < 30){
    return true;
  }
  else if(d.month == 2&&d.day < 29){
    return true;
  }
  else{
    return false;
  }
}

// check two dates is equal or not
bool d_eq(const struct date d1, const struct date d2){
  if(d1.year == d2.year&&d1.month == d2.month&&d1.day == d2.day){
    return true;
  }
  else {
    return false;
  }
}

// check the first date is later than the second date or not
bool greaterthan(const struct date d1, const struct date d2){
  if(d1.year > d2.year){
    return true;
  }
  else if(d1.year == d2.year&&d1.month > d2.month){
    return true;
  }
  else if(d1.year == d2.year&&d1.month == d2.month&&d1.day > d2.day){
    return true;
  }
  else {
    return false;
  }
} 
