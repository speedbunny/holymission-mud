/*-------------------------------------------------------------------------*/
/* FILE : food.c                                                           */
/*                                                                         */
/* Description : This is the inheritable file for food items, which may    */
/*               heal or be poison.                                        */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs.
Jun 25 1997  Kryll        Removed alt_name and alias and added alias_list.
                          Made query_name and query_food nomask so they are
                          definite returns.
*/

#include "/obj/obj_defs.h"
#include "/obj/lw.h"
#include "/obj/setlight.h"

#pragma strict_types

int    heal_amount;
int    poison;
int    strength;
int    value;
int    weight;
string eating_mess;
string eater_mess;
string long;
string name;
string short;
string *alias_list;

/* PROTOTYPES */
void set_name(string str);
void set_short(string str);
void set_long(string str);
void set_value(int val);
void set_weight(int val);
void set_strength(int val);
void set_heal_amount(int val);
void set_poison(int val);
void set_alias(string str);
void set_alt_name(string str);
void set_eating_mess(string str);
void set_eater_mess(string str);
nomask int query_food();
int query_value();
int query_weight();
nomask string query_name();
string *query_alias_list();
int query_strength();
int query_heal_amount();
int query_poison();

void reset(int arg) {
  if(arg != 0) return;

  weight = 1; 
  strength = 0;
  eater_mess = "Yum yum yum.\n"; 
  alias_list = ({});
}

void init() {
  add_action("_eat", "eat");
}

int id(string str) { 
  return (member_array(str, alias_list) + 1);
}

string short() { 
  if(!short && !name)
    return "food";
  else if(!short) 
    return name;
  return short;
}

void long() {
  if(!long)
    writelw(short() + ".\n");
  else
    writelw(long);
}

int get(string str) { 
  return 1; 
}

