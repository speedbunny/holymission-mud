
inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Fish Bowl";

    long_desc="Swimming around in the fishbowl ...\n" +
              "There are lots of colored stones on the bottom of the bowl " +
              "and some weed floating around near the surface of the water. " +
              "You wonder how you are ever going to get out of here ...\n";

    set_light(1);

    items=({"glass","Everything looks distorted as you look out through the glass bowl",
            "bowl","Everything looks distorted as you look out through the glass bowl",
            "weed","No, its not that kind of weed, its the type fish eat.",
            "stones","All the different colors of the rainbow.",
          });

    property=({ "no_teleport" });   /* also availible no_fight and  */
                                    /*     no_steal and no_clean_up */

    smell= "You blow little bubbles out of your nose.";
     no_obvious_msg= "";
    dest_dir=({
               "/players/baer/room/testroom","out",
             });

    ::reset(arg);

    replace_program("room/room");
}

