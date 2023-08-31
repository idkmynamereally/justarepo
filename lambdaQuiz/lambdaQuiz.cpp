#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include "myInput.h"
#include <vector>
#include <random>

namespace Config
{
    constexpr int multiplierMin{ 2 };
    constexpr int multiplierMax{ 4 };
    constexpr int maximumWrongAnswer{ 4 };
}

int getRandomInt(int min, int max)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    return std::uniform_int_distribution{min, max}(mt);
}

std::vector<int> generateNumbers(int start, int count, int multiplier)
{
    std::vector<int> ret(count);
    for (auto& i : ret)
    {
        i = start * start * multiplier;
        ++start;
        std::cout << i << ", ";
    }
    return ret;
}

void theGame()
{
    std::cout << "Start Where : ";
    int firstNum{ GoodInput::getInt() };
    std::cout << "How Many : ";
    int numOfNums{ GoodInput::getInt() };

    int randMulti{getRandomInt(Config::multiplierMin, Config::multiplierMax)};
    std::vector<int> nums{generateNumbers(firstNum, numOfNums, randMulti)};
    
    std::cout << "I generated " << numOfNums << " square numbers." <<
        "Do you know what each number is after multiplying it by " << randMulti << "?.\n";
    
    int guess{};
    while (true)
    {
        std::cout << "> ";
        guess = GoodInput::getInt();
        auto found = std::find(nums.begin(), nums.end(), guess);
        if (found == nums.end())
        {
            std::cout << guess << " is wrong! ";
            auto closest = std::min_element(std::begin(nums), std::end(nums), 
                [&guess](int a, int b)
                {
                    if (std::abs(guess - a) < std::abs(guess - b))
                        return true;
                    return false;
                });
            int distance{ std::abs((*closest) - guess) };
            if (distance < 4)
            {
                std::cout << "Try " << *closest << " next time.";
            }
            std::cout << '\n';
            break;
        }
        else
        {
            std::cout << "Nice! " << --numOfNums << " numbers left.\n";
            nums.erase(found);
            if (numOfNums == 0)
            {
                std::cout << "You Win!\n";
                break;
            }
        }
    }
}

int main()
{
    theGame();
    return 0;
}
