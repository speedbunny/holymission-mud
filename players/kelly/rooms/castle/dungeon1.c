inherit "room/room";

status lever_up;
 
reset(arg) {
  if (arg) return;
  lever_up=1;
  set_light(1);
  no_castle_flag=1;
  short_desc="In the dungeon";
  long_desc="You're in the dungeon of the castle.\n"+
   "Stairs lead upwards into the cellar.\n"+
   "There's a lever at the wall.\n";
  dest_dir=({
    "players/kelly/rooms/castle/cellar10","up",
    "players/kelly/rooms/castle/dungeon2","west",
   });
  items =({
     "lever","It seems that you can throw the lever",
  });
}
 
init() {
::init();
  add_action("throw","throw");
}

throw(str) {
  string opens,closes;
  opens="The door opens with a shrill sound.\n";
  closes="The door closes with a shrill sound.\n";
  if(str!="lever") return;
  write("As you throw the lever you hear a shrill sound.\n");
  say("As "+this_player()->query_name()+" throws the lever you hear a shrill sound.\n");
  if(lever_up) {
    tell_room("players/kelly/rooms/castle/dungeon2",opens);
    tell_room("players/kelly/rooms/castle/dungeon3",opens);
    tell_room("players/kelly/rooms/castle/dungeon4",opens);
    tell_room("players/kelly/rooms/castle/cell2",opens);
    tell_room("players/kelly/rooms/castle/cell3",opens);
    tell_room("players/kelly/rooms/castle/cell1",opens);
  }
  else 
  {
    tell_room("players/kelly/rooms/castle/dungeon2",closes);
    tell_room("players/kelly/rooms/castle/dungeon3",closes);
    tell_room("players/kelly/rooms/castle/dungeon4",closes);
    tell_room("players/kelly/rooms/castle/cell1",closes);
    tell_room("players/kelly/rooms/castle/cell2",closes);
    tell_room("players/kelly/rooms/castle/cell3",closes);
  }
  lever_up=!lever_up;
  return 1;
}

query_lever_up() { return lever_up; }


    
