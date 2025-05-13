inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {

        set_light(1);

        short_desc = "MUD Advertisement room";
        long_desc = "This is one of the tackiest rooms you have ever seen \
on the Holy Mission. Colorful advertisements for all kinds of places are \
tacked onto the walls and you think that you have just entered a tourist \
office. A brown cork board stands in the middle of the room with notes \
neatly tacked to it. People use it to advertise their favourite MUDs, \
maybe you could make an addition.\n";
        dest_dir = ({
            "/room/adv_guild", "west",
        });

        property = ({
            "no_fight",
            "no_sneak",
            "no_steal",
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/player/mudads" , 0,
        });
    }
    ::reset(iArg);
    replace_program("/room/room");
}
