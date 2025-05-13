
#include "setlight.h"

/* USERDOC:
general
This file can be used to make alcoholic drinks with a certain strength.
Alcoholic drinks are the fastest healers in a MUD, except for pure magical
healing, which should be rather sporadic.
This object is a standard alco_drink object and works like /obj/food.c or 
/obj/armour.c. To use this you can do:
inherit "obj/alco_drink";
...
or,
object ob;
ob = clone_object("obj/alco_drink");
ob->set_name("Apple Cider");
...
For more documentation look at /doc/build/drinks. Generally defined functions:
set_name, set_short, set_long, set_alias, set_value, set_weight, query_name,
set_alt_name, query_value, query_weight.
For an example of the use of this object, please read:
/doc/examples/apple_cider.c
*/

// prototyping
string query_name();

string name,short_desc,long_desc,drinking_mess,drinker_mess,alias,alt_name;
string empty_container;
int value,strength,weight,full,food, heal_amount, poison;

void init() 
{
  add_action("drink", "drink");
}

void reset(int arg) 
{
  if (arg!=0) return;
    food = 1;
    full = 1;
    weight = 1; 
    drinker_mess = "Gloink Glurk Glburp.\n"; 
    empty_container = "bottle";
    name = "bottle";
    short_desc = "bottle";
}

int id(string str) 
{
  if (full)
    return  str == query_name() || str == alt_name || str == alias;
  else
    return str == empty_container;
}

string short() 
{
  if (full) 
  {
    if (short_desc)
      return short_desc;
    else if (name) 
      return name;
  }
  else
  {
    if (empty_container) 
        return "An empty " + empty_container;
    else if (name)
        return "An empty " + name;
    }
       return "bottle (empty)";
}

void long() 
{
  if (full) 
  {
    if (!long_desc)
      write(short() + ".\n");
    else
       write(process_string(long_desc));
  }
  else
    write(short() + "\n");
}

int get(string str) 
{ 
  return 1; 
}

void set_name(string n) 
{ 
  name = n; 
}

void set_short(string s) 
{ 
   short_desc = s; 
}

void set_long(string l) 
{ 
   long_desc = l; 
}

void set_value(int v) 
{ 
  value = v; 
}

void set_weight(int w) 
{ 
  weight = w; 
}

/* USERDOC:
set_strength
Format: set_strength(i)
Example: set_strength(5)
This function sets the strength of the alcoholic drink. This is a value between
0 and 50. If it's strong, a player needs to have a high level to drink it. The
value 0 can be used to make a non-alcoholic drink, but it's better to use
/obj/soft_drink.c for this.
*/
void set_strength(int s) 
{ 
  strength = s; 
}

/* USERDOC:
   Here you can the heal value of your drink. This is for example useful
   when you make a special herbdrink to heal someone, or drinks which
   shouldn't heal and only make drunk. This function is shadowable.
   But please use that carefully. */

void set_heal_amount(int h)
{
   heal_amount = h;
}

/* USERDOC:
   Here you can add poison to a drink. The hit of poison is calculated
   in an arithmetic row: poison/2 * (1 + poison) reduced by the con of
   the player.  This function is shadowable. */

void set_poison(int p)
{
    poison = p;
}

void set_alias(string a) 
{ 
  alias = a; 
}

void set_alt_name(string an) 
{ 
   alt_name = an; 
}

/* USERDOC:
set_drinking_mess
Format: set_drinking_mess(s)
Example: set_drinking_mess(" drinks a beer.\n");
This function sets the string displayed to other people when one drinks the
alcoholic drink. This text is prepended with the name of the drinker, but
without a space between this name and the string and without a '.\n' at the 
end.
*/
void set_drinking_mess(string dm) 
{ 
  drinking_mess = dm; 
}

/* USERDOC:
set_drinker_mess
Format: set_drinker_mess(s)
Example: set_drinker_mess("You drink a beer.\n");
This function sets the string displayed to the one drinking the alcoholic
drink. This string should still get a '.\n' at the end.
*/
void set_drinker_mess(string dm) 
{ 
  drinker_mess = dm; 
}

/* USERDOC:
set_empty_container
Format: set_empty_container(s)
Example: set_empty_container("glass");
This sets the name of the item when someone drank the contents. Once an
alcoholic drink is empty, it will selfdestruct after some time.
*/
void set_empty_container(string ec) 
{ 
      empty_container = ec; 
}

/* USERDOC:
set_food
Format: set_food(i)
Example: set_food(1)
See also: query_food
This sets if the alcoholic drink also contains something that is food (for
example: a biscuit). Please use this function with parameter 1 if your item 
contains something that is food.
*/
void set_food(int fo) 
{ 
  food = fo; 
}

/* USERDOC:
query_food
Format: i=query_food()
See also: set_food
This function returns the value set by set_food(). This means one can check if
there is something that is food in this alcoholic drink, which is the case if
this function returns a number not equal to zero.
*/
int query_food() 
{ 
 if (food)
    return food; 
 return 0;
}

/* USERDOC:
query_drink
Format: i=query_drink()
This function always returns 1 and identifies this object as a drink.
*/
int query_drink() 
{ 
  return 1; 
}

// to see is the drink is an alco drink
int query_alco_drink()
{
    return 1;
}

string query_name() 
{ 
  if (full && name)
      return name;
  else if (empty_container)
      return empty_container; 
  else if (name)
      return name;
  return "bottle";
}

int query_value() 
{ 
  if (full) 
  {
    if (value)
      return value; 
  }
    return 10;
}

int query_weight() 
{ 
  if (weight)
     return weight; 
  return 1;
}

int query_heal_amount()
{
    if (heal_amount)
        return heal_amount;
    else if (strength)
        return strength;
    return 0;
}

int query_poison()
{
   if (poison)
       return poison;
  return 0;
}

int drink(string str) 
{
  object tp;
  string tpn;
  int poi;
  closure call;

  tp = this_player();
  call = #'call_other;
  tpn = apply(call,tp,"query_name");


  if (!str || !id(str)) return 0;

  if (!full)
  {
      notify_fail("But "+query_name()+" is empty.\n");
      return 0;
  }
  /* This just about corresponds to old function */
  if ( strength >=  ( 16 * apply(call,tp,"query_level") ) ) 
  {
    write("You sputter liquid all over the room.\n");
    say(tpn + " tries a " + query_name() + " but coughs and sputters\n" +
        "all over you.\n");
    full = 0;
    return 1;
  }
  else if ( strength >  ( 8 * apply(call,tp,"query_level") ) ) 
  {
    write("You throw it all up.\n");
    say(tpn + " tries to drink a " + query_name() + " but throws up.\n");
    full = 0;
    return 1;
  }
  if (!apply(call,tp,"drink_alco",strength))
      return 1;
  food = 0;
  full = 0;

// this call others are made to make the object shadowable 

  apply(call,tp,"heal_self",apply(call,this_object(),"query_heal_amount"));
  apply(call,tp,"set_smell","This person drank something containing alcohol !");
  if (poi = apply(call,this_object(),"query_poison"))
      apply(call,tp,"add_poison",poi);

  write(drinker_mess);
  if (drinking_mess)
    say(tpn + drinking_mess);
  else
    say(tpn + " drinks " + short_desc + ".\n");
  return 1;
}

