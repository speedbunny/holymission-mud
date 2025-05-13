inherit "/obj/thing";

#include "/players/mangla/defs.h"

int _vor2() {

    if (ENV(ENV(TO)) != find_object("/players/mangla/mentor/vortex")) {
        destruct(TO);
    }
    write("A large gust of wind picks you up, whirls you around,\n" +
          "and deposits you hard on your butt.\n");
    printf("THIS WORKED\n");
//    random_room();
    destruct(TO);
    return 1;
}

int _vor1() {

    if (ENV(ENV(TO)) != find_object("/players/mangla/mentor/vortex")) {
        destruct(TO);
   }
    write("You feel the winds beginning to take ahold of you.\n");
    call_out("_vor2",1,0);
    return 1;
}

reset (arg) {
   ::reset (arg);
   if (!arg) {
      set_name("vortex");
      id("vortex");
      set_alias("toga");
      set_value(0);
      set_weight(0);
   }
}

void init() {

    ::init();
    call_out("_vor1",2,0);
}
