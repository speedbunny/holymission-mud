inherit "room/room";
 reset(tick){
 if(tick) return;
set_light(1);
short_desc=("In Tarwins Gap");
long_desc=("This looks to be the center of Tarwins Gap. A ways to the\n"+
           "north and south you can see the opennings of the gap. The\n"+
           "mountains on both sides seem to climb on forever. The path\n"+
           "itself seems to be very wide at this point.\n");
items=({"gap", "This is the space between the two mountains",
        "center", "You stand in the center of the gap",
        "path", "The path through the gap is very wide here",
        "mountains", "They reach to far up to see the tops of them" });
dest_dir=({"/players/akira/area/gap4", "north",
           "/players/akira/area/gap2", "south" });
property=({"no_teleport"});
}
