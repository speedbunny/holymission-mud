inherit "room/room";

void reset(int arg) 
  {clone_list=({1,1,"farmer","/players/kawai/monst/dfarmer",0});
  set_light(1);
  short_desc = "Small hut";
  long_desc = "The small, yet decorative home is the dwelling of the cities "+
  "most successful farmer (probably because he is the only one "+
  "and cornered the market!).  Paintings adorn the walls of this "+
  "single room abode, as well as a small table and bed in the center\n ";
  smell = "The air is sweet and fresh.";
  dest_dir = ({"players/kawai/areas/dwarves/village17","east"});
  items = ({"paintings","Various paintings of relatives",
  "table","A plain table",
  "painting","This one is of the king",
  "bed","A small, yet comfortable looking bed"});
  ::reset(arg);
  replace_program("room/room");}


