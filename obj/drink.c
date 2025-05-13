/* DRINK.C - This is an inherit/clone file. DO NOT COPY! */
/* 290392: Wolfi: query_food added */
/* 230693: Ethereal Cashimor: USERDOC added */
/* 210394: Whisky: strikt types, faster code, removed the call_out */

#include "setlight.h"

string short_desc, name, message;
int value, strength, heal;
int full, food;
int pub_drink;		/* Drinks from the pub can't be removed from pub */
 
/* USERDOC:
general
This is a drink, which can be alcoholic or not. This file is rather old, it's
better to use alco_drink.c or soft_drink.c instead. set_value() has changed a
lot, so it's documented seperately. Other generally defined functions:
query_value, query_weight, query_name.
*/

/* USERDOC:
set_value
Format: set_value(s)
Example: set_value("beer#A beer#It tastes awful#12#5")
This function sets the entire drink. The arguments are seperated by '#', and
there are 5 of them. The first argument is the name, the second is the short
description, the third is the message displayed when the drink is drunk (this
message should not have a '.'), the fourth is the value of the item and the 
fifth is the strength of the drink.
*/
int set_value(string str) 
{
    if (sscanf(str, "%s#%s#%s#%d#%d#%d", name, short_desc, message,
	heal, value, strength) != 6)
	    return 0;
    return 1;
}

/* USERDOC:
set_pub
Format: set_pub()
This function makes this drink one that can't be removed from pubs.
*/
void set_pub() 
{
    pub_drink = 1;
}
 
mixed id(string str)
{
    if ((str == name || (str == "drk2" && pub_drink)) && full)
	return 1;
    return str == "bottle";
}
 
string short() 
{
    if (full)
	return short_desc;
    return "empty bottle";
}
 
/* The shop only buys empty bottles ! */
 
int query_value() 
{
    if (!full) return 10;
    return 0;
}
 
void long() 
{
    write(short() + ".\n");
}
 
void reset(int flag)  /* removing unused objects in the reset: whisky */
{
    if (flag)
	{
      if (!objectp(environment(environment(this_object()))))
          destruct(this_object());
      return;
    }
    food = 1;
    full = 1;
}
 
int fcn_drink(string str)
{

    if ( !stringp(str) || !id(str) || !full || !objectp(this_player()) )
	     return 0;

    if (strength > ( 2+ this_player()->query_level()) ) 
	{
    	write("You sputter liquid all over the room.\n");
    	say(this_player()->query_name() + " tries a " + name +
		" but coughs and sputters all over the room.\n"); 
    	full = 0;
	return 1;
    }
    if (!this_player()->drink_alcohol(strength) && !this_player()->query_npc())
	    return 1;

      this_player()->heal_self(heal);
      write(message + ".\n");
	  say(this_player()->query_name()+" drinks " + name + ".\n");
      full = 0;
      food = 0;
    return 1;
}
 
void init() 
{
    add_action("fcn_drink", "drink");
}
 
int get() 
{
    return 1;
}

/* USERDOC:
set_food
Format: set_food(i)
Example: set_food(1)
This function indicates this drink as a food. This should be used if there is
something edible in the drink as well.
*/
void set_food(int fo)
{ 
  if (intp(fo))
      food = fo; 
}

/* USERDOC:
query_food
Format: i=query_food()
If this function returns a value other than 0 then there is food in the drink.
*/
int query_food() 
{ 
  if (intp(food)) return food; 
  return 0;
}    

/* USERDOC:
query_drink
Format: i=query_drink()
Always returns 1, to indicate this item as a drink.
*/
int query_drink() 
{ 
  return 1; 
}
 
int query_weight() 
{
    return 1;
}

string query_name() 
{ 
  return (full ? name : "empty bottle"); 
}

