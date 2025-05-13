/* Blade's Portal Room */
/* Coded: 9.23.94      */
/* Holy Mission        */
inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A shadowy room with many exits";
        long_desc=
            "A very empty seeming room.  There is almost\n"     +
            "nothing within this large room, except for a\n"    +
            "lone torch which throws large shadows against\n"   +
            "the bare walls.  A ceiling is not high, but\n"     +
            "because of the lighting in the room, it can \n"    +
            "barely can be seen.  Upon further inspection,\n"  +
            "you notice that there is very little wall, and\n"      +
            "instead, swirling black portals.\n";

        dest_dir=({
	    "/players/blade/area/forest1/road1.c","area",
            "/players/blade/workroom.c",     "south",
            "/players/airborne/workroom.c",  "airborne",
            "/players/nokey/centralroom.c",  "central",
            "/players/haplo/workroom.c",     "haplo",
            "/players/herkules/workroom.c",  "herkules",
            "/players/tatsuo/workroom.c",    "tatsuo",
            "/players/whisky/workroom.c",    "whisky",
            "/players/tamina/workroom.c",    "tamina",
            "/players/blade/cave1.c",        "down",
	    "/players/blade/wiz/codingroom.c", "code",
            "/obj/tick.c",                   "tick",
            "room/post",                     "post",
	    "room/church",                   "church",
            "room/adv_guild",                "guild", 
	    "/players/blade/test/temple.c",  "temple",
                 });

        items=({ 
            "room",  "Yes, this looks like a room.",
            "walls", "You notice that there seem to be no walls, only\n"    +
                     "swirling black portals.\n",
            "torch", "A single sputtering torch that gives the room an\n"   +
                     "eerie look more than it lights up the room.\n",
            "ceiling", "You squint hard, and barely make out a darkish\n"   +
                       "outline of a black marble ceiling.\n", 
            "shadows", "Very dark shadows surround the room, probably\n"    +
                       "giving refuge to creatures you do not want to see.\n",
            "portals", "Dark portals swirl hypnotically, almost seeking to\n" +
                       "destroy your mind.\n",
              });

        property = ({
                     "no_sneak",
                    });

        smell = "You detect faint odors from all directions.\n";
    }
}

init()
{
  ::init();
}
