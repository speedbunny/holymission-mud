inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "The guild discussion room";
        long_desc = "This is the guild discussion room of Holy Mission. \
Wizards come here to discuss about the problems of the guilds and to \
leave notes about their opinions.\n";

        dest_dir= ({
            "/room/wiz/coding_room", "south",
        });

        items= ({
            "wall", "A standard mud wall",
        });

        property = ({
            "no_fight",           
            "no_sneak",              
            "no_steal",   
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/wiz/guild" , 0,
        });
    }
    ::reset(iArg);
}
 
void init() {
  if(!this_player()->query_immortal() || !interactive(this_player())) {
    write("You feel dizzy and run for fresh air.\n");
    this_player()->move_player("south#/room/wiz/coding_room");
    return;
  }   
  else
    ::init();
}
