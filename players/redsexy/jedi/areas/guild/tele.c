inherit "room/room";

#include "/players/mangla/defs.h"

int _con(string str) {
   if(TP->query_real_guild() !=4) {
   write("You concentrate with all your might and nothing happens.\n");
   TP->MOVEP("cannot control the force#players/redsexy/jedi/areas/guild/room");
   return 1;
}

    if(!str) {
        write("Concentrate on what?\n");
        return 1;
    }
    if(str == "on church")
        TP->move_player("fades from view#room/church");
else if(str == "on port1")
        TP->move_player("fades from view#/players/warlord/trans/port1");
    else if(str == "on ezo")
        TP->MOVEP("fades from view#/players/patience/ezo/coast/c1");
    else return 0;
    return 1;
}

void reset(int arg) {

    object ob;

    if(arg)
        return 0;

    short_desc = "Teleport";

    long_desc =
              "You feel the power contained in this room overwhelming your "+
             "sensitive mind. Many a Jedi have labored to bring you this "+
              "masterpiece of mental construction. From this room you can "+
              "project yourself to other locations. The whole room is made "+
              "from a dark midnight blue material, but in the corner you "+
              "can see where some less generous person has marred its "+
              "walls with grafitti. As you lean closer you can just read it.\n"+
              "Concentrate on <location>\n"+
             "" +
              "Availible: church, port1, ezo\n\n"+
              "";

    set_light(1);

   property=({"no_telport", "no_steal"});

    smell="\nYou smell the vibrations of thoughtful minds.\n";

    dest_dir=({"/players/mangla/guild/caperoom","west"

              });

}

void init() {

    ::init();
    add_action("_con","concentrate");
    if(!TP->query_immortal() && (TP->query_guild()!=4)) {
        write("You are not allowed in this place!\n");
        TP->MOVEP("is moved#players/redsexy/jedi/areas/guild/room");
    }
}

