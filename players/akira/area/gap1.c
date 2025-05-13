inherit "room/room";
 reset(tick){
 if(tick) return;
set_light(1);
short_desc=("In Tarwins Gap");
long_desc=("On both sides of the gap stand huge mountains that seem\n"+
            "to block out the sun. The ground if covered with stones\n"+
            "of every size and shape. The gap seems to exstand further\n"+
            "to the north and south.\n");
items=({"gap", "This is the space between to mountain ranges.",
        "mountains", "They are to large to see the tops of.",
        "sky", "It seems very dark today for some reason." });
dest_dir=({"/players/akira/area/gap2", "north",
           "/players/akira/area/gap", "south" });
property=({"no_teleport"});
}
