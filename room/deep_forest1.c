/* Mangla I removed the dest_dir because I want to know
wju the entrance disappears. I think it should be fixed though.
 */
/*Updated to remove jedi guild enterance - Redsexy March 1999*/

inherit "room/room";

int no_clean_up() {return 1; }


void reset(int arg) {

    ::reset(arg);
    if(arg) return;
    set_light(1);

    short_desc="Deep forest";

    long_desc=
              "You are in the deep forest. A small trail leads " +
              "off to the west. To the south it is so thick " +
              "that you cannot pass any further. The wood lights " +
             "up somewhat to the east.\n";

    dest_dir=({
               "room/plane12", "east",
               "players/emerald/forest/f0-0", "west",
             });
    property = ({ "no_clean_up" });

}

int move(string str) {

    if(query_verb()=="west")
        write("You feel an intense fear as you move west, as you " +
              "know how dangerous this\n" +
              "forest is reputed to be, with its deadly roving " +
              "bands of draconians.\n");
    return ::move(str);
}
