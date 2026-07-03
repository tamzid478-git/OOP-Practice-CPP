#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class vehicles
{
public:
    int vehicle_id;
    string driver_name;
    int capacity;

    vehicles(int vehicle_id, string driver_name, int capacity) //constructor
    {
        this->vehicle_id = vehicle_id;
        this->driver_name = driver_name;
        this->capacity = capacity;
    }
    virtual void displayinfo()     //function   
    {
        cout << "Vehicle_id_no=" << vehicle_id << endl;
        cout << "Drivers name of vehicle = " << driver_name << endl;
        cout << "Capacity of vehicle = " << capacity << endl;
    }
    virtual void fare_calculation(int passanger) = 0;     //function
};


class bus : public vehicles       //derived class
{
public:

    int route_number;
    bus(int vehicle_id, string name, int capacity, int route_number) : vehicles(vehicle_id, name, capacity)//constructor
    {
        this->route_number = route_number;
    }

    void displayinfo() override     //function
    {
        cout << "Details of bus : " << endl;
        cout << "Bus number =" << vehicle_id << endl;
        cout << "Driver's name of this bus = " << driver_name << endl;
        cout << "Capacity of this bus = " << capacity << endl;
        cout << "Route number of bus = " << route_number << endl;
    }

    void fare_calculation(int passanger) override      //function   
    {
        cout<<"Total fare of bus : "<< passanger * 50<<endl;
    };
};

class car : public vehicles      //derived class 
{
public:
    string car_type;
    car(int vehicle_id, string name, int capacity, string car_type) : vehicles(vehicle_id, name, capacity)
    {
        this->car_type = car_type;
    }

    void displayinfo() override     //function
    {
        cout << "Details of car :" << endl;
        cout << "Car number =" << vehicle_id << endl;
        cout << "Driver's name of this car = " << driver_name << endl;
        cout << "Capacity of this car = " << capacity << endl;
        cout << "Brand name of this car = " << car_type << endl;
    }
    void fare_calculation(int passanger) override    ///function
    {
        cout<<"Total fare of car  : "<< passanger * 100<<endl;
    };
};

int main()      //main function 
{
    vector<vehicles *> v;           //pointer as a type for dynamic allocation 
    int n;             
    cout << "Enter number of vehicles : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int choice;
        cout << "Select your choice ( 1 or 2 ) : ";
        cin >> choice;
        if(choice !=1  &&  choice != 2)
        {
            cout<<"Invalid choice (Try Again) "<<endl;
            return 0;
        }
        else if (choice == 1)
        {
            int bus_id;
            cout << "Enter bus id : ";
            cin >> bus_id;
            string driver_name;
            cout << "Enter driver name : ";
            cin >> driver_name;
            int cap;
            cout << "Enter capacity of bus : ";
            cin >> cap;
            int rout;
            cout << "Enter route number : ";
            cin >> rout;

            v.push_back(new bus(bus_id, driver_name, cap, rout));
        }

        else if (choice == 2)
        {
            int car_id;
            cout << "Enter car id : ";
            cin >> car_id;
            string driver_name;
            cout << "Enter driver name : ";
            cin >> driver_name;
            int cap;
            cout << "Enter capacity of car : ";
            cin >> cap;
            string car_type;
            cout << "Enter car's company name ";
            cin >> car_type;

            v.push_back(new car(car_id, driver_name, cap, car_type));
        }
    }

    cout<<endl<<endl;
    for (auto x : v)
    {
        x->displayinfo();
        cout<<endl;
    }
    cout<<endl<<endl;
    
    string serch_name;
    cout<<"Enter serch  name : ";
    cin>>serch_name;
    for(auto x : v)
    {
        if(x->driver_name==serch_name)
        x->displayinfo();
        cout<<endl;
    }
    cout<<endl;
    for(auto x : v)
    {
        int passanger ;
        cout<<"Enter how many passanger are there? : ";
        cin>>passanger;
        x->fare_calculation(passanger);
    }
    return 0;
}
