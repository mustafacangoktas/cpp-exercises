#include <iostream>
#include <cmath>

using namespace std;

/**
 * Used functions: pow, sqrt, max, sin, cos, abs
 */

int main() {
    const double gravity = -9.81;

    double initialVelocity = 0, launchAngle = 0, initialHeight = 0;

    cout << "Enter the initial velocity (m/s):" << endl;
    cin >> initialVelocity;

    cout << "Enter the launch angle (degrees):" << endl;
    cin >> launchAngle;

    cout << "Enter the initial height (meters):" << endl;
    cin >> initialHeight;

    double angleRadians = launchAngle * M_PI / 180;

    // Components of the initial velocity
    double velocityX = initialVelocity * cos(angleRadians);
    double velocityY = initialVelocity * sin(angleRadians);

    // Time until vertical velocity reaches 0
    double timeToPeak = abs(velocityY / gravity);

    // Maximum height = y0 + Vyt + 0.5 * a * t^2
    double maxHeight = initialHeight +
                       (velocityY * timeToPeak) +
                       (0.5 * gravity * pow(timeToPeak, 2));

    maxHeight = max(maxHeight, initialHeight);

    // Final vertical velocity using v^2 = v0^2 + 2aΔy
    double finalVelocityY = -sqrt(
            pow(velocityY, 2) +
            2 * abs(gravity) * initialHeight
    );

    // Final total velocity
    double finalVelocity = sqrt(
            pow(velocityX, 2) +
            pow(finalVelocityY, 2)
    );

    // Total flight time = time to peak + time from peak to ground
    double totalTime = timeToPeak + sqrt(
            2 * maxHeight /
            abs(gravity)
    );

    // Horizontal distance traveled
    double horizontalDistance = velocityX * totalTime;

    cout << "Maximum height: " << maxHeight << " m" << endl;
    cout << "Final vertical velocity: " << finalVelocityY << " m/s" << endl;
    cout << "Final total velocity: " << finalVelocity << " m/s" << endl;
    cout << "Total flight time: " << totalTime << " s" << endl;
    cout << "Horizontal distance: " << horizontalDistance << " m" << endl;

    return 0;
}