/*
    Lesson 2: Default and Parameterized Constructors in Depth

    What We Will Cover:
    -------------------
    - Understanding **Default Constructors** in depth
    - Understanding **Parameterized Constructors** in depth
    - Using **constructor overloading** (multiple constructors in the same class)
    - Using **default values in constructors**
    - Using **constructor initialization lists** (`: member(value)`)
    - Using **explicit constructors** (`explicit` keyword)
    - Exploring **common mistakes and best practices**
*/

#include <iostream>

/*
    1. Default Constructor (Deep Understanding)
    -------------------------------------------
    - A default constructor is a constructor that **takes no parameters**.
    - If no constructor is defined, C++ automatically provides an **implicit default
   constructor**.
    - If we define **any** constructor, the **implicit default constructor is
   removed**.
*/

class Car {
private:
    std::string brand = "Unknown";  // Default value

public:
    // Default Constructor (Explicitly Defined)
    Car() { std::cout << "Car object created with default constructor." << std::endl; }

    void show() { std::cout << "Car brand: " << brand << std::endl; }
};

void test_default_constructor() {
    Car car1;
    car1.show();
}

/*
    Expected Output:
    ----------------
    Car object created with default constructor.
    Car brand: Unknown
*/


/*
    2. Parameterized Constructor (Deep Understanding)
    -------------------------------------------------
    - A parameterized constructor allows **passing values to initialize attributes**.
    - When we define a **parameterized constructor**, the compiler does **not** provide
   a default constructor.
*/

class Bike {
private:
    std::string brand;

public:
    // Parameterized Constructor
    Bike(std::string bikeBrand) {
        brand = bikeBrand;
        std::cout << "Bike object created with brand: " << brand << std::endl;
    }

    void show() { std::cout << "Bike brand: " << brand << std::endl; }
};

void test_parameterized_constructor() {
    Bike bike1("Yamaha");
    Bike bike2("Ducati");

    bike1.show();
    bike2.show();

    // Bike bike3; ❌ ERROR: No default constructor available!
}

/*
    Expected Output:
    ----------------
    Bike object created with brand: Yamaha
    Bike object created with brand: Ducati
    Bike brand: Yamaha
    Bike brand: Ducati
*/

/*
    3. Constructor Overloading (Multiple Constructors in One Class)
    ---------------------------------------------------------------
    - We can define multiple constructors with **different parameter lists**.
*/

class Laptop {
private:
    std::string brand;
    int ram;

public:
    // Default Constructor (Using Initialization List)
    Laptop() : brand("Unknown"), ram(8) {
        std::cout << "Default constructor called! Brand: " << brand << ", RAM: " << ram
                  << "GB" << std::endl;
    }

    // Parameterized Constructor (Using Initialization List)
    Laptop(std::string laptopBrand, int laptopRam)
        : brand(laptopBrand), ram(laptopRam) {
        std::cout << "Parameterized constructor called! Brand: " << brand
                  << ", RAM: " << ram << "GB" << std::endl;
    }

    void show() {
        std::cout << "Laptop: " << brand << ", RAM: " << ram << "GB" << std::endl;
    }
};

void test_constructor_overloading() {
    Laptop laptop1;              // Calls default constructor
    Laptop laptop2("Dell", 16);  // Calls parameterized constructor

    laptop1.show();
    laptop2.show();
}

/*
    Expected Output:
    ----------------
    Default constructor called! Brand: Unknown, RAM: 8GB
    Parameterized constructor called! Brand: Dell, RAM: 16GB
*/

/*
    4. Using the Explicit Constructor
    ---------------------------------
    - `explicit` prevents **implicit conversions**.
*/

class Phone {
private:
    std::string brand;
    int battery;

public:
    // Explicit Constructor
    explicit Phone(std::string phoneBrand, int batteryCapacity)
        : brand(phoneBrand), battery(batteryCapacity) {
        std::cout << "Phone object created! Brand: " << brand
                  << ", Battery: " << battery << "mAh" << std::endl;
    }

