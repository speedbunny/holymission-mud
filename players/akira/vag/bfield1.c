inherit "room/room";
reset(arg){
    ::reset(arg);
    set_light(1);
    short_desc=("Far end of a Battlefield");
    long_desc=("This is the farside of the battlefield. The troops here\n"+
      "are always looking for a way to flank there enimies. The\n"+
      "fighting here is not very bad right now.\n");
    dest_dir=({"players/akira/vag/union1", "north",
      "players/akira/vag/reb1", "south",
      "players/akira/vag/bfield", "east",
    });
property=({"vag_quest", "no_teleport"});
}
