inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "A narrow trail";
  long_desc =
        "You stand to the north of the main road through Red Rock Junction on a smaller, less "+
        "well travelled trail. The villagers go about their business paying no attention to you. "+
        "North of you is the beginning of a dark forest of fir trees and the trail worms it's way "+
        "between them.\n";
 
  dest_dir=({
        "/players/figleaf/link/link2", "north",                           
        "/players/bobo/krooms/vill/road4", "south",
  });
  items=({
        "you", "You cannot see yourself",
        "forest", "A thick forest of fir trees",
        "fir" , "Fir trees that have grown in thick",
        "trees" , "Fir trees that have grown in thick",
        "trail" , "A narrow trail that obviously is not well used",
        "road" , "The mail road through the village",
        "village" , "Red Rock Junction",
        "villager", "Inhabitants of Red Rock Junction",
  });                                  

  ::reset();
  replace_program("room/room");
}    
