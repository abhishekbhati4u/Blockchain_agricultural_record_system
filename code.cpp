#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

struct date
{
	int day;
	int month;
	int year;
};

class land_records
{
public:
	unsigned long long int serial_no;
	string owner_name;
	unsigned long long int contact_no;
	string address;
	string state;
	string district;
	string subdivision;
	string village;
	long pin_code;
	float area;
	struct date d;
	vector<unsigned long long int> neighbours;
	bool checkdate(int da, int mo, int ye)
	{
		int flag=0;
		if(mo==1 || mo==3 || mo==5 || mo==7 || mo==8 || mo==10 || mo==12)
        {
            if(da>31)
            {
                return false;
            }
        }
        else if (mo==4 || mo==6 || mo==9 || mo==11)
        {
            if(da>30)
            {
                return false;
            }
        }
        else if(mo==2)
        {
            int leap_year=0;
            if(ye%4==0)
            {
                if(ye%100==0)
                {
                    if(ye%400==0)
                    {
                        leap_year=1;
                    }
                }
                else
                {
                    leap_year=1;
                }
            }
            if(leap_year==1)
            {
                if(da>29)
                {
                    return false;
                }
            }
            else
            {
                if(da>28)
                {
                    return false;
                }
            }


	}
	return true;
	}
void getdate()
{
	    cout<<"\nEnter the date in which the record was added:\n";
		cout<<"\nEnter the day:\t";
		cin>>d.day;
		cout<<"\nEnter the month:\t";
		cin>>d.month;
		cout<<"\nEnter the year:\t";
		cin>>d.year;
		if(!checkdate(d.day, d.month, d.year))
        {
            cout<<"\nYou have entered a wrong date.";
            getdate();
        }
}
	void check_contact_no()
	{
	    cin>>contact_no;
	    unsigned long long int cno;
	    cno=contact_no;
	    int n=0;
	    while(cno)
        {
            cno=cno/10;
            n=n+1;
        }
        if(n!=10)
        {
            cout<<"\nYou have entered a wrong number. Enter again.";
            check_contact_no();
        }
	}
	void check_serial_no()
	{
	    cin>>serial_no;
	    unsigned long long int sno;
	    sno=serial_no;
	    int n=0;
	    while(sno)
        {
            sno=sno/10;
            n=n+1;
        }
        if(n!=12)
        {
            cout<<"\nYou have entered a wrong number. Enter again.";
            check_serial_no();
        }
	}
	void check_pin_code()
	{
	    cin>>pin_code;
	    long int pco;
	    pco=pin_code;
	    int n=0;
	    while(pco)
        {
            pco=pco/10;
            n=n+1;
        }
        if(n!=6)
        {
            cout<"\nYou have entered a wrong PIN Code value.";
            check_pin_code();
        }
	}
	void getinput()
	{
		cout<<"\nEnter the Name of the owner whose record you want to enter:\n";
		cin>>owner_name;
		cout<<"\nEnter the Contact number of the owner:\n";
		check_contact_no();
		cout<<"\nEnter the Government assigned serial number of the land piece:\n";
		check_serial_no();
		cout<<"\nEnter the State in which the land piece falls:\n";
		cin>>state;
		cout<<"\nEnter the District in which the land piece falls:\n";
		cin>>district;
		cout<<"\nEnter the Sub Division in which the land piece falls:\n";
		cin>>subdivision;
		cout<<"\nEnter the Name of the village area:\n";
		cin>>village;
		cout<<"\nEnter the PIN Code of the region:\n";
		check_pin_code();
		cout<<"\nEnter the area of the region:\n";
		cin>>area;
		getdate();
		cout<<"\nEnter the serial nos. of the neighboring fields:\n";
		char ch='Y';
		unsigned long long int sr_no;
		while(ch=='y'||ch=='Y')
        {
            cout<<"\nEnter the serial number:\n";
            cin>>sr_no;
            neighbours.push_back(sr_no);
            cout<<"\nDo you want to enter more records(Y/n)?";
            cin>>ch;
        }
	}
	void show_land_records()
	{
	    cout<<"\nThe serial number of the field according to the government records";
	    cout<<serial_no;
	    cout<<"\nThe name of the owner of the field:\n";
	    cout<<owner_name;
	    cout<<"\nThe contact number of the owner is as follows:\n";
	    cout<<contact_no;
	    cout<<"\nThe complete address of the field:\n";
	    cout<<address;
	    cout<<"\nThe State is: ";
	    cout<<state;
	    cout<<"\nThe District is: ";
	    cout<<district;
	    cout<<"\nThe Sub Division is: ";
	    cout<<subdivision;
	    cout<<"\nThe Village is: ";
	    cout<<village;
	    cout<<"\nThe PIN Code of the area is: ";
	    cout<<pin_code;
	    cout<<"\nThe area of the field is: \n";
	    cout<<area;
	    cout<<"\nThe date on which the record was taken is: ";
	    cout<<d.day<<"-"<<d.month<<"-"<<d.year;
	    cout<<"\nThe serial numbers of all the neighboring fields are as follows:\n";
	    for(int i=0; i<neighbours.size(); i++)
        {
            cout<<neighbours[i];
            cout<<"\n";
        }
	}
};

