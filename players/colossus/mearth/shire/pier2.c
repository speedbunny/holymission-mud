inherit "/room/room";
void init(){
    ::init();
    "/players/colossus/mearth/shire/boat_preload"->make();
}


void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "At the pier";
    long_desc =
    "You arrive at a small pier. There are several boats docked here and\n"+
    "to the far west you think you see the outline of an island. To the east\n"+
    "is the road leading back to town.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/pier1", "east",
    });

    items= ({
      "pier", "A small pier where several boats are docked at",
      "boats", "These boats are small but they seem seaworthy",
      "road", "The road that leads back to the center of town",
    });

}

