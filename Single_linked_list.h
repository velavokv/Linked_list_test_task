//---------------------------------------------------------------------------
#ifndef Single_linked_listH
#define Single_linked_listH

#include <iostream>
//---------------------------------------------------------------------------
struct link {
  int data;
  link *next;
};
//---------------------------------------------------------------------------

class Single_linked_list {
private:
  link *link_first;
  link *link_end;

public:
  class Exception {
  public:
    char *name_method;
    Exception(char *msg) { name_method = msg; }
  };

  Single_linked_list() {
    link_first = NULL;
    link_end = NULL;
  }
  ~Single_linked_list();
  void set_head(link *link_head);
  link *get_head();
  void append(int data);
  void show();
  link *tail_recursion(link *link_list);
  static void show(link *link_list);
  static link *reverse(link *link_list);

private:
  link *tail_recursion_cycle(link *link_head, link *link_prev);
};

//---------------------------------------------------------------------------
#endif
