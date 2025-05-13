inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="A hallway";
    long_desc=
"You are at the end on a hallway on the second floor of the mage-tower. There\n"+
"is a staircase leading up. Above the stairs there is a sign reading:\n"+
"                           SUMMON-ROOM\n"+
"                     Enter on your own risk!\n"+
"To the west the corridor lead towards a turning.\n" +
"\n\n SUMMON ROOM CLOSED FOR REPAIRS -Mangla\n";
    items=({ "staircase","The stairs are leading up",
             "sign","The sign reads:\n"+
"                           SUMMON-ROOM\n"+
"                     Enter on your own risk!\n"+
"It is writen in big red letters",
});

    dest_dir=({ "players/llort/guild/tower/hallway2","west",
//              "players/llort/guild/tower/summon9","up" });
             });
/* 12.08.93 Airborne: added replace_program */
replace_program("room/room");
}
