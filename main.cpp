#include <iostream>
#include<windows.h>
#include<mysql.h>
#include<string>
#include<math.h>
#include<sstream>
#include<conio.h>
#include<string.h>
#include<limits>
#include<iomanip>
#include<time.h>


using namespace std;

 MYSQL* conn;
 MYSQL_ROW row;
 MYSQL_RES *res;
 int qstate;
 string user_id;
 int taken;


   class bank_transacts{
       string FirstName,SecondName,Age,ac_number,ac_password,profit,curent_balance,phone_no,name,second,password,loan_no,amounttaken,timePeriod,returnMoney;
       string sponsor1,sponsor2,phone_no1,phone_no2,security1,security2,Securityvalue1,securityvalue2,ownerdocumentno1,ownerdocumentno2;
    char type;
   public:
   void DISPLAYLOANAPPLICANTS();
   string laonreturncalculate(int e,int s);
   void FORADMIN();
   void Display_all_saving_ac_user();
   void Display_all_current_ac_user();
   void CREATE_SAVING_AC();
   void createcurrentaccount();
   void LOANAPPLICANTS();
   void CHANGE_PASSWORD_SAVING_AC(string pass);
   void delay( int j);
   void CHANGE_PASSWORD_CURRENT_USER_AC(string pass);
   void CHANGE_PASSWORD_ADMIN(string pass);
   void CREATE_ADMIN();
   string calculateprofit(int bal);
   void CREATESPONSORSECURITY();
   void Display_all_sponsorandsecurities();
   void ForUser();
   void write(string m);
   void exit();
   void DEPOSITMONEYSAVING();
   void DEPOSITMONEYCURRENT();
   void WITHDRAWMONEYCURRENT();
   void WITHDRAWMONEYSAVING();
   void loginadmin();
   void SHOWBALANCECURRENT();
   void SHOWBALANCESAVING();
   string encryptDecrypt(string toEncrypt);
     string Tostring(int j);
   void shade1(int p);
   void shade2(int j);
   void shade3(int l);
   void savestate(string action,int amount);
    void displaystatement();
   //int stoi(string id);
   };

  string Tostring(int j)
 {
   stringstream ss;
   ss<<j;
   return ss.str();
 }


      void delay( float j)
{
   int y;
   for(y=1;y<122000*j;y++){
     cout<<"";
   }
}
void shade1(int p)
{   int i;
    for(i=0;i<p;i++){
        cout<<"*";
        delay(1);
    }
}

 const string timerecord()
{
      time_t     now = time(0);
      struct tm  tstruct;
      char       buf[80];
      tstruct = *localtime(&now);
      strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
      return buf;
}
 void savestate(string action,int amount)
     {
       string time,transacts,pesa,ac;
       time=timerecord();
       pesa=Tostring(amount);
       transacts=action;
       ac=Tostring(taken);
   string query= "insert into bank_statement(id,action,date,amount,account)values('"+user_id+"','"+transacts+"','"+time+"','"+pesa+"','"+ac+"')";
       qstate = mysql_query(conn,query.c_str());
       if(!qstate){
       }else{
       cout<<"query problem: "<<mysql_error(conn)<<endl;}
     }

void shade2(int l)
{   int i;
    for(i=0;i<l;i++){
        cout<<".";
        delay(7);
    }
}
void shade8(int l)
{   int i;
    for(i=0;i<l;i++){
        cout<<".";
        delay(1);
    }
}
void shade3(int j)
{   int i;
    for(i=0;i<j;i++){
        cout<<"%";
        delay(1);
    }
}
void write(string m)
{
   for(int i=0;i<m.length();i++)
          {
              cout<<m[i];
              delay(1);
          }
}

void exit(){
    exit(0);
    }
