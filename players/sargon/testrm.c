inherit "room/room"; 


reset (arg) { 
    if (arg) return; 

    set_light(1); 
    short_desc="A room for testing monsters.";
    long_desc="This room is for testing monsters.  If you are a player\n"
              "you shouldn't be here.  Get some help getting out before\n"
              "its too late.\n";
    dest_dir=({
     });
}
     
