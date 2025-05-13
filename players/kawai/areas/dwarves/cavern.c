inherit "room/room";

void reset(int arg)
  {clone_list=({1,2,"guard","/players/kawai/monst/dguard",0});
  set_light(1);
  short_desc = "Entrance to Dwarf City";
  long_desc = "You stand above a small, underground city of sturdy huts.  Below, you "+
  "see scores of dwarves going about their chores, while little ones play "+
  "in the fields. Above, you only see a strange glow, illuminating the cave "+
  "and providing light for a small field of wheat next to the village.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village1","south",
  "players/kawai/areas/dwarves/entrance","north"});
  items = ({"cave","It is large and illuminated by a strange source",
  "passage","It is small and barely lit",
  "wheat","It sways slowly in the breeze...",
  "glow","The rock that makes up the ceiling of the cave radiates a soft light",
  "rock","Some of it glows and illuminates the cave",
  "ceiling","It is made of some sort of illuminating rock",
  "children","They look happily at play",
  "light","It comes from an unknown source", 
  "huts","Various sized buildings..",
  "dwarves","They look very busy",
  "field","It is a wheat field",
  "fields","Large fields of wheat",
  "village","A quaint little town, isn't it",
  "city","Charming..."});
  ::reset(arg);
  replace_program("room/room");}


