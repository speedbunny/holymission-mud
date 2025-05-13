inherit "room/room";

#include "/players/mangla/defs.h"

void reset(int arg) {

  short_desc = "Ideas Room";

  long_desc = "This is an idea room. If you ahve some ideas, or " +
              "the arches have ideas they want input on, they will " +
              "be posted here to keep the main board clearer.\n";

  set_light(1);

  items = ({
          });

  property = ({
               "no_teleport",
               "no_clean_up",
               "no_sneak",
             });

  dest_dir = ({
               "/room/wiz/general","northeast"
             });

  clone_list = ({
                 1, 1, "board", "boards/wizard_idea" , 0,
               });

    ::reset();
    replace_program("room/room");
}
