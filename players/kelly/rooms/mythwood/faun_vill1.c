inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A open place in the Fauns' village";
    long_desc="You are standing on a place in a village "+
      "inhabited of fauns.\n";
    dest_dir=({
    "players/kelly/rooms/mythwood/mythpath7","west",
    "players/kelly/rooms/mythwood/faun_mark1","east",
   });
 
}