    void show() {
        std::cout << "Phone: " << brand << ", Battery: " << battery << "mAh"
                  << std::endl;
    }
};

void test_explicit_constructor() {
    Phone phone1("Samsung", 5000);  // ✅ Allowed
    // Phone phone2 = {"Apple", 3200}; ❌ ERROR: Cannot perform implicit conversion
    phone1.show();
}

/*
    Expected Output:
    ----------------
    Phone object created! Brand: Samsung, Battery: 5000mAh
*/

/*
    5. Using Default Arguments in Constructors
    ------------------------------------------
    - Instead of defining multiple constructors, **default values** can be used.
*/

class Truck {
private:
    std::string brand;
    int capacity;

public:
    // Constructor with Default Arguments
    Truck(std::string truckBrand = "Unknown", int truckCapacity = 0)
        : brand(truckBrand), capacity(truckCapacity) {
        std::cout << "Truck created: " << brand << ", Capacity: " << capacity
                  << " tons" << std::endl;
    }

    void show() {
        std::cout << "Truck: " << brand << ", Capacity: " << capacity << " tons"
                  << std::endl;
    }
};

void test_constructor_with_defaults() {
    Truck truck1;               // Uses default values
    Truck truck2("Volvo", 20);  // Uses provided values

    truck1.show();
    truck2.show();
}

/*
    Expected Output:
    ----------------
    Truck created: Unknown, Capacity: 0 tons
    Truck created: Volvo, Capacity: 20 tons
*/
class Plane {
private:
    std::string brand = "Unknown";
    int capacity;

public:
    // Default Constructor (Implemented inside the class)
    Plane() : capacity(0), brand("escobar Air") {
        std::cout << "Default constructor called for Plane!" << std::endl;
    }

    // Parameterized Constructor (Implemented outside the class)
    Plane(std::string planeBrand, int planeCapacity);

    void show();
};
Plane::Plane(std::string planeBrand, int planeCapacity) {
    brand = planeBrand;
    capacity = planeCapacity;
    std::cout << "Parameterized constructor called! Brand: " << brand
              << ", Capacity: " << capacity << " tons" << std::endl;
}

void Plane::show() {
    std::cout << "Plane: " << brand << ", Capacity: " << capacity << " tons"
              << std::endl;
}

void test_plane(){
    Plane plane1;                  // Calls default constructor
    Plane plane2("Boeing", 20);      // Calls parameterized constructor

    plane1.show();
    plane2.show();
}

/*
    Summary:
    - **Default Constructors**: Automatically provided unless any constructor is
   defined.
    - **Parameterized Constructors**: Allow user-defined values but remove the default
   constructor.
    - **Constructor Overloading**: Multiple constructors allow different ways to create
   objects.
    - **Initialization Lists**: More efficient than assigning values inside the
   constructor.
    - **Explicit Constructor (`explicit`)**: Prevents implicit conversions.
    - **Default Arguments**: Allow a constructor to be both default and parameterized.
*/

// Single main() function to test all cases
int main() {
    std::cout << "Testing Default Constructor:" << std::endl;
    test_default_constructor();
    std::cout << "----------------------------" << std::endl;

    std::cout << "Testing Parameterized Constructor:" << std::endl;
    test_parameterized_constructor();
    std::cout << "----------------------------" << std::endl;

    std::cout << "Testing Constructor Overloading with Initialization List:"
              << std::endl;
    test_constructor_overloading();
    std::cout << "----------------------------" << std::endl;

    std::cout << "Testing Explicit Constructor (Prevents Implicit Conversions):"
              << std::endl;
    test_explicit_constructor();
    std::cout << "----------------------------" << std::endl;

    std::cout << "Testing Constructor with Default Arguments:" << std::endl;
    test_constructor_with_defaults();
    std::cout << "----------------------------" << std::endl;

    std::cout << "Testing Plane:" << std::endl;
    test_plane();
    std::cout << "----------------------------" << std::endl;

    return 0;
}