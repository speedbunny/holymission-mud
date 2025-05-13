#define TP this_player()
inherit "room/room";

void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A passageway in the dungeon";
    long_desc="This is a strange segment of the hallway.  You feel like " +
              "you are in a maze.  The walls close in on you and you " +
              "can barely tell where the walls end and another section " +
              "begins.  You can feel a draft blowing upwards from the " +
              "northeast, possibly from some sort of a pit.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h10","west",
               "players/emerald/dungeon/rooms/h12","south",
             });

    items=({"walls", "They are set close together.  You find it " +
                     "a little narrow a spots",
            "pit", "It seems to be fairly deep.  Splashing noises " +
                   "accompany frequent growls and snaps.  You could " +
                   "jump into it",
          });

}
init() {
  ::init();
    add_action("jump", "jump");
  }

jump(str) {

  if(!id(str)) {
    notify_fail("Jump where?\n");
    return 0;
  }
  if (str=="pit") {
    write("You fall into the pit!!!\n");
    TP->move_player("northeast#players/emerald/dungeon/rooms/ap2");
    return 1;
  }

}
