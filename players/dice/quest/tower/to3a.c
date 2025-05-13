inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(0);
    short_desc = "Small hall";
    no_castle_flag = 1;
    no_obvious_msg="";
        "You are standing between the walls of the throne room\n"+
        "and the outer walls. It's very narrow here.\n";

          items = ({
               "room","The beautiful decorated room can't be seen from here",
               "throne","It dissapeared after it threw you off",
               "walls","They are solid and thick",
               "dust","It's lying on everything",

              });
           dest_dir = ({ "players/dice/quest/tower/to1","up"
                      });
  smell = "The air is dull here.";
}
}
