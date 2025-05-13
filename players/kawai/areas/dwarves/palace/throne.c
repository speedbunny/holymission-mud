inherit "room/room";

void reset(int arg)
  {clone_list=({1,1,"king","/players/kawai/monst/dking",0});
  set_light(1);
  short_desc = "Throne Room";
  long_desc = "Stunning is the only word to describe what you see.  Elaborate "+
  "tapestries and trimmings line the walls, and reflect the light "+
  "in wondrous ways.  At the far end of the hall, is the kings "+
  "throne--hand crafted in solid gold, lined with jewels and covered "+
  "in the finest velvet in all the land.  A large doorway leads back "+
  "to the castle.\n";
  smell = "The air smells of spice and incense";
  dest_dir = ({"players/kawai/areas/dwarves/palace/anteroom","west"});
  items = ({"tapestries","Large, woven designs hang from the ceiling",
  "tapestry","This one looks depicts an ancient battle",
  "trimmings","Gold and silver linings are everywhere!",
  "trimming","Its a beautiful touch",
  "doors","Huge oak doors",
  "door","Pretty neat, eh?",
  "doorway","A large set of doors leading east",
  "throne","Its beautiful...probably worth a fortune but weighs a ton",
  "jewels","Assorted precious stones",
  "gold","Looks familiar...",
  "hall","It is the throne room!",
  "gold","The gold glimmers in the light",
  "silver","The silver glimmers in the light",
  "chamber","The chamber is one of the entrance rooms of the castle",
  "wall","The wall is decorated and glimmers in the light",
  "walls","The walls glimmer in the light",
  "castle","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though",
  "jewel","A rather large diamond...",
  "diamond","It is securely fixed to the throne, so don't even think of taking it",
  "stones","Various Gemstones",
  "stone","Don't even think about taking it",
  "ceiling","You are nearly blinded by the light bouncing off the walls and ceiling.\n"+
  "It seems that nearly everything is either gold or silver or other precious item",
  "velvet","Its soft and plush--what you would expect from a king",
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though"});
  ::reset(arg);
  replace_program("room/room");}