/* USERDOC:
set_name
Function  : set_name(s)
Examples  : set_name("cheese");
See also  : query_name
 
This function sets the name of the food.
*/
void set_name(string str) { 
  name = str; 
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_short
Function  : set_short(s)
Examples  : set_short("A piece of cheese")
See also  : set_long
 
This function sets the short of the food.
*/
void set_short(string str) { 
  short = str; 
}

/* USERDOC:
set_long
Function  : set_long(s)
Examples  : set_long("A moldy piece of cheese.\n");
See also  : set_short
 
This function sets the long of the food.
*/
void set_long(string str) { 
  long = str; 
}

/* USERDOC:
set_value
Function  : set_value(i)
Examples  : set_value(20)
See also  : query_value
 
This function sets the value of the food in gold.
*/
void set_value(int val) { 
  value = val; 
}

/* USERDOC:
set_weight
Function  : set_weight(i)
Examples  : set_weight(1)
See also  : query_weight
 
This function sets the weight of the food.
*/
void set_weight(int val) { 
  weight = val; 
}

/* USERDOC:
set_strength
Function  : set_strength(i)
Examples  : set_strength(5)
See also  : query_strength

This function sets the strength of the food. This is a value between 0 and 50.
High strengths indicate much healing, but also that low level characters can't
eat the food.
*/
void set_strength(int val) { 
  if(strength) return;
  if(val < 0)
    strength = 0;
  else if(val > 50)
    strength = 50;
  else
    strength = val; 
}

/* USERDOC:
set_heal_amount
Function  : set_heal_amount(i)
Examples  : set_heal_amount(5)
See also  : set_strength

This function sets how much the food will heal. Do not make it too strong
because the strength of the food can be no less than 1/5 of the healing
amount.
*/
void set_heal_amount(int val) {
  heal_amount = val;
  if(strength < val/5)
    strength = val/5;
}

/* USERDOC:
set_poison
Function  : set_poison(i)
Examples  : set_poison(10)
See also  : qeury_poison
 
This function allows you to add poison to a food. The hit of poison
is calculated by the following function: poison/2 * (1+poison) - con.
This function is shadowable, but please do so carefully.
*/
void set_poison(int val) {
  poison = val;
}

/* USERDOC:
set_alias
Function  : set_alias(s)
Examples  : set_alias("cheese")
See also  : query_alias_list
 
This function sets the alias of the food. This function is now obsolete
with the addition of set_alias_list. Do not use.
*/
void set_alias(string str) { 
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alt_name
Function  : set_alt_name(s)
Examples  : set_alt_name("cheddar")
See also  : query_alias_list
 
This function sets the alt_name of the food. This function is now obsolete
with the addition of set_alias_list. Do not use.
*/
void set_alt_name(string str) { 
  if(member_array(str, alias_list) == -1)
    alias_list += ({ str });
}

/* USERDOC:
set_alias_list
Function  : set_alias_list(*s)
Examples  : set_alias_list(({"cheddar","white cheddar","cheese"}))
See also  : query_alias_list

This function sets all the alternative ids for the food, besides 
what was set in set_name.
*/
void set_alias_list(string *str) {
  alias_list += str;
}

/* USERDOC:
set_eating_mess
Function  : set_eating_mess(s)
Examples  : set_eating_mess(" is enjoying a piece of cheese.\n");
See also  : set_eater_mess

This function sets the string displayed to other players in the room,
prepended by the eater's name. Notice the leading space and the terminating
\n in this string.
*/
void set_eating_mess(string str) { 
  eating_mess = str; 
}

/* USERDOC:
set_eater_mess
Function  : set_eater_mess(s)
Examples  : set_eater_mess("It tastes delicious.\n");
See also  : set_eating_mess

This function sets the string written to the screen of the eater. This string
should end with a \n.
*/
void set_eater_mess(string str) { 
  eater_mess = str; 
}

/* USERDOC:
query_food
Function  : i=query_food()

This function always returns 1 to indicate this object as food.
This function is nomasked.
*/
nomask int query_food() { 
  return 1;
}

/* USERDOC:
query_value
Function  : i=query_value()
See also  : set_value
 
This function returns the gold value of the food.
*/
int query_value() { 
  if(value)
    return value; 
  else if(strength)
    return (strength * 5);
  return 10;
}

/* USERDOC:
query_weight
Function  : i=query_weight()
See also  : set_weight
 
This function returns the weight of the food.
*/
int query_weight() { 
  if(weight)
    return weight; 
  return 0;
}

/* USERDOC:
query_name
Function  : s=query_name()
See also  : set_name
 
This function returns the name of the food. This function is nomasked.
*/
nomask string query_name() { 
  if(stringp(name))
    return name; 
  return "food";
}

/* USERDOC:
query_alias_list
Function  : *s=query_alias_list()
See also  : set_alias_list
 
This function returns all the possible ids of the food, or 0 if
there are none.
*/
string *query_alias_list() {
  if(sizeof(alias_list))
    return alias_list;
  return 0;
}

/* USERDOC:
query_strength
Function  : i=query_strength()
See also  : set_strength
 
This function returns the strength of the food . It should
be a number between 0 and 50.
*/
int query_strength() {
  if(strength)
    return strength;
  return 1;
}

/* USERDOC:
query_heal_amount
Function  : i=query_heal_amount()
See also  : set_heal_amount
 
This function returns the amount the food is set to heal or the strength
of the food, if the previous was not set. If neither was set, then 0
is returned.
*/
int query_heal_amount() {
  if(heal_amount)
    return heal_amount;
  else if(strength)
    return strength;
  return 0;
}

/* USERDOC:
query_poison
Function  : i=query_poison()
See also  : set_poison
 
This function returns the amount of poison the food has been set to or 0
if it is not poisonous.
*/
int query_poison() {
  if(poison)
    return poison;
  return 0;
}

status _eat(string str) {
  int poi;

  if(!str || !id(str))
    return 0;

  if((int)(TPL)*8 < strength) {
    write("You realize that you are unable to eat all this.\n");
    return 1;
  }
  if(!call_other(TP, "eat_food", strength))
    return 1;

// to shadow this function if necessary : cookingskill
  call_other(TP, "heal_self", call_other(TO, "query_heal_amount"));

  if(poi = (int)call_other(TO, "query_poison"))
    call_other(TP, "add_poison", poi);

  write(eater_mess);
  if(eating_mess)
    say(CAP((string)TPN) + eating_mess);
  else
    say(CAP((string)TPN) + " eats " + short + ".\n");
  destruct(TO);
  return 1;
}

