inherit "room/room";

void reset(int arg) 
  {short_desc="Slope";
  long_desc="You are somewhere underground, and from the little light that reaches "+
  "from above, you can tell you are far below the surface.\n";
  set_light(1);
  dest_dir=({"players/kawai/areas/slope3","down",
  "players/kawai/areas/slope1","up"});
  items=({"cave","You stand inside a small cave, formed naturally out of the surrounding rock",
  "room","You stand inside a small cave, formed naturally out of the surrounding rock",
  "rock","The rock forms a natural shelter",
  "passage","It leads further into the cave",
  "area","It slopes downward",
  "light","You think that the passage opens up to the surface above",
  "floor","Ooooh...."});
  smell="The air is damp and smell of animal waste";
  ::reset(arg);
  replace_program("room/room");}

