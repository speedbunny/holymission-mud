/*-------------------------------------------------------------------------*/
/* FILE : corpse.c                                                         */
/*                                                                         */
/* Description : This is the inheritable file for corpses.                 */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs.
 
*/

/* USERDOC:
general
This is a decaying corpse. It's created automatically when a player or a
monster dies. Generally defined functions:
set_name, query_weight, set_weight, query_name, query_real_name.
*/

#include "/obj/obj_defs.h"
#include "/obj/lw.h"

#pragma strict_types

#define DECAY_TIME        30

int    decay;
int    weight;
string *decay_name;
string name;
string race;

/* PROTOTYPES */
int prevent_insert();
void init();
void reset(int arg);
int set_name(string str);
nomask string query_real_name();
string short();
void long();
int id(string str);
void decay();
int can_put_and_get();
int search_obj(object cont);
int search(string str);
int drop();
int get();
int query_weight();
void set_weight(int val);
string query_name();
void set_race(string str);
string query_race();
string query_plural();
int query_show_short();

int prevent_insert() {
  write("The corpse is too big.\n");
  return 1;
}

void init() {
  add_action("search", "search");
}

void reset(int arg) {
  if(arg) return;

  name = "corpse";
  race = "corpse";
  decay = 4;
  decay_name=({
               "The skeleton",
               "The nearly decomposed remains",
               "The somewhat decayed remains",
               "Corpse",
             });
  return;
}

/* USERDOC:
set_name
Function  : i=set_name(s)
Examples  : i=set_name("goblin");
See also  : query_real_name
 
This function sets the name of the corpse, and returns 1.
*/
int set_name(string str) {
  name = str;
  call_out("decay", DECAY_TIME);
  return 1;
}

/* USERDOC:
query_real_name
Function  : s=query_real_name()
See also  : set_name

This function returns the real name of the corpse.
*/
nomask string query_real_name() {
  return name;
}

string short() {
  string dname;

  if(stringp(decay_name[decay-1]))
    return decay_name[decay-1] + " of " + CAP(name);
  return decay_name[0] + " of " + CAP(name);
}

void long() {
  writelw("The dead body of "+CAP(name)+".\n");
}

int id(string str) {
  return (str=="corpse" || str=="corpse of "+name || str=="remains" || 
          str=="skeleton");
}

void decay() {
  decay -= 1;
  if (decay > 0) {
    call_out("decay", 5);
    return;
  }
  destruct(TO);
}

int can_put_and_get() {
  return 1;
}

int search_obj(object cont) {
  object ob;
  int total;

  if(!cont->can_put_and_get())
    return 0;
  ob = first_inventory(cont);
  while(ob) {
    total += 1;
    write(ob->short() + ", ");
    ob = next_inventory(ob);
  }
  return total;
}

int search(string str) {
  object ob;

  if(!str || !id(str))
    return 0;
  ob = present(str, ENV(TP));
  if(!ob)
    ob = present(str, TP);
  if(!ob)
    return 0;
  write("You search " + str + ", and find:\n");
  say(TPN + " searches " + str + ".\n");
  if(!search_obj(ob))
    write("\tNothing.\n");
  else
    write("\n");
  return 1;
}

int drop() {
  call_out("decay",5);
  return 0;
}

int get() {
  if(find_call_out("decay") && TP->query_player()) {
    remove_call_out("decay");
    call_out("decay",180);
  }
  return 1;
}

/* USERDOC:
query_weight
Function  : i=query_weight()
See also  : set_weight
 
This function returns the weight of the corpse.
*/
int query_weight() {
  return weight;
}

/* USERDOC:
set_weight
Function  : set_weight(i)
Examples  : set_weight(5)
See also  : query_weight
 
This function sets the weight of the corpse.
*/
void set_weight(int val) { 
  weight = (val<0 ? 0 : val); 
}

/* USERDOC:
query_name
Function  : s=query_name()
See also  : set_name
 
This function returns the name of the corpse.
*/
string query_name() {
#if 0
  return lower_case(name);
#else
  return lower_case(short());
#endif
}

/* USERDOC:
set_race
Function  : set_race(s)
Examples  : set_race("orc")
See also  : query_race

This function sets the race of the corpse. It's also set if a player or a
monster dies. Very interesting for various purposes, especially the query_race
function.
*/
void set_race(string str) {
  race = str;
}

/* USERDOC:
query_race
Function  : s=query_race()
See also  : set_race

This function returns the race of a corpse. A very interesting function that
is unfortunately not used on many places.
*/
string query_race() {
 return race;
}

/* USERDOC:
query_plural
Function  : s=query_plural()

This function returns the plural of corpses.
*/
string query_plural() {
  return sprintf("corpses of %ss", name);
}

/* USERDOC:
query_show_short
Function  : i=query_show_short()

This function always returns 1.
*/
int query_show_short() {
  return 1;
}

