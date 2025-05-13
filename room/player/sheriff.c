inherit "/room/room";

#include <sys_defs.h>

int move(string sStr) {
    if(!sStr)
        sStr = query_verb();
    if(sStr ==" down" && !TP->IMM) {
        write("A strong magic force stops you.\n");
        say(sprintf("%s tries to go through the field, but fails.\n",
                    TP->NAME));
        return 1;
    }
    else
        return ::move(sStr);
}

void reset(int iArg) {
    if(!iArg) {
        set_light(1); 

        short_desc = "Player Sheriff's Office";
        long_desc = "\tThe Holy Mission Sheriff's Office\n\
You are in the sheriff's office for the law enforcement of Holy Mission. \
There is a desk along the south wall with a wooden chair behind it. On \
the wall above the desk, there are paintings that have been created by \
a master. There is an unusual spiral staircase located at the center of \
the room. A magical green field covers the steps, pulsing with power.\n";

        dest_dir = ({
           "/players/cashimor/extend/village1", "north",
        });

        hidden_dir = ({
           "/room/wiz/sheriff", "down",
        });

        items = ({
            "steps",     "The steps if a spiral staircase",
            "field",     "A magical green field",
            "power",     "You cannot see power, but you know it's there",
            "wall",      "There are two paintings on the south wall",
            "paintings", "Paintings of the sheriff and deputy",
            "master",    "The master painter is Nae",
            "painter",   "The master painter is Nae",
            "desk",      "A large wodden desk for the sheriff",
            "chair",     "A chair for the sheriff to sit at and pass \
judgement",
            "staircase", "A winding spiral staircase",
            "office",    "The Holy Mission Sheriff's Office",
        });

        property=({ 
            "no_fight",
            "no_sneak",
            "no_steal",
            "no_teleport",
        });

        clone_list = ({
            1, 1, "board", "/boards/player/sheriff", 0,
            2, 1, "book",  "/room/player/sheriff_book", 0,
        });
    }
    ::reset(iArg);
}
