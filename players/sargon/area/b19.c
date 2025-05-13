inherit "room/room";


reset (arg) {
    if (arg) return;

    set_light(1);
    short_desc="A forest trail.";
    long_desc=
              "You on a dark and well worn trail through a forest of huge \n" +
              " hemlocks.  The air is damp and the ground moist.\n" +
              "The sun is blocked out by the canopy of the trees and ferns blanket\n" +
              "the forest floor.  The trail forks here, one fork to the northeast and\n"+
               "the other to the northwest.\n";
    dest_dir=({
             "players/sargon/area/b18.c", "north",
              "players/sargon/area/b18w.c", "northwest",
              "players/sargon/area/b18e.c", "northeast",
              "players/sargon/area/b20.c", "south"
   });
items = ({
              "trees", "These are huge old hemlock trees." +
                        "Its amazing how they seem to create " +
                        "their own environment",
              "ferns", "The forest floor is covered with ferns " ,
             
              "trail", "This trail looks well worn, but it is moist also",
              
            });

}
