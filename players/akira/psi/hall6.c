inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("In a small hallway");
long_desc=("This is a small hallyway that leads to the north and south.\n"+
           "On both sides of you there are doors, and to the north you\n"+
           "can see a flight of stairs.\n");
dest_dir=({"/players/akira/psi/stairs3", "north",
           "/players/akira/psi/hall5", "south",
           "/players/akira/psi/study1", "east",
           "/players/akira/psi/room3", "west" });
}
