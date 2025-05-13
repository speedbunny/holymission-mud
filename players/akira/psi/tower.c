inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc="In front of a Large Tower.\n";
long_desc=("Before you stands the Legendary Tower of Highest Thought.\n"+
          "The Tower is said to be the home of the the Psionicist\n"+
          "Guild. As for the tower itself, it seems to reach up to\n"+
          "the very heavens. There are no windows on the Tower, and\n"+
          "the only way in would seem to be a large set of doors to\n"+
          "the north of here.\n");
items=({"tower", "It is a large dark tower.\n",
        "doors", "They would seem to be open.\n" });
clone_list=({1, 2, "guard", "/players/akira/mobs/guard", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/room", "north",
           "/players/akira/psi/enter", "south" });
}
