inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Inside a smal Vault.\n");
long_desc=("This is a Stasis Vault. The legends say that anything placed\n"+
           "in a stasis vault will not age so long as it is kept in the\n"+
           "vault. The walls are covered from top to bottom with magic\n"+
           "runes. Even the floor and ceilings seem to have some kind of\n"+
           "writing on them. There are small shelves that line the walls\n"+
           "and a table in the center of the room.\n");
items=({"vault", "This is a stasis vault.",
        "walls", "They are covered in magic runes",
        "ceiling", "It has some strange writing on it.",
        "floor", "It has some strange writing on it.",
        "writing", "You can not tell what it says",
        "shelves", "They don't seem to have anything on them.",
        "table", "It is a small table." });
dest_dir=({"/players/akira/area/shrine", "south"});
property=({"no_teleport"});
clone_list=({1, 1, "crystal", "/players/akira/obj/crystal", 0});
::reset(tick);
replace_program("room/room");
}
