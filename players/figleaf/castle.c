#define NAME "figleaf"
#define DEST "/players/figleaf/workroom"
/*
 * This is just the facade to a castle. If you want to enable the
 * "enter" command, move the player to a hall or something (which
 * you have to design yourself).
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

inherit "room/room";

void reset(int arg) {


object sgn;

  move_object(sgn=clone_object("/obj/thing"),"/room/forest8");
  sgn->set_name("big blue sign");
  sgn->set_alias("sign");
  sgn->set_short("A big blue sign");
  sgn->set_read("The new and improved smurf village lies to the north\nOnly level 10 and under are permitted at this time.\n\nFigleaf.\n");
  sgn->set_can_get(0);
    ::reset(arg);

    if(arg) return;

    set_light(1);

    short_desc="Castle of " + NAME;

    long_desc=
              "This is the "+short_desc+".\n"+
              NAME + " is a rather new wizard, but it is an amazing castle\n"+
              "just the same. However, the gates are closed.\n";
    items=({ 
            "castle","@@short",   /* we need that to get the 'castle' id */
          });
    move_object(this_object(), DEST);
}

init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {

    if (!id(str))
        return 0;
    write("It is not an open castle.\n");
    return 1;
}
