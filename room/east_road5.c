 /* EASTROAD5 */

inherit "room/room";

reset(arg) {
  if(!arg) {
    set_light(1);
    short_desc="East road";
    long_desc="East road runs south from here. To the west lies the training\n"
	     +"halls of the famous fighter guild.\n";

    dest_dir=({"players/kelly/rooms/vill/eastroad6","north",
	       "players/gareth/guild/castle","west",
	       "room/eastroad4","south",
                         });
    smell="There isn't a really pervading smell here.";
    replace_program("room/room");
  }
}
