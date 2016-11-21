#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;



class ta_panta_ola
{
   public:
           int pos_x;
           int pos_y;
           int unique_id;
           char a;
           bool ele;
           bool oxhma;
           bool fwt;
           bool fele;
           virtual void func1();
           ta_panta_ola(int,int,int);
           int w,z;
};


void ta_panta_ola::func1(){}

ta_panta_ola::ta_panta_ola (int pos_x,int pos_y,int unique_id)
{
    this->pos_x=pos_x;
    this->pos_y=pos_y;
    this->unique_id=unique_id;
    oxhma=false;
    fwt=false;
    fele=true;
    ele=true;
}

class stathmos:public ta_panta_ola
{
  public:
          stathmos(int,int,int);
};

stathmos::stathmos(int pos_x,int pos_y,int unique_id):ta_panta_ola(pos_x,pos_y,unique_id){a='S',oxhma=false,fwt=false,ele=false,fele=false;}

class fire:public ta_panta_ola
{
   public:
       void func1();
       fire(int,int,int);

};
void fire::func1(){}

fire::fire(int pos_x,int pos_y,int unique_id):ta_panta_ola(pos_x,pos_y,unique_id)
{
    a='F';
    fwt=true;
    fele=false;

}

class vehicle:public ta_panta_ola
{

   public:
          int water_consumption;
          int water_capacity;
          int current_water_capacity;
          int current_fuel_capacity;
          int fuel_capacity;
          int fuel_consumption;
          int velocity;
          int age;
          char eidos;
          bool situation;
          void func1();
          vehicle(int,int,int);

};
void vehicle::func1(){}


vehicle::vehicle(int pos_x,int pos_y,int unique_id):ta_panta_ola(pos_x,pos_y,unique_id)
{
    situation=false;
    oxhma=true;
    ele=false;
}


class air_force:public vehicle
{

 public:
    air_force(int,int,int);

};

air_force::air_force(int pos_x,int pos_y,int unique_id):vehicle(pos_x,pos_y,unique_id){eidos='A';}

class ground_force:public vehicle
{

 public:
    ground_force(int,int,int);

};

ground_force::ground_force(int pos_x,int pos_y,int unique_id):vehicle(pos_x,pos_y,unique_id){eidos='G';}

class aeroplano:public air_force
{
  public:
          aeroplano(int,int,int);
};

aeroplano::aeroplano(int pos_x,int pos_y,int unique_id):air_force(pos_x,pos_y,unique_id){a='P',water_consumption=0,water_capacity=0,current_water_capacity=0,current_fuel_capacity=0,fuel_capacity=0,fuel_consumption=0,velocity=0,age=0;}

class elikoptero:public air_force
{
  public:
          elikoptero(int,int,int);
};

elikoptero::elikoptero(int pos_x,int pos_y,int unique_id):air_force(pos_x,pos_y,unique_id){a='H',water_consumption=0,water_capacity=0,current_water_capacity=0,current_fuel_capacity=0,fuel_capacity=0,fuel_consumption=0,velocity=0,age=0;}

class car:public ground_force
{
  public:
          car(int,int,int);
};

car::car(int pos_x,int pos_y,int unique_id):ground_force(pos_x,pos_y,unique_id){a='C',water_consumption=0,water_capacity=0,current_water_capacity=0,current_fuel_capacity=0,fuel_capacity=0,fuel_consumption=0,velocity=0,age=0;}

class truck:public ground_force
{
  public:
          truck(int,int,int);
};
truck::truck(int pos_x,int pos_y,int unique_id):ground_force(pos_x,pos_y,unique_id){a='T',water_consumption=0,water_capacity=0,current_water_capacity=0,current_fuel_capacity=0,fuel_capacity=0,fuel_consumption=0,velocity=0,age=0;}


class moto:public ground_force
{
  public:
          moto(int,int,int);
};

moto::moto(int pos_x,int pos_y,int unique_id):ground_force(pos_x,pos_y,unique_id){a='M',water_consumption=0,water_capacity=0,current_water_capacity=0,current_fuel_capacity=0,fuel_capacity=0,fuel_consumption=0,velocity=0,age=0;}

