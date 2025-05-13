inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("In a small hallway");
long_desc=("This is a small hallway with doors on both sides. The hall\n"+
            "itself is not very well lit. It leads further to the north.\n");
dest_dir=({"/players/akira/psi/hall6", "north",
           "/players/akira/psi/stairs2", "south",
           "/players/akira/psi/study2", "east",
           "/players/akira/psi/room2", "west",
           "/players/akira/psi/room1", "southwest" });
}
