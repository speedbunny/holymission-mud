inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n";
    dest_dir=({
    "players/kelly/rooms/wastelands/waste3","west",
    "players/kelly/rooms/wastelands/waste7","south",
   });
}
 
