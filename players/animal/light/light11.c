#include "../../../room/room.h"
 
#define me capitalize(this_player()->query_name())
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
object goat, bottle;
 
reset(arg)
{
	if(!arg) {
#if 0 
     ::reset(arg);
     set_light(1);
     set_outdoors(4);
#endif
     set_light(1);
     long_desc = "The base of the mountain\n" +
        "\n" +
        "    You have came to the place where a great mountain\n" +
        "    rises from the earth. The mountain looks stunning\n" +
        "    in its majestic beauty. The mountain top is covered\n" +
        "    with glistening snow.\n" +
        "\n";
     short_desc = "The base of the mountain";
     dest_dir = ({
        "players/animal/light/light14","north",
        "players/animal/light/light3","south",
        "players/animal/light/light12","east",
        "players/animal/light/light13","west",
     });
	}
     extra_reset();
     return;
}
 
query_long() {
    return long_desc;
}
 
query_outdoorness() {
    return 4;
}
 
query_light() {
    return 1;
}
init()
{
    ::init();
    add_action("search","search");
}
 
extra_reset()
{
     if (!goat || !living(goat)) {
         goat = clone_object("obj/monster");
         call_other(goat, "set_name", "billy goat");
         call_other(goat, "set_alias", "billy");
         call_other(goat, "set_race", "goat");
         call_other(goat, "set_level", 7);
         call_other(goat, "set_hp", 180);
         call_other(goat, "set_al", 350);
         call_other(goat, "set_short", "A young billy goat");
         call_other(goat, "set_long", "This goat is young, but has a" +
               " look to it that signals it is too not weak.\n");
         call_other(goat, "set_ac", 5);
         call_other(goat, "set_wc", 12);
         call_other(goat, "set_aggressive", 0);
	bottle = clone_object("players/animal/obj/milk");
         move_object(goat, this_object());
         move_object(bottle, goat);
         }
}
 
search(str) {
    if (!str) str = "room";
    if (str == "room") {
            write("You find nothing unusual.\n");
 
          say(me + " searches the room.\n");
            return 1;
          }
     return 0;
}
