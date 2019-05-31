
#include <iostream>
#include "Single_linked_list.h"
using namespace std;

int main(int argc, char *argv[]) {
  try {
    cout << " List commands:" << endl
         << " 's' - show list" << endl
         << " 'r' - reverse and show list" << endl
         << " 't' - tail recursion and show list" << endl
         << " 'n' - delete old and create new list" << endl
         << " 'e' - exit the programm" << endl;

    int i = 1, comand, data;
    char first_char;
    string line_all;
    Single_linked_list link_list;
    do {
      line_all.clear();
      cout << "Set integer data " << i << " link list OR set command" << endl;

      cin >> line_all;
      first_char = line_all.at(0);
      if ((first_char == '-') || ((first_char >= '0') && (first_char <= '9'))) {
        link_list.append(atoi(&line_all.at(0)));
        i++;
        first_char = 'y';
      } else {
        switch (first_char) {
        // yes to continue
        case 'y':
          break;
        // exit this programm
        case 'e':
          return 0;
        // reverse list
        case 'r':
          link_list.set_head(link_list.reverse(link_list.get_head()));
        // show links list
        case 's': {
          link_list.show();
          first_char = 'y';
          break;
        }
        // tail recursion list
        case 't': {
          link_list.set_head(link_list.tail_recursion(link_list.get_head()));
          link_list.show();
          first_char = 'y';
          break;
        }
        // new list (old delete)
        case 'n': {
          link_list.~Single_linked_list();
          i = 1;
          first_char = 'y';
          break;
        }
        default:
          cout << "Enter 'y' to continue .." << endl;
          line_all.clear();
          cin >> line_all;
          first_char = line_all.at(0);
        }
      }

    } while (first_char == 'y');
  } catch (Single_linked_list::Exception exc) {
    cout << "List is empty, cannot be processed medhod " << exc.name_method
         << endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
