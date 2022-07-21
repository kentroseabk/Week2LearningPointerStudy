// Week2LearningPointerStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Car
{
private:

public:
    string make;

    Car() {};

    Car(string make) : 
        make (make)
    {
    }

    friend ostream& operator<<(std::ostream& os, const Car &myCar)
    {
        os << myCar.make;
        return os;
    }
};

void DisplayInfo(Car myCar, Car* myCarPtr, Car& myCarRef)
{
    cout << "myCar info: " << myCar << endl;
    cout << "myCarPtr: " << myCarPtr << endl;
    cout << "myCarRef: " << myCarRef << endl;
    cout << "myCarRef address: " << &myCarRef << endl;
    cout << endl;
}

int main()
{
    Car myCar("Honda");

    Car* myCarPtr = &myCar;
    Car& myCarRef = myCar;

    DisplayInfo(myCar, myCarPtr, myCarRef);

    cout << "Changing info..." << endl;
    myCarRef.make = "Toyota";

    DisplayInfo(myCar, myCarPtr, myCarRef);

    cout << "Changing info..." << endl;
    myCarPtr->make = "Nissan";

    DisplayInfo(myCar, myCarPtr, myCarRef);

    cout << "Changing info..." << endl;
    myCar.make = "Dodge";

    DisplayInfo(myCar, myCarPtr, myCarRef);

    cout << "Dereferencing via (*myCarPtr) and myCarPtr->..." << endl;
    cout << (*myCarPtr).make << ", " << myCarPtr->make << endl;

    cout << "Done...";
}
