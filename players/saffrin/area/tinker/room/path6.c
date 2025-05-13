inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
    set_light(1);
    short_desc = "A wooded path";
    long_desc =
         "You are walking on a small wooded path.  Off the path lies a wagon that is used "+
         "as a stage.  You hear music and laughter coming from inside.  "+
         "Hearing how much fun it sounds like, you feel yourself longing to enter the wagon.  "+
         "You hope the merrymakers are friendly.  "+
         "The path continues north and west from here.\n";
    dest_dir=({
      TINK+"room/path7", "north",
      TINK+"room/path5", "west",
      TINK+"room/wagon", "in",
    });
    items=({
      "wagon", "A brightly colored wagon, with curtains in its windows",
      "windows", "The windows to the wagon have curtains in them",
      "curtains", "Curtains patched together from scraps of cloth",
      "path", "A path that runs through sparce woods",
      "woods", "Sparce woods made up of oak trees",
      "trees", "Large oak trees scattered about",
    });
    ::reset();
    replace_program("room/room");
}
