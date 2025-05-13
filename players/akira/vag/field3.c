inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In a small field");
long_desc=("This is a small field with a dirt raod leading through it.\n"+
           "Too the south is what is left of a small town, and to the\n"+
           "north you can see the light of another rift. From here you\n"+
           "can still smell the smoke from the burning town.\n");
items=({"road", "It leads north and south" });
dest_dir=({"players/akira/vag/rift3", "north",
           "players/akira/vag/town" ,"south" });
property=({"no_teleport"});
}
