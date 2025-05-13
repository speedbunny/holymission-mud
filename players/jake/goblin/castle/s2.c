inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
if (arg) return;
set_light(1);
short_desc = "Hallway to the stables";
long_desc  = "The sounds of horses are getting louder coming from the north.\n" +
             "A goblin rushes past you carrying a bucket of water into the stables.\n" +
             "Small slits for windows are in the east and west walls, and you\n" +
             "think you see something in one of the windows out of the corner\n" +
             "of your eye.\n";
items = ({
  "slits","Narrow slits in the walls that serve as windows",
  "windows","You start to get a bit scared, then realize it's only a small bird",
});
dest_dir = ({
CAS + "s1","south",
CAS + "s3","north",
});
}
