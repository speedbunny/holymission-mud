inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  no_castle_flag=1;
  short_desc="On a castle yard";
  long_desc="You're standing on a yard behind the castle. To the south you see two \n"+
   "towers. There's a hole leading down.\n";
  dest_dir=({
    "players/kelly/rooms/castle/corridor2","south",
    "players/kelly/rooms/mountains/stonepath1","northwest",
    "players/kelly/rooms/mountains/stonepath2","northeast",
    "players/kelly/rooms/castle/cellar11","down",
   });
   items=({
    "hole","It's dark and a cold and wet wind blows out of it",
   });
}
 
