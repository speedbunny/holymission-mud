inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("Whats left of a small clearing.");
Long_desc=("This whole area looks like someone stepped on it! The grass\n"+
           "looks like it has been ground back into the earth. Large foot\n"+
           "prints cover the area. In the center of the field is what is\n"+
           "left of a large dinosaur, but it is to ripped apart for you\n"+
           "to tell what kind it was.\n");
items=({"dinosaur", "It looks like it has been ripped apart.",
        "prints", "There are many large ones, but also some smaller ones." });
clone_list=({ 1,5,"raptor", "players/akira/mobs/raptor", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"players/akira/vag/rift1", "east" });
property=({"vag_quest", "no_teleport"});
}
