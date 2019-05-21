#include <iostream>
#include <QTextStream>

using namespace std;

struct lists
{
    int data;
    lists *next;
};

lists* func_turn_back(lists* head);
lists* initl(int data);
void append(lists *lst,int data);
void delet(lists *lst);
void show(lists *lst);

int main()
{
    QTextStream qtin(stdin);
    QTextStream qtout(stdout);
    QString App, Yes_No;
    bool *ok=NULL;

    // INIT
    lists *lst = initl(0);
    do
    {
        qtout << endl;
        Yes_No.clear();

        int i=0;
        qtout << "enter 's' - to show result"<< endl;

        while(1)
        {

            App.clear();
            qtout << "Input int data " << i << " element list" << endl;
            qtin >> App;

            if(App.at(0) == 's') break;
            if(i==0) lst->data = App.toInt(ok);
            else     append(lst,App.toInt(ok));
            i++;

        }

        qtout << "Linked list input: "<< endl;
        show(lst);

        lst = func_turn_back(lst);

        qtout << "Linked list output: "<< endl;
        show(lst);

        delet(lst);

        qtout << "Continue? (y/n): " << endl;
        qtin >> Yes_No;

    }while(Yes_No.at(0) == 'y');

    return 0;
}


lists* func_turn_back(lists* head)
{
    //  Функция принимает указатель на односвязный список
    // и поворачивает указатели обратно, т.е. последний узел
    // списка станет главным

    lists* temp      = head;
    lists* temp_next = head->next;
    lists* temp_prev = NULL;

    head->next = NULL;
    while(temp_next)
    {
        temp_prev = temp;
        temp = temp_next;
        temp_next = temp->next;
        temp->next = temp_prev;
    }
    temp->next = temp_prev;
    return temp;
}

lists* initl(int data)
{
    lists *temp = new lists;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void append(lists *lst,int data)
{
    lists *temp = new lists;
    lists *p    = lst;
    do
    {
        if(p->next == NULL) break;
        p = p->next;
    }while(p);

    p->next    = temp;
    temp->data = data;
    temp->next = NULL;
}

void delet(lists *lst)
{
    lists *temp;
    while(lst)
    {
        temp = lst->next;
        delete lst;
        lst = temp;
    }
}

void show(lists *lst)
{
    lists *temp = lst;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    }while(temp);
}
