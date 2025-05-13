#include "lw.h"

#define TP         this_player()
#define SNAME      short_name()
#define ENV        environment
#define MASTER     "/players/matt/test/soul/mastersoul"

string *cust_adv_list;

int id(string str) {
  return str == "soul" || str == "emotesoul";
}

int get() {
  return 1;
}

void reset(int arg) {
  if(arg) return;
}

void init() {
  int i;
  string *feelings_list;

  add_action("do_emote", "me");
  add_action("do_help", "help");
  feelings_list = MASTER->query_feelings_list();
  for(i = 0; i < sizeof(feelings_list); i++)
    add_action("do_feeling", feelings_list[i]);
  write("Archwizard Matt has recoded your Soul. Type 'help soul' for help.\n");
}

int do_emote(string arg) {
  string msg;

  if(!arg) {
    write("Emote what?\n");
    return 1;
  }
  msg = TP->SNAME + " " + arg + "\n";
  write(lw("You emote: " + msg));
  say(lw(msg));
  return 1;
}

int do_help(string arg) {
  switch(arg) {
  case "soul":
    /* help soul stuff... general */
    return 1;
  case "feelings":
    /* printfs here... see /doc/examples/printf_exa.c */
    return 1;
  case "adverbs":
    /* printfs here... see /doc/examples/printf_exa.c */
    return 1;
  default:
    return 0;
  }
}

void do_feeling(string arg) {
  MASTER->do_feeling(query_verb(), explode(arg, " "));
}

string query_adverb(string adv) {
  int num;

  if((num = member_array(adv, cust_adv_list)) != -1)
    return cust_adv_list[num];
  else
    return "";
}
  
