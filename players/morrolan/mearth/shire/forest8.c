inherit "/room/room";

void reset(int arg){
    if(arg) return;
    set_light(0);
    short_desc = "In the Hobbit forest";
    long_desc =
    "Trees, trees, and more trees. You cannot believe how dense this forest\n"+
    "is. The trees here are definitely humanoid too. There's no question about\n"+
    "seeing humanoid features in these trees. The trees here have grown twisted\n"+
    "and gnarled though. There's a pervading sense of evilness through this area\n"+
    "of the forest. It might be best to leave before you meet something unpleasant.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest7", "east",
      "/players/colossus/mearth/shire/forest5", "north",
    });

    items = ({
      "trees", "Very very humanoid trees though they are twisted and gnarled",
    });
    clone_list = ({ 1,1, "huorn", "/players/colossus/mearth/shire/huorn", 0});
    ::reset();
    replace_program("room/room");
}
