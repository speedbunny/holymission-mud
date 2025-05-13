/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Front of the Vampire Castle";
    long_desc=
    "You are standing at the front of the huge dark castle. It doesn't\n"+
    "seem to be a smart thing to enter with or without an invitation.\n"+
    "Bats fly about the top of the castle towers and you feel a coldness\n"+
    "creep into your heart.\n";
    items=({
      "castle", "Castle of the Vampire King"
    });
    dest_dir=({
      "/players/sherman/darkl7","north",
      "/players/sherman/vtower1", "enter",
    });
    clone_list = ({1,3, "vampire", "/players/colossus/shermans/vampire5", 0});
    ::reset();
    replace_program("/room/room");
}
