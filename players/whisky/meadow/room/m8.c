
#define TQ this_player()->query_name()
#define TP this_player()

inherit "room/room";
#include "../meadow.h"

void reset (int arg) 
{

  if (filter_live(this_object()) < 2)
      CM("hedgehog");

  if (arg) return;
     set_light(1);
     short_desc = "On a meadow";
     long_desc = BS(
       "You are standing on a big meadow. The grass is "+
       "fresh and high. To the north and far to the west you see big "+
       "bushes and you can hear the rolling of the sea.");
   items = ({ "bushes","10 foot high hazelnut bushes" });
   dest_dir = ({
    PATH+"m7","west",
    PATH+"m9","east",
    PATH+"m5","south",
    PATH+"m4","southwest",
    PATH+"m6","southeast" });
}

init() 
{
  ::init();
  add_action("pass","pass");
}

int pass(string str) 
{

if (str=="bushes" || str=="hazelnut bushes") {
   write("You try to pass the bushes, but they are too high.\n"+
         "You hurt yourself badly.\n");
   say(TQ+" tries to pass the bushes, but falls down and hurts\n"+
       "himself badly.\n");
   TP->hit_player(5);
   return 1; 
  }
  return 0;
 }

