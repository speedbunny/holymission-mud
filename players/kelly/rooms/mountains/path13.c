inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A path";
    long_desc="A path in the mountains. \n";

    dest_dir=({
      "players/kelly/rooms/mountains/path12","down",
      "players/kelly/rooms/mountains/path14","northwest",
   });
}
