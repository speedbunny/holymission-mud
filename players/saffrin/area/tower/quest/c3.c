/* coded by Llort */
/* Spruced up by Saffrin */

inherit "/room/room";
#include "/players/saffrin/area/tower/quest/cellar.h"

reset(arg) {

    set_light(0);

    short_desc="Mage Tower Cellar";

    long_desc=
    "You are in the dark and musty cellar of the Mage Tower.  "+
    "The smell of fresh cheese overpowers your senses, making you drool.  "+
    "There is a chill in here, sending shivers down your spine.  "+
    "The cellar is made from old, slightly rotting wood.  The wall to the "+
    "west stands out.  A small corridor leads east.\n";

    dest_dir = ({ ROOM+"c1","east", });

    items = ({ "vault","An old oak-wooden vault",
      "wall","A grey stone wall",
      "walls","Grey stone walls",
      "bottom","A dark stone bottom" });

    clone_list = ({
        1, 4, "rat", "/players/saffrin/area/tower/quest/rat",0
    });


    ::reset();
}
