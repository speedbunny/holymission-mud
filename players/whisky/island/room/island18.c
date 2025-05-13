 
 
inherit "room/room";
#include "../island.h"

object *o1;
object o1;
 
void reset(int arg) 
{
  if (!o1 && !present("garschmirak",this_object()) )
  {
    o1=clone_object(MONST+"baby_dragon");
    move_object(o1,this_object());
   }
    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
         "You are now standing on the top of the volcano. "
        + "As you look down you see a big cavern with hot red "
        + "lava. This is the home of the famous Dragonlord. "
        + "This dragon likes to take his daily lava bath. "
        + "The air is so full of ash that you can hardly "
        + "breathe.");
    items = ({
          "cavern","A big hot cavern full of red lava",
          "lava","Hot red lava",
          "bottom","A black stony bottom"
             });
    dest_dir = 
        ({
        PATH+"island19", "down",
        });
}
 
