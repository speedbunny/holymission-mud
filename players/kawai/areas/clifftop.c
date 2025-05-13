inherit "room/room";

void reset(int arg) 
  {smell = "The air is damp and musty.";
  dest_dir = ({"players/kawai/areas/wfcave","northeast",
  "players/kawai/areas/cliff4","down"});
  short_desc = "Cave entrance";
  long_desc = 
  "You are at the entrance to an underground river.  The water flows under "+
  "your feet and forms a waterfall behind you.  Looking deeper into the cave "+
  "you see it bend sharply, but notice an odd light from within.\n";
  items = ({"water","It flows swiftly underneath you",
  "river","It isn't very deep, but flows rapidly",
  "light","It radiates from an unknown source",
  "cave","It's not very big, and the floor is covered with water",
  "waterfall","It's a long way down!"});
  clone_list=({1,1,"bat","obj/monster",({"set_name","giant bat",
  "set_alias","bat",
  "set_level",15,
  "set_whimpy",-1,
  "set_short","A Giant Bat",
  "set_long","One word...BIG!\n"})});				 
  ::reset(arg);
  replace_program("room/room");}
