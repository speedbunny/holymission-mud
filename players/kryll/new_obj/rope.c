/*-------------------------------------------------------------------------*/
/* FILE : rope.c                                                           */
/*                                                                         */
/* Description : This is the object file for a rop.                        */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments.
 
*/

#include "/obj/obj_defs.h"
#include "/obj/setlight.h"

#pragma strict_types

object tied_to_ob;
string tied_to;

/* PROTOTYPES */
int id(string str);
void auto_tie(string str, object ob);
int get();
int query_weight();
int query_value();
string query_name();
string short();
void long();
void init();
int tie(string str);
int untie(string str);

int id(string str) {
  return (str=="rope");
}

void auto_tie(string str, object ob) {
  tied_to = str;
  tied_to_ob = ob;
}

int get() {
  if(tied_to) {
    write("The rope is tied to " + tied_to + ".\n");
    return 0;
  }
  return 1;
}

int query_weight() {
  return 1;
}

int query_value() {
  return 15;
}

string query_name() {
  return (tied_to ? "rope tied to " + tied_to : "rope");
}

string short() {
  return (tied_to ? "A rope tied to " + tied_to : "A rope");
}

void long() {
  write("You see nothing special about the rope.\n");
}

void init() {
  add_action("tie", "tie");
  add_action("untie", "untie");
}

int tie(string str) {
  string t1, t2;
  object ob;

  if(!str)
    return 0;
  if(tied_to) {
    write("It is already tied to " + tied_to + ".\n");
    return 1;
  }
  if(sscanf(str, "%s to %s", t1, t2) != 2)
    return 0;
  if(!id(t1))
    return 0;
  if(t2 == "me") {
    write("Why would you do that ?\n");
    return 1;
  }
  ob = present(t2, TP);
  if(!ob)
    ob = present(t2, ENV(TP));
  if(!ob) {
    if(call_other(ENV(TP), "id", t2))
      ob = ENV(TP);
  }
  if(!ob) {
    write("What ?\n");
    return 1;
  }
  if(!ob->tie(t2)) {
    write("You can't tie the rope to " + t2 + ".\n");
    return 1;
  }
  if(ENV() == TP) {
    MOVE(TO, ENV(TP));
    TP->add_weight(-query_weight());
  }
  tied_to = t2;
  tied_to_ob = ob;
  write("Ok.\n");
  say((string)TPN + " ties rope to " + t2 + ".\n");
  return 1;
}

int untie(string str) {
  if(!id(str))
    return 0;
  if(!tied_to) {
    notify_fail("It is not tied to anything.\n");
    return 0;
  }
  if(tied_to_ob->untie()) {
    write("You don't seem to be able to do that.\n");
    return 1;
  }
  write("Ok.\n");
  tied_to = 0;
  tied_to_ob = 0;
  return 1;
}
