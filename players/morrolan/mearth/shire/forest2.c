inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "In the Hobbit forest";
    long_desc =
    "The trees seem to have a life of their own here. It's scary but you think\n"+
    "you saw one of them looking at you. Maybe roaming so far into the woods\n"+
    "may not be such a good idea.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest1", "east",
      "/players/colossus/mearth/shire/forest5", "south",
    });

    items = ({
      "trees", "Large trees that seem to be alive somehow",
      "tree", "You're not sure but you could have sworn that tree moved",
      "branches", "Wide and outstretching branches",
    });
}
