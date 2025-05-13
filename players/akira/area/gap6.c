inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("The Blight.\n");
long_desc=("This is the begining of the Blight. The area seems to be\n"+
           "devoid of all life. The soil is hard and the air is dry.\n"+
           "Only a few trees seem to have been able to live in this\n"+
           "place. This place has the feel and smell of death.\n");
items=({"bight", "A very bad place to be.",
        "area", "This is the blight",
        "soil", "It is rock hard",
        "air", "It is dry and smells of death",
        "trees", "You have no clue how they could live here." });
dest_dir=({"/players/akira/area/gap5", "south" });
property=({"no_teleport"});
clone_list=({1,1, "moridin", "/players/akira/mobs/moridin", 0});
::reset(tick);
replace_program("room/room");
}
