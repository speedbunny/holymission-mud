inherit "/room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "In the Hobbit forest";

    long_desc =
    "You are in a thick forest. Towards the east the trees grow too thickly\n"+
    "for you to pass. There are paths leading to the west and south. The forest\n"+
    "seems strangely quiet here though.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest1", "west",
      "/players/colossus/mearth/shire/forest6", "south",
    });

    items = ({
      "forest", "A forest filled with trees that grow thickly together",
      "trees", "The bunch of trees to the east are all bunched up and\n"+
      "prevent any further passage east",
      "paths", "These paths are trodden but not too distinct",
    });
}

