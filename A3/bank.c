#include "bank.h"
#include <stdbool.h>
  
static int balance = 0;


void deposit(int amount) {
  balance += amount;
}

// DO NOT MODIFY THE ABOVE TWO DEFINITIONS
// COMPLETE THE IMPLEMENTATION BELOW:

static int c = 100000;
static int limit = 100000;
static int used = 0;
static int low = 1;
static int least = 0;
static int limit_increase = 1;

// withdrawal the money if the daily withdraw limit is not
// exceed. or not allow to withdral
// the amount is count in cents
// effect: change the balance or print 
// "no withdrawal: daily limit exceeded\n" if the 
// withdraw is not completed
void withdrawal(int amount){
	if (used + amount <= limit)
	{
		balance = balance - amount;
		used += amount; 
	}
	else {
		printf("no withdrawal: daily limit exceeded\n");
	}
	if (balance <= -100000)
	{
		low = 0;
	}
	else{
	}
};

// reset the daily withdraw limit if the balance is positive, otherwise set the limit to 0 and reduce 5$ per day from the amount
// effect: reset the limit or print "Warning! Overdraft"
// and reduce money from the balance
void new_day(void){
	limit_increase++;
	if (balance >= 50000)
	{
		used = 0;
		limit = c;
		least++;
	}
	else if (balance >= 0)
	{
		used = 0;
		limit = c;
		least = 0;
	}
	else {
		limit = 0;
		used = 0;
		balance = balance - 500;
		printf("Warning! Overdraft\n");
	}
	if (balance <= -100000)
	{
		low = 0;
	}
	else{
	}
};

// print_balance() prints the current balance, followed by a newline
void print_balance(void){
	int b = balance / 100;
	int c = balance % 100;
	if (balance >= 0&&c < 10)
	{
		printf("balance: $%d.%d%d\n", b, 0, c);/* code */
	}
	else if (balance < 0 && c > -10)
	{
		printf("balance: -$%d.%d%d\n", -b, 0, -c);/* code */
	}
	else if (balance >= 0)
	{
		printf("balance: -$%d.%d\n", b, c);/* code */
	}
	else {
		printf("balance: -$%d.%d\n", -b, -c);
	}
};


// print_limit() prints the remaining daily withdrawal limit
void print_limit(void){
	int a = limit - used;
	int b = a / 100;
	int c = a % 100;
	if (c < 10)
	{
		printf("limit: $%d.%d%d\n", b, 0, c);/* code */
	}
	else{
		printf("limit: $%d.%d\n", b, c);
	}
}; 



// KEEP THIS DEFINIITON IF YOU CHOOSE NOT TO DO THE BONUS


void request_limit_increase(void) {
	if (low&&balance >= 100000&&used == 0&&least > 4&&limit_increase > 10)
	{
		c = c + 10000;
		limit = c;
		limit_increase = 1;
	}
	else{
		return ;
	}
}