void exit1()
{
    string l;
    l=" SORRY THE SERVICES IS NOT AVAILABLE FOR NOW NICE DAY AND WELCOME AGAIN";
      cout<<"\t\t\t";write(l);cout<<"\n\n\n\n\n"<<endl;

    }

   string laonreturncalculate(int e,int s)
   {
       double i;
       i=(e*0.1*s)+e;
    stringstream ss;
      ss<<i;
    return ss.str();
   }

    string calculateprofit(int bal)
    {
      double b;
      b=(0.1*bal);
      stringstream ss;
      ss<<b;
    return ss.str();
    }
    string encryptDecrypt(string toEncrypt) {
      char key = 'K';
    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key;

    return output;
}

   string  validate(){
                 bool gotInt = false;
                 string intext;
                    int         inval;
                while (!gotInt)
             {
        char *chk;
        cin >> intext;
        inval = (int) strtol (intext.c_str(), &chk, 10);

        if (*chk == '\0' || isspace (*chk))
        {
            gotInt = true;
               }
               else{ cout << "Enter an interger\n";}
               }
               return intext;
    }


    int  validate1(){
                 bool gotInt = false;
                 string intext;
                    int  inval;
                while (!gotInt)
             {
        char *chk;
        cin >> intext;
        inval = (int) strtol (intext.c_str(), &chk, 10);

        if (*chk == '\0' || isspace (*chk))
        {
            gotInt = true;
               }
               else{ cout << "Enter an interger\n";}
               }
              return atoi(intext.c_str());
    }


       void DISPLAYLOANAPPLICANTS()
       {

                 cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
         qstate= mysql_query(conn,"select * from loan_beneficiaries");
         if(!qstate){
             res=mysql_store_result(conn);
             while(row=mysql_fetch_row(res))
             {
                 cout<<"\t\t\tID\t\t\t"<<row[0]<<endl;
                 cout<<"\t\t\tFIRST NAME\t\t"<<row[1]<<endl;
                 cout<<"\t\t\tSECOND NAME \t\t"<<row[2]<<endl;
                 cout<<"\t\t\tAGE \t\t\t"<<row[3]<<endl;
                 cout<<"\t\t\tLOAN NUMBER \t\t"<<row[4]<<endl;
                 cout<<"\t\t\tAMOUNT TAKEN\t"<<row[5]<<endl;
                 cout<<"\t\t\tTIME TO RETURN \t"<<row[6]<<endl;
                 cout<<"\t\t\tRETURN MONEY\t\t"<<row[7]<<endl;
                 cout<<"\t\t\tPHONE NUMBER \t\t"<<row[7]<<endl;
                 cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;

             }

       }
       }
    void CREATESPONSORSECURITY()
    {
         string s,sponsor1,sponsor2,phone_no1,phone_no2,security1,security2,Securityvalue1,securityvalue2,ownerdocumentno1,ownerdocumentno2;
         cout<<"Please enter name of your First  of your sponsor."<<endl; cin>>sponsor1;
         cout<<"Please enter name of your second sponsor"<<endl; cin>>sponsor2;
         cout<<"Please enter phone number of your first sponsor"<<endl;
         phone_no1=validate();
         cout<<"Please enter phone number of your second sponsor"<<endl;
         phone_no2=validate();
         cout<<"Please enter your first property to secure your loan"<<endl; cin>>security1;
         cout<<"Please enter your second property to secure your loan"<<endl; cin>>security2;
         cout<<"Please enter your value of first property to secure your loan"<<endl;
         Securityvalue1=validate();
         cout<<"Please enter your value second property to secure your loan"<<endl;
         securityvalue2=validate();
         cout<<"Please enter ownership registered number for property one "<<endl; cin>>ownerdocumentno1;
         cout<<"Please enter ownership registered number for property second"<<endl; cin>>ownerdocumentno2;
         string query=" insert into sponsorsecurities(sponsor1,sponsor2,phone_no1,phone_no2,security1,security2,Securityvalue1,securityvalue2,ownerdocumentno1,ownerdocumentno2)"
         "values( '"+sponsor1+"', '"+sponsor2+"','"+phone_no1+"','"+phone_no2+"','"+security1+"','"+security2+"','"+Securityvalue1+"','"+securityvalue2+"','"+ownerdocumentno1+"','"+ownerdocumentno2+"')";
         qstate = mysql_query(conn,query.c_str());
         if(!qstate){
          s="SPONSOR AND SECURITY ENTERED SUCCESFULLY";
            cout<<"\n\t\t\t";write(s);cout<<"\n";
         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    }
       void DISPLAYADMIN()
       {
                   cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
         qstate= mysql_query(conn,"select * from admin");
         if(!qstate){
             res=mysql_store_result(conn);
             while(row=mysql_fetch_row(res))
             {

                 cout<<"\t\t\tFIRST NAME\t\t"<<row[1]<<endl;
                 cout<<"\t\t\tSECOND NAME \t\t"<<row[2]<<endl;
                 cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
             }
         }
       }
      void Display_all_sponsorandsecurities()
      {
                 cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
         qstate= mysql_query(conn,"select * from sponsorsecurities");
         if(!qstate){
             res=mysql_store_result(conn);
             while(row=mysql_fetch_row(res))
             {
                 cout<<"\t\t\tID\t\t\t\t\t\t\t"<<row[0]<<endl;
                 cout<<"\t\t\tFIRST SPONSOR \t\t\t\t\t\t"<<row[1]<<endl;
                 cout<<"\t\t\tSECOND SPONSOR \t\t\t\t\t\t"<<row[2]<<endl;
                 cout<<"\t\t\tFIRST SPONSOR PHONE NUMBER \t\t\t\t"<<row[3]<<endl;
                 cout<<"\t\t\tSECOND SPONSOR PHONE NUMBER\t\t\t\t"<<row[4]<<endl;
                 cout<<"\t\t\tPROPERTY ONE TO SECURE THE LOAN\t\t\t\t"<<row[5]<<endl;
                 cout<<"\t\t\tPROPERTY TWO TO SECURE THE LOAN\t\t\t\t"<<row[6]<<endl;
                 cout<<"\t\t\tVALUE OF THE PROPERTY ONE\t\t\t\t"<<row[7]<<endl;
                 cout<<"\t\t\tVALUE OF THE PROPERTY TWO\t\t\t\t"<<row[8]<<endl;
                 cout<<"\t\t\tOWNER LEGAL DOCUMENT NUMBER FOR PROPERTY ONE \t\t"<<row[9]<<endl;
                 cout<<"\t\t\tOWNER LEGAL DOCUMENT NUMBER FOR PROPERTY TWO \t\t"<<row[10]<<endl;
                 cout<<"\n"<<endl;
                     shade3(80);
                 cout<<"\n"<<endl;
             }
         }
      }
      void Display_all_current_ac_user()
     {
                 cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
         qstate= mysql_query(conn,"select * from current");
         if(!qstate){
             res=mysql_store_result(conn);
             while(row=mysql_fetch_row(res))
             {
                 cout<<"\t\t\tFIRST NAME\t\t"<<row[1]<<endl;
                 cout<<"\t\t\tSECOND NAME \t\t"<<row[2]<<endl;
                 cout<<"\t\t\tAGE \t\t\t"<<row[3]<<endl;
                 cout<<"\t\t\tAC_NUMBER\t\t"<<row[4]<<endl;
                 cout<<"\t\t\tCURRENT BALANCE \t"<<row[6]<<endl;
                 cout<<"\t\t\tPHONE NUMBER\t\t"<<row[7]<<endl;
                 cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
             }
         }
      }

      void Display_all_saving_ac_user()
    {
                cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
         qstate= mysql_query(conn,"select * from saving_ac");
         if(!qstate){
             res=mysql_store_result(conn);
             while(row=mysql_fetch_row(res))
             {   cout<<setw(6)<<"FIRST NAME"<<setw(6)<<"SECOND NAME"<<setw(6)<<"\tAGE \t"<<setw(6)<<"AC_NUMBER"<<setw(6)<<"CURRENT BALANCE"<<setw(6)<<"PHONE NUMBER"<<setw(6)<<"CURRENT PROFIT"<<setw(6)<<endl;
                 cout<<setw(6)<<row[1]<<setw(6)<<row[2]<<setw(6)<<setw(6)<<row[3]<<setw(6)<<row[4]<<setw(6)<<row[6]<<setw(6)<<row[7]<<setw(6)<<row[8]<<endl;
                cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
                /* cout<<"\t\t\tFIRST NAME\t\t"<<row[1]<<endl;
                 cout<<"\t\t\tSECOND NAME \t\t"<<row[2]<<endl;
                 cout<<"\t\t\tAGE \t\t\t"<<row[3]<<endl;
                 cout<<"\t\t\tAC_NUMBER\t\t"<<row[4]<<endl;
                 cout<<"\t\t\tCURRENT BALANCE \t"<<row[6]<<endl;
                 cout<<"\t\t\tPHONE NUMBER\t\t"<<row[7]<<endl;
                 cout<<"\t\t\tCURRENT PROFIT\t\t"<<row[8]<<endl;
                 cout<<"\n"<<endl;
                 shade3(80);
                 cout<<"\n"<<endl;
             }*/
         }}
    }

   void CREATE_ADMIN()
   {
         string name,second,password,s;
         int er;
        // while(1){
         cout<<"Please enter your First name"<<endl; cin>>name;
         cout<<"Please enter your second name"<<endl; cin>>second;
             /*string  sqlQuery= "SELECT * FROM loan_beneficiaries WHERE name ='"+name+"'AND second='"+second+"'";
      qstate = mysql_query(conn, sqlQuery.c_str());
       system("cls");
     if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                cout<<"\n\n\tFirst name or second name exit sorry try again\n\n";
            er=0;
            }
        }
    if(er==1)
          break;
         }*/
         cout<<"Please enter your password"<<endl;
          char ch;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          p= encryptDecrypt(password);
         string query= "insert into admin(name,second,password)values('"+name+"','"+second+"','"+p+"')";
         qstate = mysql_query(conn,query.c_str());
         if(!qstate){
          s="ADMIN CREATED SUCCESFULLY";
            cout<<"\n\t\t\t";write(s);cout<<"\n";
         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
   }
   }

   void LOANAPPLICANTS()
   {
         cout<<""<<endl;
         cout<<""<<endl;

         string FirstName,SecondName,Age,loan_no,amounttaken,timePeriod,returnMoney,phone_no,la;
         la="LOAN APPLYING";
         int rate,t,er;
         string s;
         while(1){
         cout<<"Please enter your First name"<<endl; cin>>FirstName;
         cout<<"Please enter your second name"<<endl; cin>>SecondName;
         cout<<"Please enter your age"<<endl;
          Age=validate();
         cout<<"Please enter your loan number"<<endl;
         loan_no=validate();
         cout<<"enter the amount you for your debt"<<endl;
         amounttaken=validate();
         cout<<"Please enter the time (in year) up to paying back"<<endl;
         timePeriod=validate();
         rate=atoi(amounttaken.c_str());
         t=atoi(timePeriod.c_str());
         returnMoney=laonreturncalculate(rate,t);
          cout<<"Amount to be returned is\n"<<returnMoney<<endl;
         cout<<"Please enter your phone number"<<endl;
          phone_no=validate();
       string  sqlQuery= "SELECT * FROM loan_beneficiaries WHERE FirstName ='"+FirstName+"'AND SecondName='"+SecondName+"'";
      qstate = mysql_query(conn, sqlQuery.c_str());
       system("cls");
     if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                cout<<"\n\n\tSorry You name exist Return the last loan of\t"<<row[7]<<"\tto get New one\n\n";
            er=0;
            }
        }
    if(er==1)
          break;
         }
         string query= "insert into loan_beneficiaries(FirstName,SecondName,Age,loan_no,amounttaken,time,returnMoney,phone_no)"
         " values('"+FirstName+"','"+SecondName+"','"+Age+"','"+loan_no+"','"+amounttaken+"','"+timePeriod+"','"+returnMoney+"','"+phone_no+"')";
         qstate = mysql_query(conn,query.c_str());
         if(!qstate){
        cout<<"\n\t\tEnter sponsor and security details to complete you loan applications\n";
        delay(20);
        CREATESPONSORSECURITY();
        s="LOAN APPLIED SUCCESFULLY WE WILL SEND TEXT SOON FOR NOTIFICATIONS";
         savestate(la,rate);
            cout<<"\n\n\t\t";write(s);cout<<"\n\n";
         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
   }
   }
   void  CHANGE_PASSWORD_SAVING_AC()
   {
        string ac_password,s;
         cout<<"\nPlease enter your new account password\n"<<endl;
          char ch;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           ac_password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          p=encryptDecrypt(ac_password);
         string query ="UPDATE saving_ac  SET `ac_password` = '"+p+"' WHERE `id` = '"+user_id+"'";
         qstate = mysql_query(conn,query.c_str());
         if(!qstate){
          s="PASSWORD CHANGED SUCCESFULLY";
            cout<<"\n\t\t\t";write(s);cout<<"\n";
         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
   }
   }
   void CHANGE_PASSWORD_ADMIN()
   {
        string password,s;
         cout<<"\nPlease enter your new account password\n"<<endl;
          char ch;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          p=encryptDecrypt(password);
         string query ="UPDATE admin  SET password = '"+p+"' WHERE id = '"+user_id+"'";
         qstate = mysql_query(conn,query.c_str());
         if(!qstate){
          s="PASSWORD CHANGED SUCCESFULLY";
            cout<<"\n\t\t\t";write(s);cout<<"\n";
         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
   }
   }
     void  CHANGE_PASSWORD_CURRENT_USER_AC()
      {
         string ac_password,s;
         cout<<"\nPlease enter your new account password\n"<<endl;
          char ch;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           ac_password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          p=encryptDecrypt(ac_password);
         string query ="UPDATE current  SET ac_password = '"+p+"' WHERE id = '"+user_id+"'";
         qstate = mysql_query(conn,query.c_str());
         if(!qstate){
          s="PASSWORD CHANGED SUCCESFULLY";
            cout<<"\n\t\t\t";write(s);cout<<"\n";
         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
  }
   }

   void createcurrentaccount(){
          int er=1;
               cout<<""<<endl;
                 cout<<""<<endl;
         string FirstName,SecondName,Age,ac_number,ac_password,current_balance,phone_no;
         //while(1)
                            // {
         cout<<"Please enter your First name"<<endl; cin>>FirstName;
         cout<<"Please enter your second name"<<endl; cin>>SecondName;
          /*string  sqlQuery= "SELECT * FROM current WHERE FirstName ='"+FirstName+"'AND SecondName='"+SecondName+"'";
          qstate = mysql_query(conn, sqlQuery.c_str());
          system("cls");
          if(!qstate)
          {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
            cout<<"\n\n\tFirst name and second name exist please try again later\n\n";
             }
             er=0;
           }
           if(er=1)
            break;
         }*/
         cout<<"Please enter your age"<<endl;
         Age=validate();
         cout<<"Please enter your account number"<<endl;
         ac_number=validate();
         cout<<"Please enter your account password"<<endl;
           char ch;
           string s;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           ac_password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          encryptDecrypt(ac_password);
          p=encryptDecrypt(ac_password);
         cout<<"\nPlease enter initial amount to deposit"<<endl;
         current_balance=validate();
         cout<<"Please enter your phone number"<<endl;
         phone_no=validate();
         string query= "insert into current(FirstName,SecondName,Age,ac_number,ac_password,curent_balance,phone_no)"
         " values('"+FirstName+"','"+SecondName+"','"+Age+"','"+ac_number+"','"+p+"','"+current_balance+"','"+phone_no+"')";
          qstate = mysql_query(conn,query.c_str());
         if(!qstate){
          s="BRAVO ACCOUNT CREATED";
            cout<<"\n\t\t\t";write(s);cout<<"\n";

         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
  }

   }



    void CREATE_SAVING_AC()
  {
         string FirstName,SecondName,Age,ac_number,ac_password,curent_balance,phone_no,profit;
         int er=1;
        // while(1)
       // {
         cout<<"Please enter your First name"<<endl; cin>>FirstName;
         cout<<"Please enter your second name"<<endl; cin>>SecondName;
       /*  string  sqlQuery= "SELECT * FROM saving_ac WHERE FirstName ='"+FirstName+"'AND SecondName='"+SecondName+"'";
         qstate = mysql_query(conn, sqlQuery.c_str());
          system("cls");
         if(!qstate)
           {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                cout<<"\n\n\tFirst name and second name exist please try again later\n\n";
            er=0;
            }
          }
          if(er==1)
            break;
         }*/


         cout<<"Please enter your age"<<endl;
         Age=validate();
         cout<<"Please enter your account number"<<endl;
         ac_number=validate();
         cout<<"Please enter your account password"<<endl;
          char ch;
          string s;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           ac_password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
         string pass;
         pass=encryptDecrypt(ac_password);
          cout<<""<<endl;
         cout<<"Please enter initial amount to deposit"<<endl;
         curent_balance=validate();
         cout<<"Please enter your phone number"<<endl;
         phone_no=validate();
         int p;
         p=atoi(curent_balance.c_str());
         profit=calculateprofit(p);
         string query= "insert into saving_ac(FirstName,SecondName,Age,ac_number,ac_password,curent_balance,phone_no,profit)"
         " values('"+FirstName+"','"+SecondName+"','"+Age+"','"+ac_number+"','"+pass+"','"+curent_balance+"','"+phone_no+"','"+profit+"')";
         qstate = mysql_query(conn,query.c_str());
         if(!qstate){
          s="BRAVO ACCOUNT CREATED";
            cout<<"\n\t\t\t"<<endl; write(s); cout<<"\n"<<endl;

         }else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
   }
  }

   void DEPOSITMONEYCURRENT()
{    int amount, a;
    string total,dp;
    dp="DEPOSIT MONEY";
    string Query= "SELECT curent_balance FROM current WHERE id ='"+user_id+"'";
    qstate = mysql_query(conn, Query.c_str());
    if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
           cout<<"ENTER AMOUNT TO DEPOSIT  \n";
          amount=validate1();
           string p;
           p=row[0];
           a=atoi(p.c_str());
           a+=amount;
         std::stringstream ss;
         ss << a;
         total = ss.str();
         system("cls");
string query ="UPDATE current  SET curent_balance = '"+total+"' WHERE id = '"+user_id+"'";

     qstate = mysql_query(conn,query.c_str());
         if(!qstate){
              string j;
            j="\n\t\t\t\tACCOUNT DEPOSIT MADE SUCCESFULLY AN AMOUNT OF\t\t\n";
            cout<<"\t\t\t"; write(j) ; cout<<"\tNew Amount is\n"<<total<<endl;

            savestate(dp,amount);

         }else{

            cout<<"query problem: "<<mysql_error(conn)<<endl;
         }
     }
}
}

