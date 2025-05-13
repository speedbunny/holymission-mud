inherit "room/room";

void reset(int arg) 
  {short_desc="Slope";
  long_desc="You are somewhere beneath the surface, although not too far down at "+
  "the moment, for you can still see light from above.\n";
  dest_dir=({"players/kawai/areas/slope2","down",
  "players/kawai/games/mineroom","east",
  "players/kawai/areas/link","up"});
  items=({"cave","You stand inside a small cave, formed naturally out of the surrounding rock",
  "room","You stand inside a small cave, formed naturally out of the surrounding rock",
  "rock","The rock forms a natural shelter",
  "passage","It leads further into the cave",
 "area","It slopes downward",
 "light","You think that the passage opens up to the surface above",
 "floor","Ooooh...."});
  set_light(1);
  smell="The air is damp and smells of animal waste";
  ::reset(arg);
  replace_program("room/room");}

