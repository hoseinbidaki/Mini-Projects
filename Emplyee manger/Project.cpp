#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void MENU();
void read_from_file();
double getAve();
void Ave();
void topEmployee();
void PosSearch();
void search_employee();
void Delete_employee ();
bool id_checker(string a, string b);
void Edit_employee();
void IncreaseBime();
void DecreaseBime ();
void searchByDate();

class Employee
{
protected:
    string name;
    string personalID;
    string organizational_position;
    string education_level;
    int salary;
public:
    Employee(string a, string b, string c, string d, int e);
    Employee(){}

    string getName();
    string getPersonalID();
    string getOrgamozational_position();
    string getEducationLevel();
    int getSalary();

    void setName(string a);
    void setPersonalID(string a);
    void setOrgamozational_position(string a);
    void setEducationLevel(string a);
    void setSalary(int x);
    void print();
};

class EmployeeInsurance : Employee
{
private:
    string InsuranceID;
    string establish;
    int payment;
    int recieved;

public:
    EmployeeInsurance(string a, string b, string c, string d, int x, string e, string f, int g, int h);
    EmployeeInsurance(){}
    string getInsuranceID();
    string getEstablish();
    string getName() {return Employee::getName();}
    string getEducationLevel() {return Employee::getEducationLevel();}
    string getOrgamozational_position() {return Employee::getOrgamozational_position();}
    string getPersonalID() {return Employee::getPersonalID();}
    int getPayment();
    int getRecieved();
    int getSalary() {return Employee::getSalary();}


    void setName(string a) {Employee::setName(a);};
    void setPersonalID(string a) {Employee::setPersonalID(a);};
    void setOrgamozational_position(string a) {Employee::setOrgamozational_position(a);}
    void setEducationLevel(string a) {Employee::setEducationLevel(a);}
    void setSalary(int x) {Employee::setSalary(x);}

    void setInsuranceID(string a);
    void setEstablish(string a);
    void setPayment(int x);
    void setRecieved(int x);
    void print();
};


int N = 0;
EmployeeInsurance *list;

int main()
{
    while(true)
    {
        system("CLS");
        MENU();
        char choice; cin >> choice;
        system("CLS");
        switch(choice)
        {
            case 'A' : read_from_file(); system("pause"); break;
            case 'B' : Ave(); system("pause"); break;
            case 'C' : topEmployee(); system("pause"); break;
            case 'D' : PosSearch(); system("pause");break;
            case 'E' : search_employee(); system("pause");break;
            case 'F' : Delete_employee(); system("pause");break;
            case 'G' : Edit_employee(); system("pause");break;
            case 'H' : IncreaseBime(); system("pause");break;
            case 'I' : DecreaseBime(); system("pause");break;
            case 'J' : searchByDate(); system("pause");break;
            case 'K' : exit(0);
            default  : break;
        }
    }
}



//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------
// The Methods of Employee Class
Employee::Employee(string a, string b, string c, string d, int x) 
{
    setName(a);
    setPersonalID(b);
    setOrgamozational_position(c);
    setEducationLevel(d);
    setSalary(x);
}
string Employee::getName() {return name;}
string Employee::getPersonalID() {return personalID;}
string Employee::getOrgamozational_position() {return organizational_position;}
string Employee::getEducationLevel() {return education_level;}
int Employee::getSalary() {return salary;}

void Employee::setName(string a) {this->name = a;}
void Employee::setPersonalID(string a) {this->personalID = a;}
void Employee::setOrgamozational_position(string a) {this->organizational_position = a;}
void Employee::setEducationLevel(string a) {this->education_level = a;}
void Employee::setSalary(int x) {salary = x;}

void Employee::print()
{
    cout << getName() << " ";
    cout << getPersonalID() << " ";
    cout << getOrgamozational_position() << " ";
    cout << getEducationLevel() << " ";
    cout << getSalary() << " ";
//    cout << endl;
}

// -------------------------------------------------------------------
// The Methods of EmployeeInsurance Class
EmployeeInsurance::EmployeeInsurance(string a, string b, string c, string d, int x,  string e, string f, int g, int h) : Employee(a, b, c, d, x)
{
    setInsuranceID(e);
    setEstablish(f);
    setPayment(g);
    setRecieved(h);
}
string EmployeeInsurance::getInsuranceID() {return InsuranceID;}
string EmployeeInsurance::getEstablish() {return establish;}
int EmployeeInsurance::getPayment() {return payment;}
int EmployeeInsurance::getRecieved() {return recieved;}

