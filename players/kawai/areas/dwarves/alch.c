inherit "room/room";

void reset(int arg) 
  {clone_list=({1,1,"zoggo","/players/kawai/monst/dalch",0});
  set_light(1);
  short_desc = "Small hut";
  long_desc = "This mysterious hut is the home of Zoggo the Alchemist, "+
  "a strange fellow fluent in the mystic arts.  The room is "+
  "overflowing with various tubes and flasks and containers "+ 
  "of every possible substance you could imagine, and then "+
  "some.\n";
  smell = "The air is bland.";
  property=({"has_fire"});
  dest_dir = ({"players/kawai/areas/dwarves/village17","north"});
  items = ({"tool","A typical alchemist's tool",
  "tools","Various tools used to handle chemicals",
  "flasks","Various shaped flasks of all sorts of odd materials",
  "flask","This particular one is labeled 'AIR'",
  "tubes","The tubes are elaborately set up in a strange contraption",
  "tube","This one is labeled 'WATER'"});
  ::reset(arg);
  replace_program("room/room");}
