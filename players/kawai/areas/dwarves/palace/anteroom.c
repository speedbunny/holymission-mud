inherit "room/room";

void reset(int arg) 
  {set_light(1);
  short_desc = "Inner Chamber";
  long_desc = "You are now in the elaborate Inner Chamber "+
  "of the palace.  Large tapestries hang from along the walls "+
  "and gold and silver trimmings line everything in sight.  A tremendous "+
  "looking doorway (at least for dwarves) opens to the east, "+
  "leading into the throne room.\n";
  smell = "The air smells of spice and incense";
  dest_dir = ({"players/kawai/areas/dwarves/palace/nchamber","northwest",
  "players/kawai/areas/dwarves/palace/schamber","southwest",
  "players/kawai/areas/dwarves/palace/throne","east"});
  items = ({"tapestries","Large, woven designs hang from the ceiling",
  "tapestry","This one looks depicts an ancient battle",
  "trimmings","Gold and silver linings are everywhere!",
  "trimming","Its a beautiful touch",
  "gold","The gold glimmers in the light",
  "silver","The silver glimmers in the light",
  "throne room","As you peer through the doorway, you get a glimpse of a\n"+
  "large and elaborately decorated hallway.  At the far end is a throne",
  "throne","You'd probably get a better look from inside",
  "hallway","You'd probably get a better look from inside",
  "doors","Huge oak doors",
  "door","Pretty neat, eh?",
  "doorway","A large set of doors leading east",
  "castle","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though",
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though"});
  ::reset(arg);
  replace_program("room/room");}
