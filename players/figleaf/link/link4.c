inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "A misty twilight";
  long_desc =
        "The trail at this point seems to rise to both the north and south. You can't be  "+
        "sure, however, because the mist is so dense that you can't see more than about two "+
        "feet from where you stand. Sound is muted and you feel cut off from everything. There "+
        "must be a large body of water nearby to cause so much mist.\n";
 
  dest_dir=({
        "/players/figleaf/link/link5", "north",
        "/players/figleaf/link/link3", "south",                           
  });
  items=({
        "you", "You cannot see yourself",
        "trail" , "Although you can't really see it, you're sure it's still there",
        "mist" , "Swirling clouds that block your vision",
   });                                  

  ::reset();
  replace_program("room/room");
}    
