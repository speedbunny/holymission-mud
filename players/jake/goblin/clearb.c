

inherit "room/room";

#include "/players/jake/defs.h"
object ghost;
int is_touched;
reset(arg) {
    if (arg) return;

    set_light(3);
    short_desc = "In the cemetary";
    long_desc = 
        "You stand in the far eastern section of the cemetary.  It also appears\n" +
        "to be the oldest section.  A rusty iron fence circles around this area\n" +
        "allowing travel only to the west.  Only one tombstone stands here, old\n" +
        "and weathered.  A large gargoyle stands on the top as if standing guard.\n" +
        
        "Tall weeds surround the tombstone, almost covering up some words carved\n" +
        "into the base of the tombstone.\n";
items = ({
"stone","A weathered old tombstone.  It is very large, and a\ngargoyle stands on the top",
"words","I hereby cast a curse:  Anyone who dares 'touch' my tomb'stone will witness my resurrection",
"gargoyle","A gargoyle carved out of stone to decorate the tombstone",
"weeds","Tall weeds",
"fence","The iron fence is real rusty",
"trees","Big evergreen trees",
"stones","Large memorials of dead goblins.\nI wouldn't touch any of them!\n",
});
 DD = ({
GOB + "cl1","west",
        });
}

init () {
  ::init();
  add_action("clone_me_now","touch");
}
clone_me_now(str) {
 if (str!="stone") return;
 if (is_touched) write ("The stone feels cold and crumbly.\n");
else {
ghost=clone_object("obj/monster");
ghost->set_name("goblin ghost");
ghost->set_short("goblin ghost");
ghost->set_long("This is the spirit of a goblin long since past.\nHe seems pissed off that you have disturbed him!\n");
ghost->set_level(10);
ghost->set_alt_name("ghost");
ghost->set_alias("goblin");
ghost->set_race("goblin");
ghost->set_hp(500);
ghost->set_wc(7);
ghost->set_ac(3);
ghost->set_aggressive(1);
ghost->set_align(-100);
ghost->add_money(500);
move_object(ghost,this_object());
write("What have you done ?!?!?!?!?!?!?\n");
say (TPN + " has made a costly error.\n");
is_touched=1;
}
return 1;
::reset();
replace_program("room/room");
}
