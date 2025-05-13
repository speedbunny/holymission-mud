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
Sep 13 1997  Warlord	  Clean up file to get tested with new base.c
*/

inherit "/players/kryll/tmp/base";
#include <lw.h>
#include <obj_defs.h>


#pragma strict_types

int    heal_amount;
int    poison;
int    strength;
string eater_mess;
string eating_mess;

/* PROTOTYPES */
void   set_strength(int val);
void   set_heal_amount(int val);
void   set_poison(int val);
void   set_eating_mess(string str);
void   set_eater_mess(string str);
nomask int query_food();
int    query_strength();
int    query_heal_amount();
int    query_poison();

void reset(int arg) {
::reset(arg);
  if(arg != 0) return;

  strength = 0;
  eater_mess = "Yum yum yum.\n";
}

void init() {
  add_action("_eat", "eat");
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
    say(CAP((string)TPN) + " eats " + short_desc + ".\n");
  destruct(TO);
  return 1;
}

