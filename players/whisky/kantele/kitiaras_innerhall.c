
inherit "/room/room";
#include "defs.h"

object beast;

void reset(int flag)
{
    if (!beast)
    {
      beast = clone_object("obj/monster");
      beast->set_name("displacer beast");
      beast->set_level(20);
      beast->set_hp(400);
      beast->set_wc(25);
      beast->set_ac(8);
      beast->set_whimpy(-1);
      beast->set_short("Kitiaras pet displacer beast is here");
      beast->set_aggressive(1);
      beast->set_alias("beast");
   }
   if (flag == 0)
   {
      dest_dir = ({
          PATH+"kitiaras_crossing","north",
          PATH+"kitiaras_lab","east",
          PATH+"kitiaras_slepingroom","west",
          PATH+"kitiaras_livingroom","south",
       });

       short_desc = "You are in a small hall";
       long_desc = BS(
           "You are in a small hall, you can smell some sulphur to the "+
           "east.");
       items = ({
        "bottom","It's a wooden bottom",
        "ceiling","The ceiling are made of dusty red bricks",
        "walls","The walls are made of dusty red bricks",
        "hall","You are standing in the hall",
        "sulphur","yellow bad smelling sulphur",
       });
    }
}
    

       
