inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Vagabond Weaponry";
    long_desc =
    "This is the weaponry of the vagabonds. Here you can drop off weapons\n"+
    "for your fellow guild members. The room is fairly large to accomodate\n"+
    "all the articles that may be dropped off.\n";

    dest_dir = ({
      "/players/nylakoorub/guild/rooms/inner/inner_room", "northwest",
    });


    property = ({ "no_teleport", "no_cleanup",
    });

}
