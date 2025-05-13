inherit "room/room";

void reset(int arg)
  {set_light(1);
  clone_list=(1,1,"disp","players/kawai/obj/disp",0);
  short_desc = "Small path";
  long_desc = "You're walking down a small path into a wheat field.  To the east, you "+
  "can return to the village.  The field lies to the south, while the rock "+
  "walls of the cave block movement to the north or west.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village5","east",
  "players/kawai/areas/dwarves/field1","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "brush","The thick hedges block entrance to the field",
  "field","The wheat sways gently in the breeze",
  "hedge","It is thick and bushy",
  "hedges","A tiny mole pokes its head out, then returns to the field",
  "mole","Awhh...how cute!",
  "cliff","It towers far above you, and is too steep to climb",
  "rock","You bang your head against it a few times just to make sure it is really rock", 
  "wall","The cliff walls are steep and smooth.  You can't do much with them",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "city","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "walls","The cliff walls are too steep and smooth to climb",
  "dwarf","Rats!  Just missed her...",
  "wheat","It's rather tall and blocks your view."});
  ::reset(arg);
  replace_program("room/room");}


