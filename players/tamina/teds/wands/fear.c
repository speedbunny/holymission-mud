inherit "obj/thing";

#include "/players/tamina/defs.h"

int charges, level;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_name("bone wand");
  set_alias("wand");
  set_short("A Bone Wand");
  set_long("This thin bone wand has strange black carvings all over it.\n");
  set_weight(1);
  set_can_get(1);
  charges = 10;
}

void init() 
{
  add_action("fear", "scare");
}

int id(string str) 
{
  return str == "wand" || str == "bone wand";
}

int query_charges() 
{ 
  return charges; 
}
/* Changed by Ethereal Cashimor: No negative value anymore...
   080393 */
int query_value() 
{
  if (charges > 0) 
    return 100 + charges * 100;
  return 0;
}

int query_info() 
{
  write("This wand radiates a strong aura of fear. Type 'scare <monster>'\n");
  write("or type 'scare all' to activate it.\n");
  return 1;
}

int fear(string str) 
{
  object ob, nob;

  if (!str) 
  {
    write("What are you trying to scare?\n");
    return 1;
  }
  if (charges <= 0) 
  {
    notify_fail("There are no charges left!\n");
    return 0;
  }
  if (str != "all") 
  {
    ob = present(str, E(TP));
    if (!ob) 
    {
      write("Can't scare something that is not there...\n");
      return 1;
    }
    charges -= 1;
    level = ob->LVL;
    if (random(100) + level > 80) 
    {
      write(CAP(str)+" is not effected!\n");
      return 1;
    }
    write(CAP(str)+" runs away in terror!\n");
    TOBJ(ob, "A tremendous fear takes hold of your body!\n");
    ob->run_away();
    return 1;
  }
  ob = first_inventory(E(TP));
  charges -= 2;
  if (!ob) 
    return 1;
  while(ob) 
  {
    nob = next_inventory(ob);
    if (living(ob) && ob != TP) 
    {
      if (ob->LVL < 30) 
      {
	if (random(100) + level < 80) 
   	{
	  write(ob->NAME+" runs in fear!\n");
	  tell_object(ob, "A treamendous fear takes hold of your body!\n");
	  ob->run_away();
	  say(ob->NAME+" runs is fear!\n");
	} 
   	else 
	{
	  write(ob->NAME+" is not effected.\n");
	}
      }
    }
    ob = nob;
  }
  return 1;
}
