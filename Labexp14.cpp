#include <iostream>
using namespace std;

class Transportation {
public:
    double calculateCost(double weight) {
        double cost = 0.0;
        if (weight >= 0.1 && weight <= 1.0) {
            cost = 5 + (2 * weight);
        } else if (weight > 1.0 && weight <= 10.0) {
            cost = 10 + (1.5 * weight);
        } else if (weight > 10.0 && weight <= 50.0) {
            cost = 20 + (1 * weight);
        } else {
            cout << "Invalid weight!" << endl;
            return -1;
        }
        return cost;
    }

    double calculateCost(double length, double width, double height) {
        double volume = (length / 100) * (width / 100) * (height / 100);
        double cost = 0.0;

        if (volume < 0.1) {
            cost = 10 + (0.5 * volume);
        } else if (volume >= 0.1 && volume < 0.5) {
            cost = 15 + (0.25 * volume);
        } else if (volume >= 0.5) {
            cost = 25 + (0.1 * volume);
        } else {
            cout << "Invalid dimensions!" << endl;
            return -1;
        }
        return cost;
    }

    double calculateCost(string packageType, double weight) {
        double cost = 0.0;

        if (packageType == "Ground") {
            if (weight >= 0.1 && weight <= 1.0) {
                cost = 5 + (2 * weight);
            } else if (weight > 1.0 && weight <= 10.0) {
                cost = 10 + (1.5 * weight);
            } else if (weight > 10.0 && weight <= 50.0) {
                cost = 20 + (1 * weight);
            }
        } else if (packageType == "Air") {
            if (weight >= 0.1 && weight <= 1.0) {
                cost = 10 + (3 * weight);
            } else if (weight > 1.0 && weight <= 10.0) {
                cost = 20 + (2 * weight);
            } else if (weight > 10.0 && weight <= 50.0) {
                cost = 30 + (1.5 * weight);
            }
        } else if (packageType == "Express") {
            if (weight >= 0.1 && weight <= 1.0) {
                cost = 15 + (4 * weight);
            } else if (weight > 1.0 && weight <= 10.0) {
                cost = 30 + (3 * weight);
            } else if (weight > 10.0 && weight <= 50.0) {
                cost = 40 + (2 * weight);
            }
        } else {
            cout << "Invalid package type!" << endl;
            return -1;
        }
        return cost;
    }
};

int main() {
    Transportation transport;

    double weight = 5.0;
    cout << "Cost for weight " << weight << "kg: " << transport.calculateCost(weight) << endl;

    double length = 150, width = 50, height = 30;
    cout << "Cost for dimensions (" << length << "cm, " << width << "cm, " << height << "cm): "
         << transport.calculateCost(length, width, height) << endl;

    string packageType = "Air";
    double weight2 = 7.5;
    cout << "Cost for " << packageType << " package with weight " << weight2 << "kg: "
         << transport.calculateCost(packageType, weight2) << endl;

    return 0;
}
