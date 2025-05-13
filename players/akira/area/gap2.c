inherit "room/room";
 reset(tick){
 if(tick) return;
set_light(1);
short_desc=("In Tarwins Gap");
long_desc=("The mountains on both sides of the gap seem to exstend\n"+
           "streight up at this point. This would seem to make it\n"+
           "impossible to climb up. The only way to move is to the\n"+
           "north and south through the gap.\n");
items=({"gap", "This is the space between two mountian ranges.",
        "mountains", "They seem to go streight up from the ground."});
dest_dir=({"/players/akira/area/gap3", "north",
          "/players/akira/area/gap1", "south" });
property=({"no_teleport"});
}
