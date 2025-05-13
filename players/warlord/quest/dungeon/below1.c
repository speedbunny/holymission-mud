inherit "/players/warlord/NEWSTUFF/room";
reset(arg){
    if (arg) return 1;
    set_light(1);
    short_desc="Tree trunk";
    long_desc=
    "You are inside a tree trunk. The rotting wood gives off an odd odor\n"+
    "You can feel a strange sensation come over your body as you peer down\n"+
    "into the darkness of the trunk. You can see some light from the hole in\n"+
    "in the wood.\n";
    dest_dir= ({
      "/players/warlord/quest/dungeon/room5","out",
      "/players/warlord/quest/dungeon/below2","down",
    });
replace_program("/room/room");
    return 1;
}
