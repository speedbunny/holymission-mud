/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Ending of the dark path";
    long_desc=
    "You are traveling on a dark path that goes south and east.\n"+
    "Like all other paths in this region, there are plenty of\n"+
    "sharp stones and thorny bushes that punish your feet.\n"+
    "Towards the south you spot a huge castle. It is now quite\n"+
    "evident that the residents are not normal people.\n";
    items=({
      "path","Still the dark path",
      "castle", "The castle looms ominously to the south and it has tall\n"+
      "fang-like towers",
    });
    dest_dir=({
      "/players/sherman/darkl6","east",
      "/players/sherman/darkl8","south"
    });
}
