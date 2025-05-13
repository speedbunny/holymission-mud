/*--------------------------------------------------------------------------*/
/* FILE : soft_drink.c                                                      */
/*                                                                          */
/* Description : This is the inheritable file for soft drinks, which       */
/*               may or may not be used for healing.                       */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs.
Jun 25 1997  Kryll        Removed alt_name and alias and added alias_list.
                          Made query_name, query_drink, query_soft_drink,
                          and query_food nomask.
*/

#include "/obj/obj_defs.h"
#include "/obj/lw.h"
#include "/obj/setlight.h"

#pragma strict_types

int    food;
int    strength;
int    value;
int    weight;
status full;
string drinker_mess;
string drinking_mess; 
string empty_container;
string long_desc;
string name;
string short_desc;
string *alias_list;

/* PROTOTYPES */
void reset(int arg);
void init();
int prevent_insert();
int id(string str);
string short();
void long();
int get();
int dest_bottle();
int min_cost();
void set_name(string str);
void set_short(string str);
void set_long(string str);
void set_value(int val);
void set_weight(int val);
void set_strength(int val);
void set_alias(string str);
void set_alt_name(string str);
void set_drinking_mess(string str);
void set_drinker_mess(string str);
void set_empty_container(string str);
void set_food(int val);
void set_alias_list(string *str);
nomask int query_food();
nomask int query_drink();
nomask int query_soft_drink();
int query_strength();
int query_value();
int query_weight();
nomask string query_name();
string *query_alias_list();

void reset(int arg) {
  if(arg) return;

  full = 1;
  weight = 1;
  food = 1; 
  drinker_mess = "Glug Glug Glug.\n"; 
  empty_container = "bottle";
  alias_list = ({});
}

void init() {
  add_action("_drink", "drink");
}

int prevent_insert() {
  if(empty_container)
    return 0;
  else {
    write("You don't want to ruin " + name + ".\n");
    return 1;
  }
}

int id(string str) {
  if(full)
    return (member_array(str, alias_list) + 1);
  else
    return str == empty_container;
}

string short() { 
  if(full) {
    if(!short_desc)
      return name;
    return short_desc;
  }
  else
    return "An empty " + empty_container;
}

void long() {
  if(full) {
    if(!long_desc)
      writelw(short() + ".\n");
    else
      writelw(long_desc);
  }
  else
    writelw(short() + ".\n");
}

int get() {
  return 1;
}

status _drink(string str) {
  if(!full)
    return 0;
  if(!str || !id(str))
    return 0;
  if((int)TPL * 8 < strength) {
    writelw("This is much to much for you to drink! "+
            "You drool most of it on the ground.\n");
    say(CAP((string)TPN) + " tries to drink " + short_desc +
        " but drools most of it on the ground.\n");
    full = 0;
    food = 0;
    return 1;
  }

  if(!(int)call_other(TP, "drink_soft", strength))
    return 1;

  full = 0;
  TP->heal_self(strength);
  writelw(drinker_mess);
  if(drinking_mess)
    say(CAP((string)TPN) + drinking_mess);
  else
    say(CAP((string)TPN) + " drinks " + short_desc + ".\n");
  call_out("dest_bottle",600);
  return 1;
}

int dest_bottle() {
  object env;

  env = ENV();
  if(!(env && (living(env) || env->id("bag")))) {
    TELLR(env, short() + " crumbles to dust.\n");
    destruct(TO);
    return 1;
  }
  else
    call_out("dest_bottle",600);	/* try again */
  return 1;
}

int min_cost() {
  return 4 * strength + (strength * strength) / 10;
}

