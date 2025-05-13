inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("A long hallway.\n");
long_desc=("This is a long hallway that lead further into the temple.\n"+
           "Huge black pillars hold up the ceiling, and a blood red\n"+
           "floor shines as if it was just cleaned. The walls seem to\n"+
           "be covered with some strange writings.\n");
items=({"hall", "This is a long hallway.",
        "pillars", "They are as black as night and hold up the ceiling.",
        "walls", "They are covered with some strange writing.",
        "writing", "You can not make out what it says" });
dest_dir=({"/players/akira/area/g_hall", "east",
           "/players/akira/area/up", "west" });
property=({"no_teleport"});
}
