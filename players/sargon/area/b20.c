inherit "room/room";


reset (arg) {
    if (arg) return;

    set_light(1);
    short_desc="A forest trail.";
    long_desc=
              "You are at the beginning of a dark and well worn trail through a \n" +
              "forest of huge hemlocks.  The air is damp and the ground moist.\n" +
              "The sun is blocked out by the canopy of the trees and ferns blanket\n" +
              "the forest floor.  The trail continues to the north.\n";
    dest_dir=({
              "players/sargon/area/b19.c", "north"
             
     });
items = ({
              "trees", "These are huge old hemlock trees." +
                        "Its amazing how they seem to create " +
                        "their own environment",
               "ferns", "The forest floor is covered with ferns " ,
             
              "trail", "This trail looks well worn, but it is moist also",
              
            });

}
