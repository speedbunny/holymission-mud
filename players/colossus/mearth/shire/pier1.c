inherit "room/room";

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Harbor road";
    long_desc =
    "You are on a path that connects the main street of the Shire to\n"+
    "a pier to your west. From this distance you can make out a small\n"+
    "pond.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/pier2", "west",
      "/players/colossus/mearth/shire/main3", "east",
    });

    items = ({
      "path", "A short path that connects the main street and pier",
      "pier", "A pier where boats dock and where you can probably get a boat",
      "pond", "A small pond where hobbits probably go fishing",
    });

}
