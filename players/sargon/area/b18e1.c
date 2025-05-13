inherit "room/room";


reset (arg) {
    if (arg) return;

    set_light(0);
    short_desc="A dark forest trail.";
    long_desc=
      "The trail is barely visible.  The trees are close to the trail " +
      "and if you're not careful you'll trip over thier roots in the dark." +
      "You get the distince feeling that you are being watched." +
      "The trail continues to the northeast and back to the southwest.\n";
              
    dest_dir=({
              "players/sargon/area/b18e.c", "southwest",
              "players/sargon/area/b18e2.c", "northeast"

   });
items = ({
              "trees", "These are huge old hemlock trees." +
                        "Its amazing how they seem to create " +
                        "their own environment",
              "ferns", "The forest floor is covered with ferns " ,
              "trail", "This trail looks well worn, but it is moist also",
              "roots", "These hemlock roots are massive, probably 300 years old",
            });

}
