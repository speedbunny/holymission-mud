/* ------------------------------------------------------------------------
   A generic file for creating potions.
   Created by Ted  [date unknown]

   Updated by Elemental Tamina 07-10-94

   Functions available:
	set_name   - Valid ID for potion
        set_alias  - Secondary ID for potion 
        set_short  - Inventory desc
	set_long   - Long desc
	set_mess   - Returned to drinker
	set_weight - weight
	set_value  - for re-sale
	set_heal   - amount player heals by
	set_pois   - amount of poison reduced/inflicted
	set_into   - alcoholic value
	set_info   - for specific reference to Identify scroll

    --------------------------------------------------------------------- */

#include "std.h"
#include "/players/tamina/defs.h"

string short_desc, name, mess, alias, long_desc, info;
int value, heal, weight, pois, into;

void reset(int arg) 
{
  if (arg) return 0;
}

int id(string str) 
{
 return str == name || str == alias || str == "potion";
}

string short() 
{
  return short_desc;
}

void long() 
{
  write(long_desc);
}

void init() 
{
  add_action("drink", "drink");
}

set_name(n)   { name = n; }
set_alias(a)  { alias = a; }
set_short(s)  { short_desc = s; long_desc = s+".\n"; }
set_long(l)   { long_desc = l; }
set_mess(m)   { mess = m; }
set_weight(w) { weight = w; }
set_value(v)  { value = v; }
set_heal(h)   { heal = h; }
set_pois(p)   { pois = p; }
set_into(x)   { into = x; }
set_info(i) 
{
  if (i)
    info = i;
  else
    info = "This is a potion. It can cure you for up to "+heal+" points,\n"+
           "and is worth "+value+".\n";
}

string query_info()   { return info; }
string query_name()   { return name; }

int query_weight() { return weight; }
int query_value()  { return value; }
int query_pois()   { return pois; }
int query_into()   { return into; }
int drop()         { return 0; }
int get()          { return 1; }

int drink(string str) 
{
  if (!this_player()->drink_alcohol(into))
  {
    write("You don't think you can drink such a strong potion at the moment...\n");
    say(TPN+" looks as if "+TP->QPRO+" cannot drink "+TP->QPOS+" potion...\n");
    return 1;
  }
  if (id(str)) 
  {
    write("You drink a potion of "+str+" healing.\n");
    if (mess)
      write(mess);
    this_player()->heal_self(heal);
    this_player()->add_poison(pois);
    this_player()->drink_alcohol(into);
    this_player()->add_weight(-weight);
    say(this_player()->query_name()+" drinks "+alias+".\n");
    destruct(this_object());
    return 1;
  }
  else
  {
    NFAIL("Drink what?\n");
    return 0;
  }
}
