#define TP this_player()
#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="There is a faint ultra-violet glow in the room.  However, " +
            "it is not a terribly comforting type of light.  Leaving this " +
            "cell just might be a good idea.  Barely visible is a hole " +
            "in the wall.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h18", "south",
           });

  items=({"hole", "A dark, forbidding hole in the wall"
          "glow","A most sinister glow",
          "light","An evil light",
          "cell","A musty, moldy cell",
        });
  clone_list=({
    1,1,"demon","/players/emerald/dungeon/monster/demon",0,
  });

  ::reset();

}
init() {
  ::init();
    add_action("enter", "enter");
  }

int enter(string str) {

  if(!id(str)) {
    notify_fail("What do you wish to enter?\n");
    return 0;
  }
  if (str=="hole") {
    write("You crawl into the hole with fear in your heart.\n");
    TP->move_player("into a hole#players/emerald/dungeon/rooms/hole");
    return 1;
  }

}
