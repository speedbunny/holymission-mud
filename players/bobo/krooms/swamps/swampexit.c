inherit "room/room";
 
object obj;
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="An entrace to the swamps";
  long_desc="You're at an entrance to the magic swamps.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/path1","north",
    "players/kelly/rooms/swamps/swamp14","south",
  });
}
