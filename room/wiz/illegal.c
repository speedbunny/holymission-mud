inherit "/room/room";

void reset(int iArg) {
    if(!iArg) {
        set_light(1);

        short_desc = "The 'illegal' room";
        long_desc = "You have entered a really dark room. This is the \
place where discussions about illegal things find their place. The idea \
of this room is 'not' to board offences, but to get a good mud without \
unfair, overpowered or bad stuff.\n";

        dest_dir= ({
            "/room/wiz/coding_room", "down",
        });

        items= ({
            "wall", "A standard mud-wall",
        });

        property = ({
            "no_fight",           
            "no_sneak",              
            "no_steal",   
            "no_teleport",
        });
           
        clone_list = ({
            1, 1, "board", "/boards/wiz/illegal" , 0,
        });
    }
    ::reset(iArg);
}
 
void init() {
  if(!this_player()->query_immortal() || !interactive(this_player())) {
    write("You feel dizzy and fall down the stairs!\n");
    this_player()->move_player("down#/room/wiz/coding_room");
    return;
  }   
  else
    ::init();
}
