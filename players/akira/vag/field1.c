inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In a large field");
long_desc=("The grass in this part of the field would seem to have been\n"+
           "eaten or all stepped on by something very big. By the size of\n"+
           "foot print, what ever made it must be huge. To the north you\n"+
           "can see a bright light that seems to be standing in mid-air.\n");
items=({"print","It is HUGE!\n",
        "light","You really cant get a good look from here.\n" });
dest_dir=({ "players/akira/vag/rift1", "north",
           "players/akira/vag/field" , "south" });
property=({"vag_quest", "no_teleport"});
}
