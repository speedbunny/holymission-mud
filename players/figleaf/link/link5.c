inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "A narrow trail";
  long_desc =
        "You stand on a narrow trail that descends to the south, vanishing into swirling "+
        "mist. Strange sounds seem to eminate from that direction. To the north the trail "+
        "just worms it's way between the trees. The air is thick with the smell of pine and "+
        "spruce.\n";
 
  dest_dir=({
        "/players/figleaf/link/link6", "north",
        "/players/figleaf/link/link4", "south",                           
  });
  items=({
        "you", "You cannot see yourself",
        "forest", "A thick forest of fir trees",
        "fir" , "Fir trees that have grown in thick",
        "trees" , "Fir trees that have grown in thick",
        "trail" , "A narrow trail that obviously is not well used",
        "mist" , "Swirling clouds that prevent you from seeing further",
   });                                  

  clone_list=({
        1, 4, "wasp", "/players/figleaf/link/wasp", 0,
   });

  ::reset();
  replace_program("room/room");
}    
