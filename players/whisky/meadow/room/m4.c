
#define TQ this_player()->query_name()
#define TP this_player()
inherit "room/room";
#include "../meadow.h"

void reset (int arg) 
{

   if (arg) return;
   set_light(1);
   short_desc = "On a meadow";
   long_desc = BS(
    "You are standing on the big meadow. The grass is "+
    "fresh and high. To the west you see big bushes "+
    "and to the east you can hear the rolling of the sea.");
   items = ({ "bushes","10 foot high hazelnut bushes" });
   dest_dir = ({
     PATH+"m7","north",
     WOOD+"forest2","south",
     PATH+"m5","east",
     PATH+"m8","northeast",
     PATH+"m2","southeast" });
}

init() 
{
  ::init();
  add_action("pass","pass");
}

int pass(string str) 
{

if (str=="bushes" || str=="hazelnutbushes") 
{
   write("You try to pass the bushes, but they are too high.\n"+
         "Instead you hurt yourself badly.\n");
   say(TQ+" tries to pass the bushes, but falls down and hurts\n"+
       "himself badly.\n");
   TP->hit_player(5);
   return 1; 
   }
  return 0;
 }

