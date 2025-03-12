/*
    Lesson 3: The Copy Constructor in Depth

    What We Will Cover:
    -------------------
    - What is a **copy constructor**?
    - How does the **default copy constructor** work?
    - Understanding **shallow copies** and **deep copies**.
    - Implementing **custom copy constructors**.
    - Using **member initializer lists** in copy constructors.
    - Preventing copying using `= delete`.
    - Edge cases and real-world examples.

    The Rule of Three:
    ------------------
    - If a class defines **any** of these three functions, it should define all three:
        1. **Copy Constructor**
        2. **Copy Assignment Operator (`operator=`)**
        3. **Destructor**

    - This lesson focuses **only on copy constructors**; destructors and assignment operators
      will be covered in later lessons.
*/

#include <cstring>   // For deep copy with dynamic memory
#include <iostream>
#include <string>    // For std::string

/*
    1. The Default Copy Constructor (Shallow Copy)
    ----------------------------------------------
    - If no copy constructor is defined, C++ provides a **default** copy constructor.
    - The default copy constructor performs a **shallow copy** (copies member values,
      including pointers, which means both objects share the same memory).
    - This can be problematic if the class contains **pointers** to dynamically allocated memory.
*/

class Bike {
private:
    char* brand;

public:
    // Constructor (Allocates dynamic memory for brand)
    Bike(const char* bikeBrand) {
        brand = new char[strlen(bikeBrand) + 1];  // Allocate memory
        strcpy(brand, bikeBrand);
    }

    // Function to display the bike's brand
    void show() const { 
        std::cout << "Bike brand: " << brand << std::endl; 
    }

    // Function to modify the brand (for demonstration purposes)
    void modifyBrand(std::size_t index, char newChar) {
        if (index < strlen(brand)) {
            brand[index] = newChar;
        }
    }

    // IMPORTANT:
    // We intentionally do not define a destructor here.
    // In a real application, not freeing allocated memory causes a leak.
    // However, if we defined a destructor, the default shallow copy would
    // lead to a double deletion (two objects pointing to the same memory).
};

void test_shallow_copy() {
    std::cout << "Test: Shallow Copy Demonstration (Bike)" << std::endl;
    Bike bike1("Yamaha");
    Bike bike2 = bike1;  // ❌ Shallow copy: both bike1 and bike2 share the same 'brand' pointer

    std::cout << "Before modifying bike1:" << std::endl;
    bike1.show();
    bike2.show();

    // Modify bike1's brand (this change affects bike2 as well)
    bike1.modifyBrand(0, 'K');

    std::cout << "After modifying bike1:" << std::endl;
    bike1.show();
    bike2.show();

    std::cout << "Note: With shallow copy, both objects share the same memory. "
              << "If a destructor were used to free the memory, it could lead to double deletion." 
              << std::endl;
}

/*
    2. Custom Copy Constructor (Deep Copy)
    --------------------------------------
    - A **deep copy** creates a new, independent copy of dynamic memory.
    - This ensures that modifying one object does not affect the other.
*/

class Laptop {
private:
    char* brand;

public:
    // Constructor (Allocates memory)
    Laptop(const char* laptopBrand) {
        brand = new char[strlen(laptopBrand) + 1];  // Allocate memory
        strcpy(brand, laptopBrand);
    }

    // Custom Copy Constructor (Deep Copy)
    Laptop(const Laptop& other) {
        brand = new char[strlen(other.brand) + 1];  // Allocate new memory
        strcpy(brand, other.brand);
        std::cout << "Laptop copied (deep copy): " << brand << std::endl;
    }

    // Function to display the laptop's brand
    void show() const { 
        std::cout << "Laptop: " << brand << std::endl; 
    }

    // Function to modify the brand (for demonstration purposes)
    void modifyBrand(std::size_t index, char newChar) {
        if (index < strlen(brand)) {
            brand[index] = newChar;
        }
    }

    // Destructor to free allocated memory (avoids memory leak)
    ~Laptop() { 
        delete[] brand; 
    }
};

