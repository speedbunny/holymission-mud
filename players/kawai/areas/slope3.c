inherit "room/room";

void reset(int arg) 
  {short_desc="Slope";
  long_desc="You are somewhere far underground.  You can see nothing up the passage, "+
  "and can only hear the distant sound of rushing water from below.\n";
  dest_dir=({"players/kawai/areas/slope2","up",
  "players/kawai/areas/passage1","down"});
  items=({"cave","You stand inside a small cave, formed naturally out of the surrounding rock",
  "room","You stand inside a small cave, formed naturally out of the surrounding rock",
  "rock","The rock forms a natural shelter",
  "passage","It leads further into the cave",
  "area","It slopes downward",
  "light","You think that the passage opens up to the surface above",
  "floor","Ooooh...."});
  smell="The air is damp and smells of animal waste";
  ::reset(arg);
  replace_program("room/room");}

