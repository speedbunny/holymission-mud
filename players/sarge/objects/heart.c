inherit "obj/treasure";
#include <lw.h>

string location;

status get() 
  {return 1;}

status drop() 
  {writelw("You careless toss the heart on the ground, upon which it splits apart, "+
  "releasing a horrible moan.  The spirit of Abduhla Gravis will never rest in "+
  "peace.\n");
  destruct(this_object());
  return 1;}

 
void reset(int arg) 
  {if(!arg)
    {set_id("heart");
    set_alias("heart");
    set_weight(0);
    set_value(1);
    set_short("A large heart");
    set_long(
    "This is the heart of the great adventurer, Abduhla Gravis.  The noble\n"+
    "warrior has passed away but can not be free until his heart is returned\n"+
    "to him.  If you can find the proper weapon perhaps you can return it\n"+
    "to him, and allow him rest.\n");}}

void init()  
  {::init();
  add_action("impale","impale");
  add_action("impale","stick");
  add_action("impale","spear");
  add_action("impale","cut");
  add_action("impale","slice");
  add_action("impale","stab");}

status impale(string str)
  {if(!str)
    {notify_fail(capitalize(query_verb())+" what?\n");
    return 0;}
  if(str=="heart")
    {if(present("denizen's sword",this_player()))
      {write("The heart of Abdulha Gravis shouts his freedom!\n");
      this_player()->set_quest("heart");
      destruct(this_object());
      return 1;}
    else
      {write("Nothing you have is worthy of such a task!!!\n");
      return 1;}}
  else 
    {notify_fail("You can't do that!\n");
    return 0;}}
