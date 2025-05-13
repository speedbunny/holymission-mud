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
    short_desc = "A forest trail";

    long_desc = 
    "The forest seems less dense up ahead.  You feel the presence of\n"+
    "something you can't quite make out.  It is still and quiet here\n"+
    "with the sounds of birds and forest creatures absent.\n";
    "north.\n"; 
    dest_dir = ({ 

        "players/sargon/area/b14.c", "south",
        "players/sargon/area/b12.c", "north"
      
    }); 

}
