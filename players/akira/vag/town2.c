inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);
short_desc=("A burnt-out town");
long_desc=("This part of the town looks like it has not been hit\n"+
           "so hard by who ever attacked it. Most of the buildings\n"+
           "are still standing, but all the doors are locked and\n"+
           "most of the windows are closed. There is not a soul to be\n"+
           "found on the streets.\n");
items=({"buildings", "They don't look all that damaged.\n",
        "doors", "All closed and locked.\n",
         "bodies", "Corpses scattered across the area.\n",
        "windows", "All closed.\n",
        "streets", "Empty, you can't see a single person.\n" });
dest_dir=({ "players/akira/vag/town", "east" });
property=({"vag_quest", "no_teleport"});
}
