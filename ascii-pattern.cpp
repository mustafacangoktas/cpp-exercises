#include <iostream>

using namespace std;

int main() {
    for (int part = 0; part < 3; part++) {
        bool isSameDesign = part % 2 == 0;
        // Top part of the repeated designs and the center design
        for (int i = 7; i > 4; i--) {
            int xCount = (7 - i) * 2 + 1;
            int spaceCount = i;

            // For the center part
            if (!isSameDesign) {
                if (i <= 5) {
                    // For the last * of the center part
                    if (i == 5) {
                        xCount = 1;
                        spaceCount = 7;
                    } else break;
                }
            }

            for (int j = 0; j < spaceCount; j++) cout << " ";
            for (int j = 0; j < xCount; j++) cout << "*";
            cout << endl;
        }

        // Bottom part of the repeated designs
        if (isSameDesign)
            for (int i = 4; i < 8; i++) {
                int xCount = (7 - i) * 2 + 1;
                int spaceCount = i;
                for (int j = 0; j < spaceCount; j++) cout << " ";
                for (int j = 0; j < xCount; j++) cout << "*";
                cout << endl;
            }
    }

    return 0;
}
