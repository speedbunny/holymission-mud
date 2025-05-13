inherit "room/room";
 
object obj;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A field";
    long_desc="You're on a field.\n"+
    "To the west a path starts into the swamps and to east there is"+
    " a path\nthourgh thick bushes.\n";
 
    dest_dir=({
    "players/kelly/rooms/mythwood/clear5","east",
    "players/kelly/rooms/swamps/sw_entr","west",
   });
 
}
 
