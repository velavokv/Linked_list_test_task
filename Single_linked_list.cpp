#include "Single_linked_list.h"
using namespace std;
//---------------------------------------------------------------------------
Single_linked_list::~Single_linked_list() {
  link *link_next;
  while (link_first) {
    link_next = link_first->next;
    delete link_first;
    link_first = link_next;
  }
}
//---------------------------------------------------------------------------
void Single_linked_list::set_head(link *link_head) {
  if (link_head) {
    link_first = link_end = link_head;
    while (link_end->next)
      link_end = link_end->next;
  } else {
    throw Exception("set_head");
  }
}
//---------------------------------------------------------------------------
link *Single_linked_list::get_head() { return link_first; }
//---------------------------------------------------------------------------
void Single_linked_list::append(int data) {
  link *link_new = new link;
  link *link_current = link_first;
  link_new->data = data;
  link_new->next = NULL;

  if (link_first) {
    link_current = link_end;
    while (link_current->next)
      link_current = link_current->next;
    link_end = link_current;
    link_end->next = link_new;
  } else
    link_first = link_end = link_new;
  ;
}
//---------------------------------------------------------------------------
void Single_linked_list::show() {
  if (link_first) {
    link *link_current = link_first;
    while (link_current) {
      cout << link_current->data << endl;
      link_current = link_current->next;
    }
    cout << endl;
  } else {
    throw Exception("show this");
  }
}
//---------------------------------------------------------------------------
link *Single_linked_list::tail_recursion(link *link_list) {
  if (link_list) {
    link *link_prev = NULL;
    return tail_recursion_cycle(link_list, link_prev);
  } else {
    throw Exception("tail_recursion");
  }
}

//--
link *Single_linked_list::tail_recursion_cycle(link *link_head,
                                               link *link_prev) {
  if (link_head->next) {
    //
    link *link_next = link_head->next;
    link_head->next = link_prev;
    return tail_recursion_cycle(link_next, link_head);
  } else {
    link_head->next = link_prev;
    return link_head;
  }
}
//---------------------------------------------------------------------------
// static method
void Single_linked_list::show(link *link_list) {
  if (link_list) {
    link *link_current = link_list;
    while (link_current) {
      cout << link_current->data << endl;
      link_current = link_current->next;
    }
    cout << endl;
  } else {
    throw Exception("show static");
  }
}
//---------------------------------------------------------------------------
// static method
link *Single_linked_list::reverse(link *link_list) {
  if (link_list) {
    link *link_current = link_list;
    link *link_next = link_list->next;
    link *link_prev = NULL;

    link_list->next = NULL;
    while (link_next) {
      link_prev = link_current;
      link_current = link_next;
      link_next = link_current->next;
      link_current->next = link_prev;
    }
    link_current->next = link_prev;
    return link_current;
  } else {
    throw Exception("reverse");
  }
}
//---------------------------------------------------------------------------
