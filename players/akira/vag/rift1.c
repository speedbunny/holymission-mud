inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In front of a large rift.");
long_desc=("You are standing in front of a huge rift in time and space.\n"+
           "It stands over 50 feet tall, and the light from it can be seen\n"+
           "for miles. From the giant foot prints in front of the rift you\n"+
           "can guess that something has already entered this realm from\n"+
           "the other side.\n");
items=({"rift", "Your knowledge of time and space tells you that this rift\n"+
                "must have been caused by a Timelord!",
        "prints", "They are Huge!" });
dest_dir=({ "players/akira/vag/field2", "east",
          "players/akira/vag/dino", "west",
          "players/akira/vag/field1", "south" });
property=({"vag_quest", "no_teleport"});
}
