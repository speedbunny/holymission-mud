#define TP this_player()
inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A street in the town";

  long_desc="You have reached the end of this street.  There are rundown " +
             "houses to the north and south.  The windows are broken and " +
            "shutters are barely hanging on.  To the east you hear loud " +
            "voices and lots of giggling.  There is a grate in the middle " +
            "of the street.\n";

  dest_dir=({"/players/emerald/town/t16","west",
             "/players/emerald/town/brothel","east",
           });

  items=({"grate","A black sewer grate.  You could probably lift it",
          "windows","Gaping holes where there was once glass",
          "shutters","Time and weather have reduced them to splinters",
          "houses","Old, dilapidated houses",
        });

  ::reset(arg);

}

void init() {

    ::init();
    add_action("move_up","lift");
    add_action("move_up", "move");
}


int move_up(string str) {

    if (!str || str!="grate") {
        notify_fail("What do you want to move? \n");
        return 0;
    }
    if (str=="grate") {
        write("Ugh, its heavy, but you manage to move the grate.\n");
        TP->move_player("down#players/emerald/dungeon/rooms/t7");
        return 1;
    }

}
