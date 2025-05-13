inherit "room/room";

object board;

recalc_power_level() { return 45; }

reset(arg) {

  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc="Outer chamber of the mage council";
    long_desc=
"You are in the gathering room of the outer cirle of the mage council.\n"+
"The room ic heavy decorated and the furniture looks very expensive.\n"+
"There is a very large table in the middle of the room, used for discussing\n"+
"the manners of this council. At the eastern wall you can see a board,\n"+
"containing suggestions and ideas of the councilmembers as well as the\n"+
"anouncements of the inner-circel members about future guild changes and\n"+
"other important news.\n";
    dest_dir=({ "players/llort/guild/tower/chamber","chamber" });
    items=({
	     "table","You think there is place for about 20 to 30 men" });

    board=clone_object("boards/mage_outer");
    move_object(board,this_object());
  }
}

init() {
  ::init();
  if(board) {
    move_object(board,this_object());     /* now it's first in the list */
  }
}