struct past_performance
{
    string name;
    string type;
    float profit;
    float yield_amount;
    struct date date_of_yield;
};

class crop_records
{
public:
    string name;
    string type;
    string water_requirements;
    string water_availability;
    float pH;
    string soil_quality;
    struct date date_of_harvest;
    struct date date_of_sowing;
    vector<past_performance> past_records;
    int past_records_flag=0;
    bool check_date(int da, int mo, int ye)
	{
		int flag=0;
		if(mo==1 || mo==3 || mo==5 || mo==7 || mo==8 || mo==10 || mo==12)
        {
            if(da>31)
            {
                return false;
            }
        }
        else if (mo==4 || mo==6 || mo==9 || mo==11)
        {
            if(da>30)
            {
                return false;
            }
        }
        else if(mo==2)
        {
            int leap_year=0;
            if(ye%4==0)
            {
                if(ye%100==0)
                {
                    if(ye%400==0)
                    {
                        leap_year=1;
                    }
                }
                else
                {
                    leap_year=1;
                }
            }
            if(leap_year==1)
            {
                if(da>29)
                {
                    return false;
                }
            }
            else
            {
                if(da>28)
                {
                    return false;
                }
            }
        }
        return true;
	}
    void check_pH_value()
    {
        cin>>pH;
        if(pH<0.0 || pH>14)
        {
            cout<<"\nYou have entered a wrong pH value.";
            cout<<"\nPlease enter again\n";
            check_pH_value();
        }
    }
    void get_sowing_date()
    {
        cout<<"\nEnter the Date on which the crop was shown:\n";
        cout<<"\nEnter the day:\n";
        cin>>date_of_sowing.day;
        cout<<"\nEnter the month:\n";
        cin>>date_of_sowing.month;
        cout<<"\nEnter the year:\n";
        cin>>date_of_sowing.year;
        if(!check_date(date_of_sowing.day, date_of_sowing.month, date_of_sowing.year))
        {
            cout<<"\nYou have entered a wrong date. Please enter again.";
            get_sowing_date();
        }
    }
    void get_harvest_date()
    {
        cout<<"\nEnter the expected date of harvest:\n";
        cout<<"\nEnter the day:\n";
        cin>>date_of_harvest.day;
        cout<<"\nEnter the month:\n";
        cin>>date_of_harvest.month;
        cout<<"\nEnter the year:\n";
        cin>>date_of_harvest.year;
        if(!check_date(date_of_sowing.day, date_of_sowing.month, date_of_sowing.year))
        {
            cout<<"\nYou have entered a wrong date. Please enter again.";
            get_harvest_date();
        }
    }
    float get_amount_of_yield()
    {
        float y;
        cout<<"\nEnter the amount of yield: ";
        cin>>y;
        if(y<0.0)
        {
            cout<<"\nYou have entered a wrong value. Enter again.";
            get_amount_of_yield();
        }
        else
        {
            return y;
        }
    }
    int d_temp, m_temp, y_temp;
    void get_past_record_date()
    {
        cout<<"\nEnter the date of the past crop harvest:\n";
        cin>>d_temp;
        cout<<"\nEnter the month:\n";
        cin>>m_temp;
        cout<<"\nEnter the year: \n";
        cin>>y_temp;
        if(!check_date(d_temp,m_temp,y_temp))
        {
            cout<<"\nYou have entered a wrong date.";
            cout<<"\nEnter again.";
            get_past_record_date();
        }
    }
    void get_past_records()
    {
        struct past_performance p;
        cout<<"\nEnter the name of the crop:\n";
        cin>>p.name;
        cout<<"\nEnter the type of the crop:\n";
        cin>>p.type;
        cout<<"\nEnter the profit earned with this crop:\n";
        cin>>p.profit;
        p.yield_amount=get_amount_of_yield();
        cout<<"\nEnter the date of the past records:\n";
        cout<<"\nEnter the day:\t";
        cin>>p.date_of_yield.day;
        cout<<"\nEnter the month:\t";
        cin>>p.date_of_yield.month;
        cout<<"\nEnter the year:\t";
        cin>>p.date_of_yield.year;
        past_records.push_back(p);
    }
    void get_crop_records()
    {
        cout<<"\nEnter the type of the crop in details:\n";
        cin>>type;
        cout<<"\nEnter the name of the crop with biological name: \n";
        cin>>name;
        cout<<"\nEnter the water requirements of the crop with explanation:\n";
        cin>>water_requirements;
        cout<<"\nEnter the availability of the water resources with all the details:\n";
        cin>>water_availability;
        cout<<"\nEnter the details of the soil quality of the field:\n";
        cin>>soil_quality;
        cout<<"\nEnter the pH value of the soil:\n";
        cin>>pH;
        get_sowing_date();
        get_harvest_date();
        char c='y';
        char op;
        cout<<"\nDo you want to enter past records?(Y/N)\n";
        cin>>op;
        if(op=='y' || op=='Y')
        {
            past_records_flag=1;

        while(c=='y'||c=='Y')
        {
            get_past_records();
            cout<<"\nDo you want to enter more?(Y/N)";
            cin>>c;
        }
        }
    }
    void show_crop_records()
    {
        cout<<"\nThe name of the crop: ";
        cout<<name;
        cout<<"\nThe type of the crop: ";
        cout<<type;
        cout<<"\nThe water requirements for the crop: \n";
        cout<<water_requirements;
        cout<<"\nThe water availability for the crop: \n";
        cout<<water_availability;
        cout<<"\nThe pH value of the soil: "<<pH;
        cout<<"\nThe description of the soil quality:\n";
        cout<<soil_quality;
        cout<<"\nThe date of sowing: ";
        cout<<date_of_sowing.day<<"-"<<date_of_sowing.month<<"-"<<date_of_sowing.year;
        cout<<"\nThe expected date of harvest for the current crop: ";
        cout<<date_of_harvest.day<<"-"<<date_of_harvest.month<<"-"<<date_of_harvest.year;
        if (past_records_flag==1)
        {
        cout<<"\nThe past records for the field are as follows:";
        for(int i=0; i<past_records.size(); i++)
        {
            cout<<"\nThe name of the crop:\n";
            cout<<past_records[i].name;
            cout<<"\nThe type of the crop:\n";
            cout<<past_records[i].type;
            cout<<"\nThe profit earned:\t";
            cout<<past_records[i].profit;
            cout<<"\nThe amount of yield: \t";
            cout<<past_records[i].yield_amount;
            cout<<"\nThe date of the yield:\t";
            cout<<past_records[i].date_of_yield.day<<"-"<<past_records[i].date_of_yield.month<<"-"<<past_records[i].date_of_yield.year;
        }
        }
    }
};

