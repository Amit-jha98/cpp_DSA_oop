#include<iostream>
#include<string>
using namespace std;

class bank{
private:
float balance = 0;
    std::string name;
    int acc_no;
    float amount;

public:
    
    bank(int b,const std::string& n, int a, float am) : balance(b), name(n), acc_no(a), amount(am) {}

    void creadit(){
        balance += amount;
        cout << "Amount credited successfully! \nAnd balance is: " << balance << endl;
    }

};

int main(){
    int acc;
    float am;
    std::string n;
    float b = 0;
    cout << "Enter account holder name: " << endl;
    getline(cin,n);
    cout << "Enter account number: " << endl;
    cin >> acc;
    if(acc<=0){
        cout << "Invalid account number!" << endl;
        return 0;
    }else{
    cout << "current balance is: " << b << endl;

    cout << "Enter amount to be added: " << endl;
    cin >> am;
    if(acc<=0){
        cout << "Invalid amount number!" << endl;
        return 0;
    }else{
    bank b1(b,n,acc,am);
    b1.creadit();
    }}
    return 0;
}
