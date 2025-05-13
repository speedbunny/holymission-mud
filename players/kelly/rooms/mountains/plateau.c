inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A plateau";
    long_desc="A large rocky plateau.\n"+
      "All around you are steep rocks.\n"+
      "A small and narrow path leads southeast.A ravine leads down to a plateau.\n";

    dest_dir=({
      "players/kelly/rooms/mountains/plateau1","down",
      "players/kelly/rooms/mountains/plateau2","north",
      "players/kelly/rooms/mythwood/plateau1","southeast",
   });

   items=({
     "path","It is small and narrow",
     "ravine","It leads down to another rocky plateau",
   });
}
