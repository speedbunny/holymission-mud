inherit "room/room";
reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("In front of a large building");
    long_desc=("In front of you stands the largest building you have\n"+
      "ever seen. I looks to be made from stone and metal.\n"+
      "The huge front doors of the building have been blown\n"+
      "open. There is also a huge flag hangging from the front\n"+
      "of the building.\n");
    items=({"flag","                ____                 \n"+
      "                    |                 \n"+
      "              ______|_____|           \n"+
      "              |     |                 \n"+
      "                    |___              \n"});
    clone_list=({1,2,"ss","players/akira/mobs/ss", 0});
    ::reset(tick);
    replace_program("room/room");
    dest_dir=({"players/akira/vag/in", "north",
      "players/akira/vag/city3", "south" });
property=({"vag_quest", "no_teleport"});
}
