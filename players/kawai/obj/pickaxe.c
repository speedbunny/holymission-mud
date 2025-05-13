inherit "obj/weapon";
#include <lw.h>
int is_sharp;

int id(string str)
  {return str=="kq1-axe"||str=="axe"||str=="pickaxe";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {is_sharp=0;
    set_id("kq1-axe");
    set_alt_name("axe");
    set_weight(2);
    set_name("a pickaxe");
    set_value(1300);
    set_class(12);
    set_alias("pickaxe");
    set_short("A pickaxe");
    set_long(lw("This pickaxe looks as if it could be used for mining ore, as well as "+
    "make for a decent weapon.  @@chk_axe@@\n"));}}

string chk_axe()
  {if(is_sharp)
    {return("It is very sharp.");}
  return("It is dull.");}

void set_sharp()
  {is_sharp=1;
  set_class(17);}

void set_dull()
  {is_sharp=0;
  set_class(12);}

int query_sharp()
  {return is_sharp;}

int query_quest_obj()
  {return 1;}

