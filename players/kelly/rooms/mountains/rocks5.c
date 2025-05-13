inherit "room/room";

object mon;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A rockpath";
    long_desc="You're on a path in the rocks.\n"+
      "To both sides the mountains raise high up into the sky.\n";

    dest_dir=({
      "players/kelly/rooms/mountains/rocks4","south",
      "players/kelly/rooms/mountains/rocks6","northeast",
   });
}
