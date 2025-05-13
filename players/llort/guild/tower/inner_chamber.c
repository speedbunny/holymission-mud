inherit "room/room";

object board;

recalc_power_level() { return 45; }

reset(arg) {

  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc="Inner chamber of the mage council";
    long_desc=
"This is the inner chamber of the mage council. The private room of the\n"+
"inner circle of the mage guild. Only Archmages are allowed to be here.\n"+
"The room seems to have no walls at all, for it is located in the heart\n"+
"of the astral plane to make sure that the privacy of the inner circle\n"+
"is undisturbed.\n";
    dest_dir=({ "players/llort/guild/tower/outer_chamber", "outer" });

    board=clone_object("boards/mage_inner");
    move_object(board,this_object());
  }
}

init() {
  ::init();
  if(board) {
    move_object(board,this_object());     /* now it's first in the list */
  }
}
