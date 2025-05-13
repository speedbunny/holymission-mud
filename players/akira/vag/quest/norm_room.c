inherit "room/room";

/* the norm room is for players who completed quest */



void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "The 4th";
    long_desc =
    "Just another part of the 4th, where portal open to \n"+
    "different realities.\n"+
    "\n";

    dest_dir = ({
      "/players/akira/vag/quest/q_connect",
      "east",
    });

    property = ({ "vag_quest", "no_teleport" });
}
