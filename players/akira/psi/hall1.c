inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=(
"In a small hallway");
long_desc=("This is a small hallway in the tower. Too the south of you\n"+
           "is a door with a sign above it the reads 'shop'. Other than\n"+
           "the door to the south, this hall is a dead end.\n");
items=({"sign", "It reads 'SHOP'"});
dest_dir=({"/players/akira/psi/shop", "south",
           "players/akira/psi/hall", "east" });
}
