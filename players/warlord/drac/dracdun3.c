

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
   smell="You smell a horrid smell, like dead bodies.";
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is a very dark and gloomy dungeon. You can smell death in every\n"
        + "corner. It looks like there is something on the back wall.\n";
    dest_dir = 
        ({
        "players/warlord/drac/drachall4", "west",
        });
    items=({"back wall","You look closely and see that someone or something has written something here",
    "writing","To find the key look for one with no body",
         });
}

