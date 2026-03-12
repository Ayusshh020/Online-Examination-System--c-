#include <iostream>
#include <string>
#include <limits>
#include <cctype> 

using namespace std;

char userResponses[10]; 

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void startExam(string &studentName, int &userScore, int totalQuestions, string questions[], char answers[]) {
    userScore = 0;
    char userAnswer;

    cout << "\nEnter Student Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, studentName);

    cout << "\n--- Welcome " << studentName << "! Exam Started ---" << endl;

    for (int i = 0; i < totalQuestions; i++) {
        bool valid = false;
        while (!valid) { 
            cout << "\n" << questions[i] << endl;
            cout << "Your Answer (A/B/C/D): ";
            cin >> userAnswer;
            userAnswer = toupper(userAnswer);

            if (userAnswer >= 'A' && userAnswer <= 'D') {
                valid = true;
                userResponses[i] = userAnswer; 
                if (userAnswer == answers[i]) {
                    userScore++;
                }
            } else {
                cout << "[!] INVALID OPTION: Please enter A, B, C, or D." << endl;
                clearInput();
            }
        }
    }

    // Immediate Professional Result Output
    float per = ((float)userScore / totalQuestions) * 100;
    cout << "\n--- OFFICIAL RESULT SHEET ---" << endl;
    cout << "Student Name : " << studentName << endl;
    cout << "Score        : " << userScore << " / " << totalQuestions << endl;
    cout << "Percentage   : " << per << "%" << endl;
    cout << "Status       : " << (per >= 35.0 ? "PASS" : "FAIL") << endl;
    cout << "-------------------------------" << endl;
}

int main() {
    int choice, score = 0;
    string studentName = "Guest";
    const int totalQuestions = 10;

    string questions[10] = {
        "1. Who invented C++?\nA. Dennis Ritchie\nB. Ken Thompson\nC. Bjarne Stroustrup\nD. Brian Kernighan",
        "2. Which is used for single line comments?\nA. //\nB. /* */\nC. <--- \nD. #",
        "3. Which data type stores fractional numbers?\nA. int\nB. float\nC. char\nD. bool",
        "4. Which operator is 'address of'?\nA. *\nB. &\nC. ->\nD. %",
        "5. STL stands for?\nA. Simple Template Library\nB. Standard Template Library\nC. Static Type Logic\nD. Single Test Line",
        "6. Loop that executes at least once?\nA. for\nB. while\nC. do-while\nD. none",
        "7. Header file for cin/cout?\nA. <stdio.h>\nB. <iomanip>\nC. <iostream>\nD. <conio.h>",
        "8. First element index in array?\nA. 1\nB. -1\nC. 0\nD. 10",
        "9. Which is NOT a keyword?\nA. volatile\nB. main\nC. friend\nD. export",
        "10. Statement terminator sign?\nA. .\nB. :\nC. ;\nD. ,"
    };
    char answers[10] = {'C', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'B', 'C'};

    do {
        cout << "\n===============================" << endl;
        cout << "   ITM SKILLS UNIVERSITY" << endl;
        cout << " ONLINE EXAMINATION SYSTEM (C++)" << endl;
        cout << "===============================" << endl;
        cout << "1. Start Exam\n2. View Result (Detailed)\n3. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "\n[!] Error: Use numbers only." << endl;
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                startExam(studentName, score, totalQuestions, questions, answers);
                break;
            case 2: {
                if (studentName == "Guest") {
                    cout << "\n[!] No data found. Please start the exam first." << endl;
                } else {
                    float per = ((float)score / totalQuestions) * 100;
                    cout << "\n--- OFFICIAL RESULT SHEET ---" << endl;
                    cout << "Student Name : " << studentName << endl;
                    cout << "Score        : " << score << " / " << totalQuestions << endl;
                    cout << "Percentage   : " << per << "%" << endl;
                    cout << "Status       : " << (per >= 35.0 ? "PASS" : "FAIL") << endl;
                    cout << "\n--- DETAILED BREAKDOWN ---" << endl;
                    
                    for(int i=0; i<totalQuestions; i++) {
                        cout << "Q" << i+1 << ": ";
                        if(userResponses[i] == answers[i]) {
                            cout << "[CORRECT] (" << answers[i] << ")" << endl;
                        } else {
                            cout << "[WRONG] Yours: " << userResponses[i] << " | Correct: " << answers[i] << endl;
                        }
                    }
                }
                break;
            }
            case 3: cout << "Exiting system..." << endl; break;
            default: cout << "Invalid Option!" << endl;
        }
    } while (choice != 3);

    return 0;
}