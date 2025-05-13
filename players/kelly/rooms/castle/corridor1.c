inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a corridor";
  long_desc="You're in a corridor.There are stairs leading into a tower.\n"+
   "There is a sign attached to the wall beside the stairs.\n";
  dest_dir=({
    "players/kelly/rooms/castle/castle_hall","south",
    "players/kelly/rooms/castle/corridor2","north",
    "players/kelly/rooms/castle/tower11","up",
   });
   items=({
    "sign","You can read it",
   });
}
 
init() {
::init();
  add_action("read","read");
}

read(str) {
  if(str!="sign") return;
  write("The sign�s pointing up and reading : Hall of Fame, this way.\n");
  return 1;
}

