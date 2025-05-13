

#define TQ this_player()->query_name()
#define TP this_player()

inherit "room/room";
#include "../meadow.h"

void reset(int arg)
{

  if (filter_live(this_object()) < 1)
  {
     CM("rabbit");
     CM("rabbit");
  }
  if (arg) return;
  set_light(1);
  short_desc = "On a meadow";
  long_desc = BS(
    "You are standing on the big meadow. The grass is "+
    "fresh and high. To the west and south you see big "+
    "bushes and you can hear the rolling of the sea.");
  items = ({ "bushes","10 foot high hazelnut bushes" });
  dest_dir = ({
     PATH+"m6","north",
     PATH+"m2","west",
     PATH+"m5","northwest" });

}

init() 
{
 ::init();
 add_action("pass","pass");
}

int pass(string str) {

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

