inherit "room/room";
 reset(tick){
 if(tick) return;
set_light(1);
short_desc=("In Tarwins Gap");
long_desc=("The path leading throught the gap is very wide at this\n"+
           "point. The mountians slope a little here but still not\n"+
           "enough to climb them. The ground is covered with stones\n"+
           "of every size and shape.\n");
items=({"gap", "this is a path leading between the two mountains",
        "path", "It leads between the mountains",
        "stones", "They cover the ground",
        "mountains", "They are simply huge!\n"});
clone_list=({ 1, 2, "trolloc", "/players/akira/mobs/trolloc", 0 });
 ::reset(tick);
 replace_program("room/room");
dest_dir=({"/players/akira/area/gap5", "north",
           "/players/akira/area/gap3", "south" });
property=({"no_teleport"});
}
