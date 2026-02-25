#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int secretNumber, guess;

    srand(time(0));
    secretNumber = rand() % 100 + 1;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Guess a number between 1 and 100" << endl;

    do
    {
        cout << "Enter your guess: ";

        if (!(cin >> guess))  
        {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();                 
            cin.ignore(1000, '\n');      
            continue;                   
        }

        if (guess > secretNumber)
        {
            cout << "Too High! Try again." << endl;
        }
        else if (guess < secretNumber)
        {
            cout << "Too Low! Try again." << endl;
        }
        else
        {
            cout << "Correct Guess! You Win!" << endl;
        }

    } while (guess != secretNumber);

    return 0;
}