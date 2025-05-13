/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Path east of Crossroads";
    long_desc=
    "To the west is the crossroads. To the east you hear some sounds coming\n"+
    "from what looks like a small house. To the north you see some mountains\n"+
    "that look like jagged teeth. All in all, the sight in front of you is not\n"+
    "a pretty one.\n";
    items=({
      "house","The house looks like a bar"
    });
    dest_dir=({
      "/players/sherman/hills/hill1","north",
      "/players/sherman/darkl2","west",
      "/players/sherman/vampirebar","east" 
    });
}
