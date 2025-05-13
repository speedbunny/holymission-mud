inherit "obj/monster";
#include <lw.h>

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_level(15);
    set_hp(1500);
    set_name("the Casino Boss");
    set_alias("boss");
    set_race("troll");
    set_alt_name("troll");
    set_al(-500); 
    set_short("The Casino Boss");
    set_long(lw("The Boss is a large, burly troll, easily 8 feet tall and over 700 "+
    "pounds of nearly pure muscle.  Being the boss of a high-class "+
    "establishment such as this, he is obviously of a much higher "+
    "class of troll than most.  In fact, he's actually literate!\n"));
    set_wc(26);
    set_ac(9);
    set_gender(1);
    set_size(4);
    set_aggressive(1);
    set_whimpy(-1);
    transfer(clone_object("/players/kawai/obj/ring"),this_object());
    command("wear ring",this_object());}}

void init()
  {::init();
  add_action("take","take");
  add_action("take","get");
  call_out("gripe",2,0);}

void gripe()
  {writelw("The troll stands up at his desk and pounds on it hard.  "+
  "Troll says: NOBODY beats the house and gets away "+
  "with it.  It's time to pay your respect!\n");}

status take(string str)
  {if(!str)
    {notify_fail(capitalize(query_verb())+" what?\n");
    return 0;}
  if(present("troll"))
    {writelw("The troll grabs you by the neck and says:  You're not touching "+
    "ANYTHING in this office so long as I'm here!\n");
    return 1;}
  else
    {return 0;}}
