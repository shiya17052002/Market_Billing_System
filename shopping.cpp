#include<iostream>
#include<fstream>

using namespace std;

class shopping{
    private:
           int pcode;
           float price;
           float dis;
           string pname;
           
    public:
            void menu();
            void administrator();
            void customer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping:: menu(){
    m:
    int choice;
    string email;
    string password;
    
    cout<<"\t\t\t\t\t\t________________________________________________\n";
    cout<<"\t\t\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t\t\t              Supermarket Main Menu              \n";
    cout<<"\t\t\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t\t\t________________________________________________\n";
    cout<<"\t\t\t\t\t\t 1) Administrator     \n";
    cout<<"\t\t\t\t\t\t                       \n";
    cout<<"\t\t\t\t\t\t 2) Customer           \n";
    cout<<"\t\t\t\t\t\t                       \n";
    cout<<"\t\t\t\t\t\t 3) Exit               \n";
    cout<<"\n\t\t\t\t\t\t Please Enter your choice! ";
    cin>>choice;
    
    switch(choice){
        
        case 1:{
            cout<<"\t\t\t\t\t\t Please Login \n";
            cout<<"\t\t\t\t\t\t Enter Email :";
            cin>>email;
            cout<<"\t\t\t\t\t\t Enter Password :";
            cin>>password;
            
            if(email=="admin@gmail.com"&&password=="admin123"){
                administrator();
            }else{
                cout<<"Invalid Email/Password";
            }
            break;
        }    
        case 2:
             {
                 customer();
             }
        case 3:
             {
                 exit(0);
             }
        default:
        {
            cout<<"please select from the given options";
        }
    }
    goto m;
}


void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t    1) Add the Product   ";
    cout<<"\n\t\t\t                          ";
    cout<<"\n\t\t\t    2) Modify the  Product   ";
    cout<<"\n\t\t\t                          ";
    cout<<"\n\t\t\t    3) Delete  the  Product   ";
    cout<<"\n\t\t\t                          ";
    cout<<"\n\t\t\t    4) Back to main menu  ";
    
    
    cout<<"\n\t\t\t    Please enter your choice   ";
    cin>>choice;
    
    switch(choice){
        
         case 1:
                {
                   add();
                   break;
                }
                
        case 2: {
            edit();
            break;
        }        
        case 3: 
              rem();
               break;
        
        case 4:
              menu();
              break;
              
        default: 
               cout<<" Invalid choice!!!";
    }
    
    goto m;
    
}

void shopping :: customer(){
    m:
    int choice;
    cout<<"\t\t\t\t    Customer \n";
    cout<<"\t\t\t\t             \n";
    cout<<"\t\t\t\t    1) Buy  product \n";
   cout<<"\t\t\t\t             \n";
   cout<<"\t\t\t\t  2) Go Back           \n";
   cout<<"\t\t\t\t    Enter your choice: ";
   
   cin>>choice;
   
   switch(choice){
       case 1:
             receipt();
             break;
        case 2:
             menu();
             
        default:
        cout<<"\t\t\t\t  Invalid choice ";
   }
    
   goto m; 
}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t\t Add new product ";
    cout<<"\n\n\t\t\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t\t Price of the product";
    cin>>price;
    cout<<"\n\n\t\t Discount on product ";
    cin>>dis;
    
    data.open(" database.txt",ios::in);
    
    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        
        while(!data.eof())
        {
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    
    
    if(token==1){
        goto m;
        }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();

    }
         
   }
    cout<<"\n\n\t\t Record inserted";
        
    }

void shopping :: edit(){
    fstream data , data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    
    cout<<"\n\n\t\t\t\t Modify the Record";
    cout<<"\n\n\t\t\t\t Product code";
    cin>>pkey;
    
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n \t\t\t File does not exist";
        
    }
    {
        data1.open("database1.txt",ios::app|ios::out);
        
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\n\t\t\t\t Product new code :";
                cin>>c;
                cout<<"\n\n\t\t\t\t Name of the product:";
                cin>>n;
                cout<<"\n\n\t\t\t\t Price of the product:";
                cin>>p;
                cout<<"\n\n\t\t\t\t Discount on  the product:";
                cin>>d;
                
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<" "<<d<<"\n";
                cout<<"\n\n\t\t\t\t\t Record edited";
                token++;
            }else{
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        
        remove("databse.txt");
        rename("database1.txt","database.txt");
        
        if(token==0){
            cout<<"\n\n Record not found sorry!!";
        }
    }
}

void shopping:: rem(){
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\n\t\t\tDelete product";
    cout<<"\n\n\n\t\t\t Product Code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n\t\t\t File doesnt exist";
        
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t\t\t\t Product deleted succesfully";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        
        data.close();
        data1.close();
        remove("databse.txt");
        rename("database1.txt","database.txt");
        
        if(token==0){
            cout<<"\n\n Record  not found ";
        }
    }
    
}
void shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________________________\n";
    cout<<"ProNo\t\t\t\tName\t\t\t\tPrice\n";
    cout<<"\n\n|___________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<"\t\t\t\t"<<pcode<<"\t\t\t\t"<<pname<<"\t\t\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
        
    }
    data.close();
    
}
void shopping::receipt(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    
    cout<<"\n\n\t\t\t\tRECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database";
        
    }else{
        data.close();
        list();
        cout<<"\n___________________________________________\n";
        cout<<"\n                                            \n";
        cout<<"\n        Please place the order              \n";
        cout<<"\n                                            \n";
        cout<<"\n_____________________________________________\n";
        do{
            m:
            cout<<"\n\n\nEnter the product code:";
            cin>>arrc[c];
            cout<<"\n\n\nEnter the product quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
             if(arrc[c]==arrc[i]){
                 cout<<"\n\nDuplicate product code. Please try again!!";
                 goto m;
             }   
             c++;
             cout<<"\n\nDo you want to buy another product? if yes then press y else no";
             cin>>choice;
            }
        }while(choice=='y');
        
        cout<<"\n\n\n\t\t\t_____________________________RECEIPT____________________________\n";
        cout<<"\n\t\tProduct No \t\t Product Name \t\t Product Quantity \t\t Price \t\t Amount \t\t Amount with Discount\n";
        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n\t\t\t"<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t\t\t"<<amount<<"\t\t"<<dis;
                    
                }
                 data>>pcode>>pname>>price>>dis; 
        }
    }
    data.close();
}
cout<<"\n\n_________________________________________________";
cout<<"\n\nTotal Amount: "<<total;
}
int main(){
    shopping s;
    s.menu();
}















