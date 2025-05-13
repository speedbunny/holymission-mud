inherit "room/room";
 reset(tick){
 if(tick) return;
set_light(1);
short_desc=("Entrance to Tarwins Gap");
long_desc=("This is the entrance to Tarwins gap. It is the only gap\n"+
           "between the Mountains of Dhoom and the Spine of the world.\n"+
           "On the othere side of the gap lies the Blight, an area\n"+
           "that knows only evil. The gap is not very wide but it is\n"+
           "wide enough to let an army of the Dark One march through\n"+
           "into the Borderlands.\n");
items=({"gap", "This is the space between to mountain ranges.",
        "blight", "It is a dead and evil place",
        "mountains", "They are to huge to see the tops of." });
dest_dir=({"/players/akira/area/gap1", "north",
            });
property=({"no_teleport"});
}
