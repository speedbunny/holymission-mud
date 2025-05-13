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
    "and below.  The hallway continues north and south.  To the north you\n"+ 
    "see some imposing figures.\n"; 



    dest_dir = ({ 


      "players/sargon/area/b3.c", "north",
       "players/sargon/area/b5.c", "south"

    }); 

}
