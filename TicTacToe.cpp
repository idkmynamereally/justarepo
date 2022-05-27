#include <iostream>

using namespace std;

class master_block{
public:
    int position;
    int state = 0; //0 for nothing // 1 for X // 2 for O

    void mark(int player){
        state = player;
    }
};

master_block table [9];
void print_table();
int diagonal_win(int lastmark);
int horizontal_win(int lastmark);
int vertical_win(int lastmark);
int check_for_win (int lastmark);

int main(){
    for (int i = 0; i < 9; i++){
        table[i].position = i;
    }
    cout << "Welcome Player 1 & Player 2";
    cout << "\nPlayer 1 = X\nPlayer 2  = O\n";

    for (int i = 0; i < 9; i++){
        print_table();
        int choice = 0;
        if (i%2 == 0){
        while(1){
                cout << "\nPlayer 1 Enter your Choice : ";
                cin >> choice;
                if (table[choice].state != 0){
                    cout << "Block Already Marked!!\n";
                    continue;
                }
                table[choice].mark(1);
                if(check_for_win(choice)){
                    cout << "\nPlayer 1 Wins\n\n";
                    print_table();
                    return 0;
                }
                break;
            }
        continue;
        }
        while(1){           //LOOP TO KEEP RUNNING TILL VALID CHOICE IS MADE
                cout << "\nPlayer 2 Enter your Choice : ";
                cin >> choice;
                if (table[choice].state != 0){
                    cout << "Block Already Marked!!\n";
                    continue;
                }
                table[choice].mark(2);      //ONCE VALID CHOICE MADE WE CAN CHECK FOR WIN AND EVENTUALLY LEAVE
                if (check_for_win(choice)){
                    cout << "\nPlayer 2 Wins\n\n";
                    print_table();
                    return 0;
                }
                break;
        }
    }
    return 0;
}
int check_for_win (int lastmark){
    if (horizontal_win(lastmark))
        return 1;
    if (vertical_win(lastmark))
        return 1;
    if (diagonal_win(lastmark))
        return 1;
    return 0;
}

int horizontal_win(int lastmark){
    int first = 0;
    if (lastmark < 3){
        first = 0;
    }
    else if (lastmark < 6){
        first = 3;
    }
    else {
        first = 6;
    }

    for (int i = first; i < first + 3; i++){
        if (table[i].state != table[first].state)
            return 0;
    }
    return 1;
}

int vertical_win(int lastmark){
    int first = 0;
    if (lastmark == 0 || lastmark == 3 || lastmark == 6){
        first = 0;
    }
    else if (lastmark == 1 || lastmark == 4 || lastmark == 7){
        first = 1;
    }
    else {
        first = 2;
    }

    for (int i = first; i < 9; i = i + 3){
        if (table[i].state != table[first].state)
            return 0;
    }
    return 1;
}

int diagonal_win(int lastmark){
    int first = 0;
    if (lastmark%2 != 0)
        return 0;

    if (lastmark == 0 || lastmark == 4 || lastmark == 8){
        first = 0;
    }
    else{
        first = 2;
    }

    if (first == 0){
        for (int i = 0; i < 9; i = i + 4){
            if (table[i].state != table[first].state)
                return 0;
        }
        return 1;
    }

    else if (first == 2){
        for (int i = 2; i < 7; i = i + 2){
            if (table[i].state != table[first].state)
                return 0;
        }
        return 1;
    }
}

void print_table(){
    for (int i = 0; i < 9; i++){
        if (i%3 == 0)
            cout << "\n";
            if (table[i].state == 0){
                cout << "  " << i << "  ";
            }
            else if (table[i].state == 1){
                cout << "  X  ";
            }
            else if (table[i].state == 2){
                cout << "  O  ";
            }
        if (i%3 != 2)
            cout << "|";
    }
}
