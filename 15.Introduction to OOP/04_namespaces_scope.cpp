/*
======================================
  COURSE 4: ENCAPSULATION BEST PRACTICES
======================================

📌 **Why is Direct Attribute Access Bad?**
   - If attributes are public, any part of the program can modify them incorrectly.
   - Example of a mistake: allowing negative temperatures in a sensor class.

📌 **Why Use Getters and Setters?**
   - Getters allow **read-only** access when needed.
   - Setters enforce **valid data constraints**.
   - Prevents direct manipulation of object state.

📌 **Best Practices for Encapsulation**
   - **Keep attributes private** to maintain control.
   - **Use setters carefully** to enforce business rules.
   - **Avoid unnecessary getters/setters** if an attribute should not be modified externally.
   - **Expose only necessary information** through methods.

📌 **Example: A Temperature Sensor**
   - The temperature cannot be below absolute zero (-273.15°C).
   - We enforce this rule inside the setter.
*/

#include <iostream>

class Temperature {
private:
    double celsius;  // Private attribute

public:
    // Constructor with validation
    Temperature(double temp) {
        if (temp < -273.15) {
            std::cerr << "Error: Temperature below absolute zero! Setting to -273.15°C." << std::endl;
            celsius = -273.15;
        } else {
            celsius = temp;
        }
    }

    // Getter: Read temperature safely
    double getCelsius() const {
        return celsius;
    }

    // Setter: Prevent invalid temperature
    void setCelsius(double temp) {
        if (temp >= -273.15) {
            celsius = temp;
        } else {
            std::cerr << "Error: Cannot set temperature below absolute zero!" << std::endl;
        }
    }

    // Convert to Fahrenheit (example of a useful method)
    double toFahrenheit() const {
        return (celsius * 9 / 5) + 32;
    }
};

int main() {
    Temperature sensor(-300);  // Invalid, should be corrected
    std::cout << "Current temperature: " << sensor.getCelsius() << "°C" << std::endl;

    sensor.setCelsius(-280);  // Invalid, should not change
    sensor.setCelsius(25);    // Valid, should update

    std::cout << "Updated temperature: " << sensor.getCelsius() << "°C" << std::endl;
    std::cout << "Temperature in Fahrenheit: " << sensor.toFahrenheit() << "°F" << std::endl;

    return 0;
}