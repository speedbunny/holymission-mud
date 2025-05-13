inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(0);
    no_castle_flag=1;
    short_desc="A cave";
    long_desc="You're in a dark cave.\n"+
      "To the south you can see light.\n"+
      "There are trails in the cave-ground.\n";
    dest_dir=({
    "players/kelly/rooms/wastelands/cave2","north",
    "players/kelly/rooms/wastelands/seashore","south",
   });
 
   items=({
   "trails","It seems that a really big beast has made this trails",
   });
}
 
