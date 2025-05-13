inherit "room/room"; 

reset(arg) { 
    if (arg) return; 
  ::reset(arg); 
  if(!present("stormtrooper")) 
{ 

} 

    set_light(1); 
    short_desc = "A long white hallway"; 

    long_desc = 
    "You are in a long white hallway with light illuminating from above\n"+ 
    "and below.  The hallway continues north and south.  You can now make\n"+
    "out the figures a little better.  The appear to be standing in front\n"+
    "of a dark place.  You sense a great evil about this place.\n";



    dest_dir = ({ 


      "players/sargon/area/b5.c", "north",
      "players/sargon/area/b7.c", "south"

    }); 

}
