inherit "room/room";

#include "/players/mangla/defs.h"

int _dig(string str) {

    write("You find small handholds and begin to claw your way out and up.\n");
    TP->MOVEP("up the well wall#room/mine/tunnel29");
    return 1;
}

int _read(string str) {

    if (str == "plaque" || str == "sign") {
        write("The plaque is imbedded in the rock and is just barely readable\n" +
              "after the ages of decay and tarnish. It reads:\n\n" +
              "WARNING: If you plan on entering this area it is _strongly_\n" +
              "         advised that you proceed in parties and are of _HIGH_\n" +
              "         levels. Otherwise your death is in your own hands.\n");
        TELLR(TO,"\nA voice echos in from the dark: YOU HAVE BEEN WARNED!!\n\n");
    }
    else write("Read what?\n");
    return 1;
}



reset(arg) {
    if(!arg) {

    short_desc="\nBottom of Shaft";

    long_desc="\n    You are standing at the bottom of a tall shaft that\n" +
              "is impossible to climb. Try as you might you know that\n" +
              "if you venture forth, the only way to leave this dreadful\n" +
              "place is to continue on and hope you can find another exit.\n" +
              "    Light only dimly penetrates the thick, inky shadows "+
              "which fill this shaft.  A dull glint on the wall marks a small plaque "+
              "which peeks out of the solid rock walls.  Foul, rank air "+
              "clings close to the ground, furthering the demise of any "+
              "sense of hope which may yet remain in this ungodly hole.\n"+
              "only extents a short distance into the dark. The shadows\n" +
              "seem to creep in on you. You do notice a plaque on the wall\n" +
              "that reflects the light dully. The walls are all made from\n" +
              "solid rock. Hope begins to fade in this dismal place where\n" +
              "even the air reeks of death and decay. It only gets blacker\n" +
              "the further you go.\n" +
              "    As the panic sets in you feel like clawing at the walls\n" +
              "climbing or digging your way out.\n\n";

    set_light(-1);

    smell="\nThe odor of rotten and decayed flesh prevails.\n";

    items = ({"sign","A dull copper plaque seemingly buried in the wall.\n" +
                     "If you read it you just might make out what it says",
              "plaque","A dull copper plaque seemingly buried in the wall.\n" +
                       "If you read it you just might make out what it says",
              "shaft","Maybe if you tried \"out\" it would work",
              "walls","The walls are made from hard rock",
              "wall","The walls are made from hard rock",
              "rock","Black, hard rock. You cannot chip it, much less dig it",
              "dark","Impenetrable blackness surrounds you",
              "shadows","Did you see something move? Fear mounts"
            });

    property=({ "no_fight" });

    dest_dir=({UNDER + "r5_2","north",
             });
    hidden_dir = ({
                    "room/mine/tunnel29", "out",
                      });
    }
}

init()
{
  ::init();
  add_action("_dig","climb");
  add_action("_dig","dig");
  add_action("_read","read");
}

