inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="Mountain top";
    long_desc="You're at the top of the mountain!\n";
    dest_dir=({"players/cashimor/rooms/deadend","south"});
    items=({"top","Almost the highest: only the magetower is higher.."});
  }
}
