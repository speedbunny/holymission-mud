inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="Mayor's property";
long_desc=
"You are on the side of the mayor's house.  This area is has\n"+
"many overgrown shrubs and hedges here.  It is difficult to\n"+
"follow the path which seems to end abbruptly in front of a\n"+
"thick hedge.\n";
    dest_dir=({
      "players/kelly/rooms/vill/mayorsgarden","northwest",
   });
   items=({
     "path","It seems that the path hasn't been used for a long time",
     "shrubs","Overgrown and wild, these shrubs are all over the place",
     "house","This is the mayor's house. It's very big and splendid",
     "hedge","A hedge of hazelnut perennial",
   });
}
