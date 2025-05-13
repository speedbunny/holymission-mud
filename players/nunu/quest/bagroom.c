inherit "room/room";

#include "/players/nunu/path.h"

int struggle() {
    string msg;
    msg="struggle ";
  
    switch(random(5)) {
    case 0: msg+="helplessly.\n";
            break;
    case 1: msg+="cowerdly.\n";
            break;
    case 2: msg+="tiredly.\n";
            break;
    case 3: "You almost bloke your way out!";
            break;
     case 4: TP->move_player("/players/nunu/quest/closet.c");
             say(TPN+" breaks free!\n");}
    write("You struggle and "+msg);
    say(TPN+ " Struggles and"+msg);
    return 1;
}

void reset(int arg) {

    if(arg) return;
    short_desc="A Brown Bag";

    long_desc="You are in a HUGE Brown Paper Bag.  The paper seems "+
              "strange to the eye.  It sure is stuffy in here.  Mabye "+
              "if you `STRUGGLE' you can get out.\n";

    set_light(1);

    items=({"paper","The paper seems to have little holes punched in "+
                    "it.",
            "holes","The holes are allowing air and light in.",
            "hole","The hole is allowing a little air and light in.",
          });

    property=({"no_teleport","no_fight","no_steal","no_clean_up"});

    smell = "It smells like a stuffy brown paper bag.\n";

}

void init() {
    ::init();
    add_action("struggle","struggle");
    add_action("struggle","STRUGGLE");
}


