/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc="Inside a big cave";
    long_desc=
    "You are at the start of a cavernous cave. It extends\n\
as far as your eyes can see and howls and sounds of\n\
creatures which promise pain and death.\n";
    items=({
      "cave", "A huge cave which extends as far as the eyes can see",
    });
    dest_dir=({
      "/players/sherman/hills/cave5","east",
      "/players/sherman/hills/hill6","west"
    });
}
