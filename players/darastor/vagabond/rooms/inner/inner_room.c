inherit "/room/room";
#define TP   this_player()




void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Inner Guild Room";
    long_desc =
    "This is the Inner Chamber of the Vagabonds Guild.\n"+
    "This vast chamber leads to many parts of the Vagabonds Guild.\n"+
    "To the northeast, east, and southeast is the Guild Armoury, Treasury,\n"+
    "and Weaponary rooms.\n"+
    "To the west, is the Omni Shop.\n"+
    "\n";

    dest_dir = ({
      "/players/nylakoorub/guild/rooms/hallway", "out",
      "/players/nylakoorub/guild/rooms/inner/omni_room", "west",
      "/players/nylakoorub/guild/rooms/inner/trea_room", "east",
      "/players/nylakoorub/guild/rooms/inner/armo_room", "northeast",
      "/players/nylakoorub/guild/rooms/inner/weap_room", "southeast",
    });

    items = ({
      "chamber", "The chamber is undergoing change even as you like at it",
      "walls", "The walls shimmer through the spectrum of the rainbow",
    });


    property = ({"no_fight", "no_steal", "no_fear", "no_sneak",
      "no_cleanup" });
}