struct login
{
    string username;
    string password;
    int category;
}s[2];
int check(string user, string pswd, int cat)
{
    s[0].username="abhishek";
    s[0].password="bhati";
    s[0].category=0;
    s[1].username="shivam";
    s[1].password="goel";
    s[1].category=1;
    int i;
    ofstream fileout;
    for(i=0; i<2; i++)
    {
        fileout.write((char*)&s[i],sizeof(s[i]));
    }
    fileout.close();
    for(i=0; i<2; i++)
    {
        if(user.compare(s[i].username)==0 && pswd.compare(s[i].password)==0 && s[i].category==cat)
        {
            return 1;
        }
    }
    return 0;
}
class records: public land_records, public crop_records
{
public:
    unsigned long long int update_hash_code=0;
    unsigned long long int previous_hash;
    unsigned long long int hash_code;
    void get_update_input()
    {
        char choice;
        cout<<"\nDo you want to add this record as an update to a previous block?\n";
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {
            cout<<"\nEnter the hash code of the block in whose relation you want to add this block to?\n";
            cin>>update_hash_code;
            getinput();
            show_land_records();
            get_crop_records();
            show_crop_records();
        }
        else
        {
            getinput();
            show_land_records();
            get_crop_records();
            show_crop_records();
        }
    }
    void calculate_hash()
    {
        hash_code=0;
        unsigned long long int temp;
        temp=serial_no;
        while(temp!=0)
        {
            hash_code=hash_code+(temp%10);
            temp=temp/10;
        }
        temp=contact_no;
        while(temp!=0)
        {
            hash_code=hash_code+(temp%10);
            temp=temp/10;
        }
        ifstream fin("hash_codes.dat",ios::in);
        unsigned long long int number;
        fin.seekg(0);
        while(!fin.eof())
        {
            fin>>number;
        }
        previous_hash=number;
        fin.close();
        temp=previous_hash;
        while(temp!=0)
        {
            hash_code=hash_code+(temp%10);
            temp=temp/10;
        }
        int i=0;
        for(i=0; i<neighbours.size(); i++)
        {
            temp=neighbours[i];
            while(temp!=0)
            {
                hash_code=hash_code+(temp%10);
                temp=temp/10;
            }
        }

        hash_code=hash_code+d.day+d.month+d.year;
        hash_code=hash_code+date_of_harvest.day+date_of_harvest.month+date_of_harvest.year;
        hash_code=hash_code+date_of_sowing.day+date_of_sowing.month+date_of_sowing.year;

        hash_code=hash_code+(int)pH+(int)area;
        hash_code=hash_code+pin_code;

        srand(time(NULL));
        int arr[20];
        for(i=0; i<20; i++)
        {
            arr[i]=rand()%10;
        }
        int num;
        for(i=0; i<name.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(name[i]))*num;
        }
        for(i=0; i<owner_name.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(owner_name[i]))*num;
        }
        for(i=0; i<address.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(address[i]))*num;
        }
        for(i=0; i<state.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(state[i]))*num;
        }
        for(i=0; i<district.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(district[i]))*num;
        }
        for(i=0; i<subdivision.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(subdivision[i]))*num;
        }
        for(i=0; i<village.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(village[i]))*num;
        }
        for(i=0; i<type.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(type[i]))*num;
        }
        for(i=0; i<water_requirements.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(water_requirements[i]))*num;
        }
        for(i=0; i<water_availability.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(water_availability[i]))*num;
        }
        for(i=0; i<soil_quality.length(); i++)
        {
            num=arr[rand()%20];
            hash_code+=(int(soil_quality[i]))*num;
        }
        for(i=0; i<past_records.size(); i++)
        {
            hash_code+=past_records[i].date_of_yield.day+past_records[i].date_of_yield.month+past_records[i].date_of_yield.year;
            hash_code+=int(past_records[i].profit);
            hash_code+=int(past_records[i].yield_amount);
            int ar[30];
            int j;
            for(j=0; j<30; j++)
            {
                ar[j]=rand()%15;
            }
            int n1=ar[rand()%30];
            for(j=0; j<past_records[i].name.length(); j++)
            {
                hash_code+=int(past_records[i].name[j])*n1;
            }
            int n2=ar[rand()%30];
            for(j=0; j<past_records[i].type.length(); j++)
            {
                hash_code+=int(past_records[i].type[j])*n2;
            }
        }
    }
    void display()
    {
        cout<<"\nThe hash value of this block is "<<hash_code;
        cout<<"\nThe hash value of the previous block is "<<previous_hash;
        if(update_hash_code)
        {
            cout<<"\nThis is an updated hash block.";
            cout<<"\nThe hash code of the block in whose reference this update was made is "<<update_hash_code;
        }
        show_land_records();
        show_crop_records();
    }
    void write_to_file()
    {
        ofstream codeout;
        codeout.open("hash_codes.dat",ios::app);
        codeout<<hash_code<<'\n';
        codeout.close();

        ofstream filewrite;
        filewrite.open("chain.txt",ios::app);
        string dat="Hash Code";
        filewrite<<dat<<'\t'<<hash_code;
        filewrite<<'\n';
        dat="Previous Hash Code";
        filewrite<<dat<<'\t'<<previous_hash;
        filewrite<<'\n';
        dat="Owner Name";
        filewrite<<dat<<'\t'<<owner_name;
        filewrite<<'\n';
        dat="Contact No";
        filewrite<<dat<<'\t'<<contact_no;
        filewrite<<'\n';
        dat="Serial No";
        filewrite<<dat<<'\t'<<serial_no;
        filewrite<<'\n';
        dat="State";
        filewrite<<dat<<'\t'<<state;
        filewrite<<'\n';
        dat="District";
        filewrite<<dat<<'\t'<<district;
        filewrite<<'\n';
        dat="Subdivision";
        filewrite<<dat<<'\t'<<subdivision;
        filewrite<<'\n';
        dat="Village";
        filewrite<<dat<<'\t'<<village;
        filewrite<<'\n';
        dat="PIN Code";
        filewrite<<dat<<'\t'<<pin_code;
        filewrite<<'\n';
        dat="Area";
        filewrite<<dat<<'\t'<<area;
        filewrite<<'\n';
        dat="Date of Adding Records";
        filewrite<<d.day<<'\t'<<d.month<<'\t'<<d.year;
        filewrite<<'\n';

        dat="Crop Name";
        filewrite<<dat<<'\t'<<name;
        filewrite<<'\n';
        dat="Crop Type";
        filewrite<<dat<<'\t'<<type;
        filewrite<<'\n';
        dat="Crop Water Requirements";
        filewrite<<dat<<'\t'<<water_requirements;
        filewrite<<'\n';
        dat="Crop Water Availability";
        filewrite<<dat<<'\t'<<water_availability;
        filewrite<<'\n';
        dat="pH Value";
        filewrite<<dat<<'\t'<<pH;
        filewrite<<'\n';
        dat="Crop Date of Sowing";
        filewrite<<dat<<'\t'<<date_of_sowing.day<<'\t'<<date_of_sowing.month<<date_of_sowing.year;
        filewrite<<'\n';
        dat="Crop Date of Harvest";
        filewrite<<dat<<'\t'<<date_of_harvest.day<<'\t'<<date_of_harvest.month<<'\t'<<date_of_harvest.year;
        filewrite<<'\n';
        filewrite.close();
    }
};

