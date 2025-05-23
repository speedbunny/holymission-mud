/*
Uglymouth 940311: fixed query_name to return empty_container when !full.
  
   This object is a standard soft_drink object and works
   like /obj/food.c or /obj/armour.c
  
   To use this you can do:
     inherit "obj/soft_drink";
   ......
   or,
   object ob;
   ob = clone_object("obj/soft_drink");
   ob->set_name("apple juice");
  
*  For more documentation look at /doc/build/drinks


   These functions are defined:

	   set_name(string)	To set the name of the item. For use in id().

   Two alternative names can be set with the calls:

	   set_alias(string) and set_alt_name(string)

	   set_short(string)	To set the short description.

	   set_long(string)	To set the long description.

	   set_value(int)	To set the value of the item.

	   set_weight(int)	To set the weight of the item.

	   set_strength(int)	To set the healing power of the item. If you
				don't wish the item to have healing powers
				just set this value to 0.

	   set_drinker_mess(string)
				To set the message that is written to the 
				player when he drinks the item.

	   set_drinking_mess(string)
				To set the message given to the surrounding
				players when this object is drunk.

	   set_empty_container(string)
				The container of the liquid inside. For
				example "bottle" or "jug".


	For an example of the use of this object, please read:
*	/doc/examples/apple_juice.c

*/

#include "setlight.h"

string name, short_desc, long_desc, drinking_mess, 
	drinker_mess, alias, alt_name, empty_container;
int value, strength, weight, full, food;

init()
{
	add_action("drink", "drink");
}

reset(arg)
{
	if (arg)
		return;

	full = 1;
	weight = 1;
        food = 1; 
	drinker_mess = "Gloink Glurk Glburp.\n"; 
	empty_container = "bottle";
}

prevent_insert()
{
	if (empty_container)
		return 0;
	else
	{
		write("You don't want to ruin " + name + ".\n");
		return 1;
	}
}

id(str)
{
	if (full)
		return  str == name || str == alt_name || str == alias;
	else
		return str == empty_container;
}

short()
{ 
	if (full)
	{
		if (!short_desc)
		    return name;

		return short_desc;
	}
	else
		return "An empty " + empty_container;
}

long() 
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

get()
{
	return 1;
}

drink(str)
{
	object tp;
	string p_name;

	tp = this_player();
	p_name = capitalize(tp->query_name());

	if (!full)
		return;

	if (!str || !id(str))
		return 0;


	if (tp->query_level() * 8 < strength)
	{
		write("This is much to much for you to drink! You drool most of it on the ground.\n");
		say(p_name + " tries to drink " + short_desc + " but drools most of it on the ground.\n");
		full = 0;
                food = 0;
		return 1;
	}

	if (!tp->drink_soft(strength))
		return 1;
	
	full = 0;
	tp->heal_self(strength);
	write(drinker_mess);
	if (drinking_mess)
		say(p_name + drinking_mess);
	else
		say(p_name + " drinks " + short_desc + ".\n");
	call_out("dest_bottle",600);
	return 1;
}

dest_bottle() {
object env;

  env=environment();
  if (!(env && (living(env) || env->id("bag")))) {
     tell_room(env,short()+" crumbles to dust.\n");
     destruct(this_object());
     return 1;
  }
  else call_out("dest_bottle",600);	/* try again */
  return 1;
}
min_cost()
{
	return 4 * strength + (strength * strength) / 10;
}

set_name(n) 
{ 
	name = n; 
}

set_short(s) 
{ 
	short_desc = s; 
}

set_long(l) 
{ 
	long_desc = l; 
}

set_value(v) 
{ 
	value = v; 
}

set_weight(w) 
{ 
	weight = w; 
}

set_strength(s) 
{
	strength = s; 
}

set_alias(a) 
{ 
	alias = a; 
}

set_alt_name(an) 
{ 
	alt_name = an; 
}

set_drinking_mess(dm) 
{ 
	drinking_mess = dm; 
}

set_drinker_mess(dm) 
{ 
	drinker_mess = dm; 
}

set_empty_container(ec)
{
	empty_container = ec;
}

set_food(fo) { food = fo; }
/*
 * Things that other objects might want to know.
 */
/* Wolfi: 29.3.92 */
query_food() {return food;}

query_strength() { return strength; }

query_value() 
{ 
	if (full)
	{
		if (value)
			return value; 
		else
			return min_cost();
	}
	else
		return 10;
}

query_weight() 
{ 
	return weight; 
}

query_name() {
  return full ? name : empty_container;
}
