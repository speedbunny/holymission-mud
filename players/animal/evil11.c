#include "../../room/std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
object alleycat, stone;
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_int();
 
extra_int() { add_action("north", "north"); }
 
TWO_EXIT("players/animal/evil9","east",
         "/players/animal/evil17", "north",
     "The hunting room",
     "\n" +
     "    A small alleycat is here hunting for mice.\n" +
     "    You see a mouse scurry into a hole in the wall.\n" +
     "    The tunnel continues to the north here.\n" +
     "\n", 0)
 
 
extra_reset()  {
      if (!alleycat || !living(alleycat)) {
         alleycat = clone_object("obj/monster");
         call_other(alleycat, "set_name", "alleycat");
         call_other(alleycat, "set_alias", "cat");
         call_other(alleycat, "set_race", "cat");
         call_other(alleycat, "set_level", 3);
         call_other(alleycat, "set_hp", 140);
         call_other(alleycat, "set_al", -100);
         call_other(alleycat, "set_short", "A young and small alleycat");
         call_other(alleycat, "set_ac", 3);
         call_other(alleycat, "set_wc", 9);
         call_other(alleycat, "set_aggressive", 0);
         stone = clone_object("obj/treasure");
         call_other(stone, "set_id", "stone");
         call_other(stone, "set_alias", "rock");
         call_other(stone, "set_short", "A small stone");
         call_other(stone, "set_weight", 2);
         call_other(stone, "set_value", 300);
         move_object(stone, alleycat);
         move_object(alleycat, this_object());
     }
}
 
north() {
    if (present("alleycat")) {
     write("The alleycat says I cannot let you pass.\n");
     return 1;
    }
    call_other(this_player(), "move_player", "north#players/animal/evil17");
    return 1;
}
