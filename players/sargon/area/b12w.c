inherit "room/room"; 

reset(arg) { 
    if (arg) return; 
  ::reset(arg); 
  if(!present("ewok")) 
{ 
move_object(clone_object("players/sargon/monster/ewok.c"),this_object()); 
move_object(clone_object("players/sargon/monster/ewok.c"),this_object());
move_object(clone_object("players/sargon/monster/ewok.c"),this_object());
} 

    set_light(1); 
    short_desc = "A clean pure white room"; 

    long_desc = 
    "The forest is dense all around you.  Furry little creatures stare at\n"+ 
    "you with there beady little brown eyes.  The path continues to the\n"+ 
    "north.\n"; 
    dest_dir = ({ 
        "players/sargon/area/b12.c", "east"
      
    }); 

}
