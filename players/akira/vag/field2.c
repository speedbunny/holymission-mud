inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In a small field");
long_desc=("This is a small field with a dirt road going through\n"+
           "it. The road leads off to the north, where you think\n"+
           "you can see a small town. From here you can see a great\n"+
           "cloud of smoke just above the town.\n");
items=({"road", "It leads to a small town",
        "town", "It looks to be on fire!\n" });
dest_dir=({"players/akira/vag/town", "north",
           "players/akira/vag/rift1", "west" });
property=({"vag_quest", "no_teleport"});
}
