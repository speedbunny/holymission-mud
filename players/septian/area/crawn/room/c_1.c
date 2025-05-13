// *****************  Coded by Septian  *********************** //

inherit "room/room";

#include "/players/septian/defs.h"

reset(arg)  {

    short_desc = "Inside a huge cavern";

    long_desc =
    "  You are standing near the edge of a gigantic cavern. It gets smaller\n" +
    "to the north and you can't help notice the towering statue of a lady in\n" +
    "that direction. The ground is hard as stone and large stalagtites rise\n" +
    "from the floor in a random pattern throughout the cavern before you. A\n" +
    "path seems to have formed to the south due to the heavy traffic to the\n" +
"divine presence in the north.\n";

    items = ({
      "cavern","What seems to be the largest cavern you have ever been in",
      "ground","You look twice and notice it is hard stone, and you can see tracks" +
      "in the path to the north and south.",
      "stalagtites","Tall stone structures spearing into the heights of the cavern",
      "path","A well-traveled path leads north and south from here",
      "statue","You feel you can get a better look if you get closer"
    });

    property = ({ });

    smell ="\nYou can smell a swift breeze in the air of a nearby watersource," +
    " mixed with some earthy dirt smell.\n";

    dest_dir = ({
      PATH1 + "crawn_church","north",
      PATH1 + "c_2","south"
    });

    replace_program("room/room");

}
