#include "../../../room/room.h"
 
#define me capitalize(this_player()->query_name())
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
object gopher;
 
reset(arg)
{
    if (arg) return;
#if 0
     ::reset(arg);
     set_light(1);
     set_outdoors(0);
#endif
set_light(1);
     long_desc = "The home of the gopher\n" +
        "\n" +
        "     An extremely large gopher lives in this hole. He is probably\n" +
        "     the biggest gopher around. He digs tunnels everywhere under\n" +
        "     the earth. One day these tunnels will be a world here.\n\n";
     short_desc = "The home of the gopher";
     dest_dir = ({
        "players/animal/light/light12","up",
     });
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
 
init() {
       ::init();
     add_action("search","search");
}
 
extra_reset()  {
               object armor;
               if (!gopher || !living(gopher)) {
         gopher = clone_object("obj/monster");
         call_other(gopher, "set_name", "large gopher");
         call_other(gopher, "set_alias", "gopher");
         call_other(gopher, "set_race", "rodent");
         call_other(gopher, "set_level", 15);
         call_other(gopher, "set_hp", 250);
         call_other(gopher, "set_al", 500);
         call_other(gopher, "set_short", "A large gopher");
         call_other(gopher, "set_long", "The gopher is the biggest you" +
          " have ever seen.\n");
         call_other(gopher, "set_ac", 7);
         call_other(gopher, "set_wc", 15);
         call_other(gopher, "set_aggressive", 0);
	 armor = clone_object("obj/armour");
         call_other(armor, "set_name", "skin");
         call_other(armor, "alt_name", "gopher skin");
         call_other(armor, "set_short", "The skin of a large gopher");
         call_other(armor, "set_long",
           "This skin is worn as a cloak.\n");
         call_other(armor, "set_ac", 1);
         call_other(armor, "set_type", "cloak");
         call_other(armor, "set_value", 500);
         call_other(armor, "set_weight", 3);
         call_other(gopher, "wield_object", armor);
         transfer(armor, gopher);
         move_object(gopher, this_object());
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
