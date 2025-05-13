inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="A hallway";
    long_desc=
"You are in a hallway on the second floor of the mage-tower. To the north you\n"+
"see a hall with a staircase leading down. To the west there is an opening\n"+
"leading out, while the corridor turns to the east.\n";
    items=({ "floor","Just an ordinary floor" });
    dest_dir=({ "players/llort/guild/tower/hall2","north",
                "players/llort/dragons/guild_stop","west",
                "players/llort/guild/tower/hallway3","east" });
}

init() { 
    ::init(); 
    add_action("west","west");
}

west() {
    write("Sorry, under construction!\n");
    return 1;
}

