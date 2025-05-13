inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Psi-Master's Room");
long_desc=("This is one of the rooms that the Psi-Master's live in.\n"+
           "The room is much larger than the students rooms and the\n"+
           "bed and desk look to be much better than the students.\n"+
           "A very nice oriental rug covers the floor and there is\n"+
           "not a speck of dust to be found in the room. From the\n"+
           "looks of this room, the Master's of the tower would seem\n"+
           "to lead a very nice life.\n");
items=({"rug", "It is a very nice looking oriental run from Ezo",
        "bed", "It is a king size bed with silk sheets",
        "desk", "It looks to be made from solid oak" });
clone_list=({1,1, "master", "/players/akira/mobs/master", 0});
::reset(tick);
replace_program("room/room");
dest_dir=({"/players/akira/psi/stairs4", "south" });
}
