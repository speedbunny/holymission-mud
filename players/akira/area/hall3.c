inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("A long hallway.\n");
long_desc=("This is a very long hallway. huge pillars reach from the\n"+
           "floor to the ceiling. The floor is a blood red color that\n"+
           "seems to shine as if it were just cleaned. The walls seem to\n"+
           "be very plain, save for some strange writing on them.\n");
items=({"hall", "This is a long hallway",
        "floor", "It is blood red and very clean.",
        "ceiling", "It seems to reach up into the heavens.",
        "pillars", "They are black as night and hold the ceiling up.",
        "writing", "You can't make out what it says" });
dest_dir=({"/players/akira/area/down", "east",
           "/players/akira/area/g_hall", "west" });
property=({"no_teleport" });
}
