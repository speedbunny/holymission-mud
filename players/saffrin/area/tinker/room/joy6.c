inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing alond the south edge of Joy's Park.  You can hear the sound of "+
         "water trickling to the northeast.  There are flowers all around you in several "+
         "varieties.  The sweet smell tickles at your nose.  The hot sun is shining "+
         "down warmly against your skin.  A light breeze gently blows through your hair.\n";
    dest_dir = ({
      TINK+"room/joy11", "north",
      TINK+"room/joy5", "east",
      TINK+"room/joy7", "west",
    });
    items =({
      "flowers", "A array of different kinds of sweet smelling flowers",
      "breeze", "You can't see a breeze, silly",
      "sun", "ARGH!!!!!!!!!!!  Pain rips apart your eyes as they are burned by the sun!",
    });
    clone_list=({
          1, 1, "butterfly", TINK+"npc/butterfl", 0,
    });
    ::reset();
    replace_program("room/room");
}
