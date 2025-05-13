inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1); 
    short_desc="Staircase";
    long_desc=
"You are on the first floor of the mage tower. There are some torches fixed\n"+
"to the walls. A hallway leads further south. To the west a sign reads\n"+
"'Magic shop'. North and east are doorways to some more rooms, but from this\n"+
"point you can't figure out what's in them. There is a staircase leading down\n"+
"to the base level.\n";
    items=({ "torch","The torches are firmly secured to the wall",
             "torches","The torches are firmly secured to the wall",
             "floor","Just an ordinary floor",
             "sign","It reads 'Magic shop'",
             "wall","There are some torches fix to the walls",
             "hallway","The hallway seems to turn to the east, and an\n"+
	               "opening leads out in the opposite direction", });
    dest_dir=({ "players/llort/guild/tower/hallway","down",
                "players/llort/guild/tower/hallway2","south",
                "players/llort/guild/tower/magic_shop","west",
                "players/whisky/magic/keg_shop","north",
                "players/llort/guild/tower/map_room","east" });

/* 12.08.93 Airborne: Added replace_program */
replace_program("room/room");
}
