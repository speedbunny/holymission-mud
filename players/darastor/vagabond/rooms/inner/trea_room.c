inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Guild treasury";
    long_desc =
    "Here you can drop of stuff that's neither armour or weapons for other\n"+
    "guild members. The room is fairly large and has the same shifting quality\n"+
    "that characterizes the other rooms of the Vagabond Guild.\n";

    dest_dir = ({
      "/players/nylakoorub/guild/rooms/inner/inner_room", "west",
    });


    property = ({ "no_teleport", "no_cleanup",
    });

}
