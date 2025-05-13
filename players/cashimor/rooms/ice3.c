#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_LONG
#define EXTRA_LONG if (id(str)) return extra_long(str);
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

int broken;
object hole;
ONE_EXIT("/players/cashimor/rooms/ice","south",
         "Wastelands of ice",
         "You are on the wastelands of ice. When you look around you see\n"
       + "ice all around you. This doesn't look too good: it's very cold\n"
       + "here.\n",
         1)

id(str) { return str == "ice"; }

extra_long(str) {
  write("You can see something swimming under the ice...\n");
  return 1;
}


extra_reset() {
  if (broken == 1) {
    broken == 0;
    destruct ("hole");
    say("The water in the hole freezes, making the hole disappear...\n");
  }
}
extra_init() {
  add_action ("south","south");
  add_action ("breek","break");
}
breek(str) {
  if (!id(str)) {
    return 0;
  }
  if (!present ("axe",this_player())) {
    write ("The ice is too hard!\n");
    return 1;
  }
  if (broken == 1) {
    write ("But there is already a hole here!\n");
    return 1;
  }
  broken = 1;
  write ("You make a nice round fishing hole in the ice...\n");
  hole = clone_object("/players/cashimor/objects/hole");
  move_object (hole,this_object());
  return 1;
}

south() {
  if (!present ("skates",this_player())) {
    write ("It's too slippery!\n");
    return 1;
  }
  this_player()->move_player("skating to the west#players/cashimor/rooms/ice");
  return 1;
}
