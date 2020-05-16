#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Command 
{
    private:
        string name;
        vector<string> params;
    public:
        Command(string name, string params1, string params2, string params3) {
            this->name = name;
            this->params.push_back(params1);
            this->params.push_back(params2);
            this->params.push_back(params3);
        }
        string getName() {
            return this->name;
        }
        string getparams(int i) const { 
        return params[i];
        } 
};


void createhotel(string name, string params1, string params2, string params3)
{
    string name1 = name;
    string floor = params1;
    string roomPerFloor = params2;
    string null = params3;
    string createhotel = "create_hotel"; 
    if(name1.compare(createhotel) == 0 )
    {
        Command& createhotel = *(new Command(name1, floor, roomPerFloor, null));
        cout << "Hotel created with " << createhotel.getparams(0) << " floor(s)," << createhotel.getparams(1) << " room(s) per floor."<< endl;
    }   
    //เพิ่มฟังก์ชั่น ให้นำค่า floor,roomPerFloor ไปตรวจสอบว่าเลขห้องที่ทำการจองอยู่นอกเหนือที่กำหนดหรือไม่แปลงเป็นint
}

void createbook(string name, string params1, string params2, string params3)
{
    string command = name;
    string numbroom = params1;
    string namecust = params2;
    string age = params3;
    string numb1[6]; 
    int keycard = 0;
    string book = "book";
    string checkout = "checkout";
    int i = 0;
    i++;
    if(command.compare(book) == 0 )
    {
            if(i==0)
            {
                Command& createbook0 = *(new Command(command, numbroom, namecust, age));
                cout << "Room " << createbook0.getparams(0) << " is booked by " << createbook0.getparams(1) << " with keycard number " << keycard << endl;
                numb1[0] = createbook0.getparams(0) ;
            }
            else if(i==1)
            {
                Command& createbook1 = *(new Command(command, numbroom, namecust, age));
                cout << "Room " << createbook1.getparams(0) << " is booked by " << createbook1.getparams(1) << " with keycard number " << keycard << endl;
                numb1[1]= createbook1.getparams(0) ;
            }
            else if(i==2)
            {
                Command& createbook2 = *(new Command(command, numbroom, namecust, age));
                cout << "Room " << createbook2.getparams(0) << " is booked by " << createbook2.getparams(1) << " with keycard number " << keycard << endl;
                numb1[2] = createbook2.getparams(0) ;
            }    
            else if(i==3)
            {
                Command& createbook3 = *(new Command(command, numbroom, namecust, age));
                cout << "Room " << createbook3.getparams(0) << " is booked by " << createbook3.getparams(1) << " with keycard number " << keycard << endl;         
                numb1[3] = createbook3.getparams(0) ;
            }
            else if(i==4)
            {
                Command& createbook4 = *(new Command(command, numbroom, namecust, age));
                numb1[4] = createbook4.getparams(0) ;
            }        
            else if(i==5)
            {
                Command& createbook5 = *(new Command(command, numbroom, namecust, age));
                numb1[5] = createbook5.getparams(0) ;
            }
            else
            {
                Command& createbook6 = *(new Command(command, numbroom, namecust, age));
                
                numb1[6] = createbook6.getparams(0) ;
            }                  
        //cout << numb1[0] << numb1[1] << numb1[2] << numb1[3] << endl;
        //Command& createbook = *(new Command(command, numbroom, namecust, age));
       // cout << "Room " << createbook.getparams(0) << " is booked by " << createbook.getparams(1) << " with keycard number " << keycard << endl;
        //เพิ่ม keycard function
        //เพิ่ม function เช็คห้องซ้ำ
    }
    else if(command.compare(checkout) == 0)
    {
        Command& createbook = *(new Command(command, numbroom, namecust, age));
        cout << "Room " << createbook.getparams(0) << " is checkout." << endl;
        //เพิ่มตรวจสอบ keycard function
        //เพิ่ม function เช็คห้องซ้ำ
    }
    
}


void command1 (string name, string params1, string params2, string params3)
{
    string command1 = name;
    string null1 = params1;
    string null2 = params2;
    string null3 = params3;
    string commands1 = "list_available_rooms";
    string commands2 = "list_guest";
    string commands3 = "get_guest_in_room";
    string commands4 = "list_guest_by_age";
    string commands5 = "list_guest_by_floor"; 
    string commands6 = "checkout_guest_by_floor";
    string commands7 = "book_by_floor";
    if(command1.compare(commands1) == 0 )
    {
    
    }
    else if(command1.compare(commands2) == 0 )
    {

    }
    
}

void demo(string token) 
{
    string s2 = token;
    stringstream ss2;
    string name, params1, params2, params3;
    ss2 << s2;
    ss2 >> name;
    ss2 >> params1;
    ss2 >> params2;
    ss2 >> params3;
    createhotel(name, params1, params2, params3);
    createbook(name, params1, params2, params3);
    command1(name, params1, params2, params3);
    //cout << name << "\n"<< params1 << "\n"<< params2 << "\n"<< params3 <<endl; 
}    

string getCommandsFromFileName(string filename)
{
	ifstream f(filename); 
	stringstream ss;	
	string contents;
		ss << f.rdbuf();
		contents = ss.str();
        vector<string> poy;

        string s = contents;
        string delimiter = "\n";
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos) 
        {
            token = s.substr(0, pos);
            //cout << token ; 
            demo(token);
                  
            s.erase(0, pos + delimiter.length());
                       
        }
            
            
	return contents;
}



int main()
{
    string filename = "input.txt" ; 
   // readtext(filename);
    getCommandsFromFileName(filename);
    return 0;
}
