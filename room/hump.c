#include "lw.h"

inherit "room/room";

status searched;

void reset (int arg) {

    string beechdesc, heapdesc;
    searched=0;

    if(arg) return;

    set_light (1);

    short_desc="Humpbacked bridge";

    long_desc=
              "You are on a humpbacked bridge, crossing a " +
              "peaceful river flowing from the north, greened " +
              "with bushes and sappy beech trees. On the " +
              "bridge a small heap of beech twigs and rotting " +
              "leaves spread a sweetish mouldy smell.\n";

    beechdesc =
              "They look healthy, getting their water from the river";

    heapdesc =
              "Many a twigs, sticks and half-rotten leaves from " +
              "the last storm cover the trash that people have " +
              "dropped or lost there. It might be an idea to " +
              "search the leaves if there is something useful " +
              "left in that heap";

    items = ({
              "bridge", "An old, wellbuilt bridge made of heavy " +
                        "stones, framed by a dirty heap of leaves " +
                        "on each side",
              "bushes", "Sappy green bushes, which drink from " +
                        "the water of the river",
              "beeches", beechdesc,
              "beechtrees", beechdesc,
              "beech trees", beechdesc,
              "trees", beechdesc,
              "leaves", heapdesc,
              "heap", heapdesc,
              "beech twigs", heapdesc,
              "twigs", heapdesc,
              "water", "It is clear and looks very deep",
              "river", "The river is very deep, too deep for a " +
                       "man to stand on the bottom",
            }); 
       
    dest_dir = ({
                 "room/wild1","west",
                 "room/vill_green","east",
               });
}

init() {
    ::init();
    add_action ("search","search");
}

  
int search(string str) {

    string invis_msg;
    object temp;

    invis_msg="You hear a rustling noise as the heap of " +
              "leaves moves aside!\n";

    if (!str || str=="bridge" || str=="room") {
        write("You search on the street and find a " +
              "heap of twigs and leaves.\n");
        return 1;
    }
    if (str=="heap" || str=="twigs"
                    || str=="leaves" || str=="beech twigs" ) {
        if (this_player()->query_ghost()) {
            write ("Your incorporeal hands pass right through the heap.\n");
            return 1;
        }
        if (searched) {
            write ("You stir up the leaves, but you find " +
                   "nothing useful left.\n");
            if (this_player()->query_invis()) {
                say (invis_msg);
                return 1;
            }
            say (lw(this_player()->query_name()
                + " stirs up the leaves on the road.\n"));
            return 1;
        }
        searched=1;

// money-calculating should be done by the player-obj, independent to changes
        write("You find 10 gold coins and a dry, combustable stick.\n");
        if (this_player()->query_invis())
            say (invis_msg +
                 "Some gold appears - and disappears again, how mystically!\n" +
                 "Adry, combustible stick raise " +
                 "from the ground -\n" +
                 "and vanish also.\n");
        else 
            say (lw(this_player()->short() + " stirs up the leaves and finds " +
                 "some money and a dry stick.\n"));
        this_player()->add_money(10);

    
// and a dry stick
        temp=clone_object("obj/torch");
        temp->set_name("stick");
        temp->set_short("a stick");
        temp->set_long("This stick is slightly black on one end.\n");
        temp->set_fuel(500);
        temp->set_weight(1);
    
        if(transfer(temp,this_player())) {
            write ("You have no hands left to pick up the stick.\n");
            if (this_player()->query_invis()) {
                say ("A stick falls to the ground.\n");
            }
            else
                say (this_player()->short() + " drops a stick.\n");
            move_object (temp,this_object());
        } 
        return 1;
    }
    write ("You find nothing special.\n");
    return 1;
}
