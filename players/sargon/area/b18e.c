inherit "room/room";


reset (arg) {
    if (arg) return;

    set_light(1);
    short_desc="A forest trail.";
    long_desc=
              "The trail gets darker here.  The trees are closer to the trail \n" +
              "which looks less well traveled.  The air is damp and the ground moist.\n" +
              "The sun is blocked out by the canopy of the trees and ferns blanket\n" +
              "the forest floor.  The trail continues to the northeast and\n"+
               "back to the southwest.\n";
    dest_dir=({
              "players/sargon/area/b19.c", "southwest",
              "players/sargon/area/b18e1.c", "northeast"
             
   });
items = ({
              "trees", "These are huge old hemlock trees." +
                        "Its amazing how they seem to create " +
                        "their own environment",
              "ferns", "The forest floor is covered with ferns " ,
             
              "trail", "This trail looks well worn, but it is moist also",
              
            });

}
