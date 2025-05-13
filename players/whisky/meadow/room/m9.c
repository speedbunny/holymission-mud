
#define TQ this_player()->query_name()
#define TP this_player()

inherit "room/room";
#include "../meadow.h"

void reset (int arg) 
{

   if (filter_live(this_object()) < 2)
      CM("bear");

   if (arg) return;
   set_light(1);
   short_desc = "On a meadow";
   long_desc = BS(
      "You are standing on the big meadow. The grass is "+
      "fresh and high. To the east you see big bushes "+
      "and to the north you see the entrance of a beautiful chapel.");
   items = ({ "bushes","10 foot high hazelnut bushes" });
   dest_dir = ({
     PATH+"m8","west",
     PATH+"m6","south",
     PATH+"m5","southwest", 
    "players/whisky/guild/room/c2", "north" });
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

