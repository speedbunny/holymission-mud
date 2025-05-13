/* POISON.C - This is an inherit/clone file. DO NOT COPY! */
/* 290392: Wolfi: Additional query-functions added */
/* 230693: Ethereal Cashimor: USERDOC added */

/* USERDOC:
general
This object is a standard food object and works like /obj/alco_drink.c or 
/obj/armour.c. Only it poisons instead of heals. To use this you can do:
   inherit "obj/food";
   ......
   or,
   object ob;
   ob=clone_object("obj/poison");
   ob->set_name("apple pie");
For more documentation look at /doc/build/food. These functions are defined:
set_name, set_alias, set_short, set_long, set_value, set_weight, set_alt_name,
query_value, query_weight, query_name.
*/

string name, short, long, eating_mess, eater_mess, alias, alt_name;
int value, strength, weight;

init() {
  add_action("eat", "eat");
}

reset(arg) {
  if (arg) return;
  weight = 1; 
  eater_mess = "Yum yum yum.\n"; 
}

prevent_insert() {
  write("You don't want to ruin " + short + ".\n");
  return 1;
}

id(str) { return  str == name || str == alt_name || str == alias; }

short() { 
  if(!short) return name;

  return short;
}

long() {
  if(!long)
    write(short() + ".\n");
  else
    write(process_string(long));
}

get() { return 1; }

eat(str) {
  object tp;

  tp = this_player();

  if (!str || !id(str)) return 0;

  if(tp->query_level() * 8 < strength) {
    write("You realize even before trying that you'll never be able to eat all this.\n");
    return 1;
   }
   if (!tp->eat_food(strength))
     return 1;
   tp->add_poison(strength);
   write(eater_mess);
   if (eating_mess)
     say(capitalize(this_player()->query_name()) + eating_mess);
   else
     say(capitalize(this_player()->query_name()) + " eats " + short + ".\n");
   destruct(this_object());
   return 1;
}

min_cost() {
  return 4 * strength + (strength * strength) / 10;
}

set_name(n) { 
  name = n; 
}

set_short(s) { 
  short = s; 
}

set_long(l) { 
  long = l; 
}

set_value(v) { 
  value = v; 
}

set_weight(w) { 
  weight = w; 
}

/* USERDOC:
set_strength
Format: set_strength(i)
Example: set_strength(5)
This function sets the strength of the food. This is a value between 0 and 50.
High strengths indicate much poisoning, but also that low level characters 
can't eat the food.
*/
set_strength(s) { 
  strength = s; 
}

set_alias(a) { 
  alias = a; 
}

set_alt_name(an) { 
  alt_name = an; 
}

/* USERDOC:
set_eating_mess
Format: set_eating_mess(s)
Example: set_eating_mess(" is enjoying an apple.\n");
See also: set_eater_mess.
This function sets the string displayed to other players in the room,
prepended by the eater's name. Notice the leading space and the terminating
\n in this string.
*/
set_eating_mess(em) { 
  eating_mess = em; 
}

/* USERDOC:
set_eater_mess
Format: set_eater_mess(s)
Example: set_eater_mess("It tastes delicious.\n");
See also: set_eating_mess.
This function sets the string written to the screen of the eater. This string
should end with a \n.
*/
set_eater_mess(em) { 
  eater_mess = em; 
}

/* USERDOC:
query_food
Format: i=query_food()
This function always returns 1 to indicate this object as food.
*/
query_food() { 
  return 1;
}

query_value() { 
  if (value)
    return value; 
  else
    return min_cost();
}

query_weight() { 
  return weight; 
}

query_name() { 
  return name; 
}






