#define TP this_player()
inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="In the alligator pit";

  long_desc="You have fallen into a pit with sheer sides.  It contains " +
            "about two feet of murky water and some rather hungry-" +
            "looking alligators.  There is a small tunnel in the wall.\n";

  items=({"sides", "Sheer walls with no handholds for climbing",
          "tunnel", "The only exit from this pit",
          "water","Filthy water with bits of human bodies floating in it",
        });

  clone_list=({
    1,3,"alligator","/players/emerald/dungeon/monster/alligator",0,
  });

  ::reset();

}

init() {
  ::init();
    add_action("enter", "enter");
  }

enter(str) {

  if(!id(str)) {
    notify_fail("What do you wish to enter?\n");
    return 0;
  }
  if (str=="tunnel") {
    write("You manage to crawl into the tunnel.\n");
    TP->move_player("into a tunnel#players/emerald/dungeon/rooms/tunnel");
    return 1;
  }

}
