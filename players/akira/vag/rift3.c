inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In front of a rift");
long_desc=("This rift is the largest you have ever seen. It stands\n"+
           "about 80 feet tall. A rift this size could easily rip this\n"+
           "this place apart. The tracks in front of it are to many to\n"+
           "count. Some are small, like a human. While others are huge.\n"+
           "You can tell that a lot of stuff as entred from this rift.\n");
items=({"rift", "A large rift that could ahve only been made by a Timelord",
        "tracks", "They are of all kinds and shapes.\n" });
dest_dir=({"players/akira/vag/juice", "east",
           "players/akira/vag/juice1", "west",
           "players/akira/vag/field3", "south" });
property=({"vag_quest", "no_teleport"});
}
