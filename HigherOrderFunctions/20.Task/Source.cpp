// include student's file
//#include "nnnnn/BullsAndCows.cpp"
#include "BullsAndCows.h"

#include <string.h>
#include <cstdlib>
#include <iostream>

#define DEFAULT_DIGITS_COUNT 4
#define DECIMAL_DIGITS_COUNT 10

using namespace std;

int secret;

// put digits of number in digit array
void get_digits(int num, int* digits, const int digits_count = DEFAULT_DIGITS_COUNT)
{
	for (int i = 0; i < digits_count; i++)
	{
		digits[digits_count - i - 1] = num % 10;
		num /= 10;
	}
}

// fill array of 10 elements - how many times a given digit is seen in a number
void get_digits_distribution(int num, int* all_digits)
{
	while (num != 0)
	{
		all_digits[num % 10]++;
		num /= 10;
	}
}

bool guess_digits_are_valid(int* digits, const int digits_count = DEFAULT_DIGITS_COUNT)
{
	const int all_digits_count = DECIMAL_DIGITS_COUNT;
	int digits_histogram[all_digits_count] = {};

	for (int i = 0; i < digits_count; i++)
	{
		digits_histogram[digits[i]]++;
	}

	if (digits_histogram[0] > 0)
	{
		return false;
	}

	for (int i = 0; i < all_digits_count; i++)
	{
		if (digits_histogram[i] > 1)
		{
			return false;
		}
	}

	return true;
}

const int* tryGuess(int guess)
{
	int* bulls_cows = new int[2];

	const int digits_count = DEFAULT_DIGITS_COUNT;

	int guess_digits[digits_count] = {};
	int secret_digits[digits_count] = {};

	get_digits(guess, guess_digits);
	get_digits(secret, secret_digits);

	if (!guess_digits_are_valid(guess_digits))
	{
		return bulls_cows;
	}

	int guess_digits_distribution[DECIMAL_DIGITS_COUNT] = {};
	int secret_digits_distribution[DECIMAL_DIGITS_COUNT] = {};

	get_digits_distribution(guess, guess_digits_distribution);
	get_digits_distribution(secret, secret_digits_distribution);

	int digits_in_both = 0;
	for (int i = 0; i < DECIMAL_DIGITS_COUNT; i++)
	{
		if (guess_digits_distribution[i] > 0 && secret_digits_distribution[i] > 0)
		{
			digits_in_both++;
		}
	}

	int bulls = 0;
	for (int i = 0; i < digits_count; i++)
	{
		if (guess_digits[i] == secret_digits[i])
		{
			bulls++;
		}
	}

	bulls_cows[0] = bulls;
	bulls_cows[1] = digits_in_both - bulls;

	return bulls_cows;
}

int main(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		secret = atoi(argv[i]);
		//cout << secret;
		play();
	}

	return 0;
}
