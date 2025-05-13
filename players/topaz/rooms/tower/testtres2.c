inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
    object treas;
    object beast;
  if(!arg) {

     short_desc = "Demon treasury";
    long_desc = "This is the room where the Demon King keeps most of his\n" +
                 "treasures.  This room has no decorations whatsoever and\n" +
                 "only a few furnishings.  There is a small desk and a\n" +
                 "chair for the treasurer.\n" +
                 "There is a safe set into the wall behind the desk.\n";

      dest_dir = ({"players/topaz/rooms/tower/floor1","up",
                     });

     items =({"treasury","This is where the Demon King keeps his valuables",
              "stairs","They're the only way out of here",
              "stairway","It leads back to the main floor of the tower",
              "desk","A small desk used by the treasurer for keeping records",
              "chair","A small chair so the treasurer doesn't have to stand",
              "decorations","There are none",
              "furnishings","Just a desk and a chair",
              "safe","It looks important",
              "wall","There is a safe in it",
              });
       set_light (1);
        move_object(treas=clone_object(MNST + "tower/treasurer"),this_object());
        move_object(beast=clone_object(MNST + "tower/trebeast"),this_object());
  }
}

init() {

object rin;
object bes;

    ::init();
    if((!rin=present("dkring",TP)) && (bes=present("beast",TO))) {
      bes->attacked_by(TP);
      return 1;
    }
    else {
      return 1;
    }
}
