inherit "room/room";
reset(tick){
if(tick)return;
set_light(1);

short_desc=("The Main Hall");
long_desc=("This is the main hall of the tower. It leads off in many\n"+
           "directions. Far to the north you think you can make out a\n"+
           "grand flight of stairs leading up. The hallways leading\n"+
           "to the east and west do not seem to be that long.\n");
dest_dir=({"/players/akira/psi/hall4", "north",
           "players/akira/psi/room", "south",
           "players/akira/psi/hall2", "east",
           "players/akira/psi/hall1", "west" });
}