void EmployeeInsurance::setInsuranceID(string a) {InsuranceID = a;}
void EmployeeInsurance::setEstablish(string a) {establish = a;}
void EmployeeInsurance::setPayment(int x) {payment = x;}
void EmployeeInsurance::setRecieved(int x) {recieved = x;}
void EmployeeInsurance::print()
{
    Employee::print();
    cout << getInsuranceID() << " ";
    cout << getEstablish() << " ";
    cout << getPayment() << " ";
    cout << getRecieved() << " ";
    cout << endl;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Others Methods
void MENU()
{
    cout << "A. Show employee list" << "\n";
    cout << "B. Average" << "\n";
    cout << "C. topSalary" << "\n";
    cout << "D. PosSearch" << "\n";
    cout << "E. Search employee" << "\n";
    cout << "F. Delete employee" << "\n";
    cout << "G. Edit employee" << "\n";
    cout << "H. IncreaseBime" << "\n";
    cout << "I. DecreaseBime" << "\n";
    cout << "J. searchByDate" << "\n";
    cout << "K. exit" << "\n";
    cout << "Please Enter your choice : ";
}

void read_from_file() 
{
    try
    {
        ifstream cin("input.txt");
        if (cin.fail()) throw 100;
        cin >> N;
        list = new EmployeeInsurance[N];
        for (int i = 0; i < N; i++) 
        {
            string a, b, c, d, e, f;
            int x, g, h;
            cin >> a >> b  >> c >> d >> x >> e >> f >> g >> h;
            list[i] = EmployeeInsurance(a, b, c, d, x, e, f, g, h);
            list[i].print();
        }
        cin.close();
    }
    catch(int e)
    {
        cerr << "file \"input.txt\" does not exist !" << '\n';
    }   
}

double getAve()
{
    double sum = 0;
    try
    {
        if (N == 0) throw 100;
        for (int i = 0; i < N; i++)
        {
            sum += list[i].getSalary();
        }
    }   
    catch(int e)
    {
        cerr << "we not have any Employee" << '\n';
        return -1;
    }
    return sum / N;
}
void Ave()
{
    double av = getAve();
    if (av == -1) return;
    cout << "The average of employee Salary is : " << av << "\n";
}

void topEmployee()
{
    double av = getAve();
    if (av == -1) return;
    for (int i = 0; i < N; i++)
    {
        if (list[i].getSalary() <= av) continue;
        cout << list[i].getName() << " " << list[i].getEducationLevel() << "\n";
    }
}

void PosSearch()
{
    cout << "please enter Orgamozational_position : " ;
    string s; cin >> s;
    try
    {
        ofstream out("output.txt");
        if (out.fail()) throw 100;
        for (int i = 0; i < N; i++)
        {
            if (list[i].getOrgamozational_position() != s) continue;
            list[i].print();
            out << list[i].getName() << " " << list[i].getOrgamozational_position() << "\n";
        }
        out.close();
    }
    catch(int e)
    {
        cerr << "error" << '\n';
    }   
}

void search_employee()
{
    cout << "please enter name of employee : ";
    string s; cin >> s;
    bool flag = false;
    for(int i = 0; i < N; i++)
    {
        if (list[i].getName() != s) continue;
        list[i].print();
        flag = true;
    }
    if (!flag)
        cout << "The employee not exist." << "\n";
}

bool id_checker(string a, string b)
{
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i]) return false;
    }
    return true;
}
void Delete_employee ()
{
    cout << "please enter peronal id of employee you want to delete : ";
    string id; cin >> id;
    bool exist = false;
    for (int i = 0; i < N; i++)
    {
        if (id_checker(id, list[i].getPersonalID())) {
            exist = true;
            cout << "the employee was deleted." << "\n";
            break;
        }
    }
    if (exist == false) 
    {
        cout << "employee not found." << "\n";
        return;
    } 
    try
    {
        ofstream out("input.txt");
        out << N - 1 << "\n";
        for (int i = 0; i < N; i++)
        {
            if (id_checker(id, list[i].getPersonalID()))  continue;
            out << list[i].getName() << " ";
            out << list[i].getPersonalID() << " ";
            out << list[i].getOrgamozational_position() << " ";
            out << list[i].getEducationLevel() << " ";
            out << list[i].getSalary() << " ";
            out << list[i].getInsuranceID() << " ";
            out << list[i].getEstablish() << " ";
            out << list[i].getPayment() << " ";
            out << list[i].getRecieved() << " ";
            out << endl;
            if (out.fail()) throw 100;
        }
        if(exist) N -= 1;
        out.close();
    }
    catch(int e)
    {
        cerr << "error" << '\n';
    }
}
void Edit_employee()
{
    cout << "please enter peronal id of employee you want to edit : ";
    string id; cin >> id;
    int idx;
    bool exist = false;
    for (int i = 0; i < N; i++)
    {
        if (id_checker(id, list[i].getPersonalID())) {
            exist = true;
            cout << "the employee was found." << "\n";
            idx = i;
            break;
        }
    }
    if (exist == false) 
    {
        cout << "employee not found." << "\n";
        return;
    } 
    string a, b, c, d, e, f;
    int x, g, h;
    cout << "enter name : "; cin >> a;
    cout << "enter personal id : "; cin >> b;
    cout << "enter Orgamozational_position : "; cin >> c;
    cout << "enter EducationLevel : "; cin >> d;
    cout << "enter salary : "; cin >> x;
    cout << "enter InsuranceID : "; cin >> e;
    cout << "enter Establish : "; cin >> f;
    cout << "enter Payment : "; cin >> g;
    cout << "enter Recieved: "; cin >> h;
    list[idx] = EmployeeInsurance(a, b, c, d, x, e, f, g, h);
    try
    {
        ofstream out("input.txt");
        out << N  << "\n";
        for (int i = 0; i < N; i++)
        {
            out << list[i].getName() << " ";
            out << list[i].getPersonalID() << " ";
            out << list[i].getOrgamozational_position() << " ";
            out << list[i].getEducationLevel() << " ";
            out << list[i].getSalary() << " ";
            out << list[i].getInsuranceID() << " ";
            out << list[i].getEstablish() << " ";
            out << list[i].getPayment() << " ";
            out << list[i].getRecieved() << " ";
            out << endl;
            if (out.fail()) throw 100;
        }
        out.close();
    }
    catch(int e)
    {
        cerr << "error" << '\n';
    }
}

