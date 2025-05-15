#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int studentCount = 60;
    const int weekCount = 10;

    srand(time(0));

    int matrix[studentCount][weekCount];
    string names[10] = {"James", "Emma", "Michael", "Olivia", "William", "Ava", "Joseph", "Sophia", "Daniel",
                        "Isabella"};
    string lastnames[6] = {"Smith", "Johnson", "Brown", "Williams", "Jones", "Garcia"};
    string fullNames[studentCount];

    // Generate 60 unique full names
    for (int i = 0; i < studentCount; i++) {
        fullNames[i] = names[i % 10] + " " + lastnames[i % 6];
    }

    // Fill the attendance matrix
    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < weekCount; j++) {
            int randomValue = rand() % 100;

            if (randomValue < 5) {
                matrix[i][j] = 2; // signed by someone else
            } else if (randomValue < 20) {
                matrix[i][j] = 0; // absent
            } else {
                matrix[i][j] = 1; // present
            }
        }
    }

    int passCount = 0, failCount = 0;

    cout << "--- Student Attendance Report ---" << endl;

    for (int i = 0; i < studentCount; i++) {
        int presentCount = 0;
        int absentCount = 0;
        int proxyCount = 0;

        for (int j = 0; j < weekCount; j++) {
            if (matrix[i][j] == 1) presentCount++;
            else if (matrix[i][j] == 0) absentCount++;
            else if (matrix[i][j] == 2) proxyCount++;
        }

        string status = (absentCount > 4 || proxyCount > 1) ? "Failed" : "Passed";
        if (status == "Passed") passCount++;
        else failCount++;

        cout << fullNames[i] << ": "
             << presentCount << " times present | "
             << absentCount << " times absent | "
             << proxyCount << " times proxy signed -> "
             << status << endl;
    }

    cout << "\n--- Summary ---\n";
    cout << "Total students: " << studentCount << endl;
    cout << "Passed students: " << passCount << endl;
    cout << "Failed students: " << failCount << endl;

    return 0;
}