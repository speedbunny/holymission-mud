
inherit "room/room";

int tick;
static string text;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Shaka's TestingRoom";
  long_desc="\n The TestingRoom Of Shaka. \n\n"
  + " It might not be much now, but wait and see in a few weeks,\n"
  + " then you will see the real shaka come out it you just might\n"
  + " be impressed, like so many before you !\n\n";
  dest_dir=({"players/shaka/workroom", "work",
             "players/shaka/rooms/central.c", "central"});
}
