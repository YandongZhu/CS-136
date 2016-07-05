#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// static bool check_row(const char* board): check each 
//   row of a sudoku obey the rule or not.
static bool check_row(const char* board);

// static bool check_column(const char* board): check  
//   each column of a sudoku obey the rule or not.
static bool check_column(const char* board);

// static bool check_block(const char* board): check each 
//   block of a sudoku obey the rule or not.
static bool check_block(const char* board);

void print_board(const char *board){
	int len = 0;
	while (board[len])
	{
		if (len % 27 == 0)
			printf("_________________________\n");
		if (len % 9 == 0)
			printf("| ");
		printf("%c ", board[len]);
		if (len % 9 == 2||len % 9 == 5)
			printf("| ");
		if (len % 9 == 8)
			printf("|\n");
		++len;
	}
	printf("_________________________\n");
}

static bool check_row(const char* board){
	for(int len = 0; len < 81; len += 9){
		int number_1 = 0;
		int number_2 = 0;
		int number_3 = 0;
		int number_4 = 0;
		int number_5 = 0;
		int number_6 = 0;
		int number_7 = 0;
		int number_8 = 0;
		int number_9 = 0;
		for (int i = len; i < 9 + len; ++i)
		{
			if (board[i] == '1')
				number_1++;
			if (board[i] == '2')
				number_2++;
			if (board[i] == '3')
				number_3++;
			if (board[i] == '4')
				number_4++;
			if (board[i] == '5')
				number_5++;
			if (board[i] == '6')
				number_6++;
			if (board[i] == '7')
				number_7++;
			if (board[i] == '8')
				number_8++;
			if (board[i] == '9')
				number_9++;
		}
		if (number_1 > 1||number_2 > 1||number_3 > 1||number_4 > 1||number_5 > 1||number_6 > 1||number_7 > 1||number_8 > 1||number_9 > 1)
			return false;
	}
	return true;
}

static bool check_column(const char* board){
	for (int len = 0; len < 9; ++len)
	{
		int number_1 = 0;
		int number_2 = 0;
		int number_3 = 0;
		int number_4 = 0;
		int number_5 = 0;
		int number_6 = 0;
		int number_7 = 0;
		int number_8 = 0;
		int number_9 = 0;
	for (int i = len; i < 82; i += 9)
	{
			if (board[i] == '1')
				number_1++;
			if (board[i] == '2')
				number_2++;
			if (board[i] == '3')
				number_3++;
			if (board[i] == '4')
				number_4++;
			if (board[i] == '5')
				number_5++;
			if (board[i] == '6')
				number_6++;
			if (board[i] == '7')
				number_7++;
			if (board[i] == '8')
				number_8++;
			if (board[i] == '9')
				number_9++;
	}
	if (number_1 > 1||number_2 > 1||number_3 > 1||number_4 > 1||number_5 > 1||number_6 > 1||number_7 > 1||number_8 > 1||number_9 > 1)
			return false;
	}
	return true;
}

static bool check_block(const char* board){
	for (int i = 0; i < 81; i += 27)
	{
		for (int j = i; j < i+9; j += 3)
		{
			int number_1 = 0;
			int number_2 = 0;
			int number_3 = 0;
			int number_4 = 0;
			int number_5 = 0;
			int number_6 = 0;
			int number_7 = 0;
			int number_8 = 0;
			int number_9 = 0;
			for (int k = j; k < j + 3; ++k)
			{
				for (int l = k; l <= k + 18; l += 9)
				{
					if (board[l] == '1')
						number_1++;
					if (board[l] == '2')
						number_2++;
					if (board[l] == '3')
						number_3++;
					if (board[l] == '4')
						number_4++;
					if (board[l] == '5')
						number_5++;
					if (board[l] == '6')
						number_6++;
					if (board[l] == '7')
						number_7++;
					if (board[l] == '8')
						number_8++;
					if (board[l] == '9')
						number_9++;
				}
			}
			if (number_1 > 1||number_2 > 1||number_3 > 1||number_4 > 1||number_5 > 1||number_6 > 1||number_7 > 1||number_8 > 1||number_9 > 1)
					return false;
		}
	}
	return true;
}

bool is_valid(const char *board){
	int row = check_row(board);
	int column = check_column(board);
	int block = check_block(board);
	return row&&column&&block;
}

