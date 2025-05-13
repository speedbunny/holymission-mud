inherit "room/room";
 reset(tick){
 if(tick)return;
set_light(1);
short_desc=("Tarwins Gap");
long_desc=("This one of the mouths of Tarwins Gap. From this end the\n"+
           "gap leads south from the Blight to the Boarderlands. Even\n"+
           "at the mouth of the gap the mountains still seem to touch\n"+
           "the very heavens. Rocks of many differnt sizes cover the\n"+
           "ground.\n");
items=({"gap", "This is the space between the two mountains",
       "rocks", "They cover most of the ground",
       "blight", "It is a dead land where evil walks freely." });
clone_list=({ 1, 4, "trolloc", "/players/akira/mobs/trolloc", 0,
              1, 2, "draghkar", "/players/akira/mobs/draghkar", 0,
              1, 1, "fade", "/players/akira/mobs/fade", 0 });
  ::reset(tick);
  replace_program("room/room");
dest_dir=({"/players/akira/area/gap6", "north",
           "players/akira/area/gap4", "south" });
property=({"no_teleport"});
}
