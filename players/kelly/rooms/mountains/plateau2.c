inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A plateau";
    long_desc="A large rocky plateau.\n"+
      "All around you are steep rocks.\n"+
      "A path leads south and north.\n";

    dest_dir=({
      "players/kelly/rooms/mountains/rocks1","north",
      "players/kelly/rooms/mountains/plateau","south",
   });

   items=({
     "path","It is small and narrow",
   });
}
