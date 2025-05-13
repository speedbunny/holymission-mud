inherit "/room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "In the Hobbit forest";
    long_desc =
    "You reach the center of the forest. The unearthly silence really\n"+
    "begins to fray your nerves. The trees wave back and forth in a dance\n"+
    "to the rhythm of the wind. You get the impression that this is one\n"+
    "place that could suddenly explode into action. The trees, while dormant,\n"+
    "seem to be living. The forest gets much darker to the south.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest7", "south",
      "/players/colossus/mearth/shire/forest5", "west",
      "/players/colossus/mearth/shire/forest6", "east",
      "/players/colossus/mearth/shire/forest1", "north",
    });

    items = ({
      "trees",
      "These trees are totally unlike any others that you have seen. With a bit\n"+
      "of imagination you can make out faces, limbs, and other features on the \n"+
      "trees. The only thing you can guess from this is that they are slumbering",
    });
}
