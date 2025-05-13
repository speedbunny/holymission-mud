inherit "room/room";

#include "/players/skeeve/area.h";

reset(arg) {
  if (!arg) 
    set_light(1);
    short_desc = "Valley";
    long_desc = "You stand at the foot of a high mountain.\n";
    dest_dir =  ({
        LAND + "hill2",    "up",
        LAND + "forest10", "east",
    });
    items = ({
      "up", "There is a big hill above you",
      "hill", "There is a big eagle at the top of the hill",
      "east", "At the end of the valley begins the forest"
    });
}

move(dir) {
   if (!dir) dir=query_verb();
   return (this_player()->query_stay_garden() && (dir=="up") ) ?
     ::move("west") : ::move(dir);
}
