inherit "room/room";

void reset(int arg) 
  {set_light(1);
  short_desc = "Underground Cavern";
  long_desc = 
  "Never have you seen such a beautiful display of nature as this.  You "+
  "stand at the entrance of a magnificent underground cavern, formed by "+
  "centuries of the flow of an underground river.  A waterfall flows into a "+
  "clear pool from a small cave high upon the cliff face, and you feel the "+
  "refreshing spray on your face.  The cave is illuminated by some unknown "+
  "light source, but the effect is stunning.\n";
  smell = "The air is crisp and refreshing.";
  dest_dir = ({"players/kawai/areas/wpass","northeast",
  "players/kawai/areas/cliff1","up",
  "players/kawai/areas/pool","dive"});
  items = ({"cavern","It is the most beautiful sight you've ever seen",
  "water","It is clear and refreshing",
  "light","It comes from some unseen source...",
  "pool","The pool is calm and clear.  There appears to be something at the bottom\n"+
  "that you could dive in after",
  "waterfall","It's incredible...there looks like there might be a cave up at the top",
  "cliff","The cliff looks slippery, although climbable with the right equipment",
  "face","The cliff looks slippery, although climbable with the right equipment",
  "cliff face","The cliff looks slippery, although climbable with the right equipment",
  "cave","The cave is the source of the waterfall.  It seems to glow with \n"+
  "a strange light."});
  ::reset(arg);
  replace_program("room/room");}

