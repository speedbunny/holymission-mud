inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);

short_desc=("Top floor of the tower");
long_desc=("You have reached the top level of the Tower. A small hall\n"+
           "leads to the south, while to the north you can see many\n"+
            "doors. Something about this level of the tower seems\n"+
            "to tell you that you should not be up here.\n");
dest_dir=({"/players/akira/psi/room5", "north",
           "/players/akira/psi/hall7", "south",
           "/players/akira/psi/study3", "west",
           "/players/akira/psi/room4", "northwest",
           "/players/akira/psi/room6", "northeast" });
}
