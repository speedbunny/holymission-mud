/* Edited by Colossus 031094 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "First level of the Vampire Castle";
    long_desc=
    "You are in the stairwell of the Vampire castle. There is a window\n"+
    "overlooking the land and which allows in a cold draft that chills\n"+
    "you. The stairs continue up and down.\n";
    items=({
      "window", "The window overlooks a dark and creepy landscape.\n"+
      "It also allows a cold draft in",
    });
    dest_dir=({
      "/players/sherman/vtower3","up",
      "/players/sherman/vtower1","down"
    });
}
