inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A path"; 
    long_desc="You are on a path in the mountains.\n";
 
    dest_dir=({
      "players/kelly/rooms/mountains/specialpath1e","northwest",
      "players/kelly/rooms/mountains/path1","southeast",
   });
   
}
