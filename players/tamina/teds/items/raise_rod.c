/* Edited by Kryll to give it charges so pking is not infinite. */

inherit "obj/thing";

#include "/players/tamina/defs.h"

int charges = 2;

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

  set_name("Rod of Resurrection");
  set_short("A Platinum Rod");
  set_long(
"This thin platimun rod is quite light and almost seems to glow.\n"+
"Perhaps you should get it identified?\n");
  set_weight(1);
  set_value(1200);
  set_can_get(1);

}

int id(string str)
{
 return str == "rod" || str == "rod of resurrection" || str == "platinum rod";
}

void init()
{
  add_action("pray", "raise");
  add_action("pray", "resurrect");
}

string query_charges()
{
  return "Unlimited";
}

int pray(string arg)
{
  object ob;
  ob = present(arg, E(TP));

  if (!arg)
  {
    notify_fail("Resurrect whom?\n");
    return 0;
  }
  if (!charges)
  {
    write("The rod is drained of power.\n");
    return 1;
  }
  if (!ob)
  {
    write(CAP(arg)+" must be present.\n");
    return 1;
  }
  if(!ob->query_living()) {
    write("You can only resurrect living creatures.\n");
    return 1;
  }
  if (!ob->query_ghost())
  {
    write(CAP(arg)+" is not a ghost!\n");
    return 1;
  }
  write("You touch "+ob->NAME+" with the rod.\n");
  say(TPN+" touches the ghost of "+ob->NAME+" with A Platimun Rod.\n");
  ob->remove_ghost();
  charges--;
  return 1;
}

string query_info()
{
  return "This is a rod of resurrection.\nType 'raise <player>' to use.\n";
}

