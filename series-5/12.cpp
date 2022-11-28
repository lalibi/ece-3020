#include <iostream>
#include <string>

using namespace std;

char encrypt(char in, string alpha, string cipher)
{
    int pos = alpha.find(in);
    char ch;

    if (pos >= 0)
    {
        // If the character was found in the lower-case latin characters
        // return the corresponding character from the cipher
        return cipher.at(pos);
    }
    else
    {
        // Otherwise, assume it is an upper-case character
        // and convert it to lower-case, before searching for it
        ch = in + 32;
        pos = alpha.find(ch);

        // If the converted character was found in the lower-case latin characters
        // return the corresponding character from the cipher, converted to upper-case
        if (pos >= 0)
        {
            return cipher.at(pos) - 32;
        }
    }

    // In all other cases, return the original character
    return in;
}

int main()
{
    int i, pos;
    char ch;
    string cipher, text;
    const string alpha = "abcdefghijklmnopqrstuvwxyz";

    getline(cin, cipher);

    if (cipher.length() != 26)
    {
        cout << "error" << endl;
        return 0;
    }

    // Check if all letters are present in the cipher
    for (i = 0; i < 26; i++)
    {
        ch = alpha[i];

        pos = cipher.find(ch);

        if (pos < 0)
        {
            cout << "error" << endl;
            return 0;
        }
    }

    while (getline(cin, text))
    {
        // Encrypt the text, character by character
        for (i = 0; i < text.length(); i++)
        {
            ch = text.at(i);
            cout << encrypt(ch, alpha, cipher);
        }

        cout << endl;
    }

    return 0;
}
