inherit "obj/thing";

#include "/players/tamina/defs.h"

int charges;

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;

  set_name("crystal ball");
  set_alias("ball");
  set_short("A Crystal Ball"); 
  set_long("This is a round crystal ball. It is slightly cloudy.\n"+
	   "Perhaps you should get it identified?\n");
  set_weight(2);
  set_value(900);
  set_can_get(1);
  charges = 10;
}

int id(string str) 
{ 
  return str == "ball" || str == "crystal" || str == "crystal ball";
}

string query_info()
{
  return "This is a crystal ball, used to locate people.\n"+
 	 "type 'peer <person>' or type 'find <person>'.\n";
}

void init() 
{
  ::init();
  add_action("view", "peer");
  add_action("view", "find");
}

int view(string arg) 
{
  object who, where, ob;
  int i;
  
  if (charges <= 0)
  {
    write("The Crystal Ball has expended all its energy.\n"+
   	  "It reverts to a mist which blows away on the winds.\n");
    return 1;
  }
  if (TP->SP < (30 + TP->LVL)) 
  {
    write("You are not strong enough to do that.\n");	
    return 1;
  }
  who = find_living(arg);
  if (!arg) 
  {
    write("What are you looking for ?\n");
    return 1;
  }
  if (!who) 
  {
    write("Couldn't find "+CAP(arg)+"\n");
    return 1;
  }
  where = E(who);
  write("You peer into the crystal ball, trying to find "+CAP(arg)+"\n");
  write("You see:\n\n");
  if (who->query_immortal()) 
  {
    write("You can't stand looking at the power surrounding "+CAP(arg)+".\n");
    write("You lose your concentration ...\n");
    return 1;
  } 
  where->long();
#if 0
  TRM(where, TPN+" looks around.\n");
#endif
  TP->restore_spell_points(-30);
  charges--;
  return 1;
}
