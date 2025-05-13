/* CORPSE.C - This is a clone file - DO NOT COPY! */
/* 220792: Bonzo: set_race, query_race added. */
/* 120992: Moonchild: set_weight, query_weight added. */
/* 070693: Ethereal Cashimor: USERDOC added. */
/* 201094: Ethereal Cashimor: Tried to fix the problem with Goblin quest */

/* USERDOC:
general
This is a decaying corpse. It's created automatically when a player or a
monster dies. Generally defined functions:
set_name, query_weight, set_weight, query_name, query_real_name.
*/

#include "setlight.h"   // Why does a corpse have light?!?!

#define DECAY_TIME        30

string      name, *decay_name;
string      race;            /* Added by Bonzo */
int         decay,weight;

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

int set_name(string n) {
  name = n;
  call_out("decay", DECAY_TIME);
  return 1;
}

string query_real_name() {
  return name;
}

string short() {

  string dname;

  if (stringp(decay_name[decay-1]))
    return decay_name[decay-1] + " of " + capitalize(name);
  return decay_name[0] + " of " + capitalize(name);
}

void long() {
  write("The dead body of "+capitalize(name)+".\n");
  return;
}

int id(string str) {
  return str == "corpse" || str == "corpse of " + name
                         || str == "remains"
                         || str == "skeleton";
}

void decay() {

  decay -= 1;
  if (decay > 0) {
    call_out("decay", 5);
    return;
  }
  destruct(this_object());
  return;
}

int can_put_and_get() {
  return 1;
}

int search_obj(object cont) {

  object ob;
  int total;

  if (!cont->can_put_and_get())
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

  if (!str || !id(str))
    return 0;
  ob = present(str, environment(this_player()));
  if (!ob)
    ob = present(str, this_player());
  if (!ob)
    return 0;
  write("You search " + str + ", and find:\n");
  say(this_player()->query_name() + " searches " + str + ".\n");
  if (!search_obj(ob))
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
  if(find_call_out("decay") && this_player()->query_player()) {
    remove_call_out("decay");
    call_out("decay",180);
  }
  return 1;
}

int query_weight() {
  return weight;
}

void set_weight(int w) { 
  weight = (w<0 ? 0 : w); 
  return;
}

string query_name() {
  return lower_case(short());
}

/* USERDOC:
set_race
Format: set_race(s)
Example: set_race("orc")
See also: query_race.
This function sets the race of the corpse. It's also set if a player or a
monster dies. Very interesting for various purposes, especially the query_race
function.
*/
void set_race(string str) {
  race = str;
  return;
}

/* USERDOC:
query_race
Format: s=query_race()
See also: set_race.
This function returns the race of a corpse. A very interesting function that
is unfortunately not used on many places.
*/
string query_race() {
 return race;
}

string query_plural() {
  return sprintf("corpses of %ss", name);
}

int query_show_short() {
  return 1;
}

int query_decayed() {
    return decay;
}
