#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Petrified Forest";
    long_desc =
    "Pools of boiling water are intermixed with huge\n"+
    "petrified tree trunks. The smell of sulfer is\n"+
    "almost overwhelming. A path leads north through the\n"+
    "petrified forest. Large footprints can be seen.\n";
    dest_dir = ({
      HOT + "fire_giant","north",
      HOT + "fire_path","south",
    });
    items = ({
      "pools","They bubble and steam",
      "water","The water bubbles and steams",
      "trees","Huge petrified trees. Your amazed that there still standing",
      "trunks","Huge petrified trees. Your amazed that there still standing",
      "footprints","These footprints are easyly five times as large as yours"
    });
    ::reset();
    replace_program("room/room");
}
