inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Second Floor of the Tower.");
long_desc=("The stairs stop here, and you are on the second floor\n"+
           "of the tower. A hall leads to the north, and you think\n"+
           "you can see another flight of stairs at the end of the\n"+
           "hall, but it is to far to tell from here.\n");
dest_dir=({"/players/akira/psi/hall5", "north",
           "/players/akira/psi/stairs", "down" });
}
