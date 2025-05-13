inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A road to Mythwood";
    long_desc = "You are traveling on a road leading to Mythwood. " +
                "The road becomes a path to the north, and returns " +
                "to the town to the south.\n";
    dest_dir=({
    "players/kelly/rooms/mythwood/mythpath8","north",
    "players/kelly/rooms/vill/road8","south",
   });
}
 
