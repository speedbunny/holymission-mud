inherit "room/room"; 


reset (arg) { 
    if (arg) return; 

    set_light(1); 
    short_desc="A well worn path in the thick forrest"; 
    long_desc="This is a dark and overgrown path through a thick forrest.\n"
              "Above you there is a tree canopy which blocks out the strong\n"
              "suns rays.  Was that something you saw moving in the bushes\n"
              "up ahead.  The path continues north.\n"; 
    dest_dir=({
              "players/sargon/area/b16.c", "north",
              "players/sargon/area/b18.c", "south"

     });
}
     
