inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Hall";
    no_castle_flag = 1;
    long_desc =
            "You are at the bottom of the tower.\n"+
            "It seems that this tower once belonged to a whealthy man with \n"+
            "lots of devoted servants. Nobody is living here now however.\n"+
            "The entire tower seems deserted\n";

            dest_dir = ({ "players/dice/quest/tower/to2","up",
            "players/dice/workroom","out",
            });


          items = ({
     "tower","A dark but not big tower",
     "man","It seems like he left with his servants"
     "wealthy man","It seems like he left the tower with his servants",
     "room","It's entirly empty",

              });

  smell = "The air is fresh.";
}
