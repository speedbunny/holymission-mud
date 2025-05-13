inherit "room/room";

void reset(int arg) 
  {set_light(1);
  short_desc = "Climbing cliff";
  long_desc = 
  "You are climbing up the face of a steep cliff.  The rock is slick from the moisture "+
  "in the air, and the climb ahead looks difficult.  Fortunately you are still near the "+
  "bottom and your sense of fear has yet to take hold...\n";
  smell = "The air crisp and sweet smelling.";
  dest_dir = ({"players/kawai/areas/cliff2","up",
  "players/kawai/areas/wcave","down"});
  property =({"no_fight","no_steal","no_hide"});
  items = ({"cliff","You are near the bottom of a steep, slick cliff",
  "cave","The cave is very far above you",
  "face","The rock is slippery, but you might be able to climb to the top",
  "rock","The rock is slippery, but you might be able to climb to the top",
  "bottom","At the base of the cliff is a small pool and plenty of hard rocks to land on"
  "cliff face","The cliff face stretches upwards about 30 feet",
  "cavern","The view is lovely, yet frightening, from here",
  "water","Crystal clear and quite refreshing looking",
  "pool","A small pool at the far end of the cave",
  "rocks","Considering where you are, best not look down",
  "waterfall","You're a bit too close for comfort"});
  ::reset(arg);
  replace_program("room/room");}