void test_deep_copy() {
    std::cout << "\nTest: Deep Copy Demonstration (Laptop)" << std::endl;
    Laptop laptop1("MacBook");
    Laptop laptop2 = laptop1;  // ✅ Deep copy: separate memory allocation

    std::cout << "Before modifying laptop1:" << std::endl;
    laptop1.show();
    laptop2.show();

    // Modify laptop1's brand (laptop2 remains unchanged)
    laptop1.modifyBrand(0, 'H');

    std::cout << "After modifying laptop1:" << std::endl;
    laptop1.show();
    laptop2.show();
}

/*
    3. Using Member Initialization List in Copy Constructor
    -------------------------------------------------------
    - Using an **initializer list** in the copy constructor can be more efficient.
*/

class Truck {
private:
    std::string brand;
    int capacity;  // Capacity in tons

public:
    // Constructor using initializer list
    Truck(const std::string& truckBrand, int truckCapacity)
        : brand(truckBrand), capacity(truckCapacity) {}

    // Copy Constructor using Initialization List
    Truck(const Truck& other)
        : brand(other.brand), capacity(other.capacity) {
        std::cout << "Truck copied: " << brand 
                  << ", Capacity: " << capacity << " tons" << std::endl;
    }

    void show() const {
        std::cout << "Truck brand: " << brand 
                  << ", Capacity: " << capacity << " tons" << std::endl;
    }
};

void test_copy_with_initialization_list() {
    std::cout << "\nTest: Copy Constructor with Initialization List (Truck)" << std::endl;
    Truck truck1("Volvo", 20);
    Truck truck2 = truck1;  // Copy constructor is called

    truck1.show();
    truck2.show();
}

/*
    4. Preventing Copying with `= delete`
    -------------------------------------
    - To prevent copying of an object, the copy constructor can be marked as `= delete`.
*/

class NotCopiable {
public:
    NotCopiable() {}

    // Delete the Copy Constructor to prevent copying
    NotCopiable(const NotCopiable& other) = delete;
};

void test_deleted_copy_constructor() {
    std::cout << "\nTest: Deleted Copy Constructor (NotCopiable)" << std::endl;
    NotCopiable obj1;
    // Uncommenting the following line will cause a compile-time error:
    // NotCopiable obj2 = obj1;
    std::cout << "Copying is prevented for NotCopiable objects." << std::endl;
}

/*
    5. Complex Copy Constructor Example (Multiple Attributes)
    ---------------------------------------------------------
    - A realistic example with multiple attributes and dynamic memory.
*/

class Plane {
private:
    std::string brand;
    int* passengers;  // Pointer to an integer representing passenger capacity

public:
    // Constructor
    Plane(const std::string& planeBrand, int capacity) : brand(planeBrand) {
        passengers = new int(capacity);  // Allocate memory and initialize with capacity
    }

    // Custom Copy Constructor (Deep Copy)
    Plane(const Plane& other) : brand(other.brand) {
        passengers = new int(*other.passengers);  // Allocate new memory and copy value
        std::cout << "Plane copied: " << brand 
                  << ", Passengers: " << *passengers << std::endl;
    }

    void show() const {
        std::cout << "Plane: " << brand 
                  << ", Passengers: " << *passengers << std::endl;
    }

    // Destructor to free allocated memory
    ~Plane() {
        delete passengers;
    }
};

void test_complex_copy_constructor() {
    std::cout << "\nTest: Complex Copy Constructor (Plane)" << std::endl;
    Plane plane1("Boeing", 180);
    Plane plane2 = plane1;  // Deep copy is performed

    plane1.show();
    plane2.show();
}

// Main Function to Run Tests
int main() {
    test_shallow_copy();
    std::cout << "----------------------------" << std::endl;

    test_deep_copy();
    std::cout << "----------------------------" << std::endl;

    test_copy_with_initialization_list();
    std::cout << "----------------------------" << std::endl;

    test_deleted_copy_constructor();
    std::cout << "----------------------------" << std::endl;

    test_complex_copy_constructor();
    std::cout << "----------------------------" << std::endl;

    return 0;
}