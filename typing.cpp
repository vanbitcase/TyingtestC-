#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int main() {
    string sentence = "The quick brown fox jumps over the lazy dog.";
    string userTyped;
    int correctChars = 0;

    cout << "Type the following sentence:\n\n";
    cout << sentence << "\n\n";

    cout << "Press Enter to start...";
    cin.get();

    auto startTime = chrono::high_resolution_clock::now();

    cout << sentence << "\n"; // Display the sentence for the user to type

    getline(cin, userTyped);

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = endTime - startTime;

    for (int i = 0; i < sentence.length() && i < userTyped.length(); i++) {
        if (sentence[i] == userTyped[i]) {
            correctChars++;
        }
    }

    int totalChars = sentence.length();
    int accuracy = (correctChars * 100) / totalChars;
    double typingSpeed = (double)totalChars / elapsed.count() * 60; // Speed in characters per minute

    cout << "\nTyping Speed: " << typingSpeed << " characters per minute" << endl;
    cout << "Typing Accuracy: " << accuracy << "%" << endl;

    return 0;
}