class city
{
   public:
           ta_panta_ola *diadromes[20][20];
           int n_air,n_moto,n_car,n_hel,n_truck,n_fire;
           void enarxi();
           void stop();
           void vlavi();
           void info();
           void insertv();
           void insertf();
           void map();
           void katastasi();
           int count_id;
           void movement();
           void elegxos(int,int);
           void qeleq(int,int);
           void qelegxos(int,int);
           void felegxos(int,int);
           void spread();
           int pos_x_kentrou;
           int pos_y_kentrou;
           int w;
           int z;
           vehicle *ox;
           void quench(int,int);
           stathmos *st;
           fire *fi;
            city();
};

city::city()
{
    int number_air;
    int number_helikopter;
    int number_car;
    int number_truck;
    int number_moto;
    int x,y;
    int count12;
    count_id=0;

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
         {
             diadromes[i][j]=NULL;
         }
    }
    srand(count12);
    pos_x_kentrou=0;
    pos_y_kentrou=rand()%20;
    diadromes[pos_x_kentrou][pos_y_kentrou]=new stathmos(pos_x_kentrou,pos_y_kentrou,count_id);
    count_id++;
    for(int i=0;i<5;i++)
    {
        do
            {
                x=rand()%20;
                y=rand()%20;

            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new fire(x,y, count_id);
            n_fire++;
            count_id++;
    }

    cout<<"Eisagete Plithos Aeroplanwn [0-5]:";
    cin>>number_air;
    system("cls");
    if( (number_air<0) || (number_air>5) )
         number_air=5;
    cout<<"Eisagete Plithos Elikopterwn [0-5]:";
    cin>>number_helikopter;
    system("cls");
    if( (number_helikopter<0) || (number_helikopter>5) )
         number_helikopter=5;
    cout<<"Eisagete Plithos Aytokinitwn [0-5]:";
    cin>>number_car;
    system("cls");
    if( (number_car<0) || (number_car>5) )
         number_car=5;
    cout<<"Eisagete Plithos Fortigwn [0-5]:";
    cin>>number_truck;
    system("cls");
    if( (number_truck<0) || (number_truck>5) )
         number_truck=5;
    cout<<"Eisagete Plithos Mhxanwn [0-5]:";
    cin>>number_moto;
    system("cls");
    if( (number_moto<0) || (number_moto>5) )
         number_moto=5;
   n_air=number_air;
   n_hel=number_helikopter;
   n_truck=number_truck;
   n_moto=number_moto;
   n_car=number_car;

  for(int i=0;i<5;i++)
    {

        if(i<number_air)
        {
            do
            {
                x=rand()%20;
                y=rand()%20;

            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new aeroplano(x,y, count_id);
            count_id++;
        }
        if(i<number_helikopter)
         {
             do
            {
                x=rand()%20;
                y=rand()%20;
            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new elikoptero(x,y, count_id);
            count_id++;
         }
        if(i<number_truck)
        {
           do
            {
                x=rand()%20;
                y=rand()%20;
            }while(diadromes[x][y]!=NULL);


           diadromes[x][y]=new truck(x,y, count_id);
           count_id++;
        }
        if(i<number_moto)
        {
            do
            {
                x=rand()%20;
                y=rand()%20;
            }while(diadromes[x][y]!=NULL);
            diadromes[x][y]=new moto(x,y, count_id);
            count_id++;
        }
        if(i<number_car)
        {

            do
            {
                x=rand()%20;
                y=rand()%20;
            }while(diadromes[x][y]!=NULL);

             diadromes[x][y]=new car(x,y, count_id);
             count_id++;
        }

    }
}
void city::insertf()
{
     for(;;)
  {
      int x;
      int y;
    system("cls");
    int e;
    cout<<"1.Vale fwtia"<<endl;
    cout<<"2.Epistrofh"<<endl;
    cout<<"3.Svhse fwtia"<<endl;
    cin>>e;
    switch(e){
                    case(1):

        {
            cout<<"Epelexes na valeis fwtia Dwse suntetagmenes [x,y]"<<endl;
          do
            {
              do
                {

                cout<<"Dwse suntetagmenes [x,y](0-20)"<<endl;
                cin>>x;
                cin>>y;

                }while((x>=20 && y >= 20) || (x<0 && y < 0));

            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new fire(x,y, count_id);
            count_id++;
            n_fire++;
        }
                   break;
                   case(2):return;break;
                   case(3):
          {
            cout<<"Epelexes na svhseis mia fwtia dwse suntetagmenes [x,y]"<<endl;
            do
                {

                cout<<"Dwse suntetagmenes [x,y](0-20)"<<endl;
                cin>>x;
                cin>>y;
                }while((x>=20 && y >= 20) || (x<0 && y < 0));
                if(diadromes[x][y]!=NULL)
                {
                if(diadromes[x][y]->a=='F')
                {
                                diadromes[x][y]=NULL;
                                 cout<<"Esvhses fwtia sto shmeio["<<x<<","<<y<<"]"<<endl;
                }
                else
                    cout<<"Den uparxei fwtia sto sugkekrimeno shmeio"<<endl;
                    system("pause");
                }

            }break;
        }
    }
}
void city::insertv()
{
    for(;;)
  {
      int x;
      int y;
    system("cls");
    int e;
    cout<<"1.Eisagwgi aeroplanou"<<endl;
    cout<<"2.Eisagwgi elikopterou"<<endl;
    cout<<"3.Eisagwgi autokinhtou"<<endl;
    cout<<"4.Eisagwgi forthgou"<<endl;
    cout<<"5.Eisagwgi moto"<<endl;
    cout<<"6.Epistrofi Stin Prosomoiwsi\n\n"<<endl;
    cout<<"Dwse Epilogi:";
    cin>>e;
    switch(e){

               case(1):

        {cout<<"Epelexes aeroplano. Dwse suntetagmenes [x,y]"<<endl;
          do
            {
              do
                {

                cout<<"Dwse suntetagmenes [x,y](0-20)"<<endl;
                cin>>x;
                cin>>y;

                }while((x>=20 && y >= 20) || (x<0 && y < 0));

            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new aeroplano(x,y, count_id);
            count_id++;
            n_air++;
        }
                   break;

               case(2):
        {cout<<"Epelexes elikoptero. Dwse suntetagmenes [x,y]"<<endl;
          do
            { do
                {

                cout<<"Dwse suntetagmenes [x,y](0-20)"<<endl;
                cin>>x;
                cin>>y;

                }while((x>=20 && y >= 20) || (x<0 && y < 0));

            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new elikoptero(x,y, count_id);
            count_id++;
            n_hel++;
        }         break;

               case(3):

        {cout<<"Epelexes autokinhto. Dwse suntetagmenes [x,y]"<<endl;
          do
            {
             do
                {
                cout<<"Dwse suntetagmenes [x,y](0-20)"<<endl;
                cin>>x;
                cin>>y;

                }while((x>20 && y >= 20) || (x<0 && y < 0));

            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new car(x,y, count_id);
            count_id++;
            n_car++;
        }        break;

               case(4):

        {cout<<"Epelexes forthgo.Dwse suntetagmenes [x,y]"<<endl;
          do
            { do
                {

                cout<<"Dwse suntetagmenes [x,y](0-20)"<<endl;
                cin>>x;
                cin>>y;

                }while((x>=20 && y >= 20) || (x<0 && y < 0));

              }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new truck(x,y, count_id);
            count_id++;
            n_truck++;
         }       break;

               case(5):

        {cout<<"Epelexes moto. Dwse suntetagmenes [x,y]"<<endl;
          do
            {
               do
                {

                cout<<"Dwse suntetagmenes [x,y](0-20)"<<endl;
                cin>>x;
                cin>>y;

                }while((x>20 && y >= 20) || (x<0 && y < 0));

            }while(diadromes[x][y]!=NULL);

            diadromes[x][y]=new moto(x,y, count_id);
            count_id++;
            n_moto++;
        }        break;

               case(6):return;break;
             }
  }
}

void city::katastasi()
{

    system("cls");
    cout<<"SYNOLIKO PLITHOS OXIMATVN => "<<n_air+n_hel+n_truck+n_moto+n_car<<endl;
    cout<<"SYNOLIKO PLITHOS FWTIWN => "<<n_fire<<endl;
    system("pause");

}

void city::map()
{
    system("cls");

    cout<<"\n\n"<<endl;

    for(int i=0;i<20;i++)
    {
        cout<<""<<endl;
        for(int j=0;j<20;j++)
        {
            if(diadromes[i][j]==NULL)
                cout<<"[ ]";
             else
                cout<<"["<<diadromes[i][j]->a<<"]";
        }
    }
  cout<<"\n\n"<<endl;



}

void city::stop()
{
  for(;;)
  {
    system("cls");
    int e;

   cout<<"                                                     )                   "<<endl;
   cout<<"       ,%,                                     ) _(___[]_               "<<endl;
   cout<<"       %%%,&&&,                     ,%%,      (;`       /\\              "<<endl;
   cout<<"       %Y/%&&&&                     %%%%   ___/_____)__/ _\\__     ,%%,  "<<endl;
   cout<<"     ^^^||^&\\Y&^^^^^^^^^^^^^^^^^^^^^%Y/%^^/ (_()   (  | /____/\\^^^%%%%^^"<<endl;
   cout<<"       `    || _,..=xxxxxxxxxxxx,    ||   |(' |LI (.)I| | LI ||   %\\Y%  "<<endl;
   cout<<"      -=      /L_Y.\"\"\"\"\"\"\"\"\"`,-n-. `     @'---|__||___|_|____||_   ||   "<<endl;
   cout<<"   __-=___.--'[========]| ] : []  \\.____________@//@___________) )______ "<<endl;
   cout<<"    -= _ _ _ |/ _ ''_ \" \" ||[ -_   |  _  _  _  _  _  _  _  _  _  _  _   "<<endl;
   cout<<"             '-(_)-(_)----'v'-(_)--'                                    "<<endl;
   cout<<"    --------------------------------------------------------------------"<<endl;
   cout<<"    ---------------------------------------------------------------------- "<<endl;
   cout<<"                                 http://ascii.co.uk/art/fire \n\n   "<<endl;

    cout<<"1.Eisagwgi Oximatos"<<endl;
    cout<<"2.Eisagwgi Fwtias"<<endl;
    cout<<"3.Plirofories Oximatos"<<endl;
    cout<<"4.Eisagwgi Katastasis Vlavis"<<endl;
    cout<<"5.Synoliki Katastasi Xarti"<<endl;
    cout<<"6.Termatismos Prosomoiwsis"<<endl;
    cout<<"7.Epistrofi Stin Prosomoiwsi\n\n"<<endl;
    cout<<"Dwse Epilogi:";
    cin>>e;
    switch(e){
               case(1):insertv();break;
               case(2):insertf();break;
               case(3):info();break;
               case(4):vlavi();break;
               case(5):katastasi();break;
               case(6):exit(1);break;
               case(7):return;break;
             }
  }
}

void city::enarxi()
{


    for(;;)
    {
        map();
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                    if(diadromes[i][j]!=NULL)
                       {
                                if((diadromes[i][j]->a=='P')||(diadromes[i][j]->a=='H')||(diadromes[i][j]->a=='C')||(diadromes[i][j]->a=='M')||(diadromes[i][j]->a=='T'))
                                {

                                    quench(i,j);

                                }
                       }
            }
        }
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                    if((diadromes[i][j]!=NULL)&&(diadromes[i][j]->oxhma=true)&&(diadromes[i][j]->a!='S')&&(diadromes[i][j]->a!='Z'))
                         diadromes[i][j]->ele=false;
            }
        }
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                    if((diadromes[i][j]!=NULL)&&(diadromes[i][j]->fwt=true)&&(diadromes[i][j]->a!='S')&&(diadromes[i][j]->a!='Z'))
                         diadromes[i][j]->fele=false;
            }
        }
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                if((diadromes[i][j]!=NULL))
                {
                    if(diadromes[i][j]->fwt)
                    {
                        spread();
                    }
                }
           }
        }
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<20;j++)
            {
                if((diadromes[i][j]!=NULL))
                {
                    if(diadromes[i][j]->oxhma)
                    {
                        movement();
                    }
                }
           }
        }

        if(kbhit())
            stop();
        Sleep(1000);

    }
}

