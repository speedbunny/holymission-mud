inherit "room/room";

void reset(int arg) 
  {clone_list=({1,4,"dwarf","/players/kawai/monst/dvet",0});
  set_light(1);
  short_desc = "Small hut";
  long_desc =
  "The long hall is typical of dwarven pride.  While usually not "+
  "festive, they certainly appreciate celebrating a victory with good "+
  "food and ale.  The hall is lined with rows of tables, all showing the "+
  "signs of past celebrations (especially those out of control).\n";
  smell = "The air is fresh.";
  dest_dir = ({"players/kawai/areas/dwarves/village11","west",
  "players/kawai/areas/dwarves/village28","east"});
  items = ({"tables","There are lots of them!",
  "hall","You're standing in it.  What do you want to look at?",
  "axe","It is rusty and worthless",
  "blade","It is rusty and worthless",
  "food","It is all gone...only the oder remains",
  "ale","It is all gone...only a few spilled drinks remain",
  "drinks","There is a shallow puddle of ale on the floor",
  "floor","It is wet and sticky",
  "puddle","You wouldn't want to drink out of it...it might not even be ale!",
  "table","This one has an axe blade buried in it.  Maybe dwarves\n"+
  "celebrate a bit too much...."});
  ::reset(arg);
  replace_program("room/room");}



