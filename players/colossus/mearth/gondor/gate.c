
#pragma strict_types

inherit "/players/colossus/private/gcity";

int closed;

#include "/players/colossus/mearth/gondor.h"
void reset(int arg){
    ::reset(arg);
    if(arg) return;
    closed = 0;
    set_enable(0);
    short_desc = "Gate of Minas Tirith";
    long_desc =
    "After travelling for a long time you arrive at the gates of Gondor\n\
or Minas Tirith in the Numenorean tongue. The name Minas Tirith mean\n\
Tower of the Guard and standing in front of the city gates with full\n\
full views of the walls you can see how the tower has lived up to\n\
the name. The white walls of Gondor are high and thick and graceful\n\
spires blend into the natural beauty of the sky. The city gates are\n\
solid structures and have never fallen to any attacker.\n";

    dest_dir = ({
      GONDOR+"/gate2", "north",
    });

    items = ({
      "walls", "The walls of Minas Tirith stand tall and proud",
      "spires", "The graceful white towers reach gracefully towards the sky",
      "gate", "@@gate@@",
    });
}

void init(){
    ::init();
    add_action("north", "north");
}

status north(){
    if(closed){
	write("You attempt to go north into Gondor but the city gates are\n\
closed.\n");
	return 1;
    }
    this_player()->move_player("north#"+GONDOR+"/gate2");
    return 1;
}

string gate(){
    if(closed)
	return "A huge and strongly reinforced gate gate stands closed before you";
    else
	return "A huge and strongly reinforced gate stands open before you";
}
