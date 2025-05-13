inherit "room/room";

#include "/players/mangla/defs.h"

static int knocked;

int _thought() {

    if(ENV(TP) != TO) return 1;
    write("After hanging here you get an idea.\n" +
          "Maybe, if there is someone up there, you should knock on the\n" +
          "door and they will let you into the building.\n");
    call_out("fall",10);
    return 1;
}

int fall() {

    if(ENV(TP) != TO) return 1;
    write("Your arms grow tired and you can no longer hold onto the rope.\n");
    write("You fall down....\n\n");
    write("OUCH!\n\nThat was a hard touchdown.\n");
    TP->hit_player(20);
    TP->MOVEP("the express way down#players/kelly/rooms/mythwood/plateau1");
    return 1;
}

int knock(string str) {

    if(str!="at door" && str!="at trapdoor" && str!="on door") return 0;
    if (knocked==0) {
        write("As you knock, the door opens with a shrill sound.\n");
        knocked=1;
        return 1;
    }
    else {
        write("Your knocking has no effect.\n");
        return 1;
    }
}

int open(string str) {

    if(str!="door" && str!="trapdoor") return 0;
    write("You try hard, but the door is too heavy for you.\n");
    return 1;
}

int upwards() {

    if (!knocked) {
        write("You cannot go up, the door is closed!\n");
        return 1;
    }
    else {
        write("You scramble up through the door.\n");
        TP->MOVEP("up#players/kelly/rooms/mythwood/cloister");
        return 1;
    }
}

void reset(int arg) {

    if (arg) return;
    set_light(1);
    short_desc="The top of the rope";
    long_desc="You hanging at the top of the rope.\n"+
              "Above you there is an trapdoor.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/plateau1","down",
             });
    items=({
            "trapdoor","A old wooden trapdoor",
            "door","A old wooden trapdoor",
          });
}

init() {
::init();
  add_action("knock","knock");
  add_action("open","open");
  add_action("upwards","up");
  call_out("_thought",15);
}

