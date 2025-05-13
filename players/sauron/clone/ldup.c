#include "/players/sauron/include/include.h"

int id(string str);
int _get();
int _activate(string str);
int do_cmd(string str);
string query_auto_load();
int get();
int drop(string str);
string query_name();
nomask string short();
void long();
int query_weight();
int query_value();
void reset(int arg);
void init();

string root;
object owner;

int id(string str) {
  return str=="ldup" || str=="ldup tool";
}

int _get() {
  printf("Oiy! Hands off! That isn't yours to %s.\n",query_verb());
  if(owner)
    tell_object(owner,
                sprintf("%s just tried to %s something from your inventory.\n",
                        (string)this_player()->query_real_name(1),
                        query_verb()));
  return 1;
}

int _activate(string str) {
  if(!str || !id(str)) {
    notify_fail("Activate what?\n");
    return 0;
  }
  move_object(this_object(),environment());
  write("Ldup activated.\n");
  return 1;
}

int do_cmd(string str) {
  if(query_verb()==".")
    return 0;
  if(file_size(root+query_verb()+".c")>0)
    return (int)call_other(root+query_verb(),"_"+query_verb(),str);
  else
    return 0;
}

string query_auto_load() {
  return CLONE+"ldup:";
}

int get() {
  return 1;
}

int drop(string str) {
  if(query_verb()!="quit")
    write("You want someone else to get your Ldup tool?\n");
  return 1;
}

string query_name() {
  return "ldup";
}

nomask string short() {
  if(owner && this_player() && (owner!=this_player()))
    tell_object(owner,sprintf("*** %s checked your inventory ***\n",
                              (string)this_player()->query_real_name(1)));
  return "A Ldup tool";
}

void long() {
  write("A Ldup tool.\n");
}

int query_weight() {
  if((string)this_player()->query_real_name()!="sauron" &&
     (string)this_player()->query_real_name()!="dave")
    return 1000;
  else
    return 0;
}

int query_value() {
  return 0;
}

void reset(int arg) {
  if(!arg) {
    root="/players/sauron/clone/ldup_cmds/_";
  }
}

void init() {
  if(owner && environment(this_object())!=owner) {
    tell_object(owner,
                sprintf("*** %s moved your ldup tool to %O ***\n",
                        (string)this_player()->query_real_name(1),
                        environment()));
    return;
  }
  else if(owner && environment()==environment(this_player())) {
    tell_object(owner,sprintf("*** %s entered your inventory ***\n",
                              (string)this_player()->query_real_name(1)));
    add_action("_get","get");
    add_action("_get","take");
    return;
  }
  else if((string)this_player()->query_real_name()!="sauron" &&
          (string)this_player()->query_real_name()!="dave")
    return;
  else {
    if(!owner)
      owner=this_player();
    add_action("_activate","activate");
    add_action("do_cmd","",1);
  }
}