void IncreaseBime()
{
    cout << "please enter peronal id of employee you want to increase : ";
    string id; cin >> id;
    cout << "please enter amount of Bime you want to increase : ";
    int amount ; cin >> amount;
    int idx;
    bool exist = false;
    for (int i = 0; i < N; i++)
    {
        if (id_checker(id, list[i].getPersonalID())) {
            exist = true;
            cout << "the employee was found." << "\n";
            idx = i;
            break;
        }
    }
    if (exist == false) 
    {
        cout << "employee not found." << "\n";
        return;
    } 
    list[idx].setPayment(list[idx].getPayment() + amount);
    cout << "increase payment was done." << "\n";
    try
    {
        ofstream out("input.txt");
        out << N  << "\n";
        for (int i = 0; i < N; i++)
        {
            out << list[i].getName() << " ";
            out << list[i].getPersonalID() << " ";
            out << list[i].getOrgamozational_position() << " ";
            out << list[i].getEducationLevel() << " ";
            out << list[i].getSalary() << " ";
            out << list[i].getInsuranceID() << " ";
            out << list[i].getEstablish() << " ";
            out << list[i].getPayment() << " ";
            out << list[i].getRecieved() << " ";
            out << endl;
            if (out.fail()) throw 100;
        }
        out.close();
    }
    catch(int e)
    {
        cerr << "error" << '\n';
    }
}

void DecreaseBime()
{
    cout << "please enter peronal id of employee you want to dencrease : ";
    string id; cin >> id;
    cout << "please enter amount of Bime you want to decrease : ";
    int amount ; cin >> amount;
    int idx;
    bool exist = false;
    for (int i = 0; i < N; i++)
    {
        if (id_checker(id, list[i].getPersonalID())) {
            exist = true;
            cout << "the employee was found." << "\n";
            idx = i;
            break;
        }
    }
    if (exist == false) 
    {
        cout << "employee not found." << "\n";
        return;
    } 
    list[idx].setRecieved(list[idx].getRecieved() - amount);
    cout << "decrease payment was done." << "\n";
    try
    {
        ofstream out("input.txt");
        out << N  << "\n";
        for (int i = 0; i < N; i++)
        {
            out << list[i].getName() << " ";
            out << list[i].getPersonalID() << " ";
            out << list[i].getOrgamozational_position() << " ";
            out << list[i].getEducationLevel() << " ";
            out << list[i].getSalary() << " ";
            out << list[i].getInsuranceID() << " ";
            out << list[i].getEstablish() << " ";
            out << list[i].getPayment() << " ";
            out << list[i].getRecieved() << " ";
            out << endl;
            if (out.fail()) throw 100;
        }
        out.close();
    }
    catch(int e)
    {
        cerr << "error" << '\n';
    }
}

void searchByDate()
{
    cout << "please enter ur date u want to search : ";
    string id; cin >> id;
    for (int i = 0; i < N; i++)
    {
        if (list[i].getEstablish() == id) {
            list[i].print();
        }
    }
}
