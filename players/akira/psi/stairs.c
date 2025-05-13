inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc="In front of a Grand Staircase";
long_desc=("This is a Gand flight of Stairs leading up into the\n"+
           "tower. off to the west of the stairs you can see what\n"+
           "looks to be a psionicist training area. As for the stairs\n"+
           "themselves, they as solid marable.\n");
clone_list=({1, 2, "guard", "/players/akira/mobs/guard", 0});
dest_dir=({"/players/akira/psi/hall4", "south",
           "/players/akira/psi/train2", "west",
           "/players/akira/psi/train1", "southwest",
           "/players/akira/psi/train3", "southeast",
           "/players/akira/psi/stairs2", "up" });
	::reset(tick);
	replace_program("room/room");
}
