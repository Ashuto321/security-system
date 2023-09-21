#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    int a,i=0;
    string text,old,password1,password2,pass, name,password0,age,user,word,word1;
    string creds[2],cp[2];

    cout<<"     Security system   "<<endl;

    cout<<"|____________________________________________|"<<endl<<endl;
    cout<<"|              1.register                    |"<<endl;
    cout<<"|              2.Login                       |"<<endl;
    cout<<"|              3.Change password             |"<<endl;
    cout<<"|______________4.End Program_________________|"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>a;

        switch(a){
            case 1:{
                cout<<"_____________________________________"<<endl;
                cout<<"______________register_______________"<<endl;
                cout<<"                                     "<<endl;
                cout<<"_____________________________________"<<endl;
                cout<<"please enter user name: "<<endl;
                cin>>name;
                cout<<"please enter the password: "<<endl;
                cin>>password0;
                cout<<"please eneter the age"<<endl;
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                  of1<<name<<"\n";
                  of1<<password0;
                  cout<<"registration successful"<<endl;  
                }
                break;
            }
            case 2:{
                i=0;
                cout<<"____________________________________________"<<endl;
                cout<<"--------------------Login-------------------"<<endl;
                cout<<"____________________________________________"<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"please enter the user name"<<endl;
                cin>>user;
                cout<<"please enter the password;"<<endl;
                cin>>pass;

                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word;
                            creds[i]=word;
                            i++;
                        }
                        if(user==creds[0] && pass==creds[1]){
                            cout<<"---login successful---"<<endl;
                            cout<<endl<<endl;

                            cout<<"details: "<<endl;

                            cout<<"user name: "+name<<endl;
                            cout<<"password: "+pass<<endl;
                            cout<<"age:"+age<<endl;

                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"Incorrect credentails"<<endl;
                            cout<<"|          1.press 2 to login    |"<<endl;
                            cout<<"|          2.press 3 to change password |"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                i=0;
                cout<<"----------------------change password-------------"<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"enter te old passord"<<endl;
                cin>>old;
                if(of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0,text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }
                        if(old==cp[1]){
                            of0.close();

                            ofstream of1;
                            if(of1.is_open()){
                                cout<<"enter your new password";
                                cin>>password1;
                                cout<<"enter your password again";
                                cin>>password2;

                                if(password1==password2){
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"password changed successfully ";
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"pasword do not match"<<endl;
                                }
                            }
                        }
                        else{
                            cout<<"please enter a valid password"<<endl;
                            break;
                        }
                    }
                }

                break;
            }

            case 4:{
                cout<<"__________thankyou_________";
                break;
            }
            default:
            cout<<"enter a valid choice";

        }
    }
    while(a!=4);
    return 0;

}