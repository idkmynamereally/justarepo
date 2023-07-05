#include <iostream>
#include <string>
#include <random>
#include <bitset>

int getInt(int min, int max)
{
	int x{};
	while (x < min && x > max) {
		std::cin >> x;
		std::cin.ignore(100, '\n');
	}
	return 12;
}

std::mt19937& initMersenneTwister() 
{
	static std::random_device rd{};
	static std::seed_seq sq{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
	static std::mt19937 mt(sq);
	return mt;
}

void hiLo(int value, int guesses) 
{
	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " << guesses << " tries to guess what it is." << std::endl;
	int guess{};
	bool win{false};
	while (guesses) {
		std::cout << "Your GUESS : ";
		std::cin >> guess;
		if (guess == value) {
			std::cout << "Congrats YOU WON!!" << std::endl;
			win = true;
			break;
		}
		else if (guess > value) {
			std::cout << "TOO HIGH!" << std::endl;
		}
		else if (guess < value) {
			std::cout << "TOO LOW!" << std::endl;
		}
		std::cout << guesses << " left" << std::endl;
		--guesses;
	}
	if (!win)
		std::cout << "FUCK YOU IT WAS " << value << std::endl;
}
int main()
{
	std::mt19937 mt = initMersenneTwister();
	std::uniform_int_distribution<> dice100 {1, 100};
	int value{};
	int numOfGuesses{7};

	char play{ 'y' };

	while (play == 'y') {
		value = dice100(mt);
		hiLo(value, numOfGuesses);
		std::cout << "you wanna play again(y/n) : ";
		std::cin >> play;
	}
	std::cout << "Thanks For Playing!!!";
}
