inherit "/obj/thing";

#include "/players/tamina/defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("pipe");
  set_weight(2);
  set_value(50);
  set_short("A small wooden pipe");
  set_long("A small wooden pipe, that looks very clean, as if never used. "+
           "There is a piece of writing etched into the woodwork... \n");
  set_read("...Breathing is the most important part of living...\n");
  set_can_get(1);
}

int id(string str)
{
  return str == name || str == "water key";
}

void init()
{
  AA("blow_it", "blow");
  AA("suck_it", "suck");
  ::init();
}

int blow_it(string str)
{
  if (!id(str))
  {
    NFAIL("Blow what?\n");
    return 0;
  }
  if (E(TP)->query_env_name() == "water")
  {
    write("You blow hard through the pipe.\n"+
	  "Several small bubbles emit from the end of the pipe.\n");
      say(TPN+" blows bubbles through his pipe.\n");

    return 1;
  }
  else
  {
    write("You give a sharp blow on the pipe, and make a little:\n\n"+
	  "                **  T O O T **\n\n");
      say(TPN+" makes a little -= TOOT =- from "+TP->QPOS+" pipe!\n");
    
    return 1;
  }
}

int suck_it(string str)
{
  if (!id(str))
  {
    NFAIL("Suck what ?!?\n");
    return 0;
  }
  if (E(TP)->query_env_name() == "water")
  {
    write("You suck the Water through the pipe !!\n"+
	  "You cough as you gag on the water falling down your throat.\n");
      say(TPN+" coughs and splutters as "+TP->QPRO+" sucks water down\n"+
	  "through "+TP->QPOS+" wooden pipe.\n");

    HIT(10);

    return 1;
  }
  else
  {
    write("You suck air through your wooden pipe.\n");
      say(TPN+" makes a small sucking sound, as air is drawn in through\n"+
	  TP->QPOS+" wooden pipe.\n");

    return 1;
  }
}

