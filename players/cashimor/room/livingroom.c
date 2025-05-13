inherit "players/cashimor/inherit/sand";

reset(arg) {
object flint;

  ::reset(arg);
  if(!arg) {
    short_desc="Livingroom";
    long_desc="This looks like a very old livingroom. There is a\n"
            + "hearth here, a stone table and some rubbish. To the\n"
            + "south is an opening and to the east is an opening.\n";
    items=({"hearth","There is a chimney leading up in it",
            "table","It looks very old",
            "livingroom","It looks really very old",
            "opening","There probably used to be a door there",
            "rubbish","Probably furniture that didn't survive Time"});
    dest_dir=({"players/cashimor/room/chimney","up",
               "players/cashimor/room/bedroom","east",
               "players/cashimor/room/corridor","south"});
    if(!present("flint",this_object())) {
      flint=clone_object("obj/flint");
      move_object(flint,this_object());
    }
  }
}
