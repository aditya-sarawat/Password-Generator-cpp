#include <bits/stdc++.h>

using namespace std;


int selectArray()
{
    srand(time(nullptr));
    int i = rand() % 5;
    if (i == 0.0)
        i++;
    
    return i;
}

int getKey()
{
    srand(time(nullptr));

    int key = rand() % 26;
    return key;
}

void generate_password(int length)
{

    string password;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s_symbol = "!@#$%&";
    string number = "0123456789";

    int key;
    int count_alphabet = 0;
    int count_ALPHABET = 0;
    int count_number = 0;
    int count_s_symbol = 0;

    int count = 0;

    while (count < length) {
        int k = selectArray();

        if (count == 0) {
            k = k % 3;
            if (k == 0)
                k++;
        }

        switch (k) {
        case 1:
            // following if condition will check if minimum requirement of alphabet
            // character has been fulfilled or not
            // in case it has been fulfilled and minimum requirements of other
            // characters is still left then it will break ;
            if ((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_s_symbol == 0))
                break;

            key = getKey();
            password = password + alphabet[key];
            count_alphabet++;
            count++;
            break;

        case 2:
            // following if condition will check if minimum requirement of
            // ALPHABET character has been fulfilled or not
            // in case it has been fulfilled and minimum requirements of
            // other characters is still left then it will break ;
            if ((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 || count_alphabet == 1 || count_s_symbol == 0))
                break;
            key = getKey();
            password = password + ALPHABET[key];
            count_ALPHABET++;
            count++;
            break;

        case 3:
            // following if condition will check if minimum requirement
            // of Numbers  has been fulfilled or not
            // in case it has been fulfilled and minimum requirements of
            // other characters is still left then it will break ;
            if ((count_number == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 1 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;

            key = getKey();
            key = key % 10;
            password = password + number[key];
            count_number++;
            count++;
            break;

        case 4:
            // following if condition will check if minimum requirement of
            // Special symbol character has been fulfilled or not
            // in case it has been fulfilled and minimum requirements of
            // other characters is still left then it will break ;
            if ((count_s_symbol == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_number == 0))
                break;

            key = getKey();
            key = key % 6;
            password = password + s_symbol[key];
            count_s_symbol++;
            count++;
            break;
        }
    }

    cout << "\n\n";
    cout << "Password : "<< password;;
    cout << "\n\n";
}
int main()
{
    int opt, length;
    //Menu
    do {
        cout << "\n\n";
        cout << "    Random Password Generator\n";
        cout << "\n";
        cout << "     1. Generate Password"
             << "\n";
        cout << "     2. Exit"
             << "\n\n";
        cout << "> ";
        cin >> opt;

        switch (opt) {
        case 1:
            cout << "\n\nEnter Length (greater than 7):  ";
            cin >> length;
            
            //if length is less than 7 , program  will show error
            if (length < 7) {
                cout << "\nError : Password Length Should be atleast 7\n";
            }
            
            // Length should not exceed 100 , program should show error if it exceeds
            else if (length > 100) {
                cout << "\nError : Maximum length of password should be 100\n";
            }
            
            //Otherwise call generate_password() function to generate password
            else
                generate_password(length);

            break;

        default:
            
            // If invalid option is chosen by user it will also show error
            if (opt != 2) {
                printf("\nInvalid choice\n");
                printf("Please Press ( 1 ) to generate password and ( 2 ) to exit.\n");
            }
            break;
        }
    } while (opt != 2);

    return 0;
}
