inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("In a small hallway");
long_desc=("This is a small hallway leading of from a the main room.\n"+
           "Just to the south is a door with a sign above it that reads\n"+
           "'Third Eye Inn, Enter at Own Risk'. Other than the door to\n"+
           "the south, the hall is a dead end.\n");
items=({"sign","A small broken down sign reads \n"+
              "The Whole Your Inn, Enter at own risk\n"});
dest_dir=({"/players/akira/psi/bar", "south",
           "/players/akira/psi/hall", "west" });
}
