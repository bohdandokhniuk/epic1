/*"Автономність портативної станції", Дохнюк Богдан , cші-14*/
#include <iostream>
using namespace std ;

string model,name;
double eff,P;
unsigned short C,years,charge; 

void Exit ()
{
cout<<"Помилка вводу.Введіть коректне значення!";
exit(1);
}

//введення та перевірка даних
int main() {
cout<<"Модель станції : ";
cin>>model; 
if(model.length()>31)Exit();

cout<<"Паспортна ємність, Вт·год : ";
cin>>C;
if(C<=0)Exit();

cout<<"Вік станції, років : ";
cin>>years;
if(years<0||years>20)Exit();

cout<<"Рівень заряду, % : ";
cin>>charge;
if(charge<0||charge>100)Exit();

cout<<"ККД інвертора, % : ";
cin>>eff;
if(eff<=0||eff>100)Exit();

cout<<"Потужність приладу, Вт : ";
cin>>P;
if(P<=0)Exit();

//розрахунки над даними)
//Фактична ємність з урахуванням віку, Вт·год
//Піднесення до степеня
double C_eff =(1-2.0/100.0);
double temp = C_eff;
for(int i=1;i<years;i++)
{
C_eff*=temp;
}

C_eff*=C;

//Запас енергії при поточному заряді, Вт·год
double E_stored = C_eff * charge/ 100;
//Корисна енергія, що дійде до приладу, Вт·год
double E_useful = E_stored * eff / 100;
//Втрати на перетворенні напруги, Вт·год
double E_loss = E_stored - E_useful;
//Час роботи, годин
double T=E_useful / P;
//Повні години
int h = T;
//Хвилини, що залишились
int m=((T - h) * 60);

//заокруглення
T=double(int(T*100))/100;
C_eff=double(int(C_eff*10))/10;
E_stored=double(int(E_stored*10))/10;
E_useful=double(int(E_useful*10))/10;
E_loss=double(int(E_loss*10))/10;

cout<<"Модель станції : "<<model<<endl;
cout<<"Паспортна ємність, : "<<C<<" Вт·год"<<endl;
cout<<"Вік станції : "<<years<<" р."<<endl;
cout<<"Фактична ємність : "<<C_eff<<" Вт·год"<<endl;
cout<<"Рівень заряду, % : "<<charge<<" %"<<endl;
cout<<"ККД інвертора, % : "<<eff<<" %"<<endl;
cout<<"Запас енергії при поточному заряді : "<<E_stored<<" Вт·год"<<endl;
cout<<"Корисна енергія, що дійде до приладу : "<<E_useful<<" Вт·год"<<endl;
cout<<"Втрати на перетворенні : "<<E_loss<<" Вт·год"<<endl;
cout<<"Час роботи,годин : "<<T<<" год "<<" = "<<h<<" год "<<m<<" хв"<<endl;

    return 0;
}