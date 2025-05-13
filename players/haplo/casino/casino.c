
 /* Installed for players of holy mission, just for the hell of it.
     Haplo - 12-24-95   */
inherit "room/room";
#include "/players/haplo/defs.h"

object poker;

reset(arg)
{
    if(arg) return;

    set_light(1);
    short_desc ="Misson Casino";
    long_desc=
 "You entered into a brilliantly illuminated room. You can see the walls "+
 "decorated in gold and silver inlays. You can see ostentatious paitings and "+
 "curtains hanging on the walls. You can smell smoke from the cigars which "+
 "are sold liberally. There is a place for you to play poker should you wish "+
 "to try your luck!\n";
    items=({
     "painting","Many tacky paintings hanging around.",
    });

  property=  ({
                "no_fight",
                "no_magic",
                "has_fire"
          });
   poker=CO("/players/haplo/casino/poker");
    transfer(poker,this_object());
    dest_dir=({
     "/room/vill_track","south",
    });
}

