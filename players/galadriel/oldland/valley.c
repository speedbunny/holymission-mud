inherit "room/room";

#include "/players/skeeve/area.h";

reset(arg) {
    if (!arg) {
    set_light(1);
    short_desc = "Valley";
    long_desc = "You are standing in a small valley.\n";
    dest_dir =   ({
        LAND + "forest9", "east",
        LAND + "cave", "west",
       });
    items = ({
      "west", "There is a dark cave. It seems to be very dangerous",
      "cave", "What a monster will live in this cave?",
      "east", "At the end of the valley begins the forest"
    });
   }
}

move(dir) {
   if (!dir) dir=query_verb();
   if ((this_player()->query_stay_garden()) && (dir=="west"))
     return ::move("east");
   else
     return ::move(dir);
}