void DEPOSITMONEYSAVING()
{ int amount,a;

string total,total2,dp;
      dp="DEPOSIT MONEY";
    string Query= "SELECT curent_balance  FROM saving_ac WHERE id ='"+user_id+"'";
 qstate = mysql_query(conn, Query.c_str());
    if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
           cout<<"ENTER AMOUNT TO DEPOSIT\n";
           amount=validate1();
           string j;
           j=row[0];
           a=atoi(j.c_str());
           a+=amount;
          stringstream ss;
         ss <<a;
         total2 = ss.str();
         total=calculateprofit(a);
         system("cls");
string query ="UPDATE saving_ac  SET curent_balance = '"+total2+"',profit='"+total+"' WHERE id = '"+user_id+"'";

     qstate = mysql_query(conn,query.c_str());
         if(!qstate){
            string j;
            j="\n\t\t\t\tACCOUNT DEPOSIT MADE SUCCESFULLY AN AMOUNT OF\t\t\n";
            cout<<"\t\t\t";write(j);cout<<"\tNew Amount is\t"<<total2<<"\tNew profit is\t"<<total<<endl;
            savestate(dp,amount);

         }else{

            cout<<"query problem: "<<mysql_error(conn)<<endl;
         }
     }
}
}


  void WITHDRAWMONEYCURRENT()
{ int amount,a;
string total,wm;
   wm="WITHDRAW MONEY";
    string Query= "SELECT curent_balance FROM current WHERE id ='"+user_id+"'";
 qstate = mysql_query(conn, Query.c_str());
    if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
           cout<<"ENTER AMOUNT TO WITHDRAW\n";

           while(1)
        {  amount=validate1();
           string j;
           int g;
           j=row[0];
           a=atoi(j.c_str());
           g=amount+5000;
           if(g>=a)
           {
             cout<<"insufficient amount please Try again\n";
           }
           else
             break;

        }

        int c;
            c=a-amount;
         stringstream ss;
         ss << c;
         total = ss.str();
         system("cls");
string query ="UPDATE current SET curent_balance = '"+total+"' WHERE id = '"+user_id+"'";

     qstate = mysql_query(conn,query.c_str());
         if(!qstate){
            string j;
            j="\n\t\t\tACCOUNT DEPOSIT MADE SUCCESFULLY AN AMOUNT OF\n\t\t";
            cout<<"\t\t\t";write(j);cout<<"\tNew Amount is\t"<<total<<endl;
            savestate(wm,amount);

         }else{

            cout<<"query problem: "<<mysql_error(conn)<<endl;
         }
     }
}
}

  void WITHDRAWMONEYSAVING()
{ int amount,a;
string total,total2,wm;
wm="WITHDRAW MONEY";
    string Query= "SELECT curent_balance  FROM saving_ac WHERE id ='"+user_id+"'";
 qstate = mysql_query(conn, Query.c_str());
    if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
           cout<<"ENTER  AMOUNT TO WITHDRAW\n";
           while(1)
        {  amount=validate1();
           string j;
           int g;
           j=row[0];
           a=atoi(j.c_str());
            g=amount+5000;
           if(g>=a)
           {
             cout<<"insufficient amount please Try again\n";
           }
           else
             break;
        }
           int p;
           p=a-amount;
        stringstream ss;
         ss << p;
         total = ss.str();
         total2=calculateprofit(p);
         system("cls");
string query ="UPDATE saving_ac SET curent_balance = '"+total+"',profit='"+total2+"' WHERE id = '"+user_id+"'";

     qstate = mysql_query(conn,query.c_str());
         if(!qstate){
            string j;
            j="\n\t\t\tACCOUNT DEPOSIT MADE SUCCESFULLY AN AMOUNT OF\n\t\t";
            cout<<"\t\t\t";write(j);cout<<"\tNew Balance is\t"<<total<<"\tNew profit is\t"<<total2<<endl;
            savestate(wm,amount);

         }else{

            cout<<"query problem: "<<mysql_error(conn)<<endl;
         }
     }
}
}

  void SHOWBALANCESAVING(){
     string Query= "SELECT curent_balance FROM saving_ac WHERE id ='"+user_id+"'";
      qstate = mysql_query(conn, Query.c_str());
          if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
                    shade3(40);
           cout<<"\n\t\tYOUR BALANCE IS....."<<row[0]<<"\t \n\n\t\t\!! ENJOY OUR SERVICE\n";
                 shade3(40);
     }

}
}

    void SHOWBALANCECURRENT(){
     string Query= "SELECT curent_balance FROM current  WHERE id ='"+user_id+"'";
 qstate = mysql_query(conn, Query.c_str());
if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
           cout<<"\n\t\tYOUR BALANCE IS....."<<row[0]<<"\t \n\n\t\t!! ENJOY OUR SERVICE\n";
                 shade3(100);
     }

}
}
    void displaystatement()
    { int er;
      string ac;
      ac=Tostring(taken);
     string  sqlQuery= "SELECT * FROM bank_statement WHERE '"+user_id+"'AND account='"+ac+"'";
     qstate = mysql_query(conn, sqlQuery.c_str());
      system("cls");
     if(!qstate)
         {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {   shade1(88);
                cout<<"\n"<<endl;
                cout<<"Transactions.......\t\t"<<row[2]<<endl;
                cout<<"Date and time......\t\t"<<row[3]<<endl;
                cout<<"Amount of money....\t\t"<<row[4]<<endl;
            er=0;
            }
        }
    if(er==1){

    cout <<"\n UNFORTUNATELY THERE IS NO ANY TRANSACTIONS CARRIED OUT ENJOY OUR SERVICES\n";

    if(res != NULL)
       mysql_free_result(res);

            }
    }



   void ForUser(){
             cout<<"\n\n\t\t\t";shade3(16);cout<<"\tOUR SERVICES\t";shade3(14);
             string bs,al,dm,wm,cc,cb,ex,sa,ca,pc,in;
             int selected,d,f,g,h;
             cout<<"\n\n\n\t\t\tSERVICE\t\tENTRY NUMBER\n\n";
             bs="BANK STATEMENT....1";
             cout<<"\t\t\t";write(bs);cout<<"\n"<<endl;
             al="APPLY FOR LOAN....2";
             cout<<"\t\t\t";write(al);cout<<"\n"<<endl;
             dm="DEPOSIT MONEY.....3";
             cout<<"\t\t\t";write(dm);cout<<"\n"<<endl;
             wm="WITHDRAW MONEY....4";
             cout<<"\t\t\t";write(wm);cout<<"\n"<<endl;
             cc="CUSTOMER CARE.....5";
             cout<<"\t\t\t";write(cc);cout<<"\n"<<endl;
             cb="CHECK BALANCE.....6";
             cout<<"\t\t\t";write(cb);cout<<"\n"<<endl;
             pc="CHANGE PASSWORD...7";
              cout<<"\t\t\t";write(pc);cout<<"\n"<<endl;
             ex="EXIT.....8";
             cout<<"\t\t\t\t\t";write(ex);cout<<"\n"<<endl;
             cout<<"\t\t ENTER THE SERVICES ENTRY NUMBER FOR YOUR SERVICES DESIRE"<<endl;
            selected=validate1();

        switch(selected){
            case 1:
                {
                     system("cls");
                    d=taken;
                    switch(d){
                    case 1:
                     system("cls");
                     displaystatement();
                      cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int g;
                    g=validate1();
                    if(g=1){
                   system("cls");
                    ForUser();}
                    else{exit();}
                       break;
                        case 2:
                      system("cls");
                        displaystatement();
                      cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int t;
                    t=validate1();
                    if(t=1){
                   system("cls");
                    ForUser();}
                     else{exit();}
                      break;
                    default:
                      cout<<"\n\t\tYOU ENTERED THE WRONG CHOICE\t\n"; system("cls"); ForUser();}
                }
                break;

            case 2:{
                  system("cls");
                   f=taken;
                    switch(f){
                    case 1:
                     system("cls");
                       LOANAPPLICANTS();
                     cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int v;
                    v=validate1();
                    if(v=1){
                   system("cls");
                    ForUser();} else{exit();}
                     break;
                        case 2:
                    system("cls");
                      cout<<"OOPS WE ARE SORRY LOAN NOT RECHABLE TO CURRENT ACCOUNT"<<endl;
                       cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int x;
                    x=validate1();
                    if(x=1){
                   system("cls");
                    ForUser();} else{exit();}
                      break;
                    default:
                      cout<<"YOU ENTERED THE WRONG CHOICE\t\n"; system("cls"); ForUser();}
                }
                break;

            case 3:
               {   system("cls");
                    g=taken;
                    switch(g){
                    case 1:
                     system("cls");
                     DEPOSITMONEYSAVING();
                   cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int q;
                    q=validate1();
                    if(q=1){
                   system("cls");
                    ForUser();} else{exit();}
                     break;
                        case 2:
                    system("cls");
                    DEPOSITMONEYCURRENT();
                 cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int w;
                    w=validate1();
                    if(w=1){
                   system("cls");
                    ForUser();} else{exit();}
                      break;
                    default:
                      cout<<"YOU ENTERED THE WRONG CHOICE\t\n";system("cls");ForUser();}
                }
                break;

            case 4:
                {   system("cls");
                    d=taken;
                    switch(d){
                    case 1:
                     system("cls");
                     WITHDRAWMONEYSAVING();
                   cout<<"\n\n\n\t\t\tEnter1 for homepage"<<endl;
                    int h;
                    h=validate1();
                    if(h=1){
                   system("cls");
                    ForUser();} else{exit();}
                     break;
                        case 2:
                    system("cls");
                    WITHDRAWMONEYCURRENT();
                   cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int m;
                    m=validate1();
                    if(m=1){
                   system("cls");
                    ForUser();} else{exit();}
                      break;
                    default:
                      cout<<"YOU ENTERED THE WRONG CHOICE\t\n"; system("cls"); ForUser();}
                }
                break;
            case 5:
               exit1();
                cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int o;
                    o=validate1();
                    if(o=1){
                    system("cls");
                    ForUser();} else{exit();}
                break;
            case 6:
                 {  system("cls");
                    h=taken;
                    switch(h){
                    case 1:
                     system("cls");
                    SHOWBALANCESAVING();
                    cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int z;
                    z=validate1();
                    if(z=1){
                   system("cls");
                    ForUser();} else{exit();}
                     break;
                        case 2:
                     system("cls");
                     SHOWBALANCECURRENT();
                   cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int p;
                    p=validate1();
                    if(p=1){
                   system("cls");
                    ForUser();} else{exit();}
                      break;
                    default:
                      cout<<"\n\t\t\tYOU ENTERED THE WRONG CHOICE\t\n"; system("cls");
                     ForUser();}
                }
                break;
                case 7:
                     system("cls");
                    d=taken;
                    switch(d){
                    case 1:
                     system("cls");
                    CHANGE_PASSWORD_SAVING_AC();
                   cout<<"\n\n\n\t\t\tEnter1 for homepage"<<endl;
                    int h;
                    h=validate1();
                    if(h=1){
                   system("cls");
                    ForUser();} else{exit();}
                     break;
                        case 2:
                    system("cls");
                    CHANGE_PASSWORD_CURRENT_USER_AC();
                   cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int m;
                    m=validate1();
                    if(m=1){
                   system("cls");
                    ForUser();} else{exit();}
                      break;
                    default:
                      cout<<"YOU ENTERED THE WRONG CHOICE\t\n"; system("cls");
                      ForUser();
                      }
            break;
            case 8:
                exit();
                break;

            default:
                in="\t\t\tInvalid choice\n";
                   cout<<"\n\t\t\t";
                   shade8(48);
               cout<<"\t\t\t\t\t";write(in);
                    cout<<"\t\t\t";
                    shade8(48);
                  system("cls");
                  ForUser();
                   }
    }
    void loginsaving()
 {   string UserName,ac_password;
    int er=1;
     cout<<"\n\nEnter Your Name : "<<endl;
     cin>>UserName;
     system("cls");
     cout<<"\nEnter Your Password : "<<endl;
           char ch;
           string s;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           ac_password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          p=encryptDecrypt(ac_password);
string  sqlQuery= "SELECT * FROM saving_ac WHERE FirstName ='"+UserName+"'AND ac_password='"+p+"'";
 qstate = mysql_query(conn, sqlQuery.c_str());
   system("cls");
    if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            { user_id=row[0];
            cout<<"\t\t***************************************************************\n";
            cout<<"\t\t\t WELCOME :\t"<<row[1]<<"\t"<<row[2]<<"\t !! ENJOY OUR SERVICE\n";
            cout<<"\t\t****************************************************************\n";
           er=0;
           ForUser();
            }
        }
    if(er==1){

cout <<"\n Your ACCOUNT Number OR PASSWORD is INCORECT please Try AGAIN\n";

cout<<"\t\t\tEnter 1 for try again or 0 to quit\n";
  int q;
  q=validate1();
  if(q=1){loginsaving();} else{exit();}

}   if(res != NULL)
       mysql_free_result(res);

}

 void logincurrent()
 {
 string name,password;
    int er=1;
     cout<<"\n\nEnter Your Name : "<<endl;
     cin>>name;
     system("cls");
     cout<<"\nEnter Your Password : "<<endl;
        char ch;
           string s;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          p=encryptDecrypt(password);
      string  sqlQuery= "SELECT * FROM current WHERE FirstName ='"+name+"'AND ac_password='"+p+"'";
     qstate = mysql_query(conn, sqlQuery.c_str());
      system("cls");
     if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            { user_id=row[0];
              cout<<"\n"<<endl;
                 shade3(80);
            cout<<"\n\n\t WELCOME : "<<row[1]<<"\t"<<row[2]<<"\t !! ENJOY OUR SERVICE\n\n";
                 shade3(80);

            er=0;
            cout<<"\n"<<endl;
            ForUser();
            }
        }
    if(er==1){

cout <<"\n Your ACCOUNT Number OR PASSWORD is INCORECT please Try AGAIN\n";

cout<<"\t\t\tEnter 1 for try again or 0 to quit\n";
  int q;
  q=validate1();
  if(q=1){logincurrent();} else{exit();}
}
    if(res != NULL)
       mysql_free_result(res);

}

