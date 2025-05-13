inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "A narrow trail";
  long_desc =
        "You are standing on a narrow trail running north and south between the trees "+
        "of a dense forest. To the north you hear the gentle sound of lapping water. The "+
        "air is thick with the smell of pine and spruce.\n";
 
  dest_dir=({
        "/players/saffrin/area/fairy/bank/bank18", "north",
        "/players/figleaf/link/link5", "south",                           
  });
  items=({
        "you", "You cannot see yourself",
        "forest", "A thick forest of fir trees",
        "fir" , "Fir trees that have grown in thick",
        "trees" , "Fir trees that have grown in thick",
        "trail" , "A narrow trail that obviously is not well used",
   });                                  

  ::reset();
  replace_program("room/room");
}    
