inherit "room/room";

object voorwerp;

reset(arg) {
  if(!arg) {
    set_light(0);
    short_desc="On the narrow bridge";
    long_desc="You're on a long and very narrow east-west bridge.\n"
            + "To the north and to the south are dangerous depths.\n";
    dest_dir=({"room/mine/mine3","west",
               "players/cashimor/rooms/wayout","east",
               "players/cashimor/rooms/water","north",
               "players/cashimor/rooms/water","south",
               "players/cashimor/rooms/water","down"});
  }
  if(!present("fireorc",this_object())) {
    voorwerp=clone_object("players/cashimor/monsters/fireorc");
    move_object(voorwerp,this_object());
  }
}
 
