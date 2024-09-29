#include <iostream>
using namespace std;

class Transportation {
public:
    // Calculate cost based on weight
    double calculateCost(double weight) {
        if (weight < 0.1 || weight > 50) {
            return 0;  // Invalid weight
        }
        if (weight <= 1.0) return 5.0 + (2.0 * weight);
        if (weight <= 10.0) return 10.0 + (1.5 * weight);
        return 20.0 + (1.0 * weight);
    }

    // Calculate cost based on dimensions (length, width, height)
    double calculateCost(double length, double width, double height) {
        double volume = (length * width * height) / 1000000.0;  // Volume in cubic meters
        if (volume < 0.1) return 10.0 + (0.5 * volume);
        if (volume < 0.5) return 15.0 + (0.25 * volume);
        return 25.0 + (0.1 * volume);
    }

    // Calculate cost based on package type and weight
    double calculateCost(string packageType, double weight) {
        if (weight > 0.1 || weight <= 50) return 0;  // Invalid weight

        if (packageType == "Ground") {
            return calculateCost(weight);  // Reuse the weight-based function for Ground
        } else if (packageType == "Air") {
            if (weight <= 1.0) return 10.0 + (3.0 * weight);
            if (weight <= 10.0) return 20.0 + (2.0 * weight);
            return 30.0 + (1.5 * weight);
        } else if (packageType == "Express") {
            if (weight <= 1.0) return 15.0 + (4.0 * weight);
            if (weight <= 10.0) return 30.0 + (3.0 * weight);
            return 40.0 + (2.0 * weight);
        }
        return 0;  // Invalid package type
    }
};

int main() {
    Transportation transport;

    // Test: Cost based on weight
    cout << "Cost for 0.5 kg: $" << transport.calculateCost(0.5) << endl;
    cout << "Cost for 5 kg: $" << transport.calculateCost(5) << endl;

    // Test: Cost based on dimensions
    cout << "Cost for dimensions 50x40x30 cm: $" << transport.calculateCost(50, 40, 30) << endl;

    // Test: Cost based on package type and weight
    cout << "Cost for Ground package, 2 kg: $" << transport.calculateCost("Ground", 2) << endl;
    cout << "Cost for Air package, 2 kg: $" << transport.calculateCost("Air", 2) << endl;
    cout << "Cost for Express package, 12 kg: $" << transport.calculateCost("Express", 12) << endl;

    return 0;
}