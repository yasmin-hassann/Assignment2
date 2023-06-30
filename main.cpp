
#include <iostream>
#include "SingleLinkedList.h"
#include "Employee.h"

int main() {
    SingleLinkedList<int> myList;

    myList.push_front(10);
    myList.push_front(5);
    myList.push_back(20);

    myList.displayList();  // Output: List: 5 10 20

    myList.pop_front();
    myList.pop_back();

    myList.displayList();  // Output: List: 10

    myList.insert(1, 15);

    myList.displayList();  // Output: List: 10 15

    myList.remove(0);

    myList.displayList();  // Output: List: 15

    int item = 20;
    size_t index = myList.find(item);
    if (index != myList.find(item)) {
        std::cout << "Item " << item << " found at index " << index << std::endl;
    }
    else {
        std::cout << "Item " << item << " not found" << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    // Create instances of Professional and Nonprofessional employees
    Professional prof("John Doe", 30, 5000.0, 20);
    Nonprofessional nonProf("Jane Smith", 25, 15.0, 80);
    // Display information for the Professional employee
    std::cout << "Professional Employee: " << prof.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: " << prof.computeHealthCareContributions() << std::endl;
    std::cout << "Vacation Days: " << prof.computeVacationDays() << std::endl;
    // Display information for the Nonprofessional employee
    std::cout << "\nNonprofessional Employee: " << nonProf.calculateWeeklySalary() << std::endl;
    std::cout << "Health Care Contributions: " << nonProf.computeHealthCareContributions() << std::endl;
    std::cout << "Vacation Days: " << nonProf.computeVacationDays() << std::endl;
    return 0;
}
