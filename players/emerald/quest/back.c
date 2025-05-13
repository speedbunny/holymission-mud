inherit "/room/room";

int found;
object list;
void reset(int arg) {
  found=0;
  if(arg) return;

  set_light(0);
  short_desc="Backroom of the alchemist shoppe";
  long_desc="This is a dark room behind the main room of the alchemist " +
            "shoppe.  There are no windows, just shelves and shelves of " +
            "vials, flasks, and other alchemical equipment.  An entire wall " +
            "is devoted to books and notebooks, several of which appear to " +
            "be quite ancient.\n";

  dest_dir=({"/players/emerald/quest/lroom","north",
           });

  items=({"shelves","They go from floor to ceiling",
          "vials","Glass vials filled with liquids",
          "flasks","Glass flasks filled with strange chemicals",
          "equipment","Beakers, tongs, and other necessary tools of the trade",
          "wall","It is hidden behind the shelves",
          "books","They contain formulae for making things",
          "notebooks","The results of experiments conducted by the alchemist",
        });


  ::reset();

}

init() {

  ::init();

  add_action("search","search");
}

search(str) {
object list;

  if(!id(str)) {
    write("Search what?\n");

    return 1;
  }
  if(str=="notebooks" && !found) {
    write("You find a piece of paper.\n");
    move_object(list=clone_object("players/emerald/quest/list"),
        this_object());
    found=1;
    return 1;
  }
  say(this_player()->query_name() + " searches the " + str + " and \n"
           "finds nothing.\n");
  write("You search the " + str + " and find nothing.\n");
  return 1;

}
