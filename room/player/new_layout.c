inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "New Mud Layout Discussion";
        long_desc = "The mud will be going through some changing times in \
the near future and we, as the mud administrators, would like to lay out \
some of these designs and get player feedback as to how they should, or \
should not proceed. In the near future the new town layout will be \
availible from this room. For now, please just post your ideas and \
comments regarding one more mud reorganization. Note: With this reorg \
there will be help files containing full and partial mud maps. Individual \
wizards will be encouraged to supply maps of thier areas, with the \
precaution that area maps do not infringe on or offer quest information. \
Check back here for more details as they are known.\n";

        dest_dir = ({
            "/room/church", "out"
        });

        property = ({
            "no_fight",
            "no_sneak",
            "no_steal",
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/player/new_layout" , 0,
        });
    }
    ::reset(iArg);
    replace_program("/room/room");
}
