inherit "/room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "In the Hobbit forest";
    long_desc =
    "You reach the southern part of the forest, to go further south would\n"+
    "mean chopping through countless trees that grow thickly enough to block\n"+
    "your passage south. To the west you hear a strange rustling.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest8", "west",
      "/players/colossus/mearth/shire/forest9", "east",
      "/players/colossus/mearth/shire/forest4", "north",
    });

    items = ({
      "trees", "The trees just grow too thickly to penetrate",
    });
}
