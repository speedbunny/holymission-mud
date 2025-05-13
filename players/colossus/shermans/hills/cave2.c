/* Edited by Colossus 070994 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc="Inside a big cave";
    long_desc=
    "You are in another part of this huge cave complex. There is nothing\n\
different between this and any of the other parts of the cave except\n\
for a scratching and clicking sounds which comes from the south.\n";
    items=({
      "cave", "Another part of the huge cave complex",
    });
    dest_dir=({
      "/players/sherman/hills/cave3","south",
      "/players/sherman/hills/cave10","up"
    });
}
