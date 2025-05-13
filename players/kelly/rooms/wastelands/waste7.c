inherit "room/room";
 
object obj;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n";
    dest_dir=({
    "players/kelly/rooms/wastelands/waste9","south",
    "players/kelly/rooms/wastelands/waste6","west",
    "players/kelly/rooms/wastelands/waste4","north",
   });
 
   obj=clone_object("/obj/torch");
   move_object(obj,this_object());
}
 
 
