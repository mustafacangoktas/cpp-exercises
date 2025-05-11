#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int studentCount = 60;
    const int weekCount = 10;

    srand(time(0));

    int matrix[studentCount][weekCount];
    string names[studentCount];

    // Generate student names
    for (int i = 0; i < studentCount; i++) {
        names[i] = "Student" + to_string(i + 1);
    }

    // Fill the attendance matrix with custom probabilities
    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < weekCount; j++) {
            int randomValue = rand() % 100; // Random number between 0-99

            if (randomValue < 5) {
                // 5% probability (0-4)
                matrix[i][j] = 2; // signed by someone else
            } else if (randomValue < 20) {
                // 15% probability (5-19)
                matrix[i][j] = 0; // absent
            } else {
                // 80% probability (20-99)
                matrix[i][j] = 1; // present
            }
        }
    }

    int passCount = 0, failCount = 0, totalProxySign = 0;
    string proxySigners[studentCount];  // Students who had someone else sign for them

    for (int i = 0; i < studentCount; i++) {
        int absenceCount = 0;
        int proxySignCount = 0;

        for (int j = 0; j < weekCount; j++) {
            if (matrix[i][j] == 0) absenceCount++;
            if (matrix[i][j] == 2) proxySignCount++;
        }

        if (absenceCount > 4 || proxySignCount > 1)
            failCount++;
        else
            passCount++;

        if (proxySignCount > 0) {
            totalProxySign++;
            proxySigners[totalProxySign] = names[i];
        }
    }

    cout << "Passed students: " << passCount << endl;
    cout << "Failed students: " << failCount << endl;
    cout << "Students who had someone else sign for them: " << totalProxySign << endl;
    cout << "Names of students who had someone else sign for them:" << endl;
    for (int i = 0; i < totalProxySign; i++) {
        cout << proxySigners[i] << endl;
    }

    return 0;
}