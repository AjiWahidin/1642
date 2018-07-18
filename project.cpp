#include <iostream>
#include <conio.h>
using namespace std;

bool login();
void Menu();
void cekSaldo();
void transferPulsa();
int logout();

class Jualpulsa{
    private : int saldoPulsa;

    public:
   
    void setAwal(int s){
        saldoPulsa = saldoPulsa;
    }
    int Saldo(){
        return saldoPulsa;
    }
    
    void transferPulsa(int s, string r){
        saldoPulsa -=s;
        cout << s << " berhasil dikirim ke nomor : " << r << endl;
    }
	Jualpulsa(){
        saldoPulsa = 2000000;
    }

}; Jualpulsa wahidin;

bool login(){
    char ch;
	int loop=1;
    string username, password;
    bool isLogin;
    cout << "========LOGIN=========" << endl;
    cout << "username: "; cin >> username;
    cout << "password: ";
	ch = getch();
	while(ch != 1 && loop <=8){//character 13 is enter
      password.push_back(ch);
      cout << '*';
      ch = getch();
      loop++;
   }
    (username == "wahidin" && password == "1234qwer")? isLogin = true: isLogin = false;
    wahidin.setAwal(2000000);
    return isLogin;
}

void Menu(){
    system("cls");
    int choice;
    cout << "======================" << endl;
    cout << "1.Cek saldo" << endl;
    cout << "2.Transfer Pulsa" << endl;
    cout << "3.Logout" << endl;
    cout << "======================" << endl;
    cout << "pilihan: "; cin >> choice;
    switch(choice){
        case 1:
            cekSaldo();
            break;
        case 2:
            transferPulsa();
            break;
        case 3:
           logout();
            break;
        default:
        Menu();
        break;
    }
}

void cekSaldo(){
    system("cls");
    char b;
    cout << "======================" << endl;
    cout << "Saldo anda : " << wahidin.Saldo() << endl;
    cout << "\nPress B For Back" << endl;
    cin >> b;
    if(b == 'b' || b == 'B'){
        Menu();
    }
}

void transferPulsa(){
    int Pulsa;
	string	noTelepon;
    char b, keyword;
    system("cls");
    cout << "======================================================" << endl;
    cout << "Nomor Hp tujuan \t\t: ";
    cin >> noTelepon;
    cout << "Jumlah pulsa yang dikirim \t: ";
    cin >> Pulsa;
    cout << "Press [Y] For yes, Press [C] For cancel" << endl;
    cin >> keyword;
    if(keyword == 'y' || keyword == 'Y'){
        wahidin.transferPulsa(Pulsa, noTelepon);
    }else if(keyword == 'c' || keyword == 'C'){
        Menu();
    }
    cout << "\nPress B For Back" << endl;
    cin >> b;
    if(b == 'b' || b == 'B'){
        Menu();
    }
}

int logout(){
    system("cls");
    return 0;
}

int main()
{
    up:
    if(login()){
        Menu();
    }else{
        system("cls");
        cout << "something wrong" << endl;
        goto up;
    }
}