void city::felegxos(int a,int b)
{

    static int count=0;
    srand(count);
    int b_old,a_old,x;
    b_old=b;
    a_old=a;
    if((a==0)&&(b==0))
    {
         x=rand()%2;
         if(x==1)
            b++;
         else
             a++;
    }
    else if( (a==0)&&(b==19) )
    {
        x=rand()%2;
        if(x==1)
             b--;
        else
             a++;
    }
    else if((a==19)&&(b==0))
    {
        x=rand()%2;
        if(x==1)
            b++;
        else
            a--;
    }
    else if((a==19)&&(b==19))
    {
        x=rand()&2;
        if(x==1)
            b--;
        else
            a--;
    }
    else if(a==0)
    {
        x=rand()%3;
        if(x==1)
            a++;
        else if(x==2)
            b++;
        else
            b--;
    }
    else if(a==19)
    {
        x=rand()%3;
        if(x==1)
            a--;
        else if(x==2)
            b++;
        else
            b--;
    }
    else if(b==0)
    {
        x=rand()%3;
        if(x==1)
            b++;
        else if(x==2)
            a++;
        else
            a--;
    }
    else if(b==19)
    {
        x=rand()%3;
        if(x==1)
            b--;
        else if(x==2)
            a++;
        else
            a--;
    }
    else
    {
        x=rand()%4;
        if(x==1)
            b--;
        else if(x==2)
            a++;
        else if(x==3)
            a--;
        else
            b++;
    }

     count++;
     x=rand()%1000;
        if(diadromes[a][b]==NULL)
           {
             if(x<10)
            {
                {
                            diadromes[a_old][b_old]->pos_y=b;
                            diadromes[a_old][b_old]->pos_x=a;
                            diadromes[a][b]=diadromes[a_old][b_old];
                            diadromes[a_old][b_old]=new fire(a_old,b_old,count_id);
                            count_id++;
                            n_fire++;
                }
            }
           }
        else if(diadromes[a][b]!=NULL)
        {
             if(diadromes[a][b]->a=='S')
              {
               if(x<9)
                {
                                diadromes[a_old][b_old]->pos_y=b;
                                diadromes[a_old][b_old]->pos_x=a;
                                diadromes[a][b]->a='Z';
                                diadromes[a_old][b_old]=new fire(a_old,b_old,count_id);
                                count_id++;
                                n_fire++;
                }
              }
             else if(diadromes[a][b]->a=='P')
             {
                 if(x<11)
                            {
                                diadromes[a_old][b_old]->pos_y=b;
                                diadromes[a_old][b_old]->pos_x=a;
                                diadromes[a][b]->a='p';
                                diadromes[a_old][b_old]=new fire(a_old,b_old,count_id);
                                count_id++;
                                n_fire++;
                            }
             }
             else if(diadromes[a][b]->a=='H')
             {
                 if(x<11)
                            {
                                diadromes[a_old][b_old]->pos_y=b;
                                diadromes[a_old][b_old]->pos_x=a;
                                diadromes[a][b]->a='h';
                                diadromes[a_old][b_old]=new fire(a_old,b_old,count_id);
                                count_id++;
                                n_fire++;
                            }
             }
             else if(diadromes[a][b]->a=='C')
             {
                 if(x<21)
                            {
                                diadromes[a_old][b_old]->pos_y=b;
                                diadromes[a_old][b_old]->pos_x=a;
                                diadromes[a][b]->a='c';
                                diadromes[a_old][b_old]=new fire(a_old,b_old,count_id);
                                count_id++;
                                n_fire++;
                            }
             }
             else if(diadromes[a][b]->a=='T')
             {
                 if(x<21)
                            {
                                diadromes[a_old][b_old]->pos_y=b;
                                diadromes[a_old][b_old]->pos_x=a;
                                diadromes[a][b]->a='t';
                                diadromes[a_old][b_old]=new fire(a_old,b_old,count_id);
                                count_id++;
                                n_fire++;
                            }
             }
             else if(diadromes[a][b]->a=='M')
             {
                 if(x<41)
                            {
                                diadromes[a_old][b_old]->pos_y=b;
                                diadromes[a_old][b_old]->pos_x=a;
                                diadromes[a][b]->a='m';
                                diadromes[a_old][b_old]=new fire(a_old,b_old,count_id);
                                count_id++;
                                n_fire++;
                            }
             }
        }
}
void city::qelegxos(int a,int b)
{
    int b_old,a_old,i;
    for(i=0;i<8;i++)
    {
       if(diadromes[a][b]!=NULL)
       {
        switch(i)
        {
            case(0):if((--a>0)&&(++b<20)){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                         qeleq(a_old,b_old);}

                }break;
            case(1):if(++b<20){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                            qeleq(a_old,b_old);}
                }break;
            case(2):if((++a<20)&&(++b<20)){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                            qeleq(a_old,b_old);}
                }break;
            case(3):if(--a>0){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                            qeleq(a_old,b_old);}
                }break;
            case(4):if(++a<20){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                            qeleq(a_old,b_old);}
                }break;
            case(5):if((--a>0)&&(--b>0)){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                            qeleq(a_old,b_old);}
                }break;
            case(6):if(--b>0){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                            qeleq(a_old,b_old);}
                }break;
            case(7):if((++a<20)&&(--b>0)){
                if(diadromes[a][b]!=NULL)
                        {
                            a_old=a;
                            b_old=b;
                            qeleq(a_old,b_old);}
            }break;
        }
      }
    }
}
void city::qeleq(int x,int y)
{
        if(diadromes[x][y]->a=='F')
            {
                    diadromes[x][y]->a='E';
            }
        else if(diadromes[x][y]->a=='c')
            {
                    diadromes[x][y]->a='C';
            }
        else if(diadromes[x][y]->a=='p')
            {
                    diadromes[x][y]->a='P';
            }
        else if(diadromes[x][y]->a=='m')
            {
                    diadromes[x][y]->a='M';
            }
        else if(diadromes[x][y]->a=='h')
            {
                    diadromes[x][y]->a='H';
            }
        else if(diadromes[x][y]->a=='Z')
            {
                    diadromes[x][y]->a='S';
            }
        else if(diadromes[x][y]->a=='t')
            {
                    diadromes[x][y]->a='T';
            }
}
void city::elegxos(int a,int b)
{

    static int count=0;
    srand(count);
    int b_old,a_old,x;
    b_old=b;
    a_old=a;
    if((a==0)&&(b==0))
    {
         x=rand()%2;
         if(x==1)
            b++;
         else
             a++;
    }
    else if( (a==0)&&(b==19) )
    {
        x=rand()%2;
        if(x==1)
             b--;
        else
             a++;
    }
    else if((a==19)&&(b==0))
    {
        x=rand()%2;
        if(x==1)
            b++;
        else
            a--;
    }
    else if((a==19)&&(b==19))
    {
        x=rand()&2;
        if(x==1)
            b--;
        else
            a--;
    }
    else if(a==0)
    {
        x=rand()%3;
        if(x==1)
            a++;
        else if(x==2)
            b++;
        else
            b--;
    }
    else if(a==19)
    {
        x=rand()%3;
        if(x==1)
            a--;
        else if(x==2)
            b++;
        else
            b--;
    }
    else if(b==0)
    {
        x=rand()%3;
        if(x==1)
            b++;
        else if(x==2)
            a++;
        else
            a--;
    }
    else if(b==19)
    {
        x=rand()%3;
        if(x==1)
            b--;
        else if(x==2)
            a++;
        else
            a--;
    }
    else
    {
        x=rand()%4;
        if(x==1)
            b--;
        else if(x==2)
            a++;
        else if(x==3)
            a--;
        else
            b++;
    }

     count++;
    if(diadromes[a][b]==NULL)
    {
                diadromes[a_old][b_old]->pos_y=b;
                diadromes[a_old][b_old]->pos_x=a;
                diadromes[a][b]=diadromes[a_old][b_old];
                diadromes[a_old][b_old]=NULL;

    }
}
void city::spread()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(!(diadromes[i][j]==NULL))
            {
               if((diadromes[i][j]->fwt)&&(!diadromes[i][j]->fele)&&(diadromes[i][j]->a!='S'))
               {
                        diadromes[i][j]->fele=true;
                        felegxos(i,j);

               }
            }
        }
    }
}
void city::movement()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(!(diadromes[i][j]==NULL))
            {
                if( (diadromes[i][j]->oxhma)&&(!diadromes[i][j]->ele)&&(diadromes[i][j]->a!='S'))
                {
                    diadromes[i][j]->ele=true;
                    elegxos(i,j);
                 }


            }
        }
    }
}
void city::quench(int i,int j)
{
    //for(int i=0;i<20;i++)
    //{
       // for(int j=0;j<20;j++)
       // {
       //     if(!(diadromes[i][j]==NULL))
       //     {
          //      if((diadromes[i][j]->a=='M')||(diadromes[i][j]->a=='C')||(diadromes[i][j]->a=='P')||(diadromes[i][j]->a=='H')||(diadromes[i][j]->a=='T'))//&&(!diadromes[i][j]->ele)&&(diadromes[i][j]->a!='S'))
          //      {
                    //cout<<"mpainei sthn malakia"<<endl;
                    //system("pause");
                    qelegxos(i,j);
         //       }
        //    }
      //  }
 //   }
}
void city::info()
{
    vehicle *ox;
    system("cls");
    int code;
    cout<<"Oximata :"<<endl;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {

            if(diadromes[i][j]!=NULL)
            {
                 if( (diadromes[i][j]->a!='F') && (diadromes[i][j]->a!='S'))
                   cout<<"Typos Oximatos :"<<diadromes[i][j]->a<<" me monadiko kwdiko: "<<diadromes[i][j]->unique_id<<"kai thesi: ["<<i<<","<<j<<"]"<<endl;

            }
        }
    }
    cout<<"\n\nDwse kwdiko oximatos";
    cin>>code;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
           if(diadromes[i][j]!=NULL)
           {
            if(diadromes[i][j]->unique_id==code)
            {
                ox=dynamic_cast<vehicle*>(diadromes[i][j]);
                cout<<"Plhrofories Oxhmatos"<<endl;
                cout<<"Typos Oximatos: "<<diadromes[i][j]->a<<"\nMe monadiko kwdiko: "<<diadromes[i][j]->unique_id<<"\nThesi: ["<<i<<","<<j<<"]\n\n"<<endl;
                cout<<"Katanalwsh nerou gia to svhsimo ths fwtias:"<<ox->water_consumption<<endl;
                cout<<"Xwritikothta nerou:"<<ox->water_capacity<<endl;
                cout<<"Trexousa xwritikothta nerou:"<<ox->current_water_capacity<<endl;
                cout<<"Trexousa xwristikothta kausimou:"<<ox->current_fuel_capacity<<endl;
                cout<<"Xwritikothta kausimou:"<<ox->fuel_capacity<<endl;
                cout<<"Katanalwsh kausimou:"<<ox->fuel_consumption<<endl;
                cout<<"Taxuthta:"<<ox->velocity<<endl;
                cout<<"Hlikia:"<<ox->age<<endl;
                cout<<"\n"<<endl;
                system("pause");
                return;

           }
          }
        }
    }
}
void city::vlavi()
{
    vehicle *ox;
    system("cls");
    int code;
    cout<<"Oximata :"<<endl;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {

            if(diadromes[i][j]!=NULL)
            {
                 if( (diadromes[i][j]->a!='F') && (diadromes[i][j]->a!='S'))
                   cout<<"Typos Oximatos :"<<diadromes[i][j]->a<<" me monadiko kwdiko: "<<diadromes[i][j]->unique_id<<"kai thesi: ["<<i<<","<<j<<"]"<<endl;


            }
        }
    }
    cout<<"\n\nDwse kwdiko oximatos";
    cin>>code;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
           if(diadromes[i][j]!=NULL)
           {
            if(diadromes[i][j]->unique_id==code)
            {
                ox=dynamic_cast<vehicle*>(diadromes[i][j]);
                ox->situation=true;
                cout<<"Epilexate to oxhma me ta parakatw xarakthristika:"<<endl;
                cout<<"Typos Oximatos: "<<diadromes[i][j]->a<<"\nMe monadiko kwdiko: "<<diadromes[i][j]->unique_id<<"\nThesi: ["<<i<<","<<j<<"]"<<endl;
                cout<<"H katastash einai(0:energo/1:vlavi) :"<<ox->situation<<endl;
                system("pause");
                return;
            }
           }
        }
    }
}

int main()
{
    system("color 80");
    city *c=new city();
    c->enarxi();
    system("pause");

    return 0;
}
