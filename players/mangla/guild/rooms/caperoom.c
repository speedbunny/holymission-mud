inherit "room/room";

#include "/players/mangla/defs.h"
#define this_guild GM->query_number("jedi")


int _exchange_weapon (string str) { // Contributed by Scooter.

    object ob;
    object new;
    int class;

    if (!str) {
        write ("exchange <weapon>\n");
        return 1;
    }
//Added by Redsexy Feb 1998 - only a true jedi can exchange

    if(TP->query_real_guild()!=4) {
        write("Only true jedi are allowed to exchange weapons.\n");
        return 1;
    }

    ob = present(str,TP);
    if (!ob) {
        write ("You do not have that weapon to exchange.\n");
        return 1;
    }
    class = ob->weapon_class();
    destruct(ob);
    ob = present("handle",TP);

    if (ob)
        destruct(ob);

    write ("You exchange "+str+" for a new lightsaber.\n");
    ob = clone_object("/players/mangla/guild/lightsaber");
    ob->set_class(class);
    ob->set_weight(1);
    transfer(ob,TP);
    return 1;
}


void reset(int arg) {

    if(arg)
        return 0;

    short_desc = "The Caperoom of the Jedi Guild in the lower sanctums";

    long_desc =
              "You are in a special room of the Jedi Guild.  It is " +
            "in this room that you receive your cloak and lightsaber. " +
              "Please be nice to Ben, he is your benefactor and teacher. " +
              "A stairway lies to the south, leading back to the inner " +
              "sanctums, a long corridor stretches to the west and to " +
              "the north lies the teleport room where jedi can travel " +
              "to distant lands.\n" +
              "";

    set_light(1);
//Added no_steal and no_hide 05.08.97 by Sargon
    property=({"no_teleport","no_steal","no_hide"}); 

    smell="\nHerbal ethereal sensations fill you.\n";

    dest_dir=({
               "/players/mangla/guild/rooms/inner","south",
               "/players/mangla/guild/rooms/corridor1", "west",
               "/players/mangla/guild/rooms/storage","east",
              "/players/mangla/guild/rooms/tele","north",
             });

    MOVE(clone_object(PATH + "guild/ben"),TO);

}

void init() {

    ::init();
    add_action ("_exchange_weapon","exchange");
//   if((TPL < 30) && (TP->query_guild()!=4)) {
//05.07.97 Sargon changed to query_immortal
    if(TP->query_guild()!=4 &&!TP->query_immortal()) {
        write("You are not one with the force.\n");
        TP->MOVEP("is moved#players/mangla/guild/room");
    }
}
