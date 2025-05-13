/*-------------------------------------------------------------------------*/
/* FILE : alco_drink.c                                                     */
/*                                                                         */
/* Description : This is the inheritable file for alcoholic drinks, which  */
/*               may or may not be used for healing.                       */
/*               DO NOT COPY THIS FILE!                                    */
/*-------------------------------------------------------------------------*/
/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Mar 14 1997  Kryll        Cleaned up this file. Removed extraneous comments,
                          added full USERDOCs.
Jun 25 1997  Kryll        Removed alt_name and alias and added alias_list.
                          Made query_name, query_drink, query_alco_drink, 
                          and query_food nomask. 
Sep 13 1997  Warlord      Updated file to work with base.c
*/

inherit  "/players/kryll/tmp/base";
#include <obj_defs.h>
#include <lw.h>
#pragma strict_types;

int    food;
int    heal_amount;
int    poison;
int    strength;
status full;
string drinker_mess;
string drinking_mess;
string empty_container;
void set_strength(int val);
void set_heal_amount(int val);
void set_poison(int val);
void set_drinking_mess(string str);
void set_drinker_mess(string str);
void set_empty_container(string str);
void set_food(int val);
nomask int query_food();
nomask int query_drink();
nomask int query_alco_drink();
int query_strength();
int query_heal_amount();
int query_poison();

void reset(int arg) {
  ::reset(arg);
  if(arg != 0) return;

  food = 1;
  full = 1;
  drinker_mess = "Glug Glug Glug.\n";
  empty_container = "bottle";
}

void init() {
  add_action("_drink", "drink");
}

/*
int id(string str) {
  if(full)
    return (member_array(str, alias_list) + 1);
  else
    return str == empty_container;
}

string short() {
  if(full) {
    if(short_desc)
      return short_desc;
    else if(name) 
      return name;
  }
  else {
    if(empty_container) 
      return "An empty " + empty_container;
    else if(name)
      return "An empty " + name;
  }
  return "bottle (empty)";
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

*/
/* USERDOC:
set_strength
Function  : set_strength(i)
Examples  : set_strength(5)
See also  : query_strength

This function sets the strength of the alcoholic drink. This is a value
between 0 and 50. If it's strong, a player needs to have a high con and/or
level to drink it. The value can be 0 to make a non-alcoholic drink,
but it is preferable to use /obj/soft_drink.c for that purpose.
*/
void set_strength(int val) {
  if(strength) return;
  if(val < 0)
    strength = 1;
  else if(val > 50)
    strength = 50;
  else
    strength = val; 
}

/* USERDOC:
set_heal_amount
Function  : set_heal_amount(i)
Examples  : set_heal_amount(5)
See also  : query_heal_amount

This function allows you to set the heal value of the drink. This is
useful when you make a special drink to heal someone or with drinks
which should not heal, but only make you drunk. This function is 
shadowable, but please use that carefully!
*/
void set_heal_amount(int val) {
  if(val/5 > strength)
    strength = val/5;
  heal_amount = val;
}

/* USERDOC:
set_poison
Function  : set_poison(i)
Examples  : set_poison(10)
See also  : qeury_poison

This function allows you to add poison to a drink. The hit of poison
is calculated by the following function: poison/2 * (1+poison) - con.
This function is shadowable, but please do so carefully.
*/
void set_poison(int val) {
  poison = val;
}


/* USERDOC:
set_drinking_mess
Function  : set_drinking_mess(s)
Examples  : set_drinking_mess(" drinks a beer.\n");
See also  : set_drinker_mess

This function sets the string displayed to other people when one drinks the
alcoholic drink. This text is prepended with the name of the drinker, but
a space is needed between the drinker's name and this string and a '.\n' is
needed at the end.
*/
void set_drinking_mess(string str) {
  drinking_mess = str; 
}

/* USERDOC:
set_drinker_mess
Function  : set_drinker_mess(s)
Examples  : set_drinker_mess("You drink a beer.\n");
See also  : set_drinking_mess

This function sets the string displayed to the one drinking the alcoholic
drink. This string should still get a '.\n' at the end.
*/
void set_drinker_mess(string str) { 
  drinker_mess = str; 
}

/* USERDOC:
set_empty_container
Function  : set_empty_container(s)
Examples  : set_empty_container("glass");
See also  :

This function sets the name of the item after someone drinks the contents
of the drink. Once an alcoholic drink is empty, it will self-destruct
after some time.
*/
void set_empty_container(string str) { 
  empty_container = str; 
}

/* USERDOC:
set_food
Function  : set_food(i)
Examples  : set_food(1)
See also  : query_food

This function sets the alcoholic drink to also contain something that is
food (for example: a biscuit). Please use this function with parameter 1
if your item contains something that is food.
*/
void set_food(int val) { 
  food = val; 
}

/* USERDOC:
query_food
Function  : i=query_food()
See also  : set_food

This function returns the value set by set_food(). This means one can check if
there is something that is food in this alcoholic drink, which is the case if
this function returns a number not equal to zero. This function is
nomasked.
*/
nomask int query_food() { 
  if(food)
    return food; 
  return 0;
}

/* USERDOC:
query_drink
Function  : i=query_drink()
See also  : query_alco_drink

This function always returns 1 and identifies this object as a drink.
This function is nomasked.
*/
nomask int query_drink() { 
  return 1; 
}

/* USERDOC:
query_alco_drink
Function  : i=query_alco_drink()
See also  : query_drink

This function always returns 1 and identifies this object as an alcoholic
drink. This function is nomasked.
*/
nomask int query_alco_drink() {
  return 1;
}



/* USERDOC:
query_strength
Function  : i=query_strength()
See also  : set_strength

This function returns the strength of alcohol in the drink. It should
be a number between 0 and 50.
*/
int query_strength() {
  return strength;
}

/* USERDOC:
query_heal_amount
Function  : i=query_heal_amount()
See also  : set_heal_amount

This function returns the amount the drink is set to heal or the strength
of the drink, if the previous was not set. If neither was set, then 0
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

This function returns the amount of poison the drink has been set to or 0
if it is not poisonous.
*/
int query_poison() {
  if(poison)
    return poison;
  return 0;
}

status _drink(string str) {
  int poi;

  if(!str || !id(str))
    return 0;

  if(!full) {
    notify_fail("But " + NAME + " is empty.\n");
    return 0;
  }

/* This just about corresponds to old function */
  if(strength >=  16 * (int)TPL) {
    write("You sputter liquid all over the room.\n");
    say(CAP((string)TPN) + " tries a " + NAME + " but coughs and sputters\n" +
        "all over you.\n");
    full = 0;
    return 1;
  }
  else if(strength > 8 * (int)TPL) {
    write("You try to drink it, but in the end you throw it all up.\n");
    say(CAP((string)TPN) + " tries to drink a " + NAME + " but throws up.\n");
    full = 0;
    return 1;
  }
  if(!call_other(TP, "drink_alco", strength))
    return 1;
  food = 0;
  full = 0;

// these call others are made to make the object shadowable 

  call_other(TP, "heal_self", call_other(TO, "query_heal_amount"));
  if(poi = (int)call_other(TO, "query_poison"))
    call_other(TP, "add_poison", poi);

  write(drinker_mess);
  if(drinking_mess)
    say(CAP((string)TPN) + drinking_mess);
  else
    say(CAP((string)TPN) + " drinks " + short_desc + ".\n");
  return 1;
}

