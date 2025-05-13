#define TP this_player()


inherit"players/warlord/NEWSTUFF/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "forest";
    no_castle_flag = 0;
    long_desc = 
        "You see north of you a clearing with a large white beast running around.\n"
        + "The sight of it makes you feel happy inside. The forest here has many \n"
        + "flowers and a beautiful stream.\n";
items =({
       "stream","The stream is filled with crystal blue water.",
        "beast","It looks like a white horse",
       "flowers","The flowers are of all different colors and their fragrance is pleasent",
             });
    dest_dir = 
        ({
        "players/warlord/quest/dungeon/room17", "north",
        "players/warlord/quest/dungeon/room32", "east",
        });
}

init () {
::init();
add_action("north","north");
}
north() {
if (!present("necklace",TP)) {
write("You do not possess the proper item to go north !\n");
return 1;
}
return !TP->move_player("north#/players/warlord/quest/dungeon/room17");
}