void creategenesisblock()
{
    unsigned long long int num;
    num=0;
    ofstream filout;
    filout.open("hash_codes.dat",ios::app);
    filout<<num<<'\n';
    filout.close();
    ofstream fil;
    fil.open("Chain.txt",ios::app);
    string data="Hash Code";
    fil<<data<<'\t'<<num;
    fil<<'\n';
    data="This is the genesis block.";
    fil<<data<<'\t'<<num<<'\n\n';
    fil.close();
}

int main()
{
    string uname;
    string pwd;
    cout<<"\nEnter user name: ";
    cin>>uname;
    cout<<"\n Enter password: ";
    cin>>pwd;
    if(check(uname,pwd,0))
    {
        cout<<"Accepted.\n";
    }
    else
    {
        cout<<"\nNot Accepted.";
        exit(0);
    }
    unsigned long long int temp_num;
    ifstream filein;
    filein.open("hash_codes.dat",ios::in);
    filein.seekg(0);
    filein>>temp_num;
    if(temp_num==0)
    {
        creategenesisblock();
    }
    filein.close();
    cout<<"\nThe genesis block has been created.";
    records rec;
    rec.get_update_input();
    rec.display();
    rec.write_to_file();
    ofstream filewrite;
    filewrite.open("chain.txt",ios::app);
    filewrite.close();
    cout<<"\nThe contents of the file are as follows: \n";
    ifstream fin;
    fin.open("Chain.txt",ios::in);
    char ch;
    while(fin)
    {
        fin.get(ch);
        cout<<ch;
    }
    fin.close();
	return 0;
}