void FORADMIN()
{
   cout<<"\n\n\t\t";shade3(17);cout<<"OUR SERVICES";shade3(16);cout<<"\n\n\n";
       string bs,al,dm,wm,cc,cb,rt,in,pc,ex;
       int selected;
          bs="DISPLAY ALL CURRENT ACCOUNT USER......1";
          al="DISPLAY ALL SAVING ACCOUNT USER.......2";
          wm="DISPLAY ALL SPONSOR AND SECURITIES....3";
          cb="DISPLAY ALL ADMIN.....................4";
          dm="DISPLAY ALL LOAN APLICANTS............5";
          rt="CREATE EXTRA ADMIN....................6";
          pc="CHANGE PASSWORD.......................7";
          ex="EXIT..................................8";
          cout<<"\t\t\t";write(bs);cout<<"\n"<<endl;
          cout<<"\t\t\t";write(al);cout<<"\n"<<endl;
          cout<<"\t\t\t";write(wm);cout<<"\n"<<endl;
          cout<<"\t\t\t";write(cb);cout<<"\n"<<endl;
           cout<<"\t\t\t";write(dm);cout<<"\n"<<endl;
          cout<<"\t\t\t";write(rt);cout<<"\n"<<endl;
          cout<<"\t\t\t";write(pc);cout<<"\n"<<endl;
          cout<<"\t\t\t";write(ex);cout<<"\n"<<endl;
          cout<<"\t\t ENTER THE SERVICES ENTRY NUMBER FOR YOUR SERVICES DESIRE"<<endl;
          selected=validate1();
           switch(selected){
            case 1:
                 system("cls");
                 Display_all_current_ac_user();
                     cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int v;
                    v=validate1();
                    if(v=1){
                   system("cls");
                    FORADMIN();} else{exit();}
                 break;
            case 2:
                  system("cls");
                  Display_all_saving_ac_user();
                      cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int j;
                    j=validate1();
                    if(j=1){
                   system("cls");
                    FORADMIN();} else{exit();}
                  break;
            case 3:
                  system("cls");
                  Display_all_sponsorandsecurities();
                      cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int o;
                    o=validate1();
                    if(o=1){
                   system("cls");
                    FORADMIN();} else{exit();}
                    break;
            case 4:
                  system("cls");
                  DISPLAYADMIN();
                      cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int i;
                    i=validate1();
                    if(i=1){
                   system("cls");
                    FORADMIN();} else{exit();}
                    break;
            case 5:
                  system("cls");
                  DISPLAYLOANAPPLICANTS();
                      cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int y;
                    y=validate1();
                    if(y=1){
                   system("cls");
                    FORADMIN();} else{exit();}
                    break;
            case 6:
                 system("cls");
                 CREATE_ADMIN();
                       cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int u;
                    u=validate1();
                    if(u=1){
                   system("cls");
                    FORADMIN();} else{exit();}
                    break;
            case 7:
                  system("cls");
                  CHANGE_PASSWORD_ADMIN();
                      cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int z;
                    z=validate1();
                    if(z=1){
                   system("cls");
                    FORADMIN();} else{exit();}
                  break;
            case 8:
                exit();
                break;
            default:
                in="\t\t\tInvalid choice\n";
                   cout<<"\n\t\t\t";
                   shade8(48);
               cout<<"\t\t\t\t\t";write(in);
                    cout<<"\t\t\t";
                    shade8(48);
                  system("cls");
                  FORADMIN();
                   }
           }




    void loginadmin()
 {  string name,password;
    int er=1;
     cout<<"\n\nEnter Your Name : "<<endl;
     cin>>name;
     system("cls");
     cout<<"\nEnter Your Password : "<<endl;
        char ch;
           string s;
           ch = _getch();
           while(ch != 13){//character 13 is enter
           password.push_back(ch);
           cout << '*';
           ch = _getch();
          }
          string p;
          encryptDecrypt(password);
         p=encryptDecrypt(password);
      string  sqlQuery= "SELECT * FROM admin WHERE name ='"+name+"'AND password='"+p+"'";
     qstate = mysql_query(conn, sqlQuery.c_str());
      system("cls");
     if(!qstate)

        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            { user_id=row[0];
              cout<<"\n"<<endl;
                 shade3(80);
            cout<<"\n\n\t WELCOME : "<<row[1]<<"\t"<<row[2]<<"\t !! ENJOY OUR SERVICE\n\n";
                 shade3(80);

            er=0;
            cout<<"\n"<<endl;
            system("cls");
            FORADMIN();
            }
        }
    if(er==1){

cout <<"\n Your ACCOUNT Number OR PASSWORD is INCORECT please Try AGAIN\n";
  cout<<"\t\t\tEnter 1 for try again or 0 to quit\n";
  int q;
  q=validate1();
  if(q=1){loginadmin();} else{exit();}

}
    if(res != NULL)
       mysql_free_result(res);

}
     void welcomenote()
{
        cout<<""<<endl;
        cout<<""<<endl;
     // cout<<"\t\t";shade1(60);cout<<"\n\t\t*"<<setw(63)<<"*\n\t\t*"<<setw(126)<<"*\n\t\t*WELCOME TO MWAPINGA BANK ONLINE SYSTEM ENJOY OUR SERVICES *\n\t\t*"<<setw(63)<<"\*\n\t\t*"<<setw(60)<<"*\n";cout<<"\t\t";shade1(60);
          cout<<""<<endl;
          cout<<""<<endl;
         // cout<<"\n\n\n\t\t\tLoading";shade2(18);
          system("cls");
         // cout<<"\t\t";shade1(60);cout<<"\n\t\t*"<<setw(63)<<"*\n\t\t*"<<setw(126)<<"*\n\t\t*WELCOME TO MWAPINGA BANK ONLINE SYSTEM ENJOY OUR SERVICES *\n\t\t*"<<setw(63)<<"\*\n\t\t*"<<setw(60)<<"*\n";cout<<"\t\t";shade1(60);
          cout<<""<<endl;
          cout<<""<<endl;
          string q,r,u,t,ex,s,c,sa,ca,in;
          int b,d,f;
          q="LOG IN..........";

          cout<<"\t\t\t\t";write(q);  cout<<""<<endl;cout<<""<<endl;
          cout<<"\t\t\t\tFOR\t\tENTRY NUMBER"<<endl;cout<<""<<endl;
           r="ADMIN............1";
           u="USER.............2";
           t="CREATE ACCOUNT...3";
          ex="EXIT.............4";
          //cout<<"\t\t\t\t";write(r);  cout<<""<<endl;cout<<""<<endl;
          cout<<"\t\t\t\t";write(u);  cout<<""<<endl;cout<<""<<endl;
          cout<<"\t\t\t\t";write(t);  cout<<""<<endl;cout<<""<<endl;
           cout<<"\t\t\t\t";write(ex);  cout<<""<<endl;cout<<""<<endl;
           cout<<"\t\t\tENTER THE  ENTRY NUMBER FOR YOUR SERVICES DESIRE"<<endl;
          b=validate1();
        switch(b){
            case 1:
                 system("cls");
                loginadmin();
            break;
            case 2:{  system("cls");
                   cout<<"\tWELCOME USER TO OUR SYSTEM CHOOSE ACCOUNT TYPE\n";
                    sa="SAVING ACCOUNT............1";
                    ca="CURRENT ACCOUNT...........2";
                   cout<<"\t\t\t\t";write(sa);  cout<<""<<endl;cout<<""<<endl;
                   cout<<"\t\t\t\t";write(ca);  cout<<""<<endl;cout<<""<<endl;
                    cout<<"\t\t\t\tENTER THE  ENTRY NUMBER FOR YOUR SERVICES DESIRE"<<endl;
                   d=validate1();
                   taken=d;
                   switch(d){
                     case 1:
                     system("cls");
                     loginsaving();
                     system("cls");
                     welcomenote();

                     break;

                     case 2:
                       system("cls");
                        logincurrent();
                        system("cls");
                        welcomenote();
                       break;

                default:
                    cout<<"YOU ENTERED THE WRONG CHOICE\t";
                    system("cls");
                    welcomenote();
                }
                    break;
               }
                  case 3:
                {   system("cls");
                    cout<<"\tWELCOME USER TO OUR SYSTEM CHOOSE ACCOUNT TYPE\n";
                    sa="SAVING ACCOUNT............1";
                    ca="CURRENT ACCOUNT...........2";
                   cout<<"\t\t\t\t";write(sa);  cout<<""<<endl;cout<<""<<endl;
                   cout<<"\t\t\t\t";write(ca);  cout<<""<<endl;cout<<""<<endl;
                    cout<<"\t\t\t\tENTER THE  ENTRY NUMBER FOR YOUR SERVICES DESIRE"<<endl;
                   f=validate1();
                   switch(f){
                     case 1:
                     system("cls");
                    CREATE_SAVING_AC();
                    cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int o;
                    o=validate1();
                    if(o=1){
                    system("cls");
                    welcomenote();} else{exit();}
                     break;

                     case 2:
                       system("cls");
                        createcurrentaccount();
                        cout<<"\n\n\n\t\t\tEnter 1 for homepage"<<endl;
                    int t;
                    t=validate1();
                    if(t=1){
                    system("cls");
                    welcomenote();} else{exit();}
                       break;

                default:
                    cout<<"YOU ENTERED THE WRONG CHOICE\t";
                      system("cls");
                    welcomenote();
                }

                break;
            case 4:
                exit();

            default:
               in="\t\t\tInvalid choice\n";
                   cout<<"\n\t\t\t";
                   shade8(48);
               cout<<"\t\t\t\t\t";write(in);
                    cout<<"\t\t\t";
                    shade8(48);
                  system("cls");
                  welcomenote();
                   }
}
}

  main()
 {
      conn = mysql_init(0);

      int qstate;
      conn= mysql_real_connect(conn,"localhost","root","","bank system",0,NULL,0);
      if(conn)
            {
    welcomenote();
    }
    else{
      cout<<"query execution problem!"<<mysql_error(conn)<<endl;
     }
   mysql_close(conn);
}
