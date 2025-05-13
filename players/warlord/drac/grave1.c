inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "graveyard";
    no_castle_flag = 0;
    long_desc = 
        "You are in a dark and creepy graveyard, there are tombstones north\n"
        + "and south blocking your way..\n";
    dest_dir = 
        ({
        "players/warlord/drac/gravent", "gate",
        "players/warlord/drac/grave2", "east",
        });
items=({
"tombstones","There is one to the north and south. Which one?",
"north tombstone","This tombstone tells a tale of a valiant warrior who died with honour",
"south tombstone","This tombstone is battered greatly and illegible",
});
replace_program("room/room");
}