/* USERDOC:
set_name
Function  : set_name(s)
Examples  : set_name("cidar")
See also  : query_name

This function sets the name of the drink.
*/
void set_name(string str) { 
  name = str;
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_short 
Function  : set_short(s)
Examples  : set_short("A bottle of cidar")
See also  :
 
This function sets the short of the object. 
*/
void set_short(string str) { 
  short_desc = str;
}

/* USERDOC:
set_long 
Function  : set_long(s)
Examples  : set_long("A tall bottle of cold cidar.\n")
See also  :
 
This function sets the long of the object. 
*/
void set_long(string str) { 
  long_desc = str;
}

/* USERDOC:
set_value 
Function  : set_value(i)
Examples  : set_value(50)
See also  : query_value
 
This function sets the gold value of the drink when it is full. 
*/
void set_value(int val) { 
  value = val; 
}

/* USERDOC:
set_weight 
Function  : set_weight(i)
Examples  : set_weight(2)
See also  : query_weight
 
This function sets the weight of the drink. 
*/
void set_weight(int val) { 
  weight = val; 
}

/* USERDOC:
set_strength 
Function  : set_strength(i)
Examples  : set_strength(5)
See also  : query_strength
 
This function sets the strength of the drink. It should be in a range
from 0 to 25. 
*/
void set_strength(int val) {
  if(val < 0)
    strength = 0;
  else if(val > 25)
    strength = 25;
  else
    strength = val; 
}

/* USERDOC:
set_alias 
Function  : set_alias(s)
Examples  : set_alias("apple juice")
See also  : query_alias_list
 
This function sets the alias of the drink. This function is obsolete
with the addition of set_alias_list. Do not use.
*/
void set_alias(string str) { 
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alt_name 
Function  : set_alt_name(s)
Examples  : set_alt_name("juice")
See also  : query_alias_list
 
This function sets the alt_name of the drink. This function is obsolete
with the addition of set_alias_list. Do not use.
*/
void set_alt_name(string str) { 
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alias_list
Function  : set_alias_list(*s)
Examples  : set_alias_list(({"juice","apple juice","fruit juice"}))
See also  : query_alias_list

This function sets all the possible alternative ids of the soft
drink besides what was set in set_name.
*/
void set_alias_list(string *str) {
  alias_list += str;
}

/* USERDOC:
set_drinking_mess 
Function  : set_drinking_mess(s)
Examples  : set_drinking_mess(" drinks the soda down.\n")
See also  : set_drinker_mess
 
This function sets the message the other people in the room receive
when the drinker drinks. The string must start with an empty space and
end in a '\n'. 
*/
void set_drinking_mess(string str) { 
  drinking_mess = str; 
}

/* USERDOC:
set_drinker_mess 
Function  : set_drinker_mess(s)
Examples  : set_drinker_mess("You hastily drink the soda down.\n")
See also  : set_drinking_mess
 
This function sets the message the drinker receives after he drinks.
It needs to end in a '\n'. 
*/
void set_drinker_mess(string str) { 
  drinker_mess = str; 
}

/* USERDOC:
set_empty_container 
Function  : set_empty_container(s)
Examples  : set_empty_container("jar")
See also  :
 
This function allows you to set what the container looks like after
it has been emptied of its drink. The default is "bottle". 
*/
void set_empty_container(string str) {
  empty_container = str;
}

/* USERDOC:
set_food 
Function  : set_food(i)
Examples  : set_food(1)
See also  : query_food
 
This function allows the drink to be set to contain food also. A 0 
indicates no food. 
*/
void set_food(int val) {
  food = val;
}

/* USERDOC:
query_food 
Function  : i=query_food()
See also  : set_food
 
This function returns whether this drink has food in it also. 
This function is nomasked.
*/
nomask int query_food() {
  return food;
}

/* USERDOC:
query_strength 
Function  : i=query_strength()
See also  : set_strength
 
This function returns the strength of the drink. 
*/
int query_strength() {
  return strength;
}

/* USERDOC:
query_value 
Function  : i=query_value()
See also  : set_value
 
This function returns the gold value of the drink. 
*/
int query_value() { 
  if (full) {
    if (value)
      return value; 
    else
      return min_cost();
  }
  else
    return 10;
}

/* USERDOC:
query_weight 
Function  : i=query_weight()
See also  : set_weight
 
This function returns the weight of the object. 
*/
int query_weight() { 
  return weight; 
}

/* USERDOC:
query_name 
Function  : s=query_name()
See also  : set_name
 
This function returns the name of the drink. This function is nomasked.
*/
nomask string query_name() {
  return full ? name : empty_container;
}

/* USERDOC:
query_drink
Function  : i=query_drink()
See also  : query_soft_drink
 
This function always returns 1 indicating that this is a drink.
This function is nomasked.
*/
nomask int query_drink() {
  return 1;
}
 
/* USERDOC:
query_soft_drink
Function  : i=query_soft_drink()
See also  : query_drink, query_food
 
This function always returns 1, indicating that this is a soft drink.
This function is nomasked.
*/
nomask int query_soft_drink() {
  return 1;
}
 
/* USERDOC:
query_alias_list
Function  : *s=query_alias_list()
See also  : set_alias_list
 
This function returns all the possible ids of the drink, or 0
if there are none. 
*/
string *query_alias_list() {
  return alias_list;
}

