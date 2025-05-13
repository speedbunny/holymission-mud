inherit "room/room";

void reset(int arg)
  {clone_list=({1,1,"dwarf","/players/kawai/monst/dsmith",0});
  set_light(1);
  short_desc = "Small hut";
  long_desc = "The small building is the home and workplace of the finest, "+
  "and only, smith in the city.  Around the room are scattered "+
  "tools at chunks of metal used to fashion various items from "+
  "swords to racks to animal traps.  A large pit is in the center "+
  "and in it burns the fire used for heating metal.\n";
  smell = "The air is steamy.";
  property="has_fire";
  dest_dir = ({"players/kawai/areas/dwarves/village17","west"});
  items = ({"tool","A typical metal working tool",
  "building","You are in it",
  "home","Peering into the back rooms, you notice a small living area",
  "rooms","You can't see much other than a bed",
  "bed","It is a normal bed",
  "room","Which one?  This room or the back room?",
  "back room","It is a small living area",
  "this room","You are standing in it",
  "area","It looks like the smith lives there",
  "living area","It looks like the smith lives there",
  "tools","Various tools used to fashion metal objects",
  "anvil","An anvil.  It shows the wear of many years use",
  "bucket","It contains water to help cool the metal",
  "metal","Just an incredibly heavy piece of iron",
  "trap","A basic animal trap",
  "traps","A few traps line the back of the wall as a display of the smith's skill",
  "rack","A simple metal storage rack",
  "rack","The racks, works of the smith you assume, are used to display various items",
  "sword","A fine sword, securely fashioned to the wall",
  "swords","The swords are securely fixed to the wall",
  "wall","The wall has several items on display",
  "walls","The walls have several items on display",
  "items","Various racks, swords, and traps",
  "item","Which item?",
  "chunk","'Tis more than you could ever dream of carrying",
  "fire","It is unusually hot and dangerous",
  "pit","It is where the smith heats his metal"});
  ::reset(arg);
  replace_program("room/room");}

