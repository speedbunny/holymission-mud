inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Vagabond Armoury";
    long_desc =
    "This is the armoury of the vagabonds. Here you can drop off armour\n"+
    "for your fellow guild members. The room is fairly large to accomodate\n"+
    "all the articles that may be dropped off.\n";

    dest_dir = ({
      "/players/nylakoorub/guild/rooms/inner/inner_room", "southwest",

    });

    property = ({ "no_teleport", "no_cleanup", 
    });

}
