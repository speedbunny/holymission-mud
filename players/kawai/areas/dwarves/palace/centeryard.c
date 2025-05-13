inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Courtyard";
  long_desc = "You stand in the center of a beautiful courtyard.  Standing "+
  "tall in the center is a large marble statue of the King.  Obviously, "+
  "it is much larger than life...several times larger, actually. "+
  "Nevertheless, it is a beautiful statue.  In the surrounding area "+
  "flowers bloom and sculptured shrubs abound.  The courtyard "+
  "continues east and west.\n";
  smell = "The air sweet";
  dest_dir = ({"players/kawai/areas/dwarves/palace/westyard","west",
  "players/kawai/areas/dwarves/palace/eastyard","east",
  "players/kawai/areas/dwarves/palace/swalk","south",
  "players/kawai/areas/dwarves/palace/nwalk","north"});
  items = ({"cave","It is large and illuminated by a strange source",
  "courtyard","It is beautifully decorated.  In the center is a large statue",
  "statue","It is a large statue of the king....obviously not life-sized",
  "flowers","Roses, tulips, lilacs...the usual sort",
  "rose","'Tis a rose...and a beautiful one",
  "roses","Rows of various colored rose bushes adorn the yard",
  "tulip","A tulip!  How lovely!",
  "tulips","You've always thought that Two lips are better better than one!\n"+
  "(Bad pun, I know...)",
  "lilac","The lilac is sweetly scented",
  "lilacs","The lilac bush is in full bloom and a nice deep lavender color",
  "castle","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though",            
  "shrubs","lots of shrub sculptures",
  "shrub","Look! Its a shrub sculpture of a....a.....shrub!",
  "flower","A rose, how lovely!",
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though"});
  ::reset(arg);
  replace_program("room/room");}

        

