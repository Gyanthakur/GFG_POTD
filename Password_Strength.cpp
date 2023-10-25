#include <bits/stdc++.h>
using namespace std;

void printStrongNess(string& input)
{
    int n = input.length();
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
//taking a string with all upper and lower case alphabets
    string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
//running loop till the length of the string/password
    for (int i = 0; i < n; i++) 
    {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;

        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }

    // checking the strength of your password
    cout << "Strength of your password:- ";
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8))
        cout << "Strong" << endl;
    else if ((hasLower || hasUpper) &&
             specialChar && (n >= 6))
        cout << "Moderate" << endl;
    else
        cout << "Weak" << endl;
}
//main function to input the password
int main()
{
    string input;
    cout<<"Enter your password: ";
    cin>>input;
    printStrongNess(input);
    return 0;
}
