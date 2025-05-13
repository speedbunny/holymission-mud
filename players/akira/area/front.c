inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc= ("Temple of the Fallen.\n");
long_desc= ("This is the legendary Temple of the Fallen. It was created\n"+
           "in memory of all the people who were killed in the Summoner\n"+
           "Wars. The temple itself is built into the side of a huge\n"+
           "mountain. There is only one entrance and there seems to be\n"+
           "no windows.\n");
items=({"temple", "This is the Temple of the Fallen.",
       "windows", "There are none.",
        "mountain", "It seems to reach up into the heavens.",
       "entrance", "There is one in the front." });
dest_dir=({"/players/akira/area/hall1", "north"});
}
