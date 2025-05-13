inherit "room/room";

#include <lw.h>

int alive;

void reset(int arg)
  {alive=1; 
  if(!arg)
    {clone_list=({1,1,"beholder","obj/monster",({ "set_name","A beholder",
    "set_alias","beholder",
     "set_race","beholder",
     "set_alt_name","monster",
     "set_level",23,
     "set_ac",15,
     "set_wc",22,
     "set_hp",1800,
     "set_spell_mess1","Beholder gazes!",
     "set_spell_mess2","Beholder hits with a tentacle",
     "set_chance",40,
     "set_spell_dam",30,
     "set_short","A beholder",
     "set_long","The beholder is a hideous beast, just a giant eyeball hovering several feet\n"+
     "above the ground, with tentacles waving in every direction!  Slime drips off\n"+
     "its disgusting little body and forms a little puddle underneath it.\n",
     "add_money",1500})});
     set_light(-4);
     short_desc = "Prison Cell";
     long_desc ="As you reach the end of the prison hall, you come across a large cell.  "+
     "@@chk_children@@";
     smell = "The air smells of death and decay.";
     dest_dir = ({"players/kawai/areas/quest/prison","west"});
     items = ({"cave","It is cold and damp",
     "passage","It is cold and damp",
     "blood","A pool nearly a foot deep.  You wonder how many people\n"+
     "died for this.",
     "body","No wholes...just parts",
     "bodies","You only find fragments",
     "part","Looks like a foot...",
     "parts","Assorted body parts...",
     "rune","You can not read them",
     "hall","Dozens of makeshift prison cells line the walls, each full of decaying corpses",
     "runes","They are in some archaic language, foreign to you",
     "cell","This one contains the half decayed remains of an elf",
     "cells","Makeshift prison cells",
     "corpse","Looks like a small child",
     "corpses","Many of them old and decaying",
     "children","@@children@@",
     "child","@@child@@"});}
  ::reset(arg);}

void init()
  {::init();
  add_action("op","open");
  add_action("op","enter");
  add_action("op","unlock");}

string children()
  {if(alive) 
    {return "They are all sick and dying";}
  return "There is nothing but charred remains";}

string child()
  {if(alive)
    {return "As you look down on the child, it coughs up some blood and dies";}
  return "It is nothing but a pile of ashes...";}

string chk_children()
  {if(alive)
    {return "Inside the cell are dozens of screaming children, starved and "+
    "dying of disease. \"Help us!\" they shout, many coughing up blood "+
    "in the process.\n";}
  return "Inside the cell are the burned and smoldering bodies of dozens of "+
  "innocent children.\n";}

int query_alive() 
  {return alive;}

void kc()
  {if(alive)
    {writelw("As you move towards the door, a cloud of gaseous acid fills the "+
    "cell of children.  For what seems an eternity their screams echo "+
    "throughout the realm.  As the gas clears, only their charred bodies "+
    "remain.\n");
    if(!random(5))
      {shout("The screams of dying children echo throughout the realm...\n");}
    alive=0;}
  else
    {write("Nothing happens...\n");}}


status op(string str)
  {if(str=="cell"||str=="cells")
    {if(present("beholder"))
      {write("The beholder blocks your way!\n");
      return 1;}
    if(query_verb()=="unlock")
      {write("You can't unlock them.\n");}  
    else
      {write("They are all locked.\n");}
    kc();
    return 1;}
  notify_fail(capitalize(query_verb())+" what?\n");}
