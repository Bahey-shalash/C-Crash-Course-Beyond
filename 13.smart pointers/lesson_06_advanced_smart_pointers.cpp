/*  
    ========================================================
    Lesson 6: Advanced Smart Pointer Techniques
    ========================================================

    # What You'll Learn:
    - Custom deleters for smart pointers
    - Using smart pointers with classes
    - `enable_shared_from_this<T>` for safe `shared_ptr` retrieval
    - Using smart pointers in multithreading
    - Performance considerations and best practices

    # Why Learn This?
    Understanding advanced smart pointer techniques helps avoid **memory leaks, 
    dangling pointers, and performance issues** in modern C++ applications.
*/

#include <iostream>
#include <memory>
#include <thread>
#include <vector>

//
// 1️⃣ Custom Deleters for Smart Pointers
//
void customDeleterExample() {
    std::unique_ptr<int, void(*)(int*)> ptr(new int(99), [](int* p) {
        std::cout << "Custom Deleter Called for: " << *p << "\n";
        delete p;
    });

    std::cout << "Value inside customDeleter ptr: " << *ptr << "\n";
}

//
// 2️⃣ Using Smart Pointers in Classes
//
class Person {
public:
    std::string name;
    std::shared_ptr<Person> bestFriend;  // Shared ownership example

    Person(std::string n) : name(n) {
        std::cout << "Person created: " << name << "\n";
    }

    ~Person() {
        std::cout << "Person destroyed: " << name << "\n";
    }
};

void smartPointerWithClass() {
    std::shared_ptr<Person> p1 = std::make_shared<Person>("Alice");
    std::shared_ptr<Person> p2 = std::make_shared<Person>("Bob");

    p1->bestFriend = p2; // Shared ownership
    p2->bestFriend = p1; // 🚨 Circular reference (use weak_ptr to fix this!)
}

//
// 3️⃣ `enable_shared_from_this<T>` to Avoid Issues
//
class SharedThis : public std::enable_shared_from_this<SharedThis> {
public:
    void show() {
        std::cout << "Inside SharedThis instance.\n";
    }

    std::shared_ptr<SharedThis> getShared() {
        return shared_from_this(); // Safe way to get shared_ptr from this
    }
};

void enableSharedFromThisExample() {
    std::shared_ptr<SharedThis> obj = std::make_shared<SharedThis>();
    std::shared_ptr<SharedThis> obj2 = obj->getShared();

    std::cout << "Reference count: " << obj.use_count() << "\n"; // 2
    obj2->show();
}

//
// 4️⃣ Smart Pointers in Multithreading
//
void threadFunction(std::shared_ptr<int> sharedData) {
    std::cout << "Thread received shared_ptr with value: " << *sharedData << "\n";
}

void multithreadingWithSharedPtr() {
    std::shared_ptr<int> sharedData = std::make_shared<int>(500);

    std::thread t1(threadFunction, sharedData);
    std::thread t2(threadFunction, sharedData);

    t1.join();
    t2.join();

    std::cout << "Final Reference Count: " << sharedData.use_count() << "\n"; // Should be 1
}

//
// 5️⃣ Performance Considerations
//
void performanceComparison() {
    const int size = 1'000'000;

    // Unique Pointer
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::unique_ptr<int>> uniqueVec;
    for (int i = 0; i < size; ++i) {
        uniqueVec.push_back(std::make_unique<int>(i));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Unique Pointer Time: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
              << "ms\n";

    // Shared Pointer
    start = std::chrono::high_resolution_clock::now();
    std::vector<std::shared_ptr<int>> sharedVec;
    for (int i = 0; i < size; ++i) {
        sharedVec.push_back(std::make_shared<int>(i));
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Shared Pointer Time: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
              << "ms\n";
}

int main() {
    std::cout << "Demonstrating Custom Deleters:\n";
    customDeleterExample();

    std::cout << "\nDemonstrating Smart Pointers in Classes:\n";
    smartPointerWithClass();

    std::cout << "\nDemonstrating `enable_shared_from_this<T>`:\n";
    enableSharedFromThisExample();

    std::cout << "\nDemonstrating Smart Pointers in Multithreading:\n";
    multithreadingWithSharedPtr();

    std::cout << "\nComparing Performance of Smart Pointers:\n";
    performanceComparison();

    return 0;
}