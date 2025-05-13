inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "A narrow trail";
  long_desc =
        "You are standing at the edge of a forest that stretches away into darkness to the north. "+
        "The trail worms it's way between the trees and vanishes. To the south you can see Red Rock "+
        "Junction in the distance.\n";
 
  dest_dir=({
        "/players/figleaf/link/link3", "north",                           
        "/players/figleaf/link/link1", "south",
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
