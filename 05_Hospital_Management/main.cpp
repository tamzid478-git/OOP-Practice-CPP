#include <iostream>
#include <unordered_map>
using namespace std;

// Custom Exception
class invalid_name : public runtime_error
{
public:
    invalid_name(const string &msg) : runtime_error(msg) {}
};

// Abstract Class
class patient
{
protected:
    string patient_id;
    string patient_name;
    int age;

public:
    patient(string patient_id, string patient_name, int age)
    {
        this->patient_id = patient_id;
        this->patient_name = patient_name;
        this->age = age;
    }

    virtual void display_info()
    {
        cout << "Patient ID   : " << patient_id << endl;
        cout << "Patient Name : " << patient_name << endl;
        cout << "Age          : " << age << endl;
    }

    virtual double calculate_bill() = 0;

    string get_patient_id()
    {
        return patient_id;
    }

    // Method Overloading
    void admit()
    {
        cout << "Patient Admitted." << endl;
    }

    void admit(int room_no)
    {
        cout << "Patient Admitted in Room " << room_no << endl;
    }

    void discharge()
    {
        cout << "Patient Discharged." << endl;
    }

    void discharge(string date)
    {
        cout << "Patient Discharged on " << date << endl;
    }

    virtual ~patient() {}
};

// Indoor Patient
class indoor_patient : public patient
{
public:
    int num_of_days;

    indoor_patient(string patient_id, string patient_name, int age, int num_of_days)
        : patient(patient_id, patient_name, age)
    {
        this->num_of_days = num_of_days;
    }

    double calculate_bill() override
    {
        return num_of_days * 2000;
    }

    void display_info() override
    {
        patient::display_info();
        cout << "Patient Type : Indoor" << endl;
        cout << "Days         : " << num_of_days << endl;
    }
};

// Outdoor Patient
class outdoor_patient : public patient
{
public:
    double consultation_fee;

    outdoor_patient(string patient_id, string patient_name, int age, double consultation_fee)
        : patient(patient_id, patient_name, age)
    {
        this->consultation_fee = consultation_fee;
    }

    double calculate_bill() override
    {
        return consultation_fee;
    }

    void display_info() override
    {
        patient::display_info();
        cout << "Patient Type : Outdoor" << endl;
        cout << "Consultation Fee : " << consultation_fee << endl;
    }
};

// Hospital Class
class hospital
{
public:
    unordered_map<string, patient *> mp;

    void add_patient(patient *p)
    {
        mp[p->get_patient_id()] = p;
    }

    patient *search_patient(string id)
    {
        auto it = mp.find(id);

        if (it != mp.end())
            return it->second;

        throw invalid_name("Patient Not Found!");
    }

    void display()
    {
        cout << "\n========== Patient List ==========\n";

        for (auto x : mp)
        {
            x.second->display_info();
            cout << "Bill : " << x.second->calculate_bill() << endl;
            cout << "---------------------------" << endl;
        }
    }

    void calculate_hospital_bill()
    {
        double total_bill = 0;

        cout << "\n========== Bills ==========\n";

        for (auto x : mp)
        {
            double bill = x.second->calculate_bill();

            cout << x.first << " -> " << bill << endl;

            total_bill += bill;
        }

        cout << "\nTotal Hospital Bill = " << total_bill << endl;
    }

    ~hospital()
    {
        for (auto x : mp)
        {
            delete x.second;
        }
    }
};

int main()
{
    hospital hs;

    patient *ii = new indoor_patient("101", "Jihad", 22, 3);
    patient *oo = new outdoor_patient("102", "Rahim", 30, 900);

    hs.add_patient(ii);
    hs.add_patient(oo);

    hs.display();

    cout << endl;

    ii->admit();
    ii->admit(205);

    cout << endl;

    oo->discharge();
    oo->discharge("20-07-2026");

    cout << endl;

    hs.calculate_hospital_bill();

    cout << "\n========== Search ==========\n";

    try
    {
        patient *p = hs.search_patient("101");
        p->display_info();
    }
    catch (const invalid_name &e)
    {
        cout << e.what() << endl;
    }

    cout << "\n========== Invalid Search ==========\n";

    try
    {
        patient *p = hs.search_patient("999");
        p->display_info();
    }
    catch (const invalid_name &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
