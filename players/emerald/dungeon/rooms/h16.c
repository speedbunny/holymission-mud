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
              "southeast, probably from a large opening in the floor.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h15","north",
               "players/emerald/dungeon/rooms/h17","west",
             });

    items=({"walls", "They are set close together.  You find it " +
                     "a little narrow a spots",
            "opening", "It seems to be fairly deep.  Splashing noises " +
                   "accompany frequent growls and snaps.  You could " +
                   "probably jump into it",
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
  if (str=="opening") {
    write("You fall into the pit!!!\n");
    TP->move_player("southeast#players/emerald/dungeon/rooms/ap1");
    return 1;
  }
}
