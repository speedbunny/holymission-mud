

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is a long and dark hallway..the floor is very damp.\n"
        + "You see a glittering light near the end of the hallway...\n";
    items=({
    "floor","The floor is damp with blood",
          });
    dest_dir = 
        ({
        "players/warlord/drac/drac1", "south",
/*
        "players//warlord/drac/dracdun1", "west",
*/
        "players/warlord/drac/dracdun2", "east",
        "players/warlord/drac/drachall4", "north",
        });
}

