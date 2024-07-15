
#include <iostream>
#include <cstring>
using namespace std;
 
int Tablesize = 10;
struct HashTable
{
 char Key[10]; 
 int Val; 
} HT1[10], HT2[10];
void init ()
{
 int i;
 for (i = 0; i < Tablesize; i++)
 {
 strcpy (HT1[i].Key, ".....");
 HT1[i].Val = 0;
 }
 for (i = 0; i < Tablesize; i++)
 {
 strcpy (HT2[i].Key, ".....");
 HT2[i].Val = 0;
 }
}

int HashFun (char key[])
 int i, index, sum = 0;
 for (i = 0; key[i] != '\0'; i++)
 {
 sum = sum + key[i];
 }
 index = sum % Tablesize;
}
 
void insert_HT1 (char Cname[], int Tele)
{
 int i, id, index;
 index = HashFun (Cname);
 if (strcmp (HT1[index].Key, ".....") == 0) 
 {
 strcpy (HT1[index].Key, Cname);
 HT1[index].Val = Tele;
 }
 else 
 {
 while (strcmp (HT1[index].Key, ".....") != 0)
{
 index = (index + 1) % Tablesize;
}
 strcpy (HT1[index].Key, Cname);
 HT1[index].Val = Tele;
 }
}

void insert_HT2 (char Cname[], int Tele) 
{
 int i, index;
 index = HashFun (Cname);
 if (strcmp (HT2[index].Key, ".....") == 0) 
 {
 strcpy (HT2[index].Key, Cname);
 HT2[index].Val = Tele;
 }
 else 
 {
 i = 1;
 int id = index;
 while (strcmp (HT2[id].Key, ".....") != 0)
{
 id = (index + i * i) % Tablesize;
 i++;
}
 strcpy (HT2[id].Key, Cname);
 HT2[id].Val = Tele;
 }
}
 
void display ()
{
 int i;
 cout << "\n\n------ Hash Table 01 ------ ";
 cout << "\n\n Bucket (Key , Value)";
 for (i = 0; i < Tablesize; i++)
 {
 cout << "\n " << i << " - (" << HT1[i].Key << " , " << HT1[i].
Val << ")";
 }
 cout << "\n\n------ Hash Table 02 ------ ";
 cout << "\n\n Bucket (Key , Value)";
 for (i = 0; i < Tablesize; i++)
 {
 cout << "\n " << i << " - (" << HT2[i].Key << " , " << HT2[i].
Val << ")";
 }
}

void search_HT1 (char Cname[])
{
 int index = HashFun (Cname);
 int cnt = 1;
 int id = index;

 if (strcmp (HT1[id].Key, Cname) == 0)
 {
 cout<<"\n\t"<<HT1[id].Key<<" : "<<HT1[id].Val<<" : "<<cnt;
 }
 else
 {
 int i = 1;
 while (strcmp (HT1[id].Key, Cname) != 0)
{
 id = (index + i) % Tablesize;
 i++; 
 cnt++;
}

 cout<<"\n\t"<< HT1[id].Key<<" : "<<HT1[id].Val<<" : "<<cnt;
 }
}
 
void search_HT2 (char Cname[])
{
 int index = HashFun (Cname);
 int cnt = 1;
 int id = index;
 if (strcmp (HT2[id].Key, Cname) == 0)
 {
 cout<<"\n\t"<< HT2[id].Key<<" : "<<HT2[id].Val<<" : "<<cnt;
 }
 else 
 {
 int i = 1;
 while (strcmp (HT2[id].Key, Cname) != 0)
{
 id = (index + i * i) % Tablesize;
 i++; 
 cnt++; 
}
 cout<<"\n\t"<< HT2[id].Key<<" : "<<HT2[id].Val<<" : "<<cnt;
 }
}

int main ()
{
 cout << "\n ----A C++ Program to implement Hash Table Data Structure----";
 init();
 //......INSERT In Hash Table - 01
 insert_HT1 ("Amol", 915033);
 insert_HT1 ("Amit", 925033);
 insert_HT1 ("Ajay", 935033);
 insert_HT1 ("Sanjay", 945033);
 insert_HT1 ("Sanika", 955033);
 insert_HT1 ("Seeta", 965033);
 insert_HT1 ("Gita", 975033);
 insert_HT1 ("Babita", 985033);

//......INSERT In Hash Table - 02
 insert_HT2 ("Amol", 915033);
 insert_HT2 ("Amit", 925033);
 insert_HT2 ("Ajay", 935033);
 insert_HT2 ("Sanjay", 945033);
 insert_HT2 ("Sanika", 955033);
 insert_HT2 ("Seeta", 965033);
 insert_HT2 ("Gita", 975033);
 insert_HT2 ("Babita", 985033);
 display ();
//......SEARCH In Hash Table – 01
 cout<<"\n\n ----- Search in Hash Table-01 -----";

 cout<<"\n\t Client : Telephone : comparisons";
 search_HT1 ("Seeta");
 search_HT1 ("Sanika");
 search_HT1 ("Babita");
//......SEARCH In Hash Table – 02
 cout<<"\n\n ----- Search in Hash Table-02 -----";

 cout<<"\n\t Client : Telephone : comparisons";
 search_HT2 ("Seeta");
 search_HT2 ("Sanika");
 search_HT2 ("Babita");
 return 0;
}
/*-------------------OUTPUT--------------------
----A C++ Program to implement Hash Table Data Structure----
------ Hash Table 01 ------
 Bucket (Key , Value)
 0 - (Sanika , 955033)
 1 - (Gita , 975033)
 2 - (Babita , 985033)
 3 - (Amol , 915033)
 4 - (Sanjay , 945033)
 5 - (Amit , 925033)
 6 - (..... , 0)
 7 - (Gita , 975033)
 8 - (Seeta , 965033)
 9 - (Ajay , 935033)
------ Hash Table 02 ------
 Bucket (Key , Value)
 0 - (Sanika , 955033)
 1 - (..... , 0)
 2 - (Babita , 985033)
 3 - (Amol , 915033)
 4 - (Sanjay , 945033)
 5 - (Amit , 925033)
 6 - (..... , 0)
 7 - (..... , 0)
 8 - (Seeta , 965033)
 9 - (Ajay , 935033)
----- Search in Hash Table-01 -----
 Client : Telephone : comparisons
 Seeta : 965033 : 1
 Sanika : 955033 : 2
 Babita : 985033 : 4
----- Search in Hash Table-02 -----
 Client : Telephone : comparisons
 Seeta : 965033 : 1
 Sanika : 955033 : 2
 Babita : 985033 : 46344
