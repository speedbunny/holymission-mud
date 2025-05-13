#define TP this_player()
inherit "/room/room";

void reset (int arg) {
  ::reset();

  if(arg) return;
  set_light(1);

  short_desc="A path in the countryside";

  long_desc="You have arrived at the end of the path.  Before you lies " +
            "an old abandoned well.  The superstructure has mainly rotted " +
            "away, but parts of it still remain.  An old broken rope " +
            "dangles uselessly from the wooden handle, its frayed end " +
            "showing that it is no longer attached to the bucket.\n";

  dest_dir=({"/players/emerald/country/4","south",
           });

  items=({"well","It's dark in there, but you could probably enter it",
          "rope","An old, rotten, snapped rope",
          "handle","It was once used to bring the bucket up from the bottom",
        });


  ::reset(arg);

}

void init() {
  ::init();
    add_action("enter", "enter");
  }

int enter(string str) {

  if(!id(str)) {
    notify_fail("What do you wish to enter?\n");
    return 0;
  }
  if (str=="well") {
    write("You enter the dark well.\n");
    TP->move_player("into a well#players/emerald/country/well");
    return 1;
  }

}
