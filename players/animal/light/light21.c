#include "../../../room/room.h"
 
#define me capitalize(this_player()->query_name())
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
object elk, celk;
 
reset(arg)
{
	if(!arg) {
#if 0 
     ::reset(arg);
     set_light(1);
     set_outdoors(4);
#endif
     set_light(1);
     long_desc = "The home of the bull elk\n" +
        "\n" +
        "     A rather large bull elk can be found here sometimes.\n" +
        "     He is usually eating grass, or trying to find a cow to\n" +
        "     mate with.\n"+
	"\n";
     short_desc = "The home of the elk";
     dest_dir = ({
        "players/animal/light/light20","south",
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
 
extra_reset()  {
     int i;
     object weapon, horn;
               if (!elk || !living(elk)) {
         elk = clone_object("obj/monster");
         call_other(elk, "set_name", "bull elk");
         call_other(elk, "set_alias", "bull");
         call_other(elk, "set_race", "elk");
         call_other(elk, "set_level", 17);
         call_other(elk, "set_hp", 400);
         call_other(elk, "set_al", 900);
         call_other(elk, "set_short", "A large bull elk");
         call_other(elk, "set_long", "This bull is a monster. On his head" +
	" are a set of perfectly shaped horns.\nHe is an 8 point!\n");
         call_other(elk, "set_ac", 10);
         call_other(elk, "set_wc", 18);
         call_other(elk, "set_aggressive", 0);
         weapon = clone_object("obj/weapon");
         call_other(weapon, "set_name", "antlers");
         call_other(weapon, "alt_alias", "horns");
         call_other(weapon, "set_short", "A large set of elk antlers");
         call_other(weapon, "set_long",
         "These are the finest set of antlers around.\n");
         call_other(weapon, "set_class", 7);
         call_other(weapon, "set_value", 2200);
         call_other(weapon, "set_weight", 3);
         call_other(elk, "wield_object", weapon);
         transfer(weapon, elk);
         call_other(weapon,"set_hit_func", this_object());
         move_object(elk, this_object());
         }
    i = 0; 
	if(!present("cow elk",this_object())) {
     while(i<3) { 
    i += 1; 
    celk = clone_object("obj/monster"); 
    call_other(celk, "set_name", "cow elk"); 
    call_other(celk, "set_alias", "cow"); 
    call_other(celk, "set_race", "elk"); 
    call_other(celk, "set_level", random(9) + 2); 
    call_other(celk, "set_hp", random(100)+150);  
    call_other(celk, "set_al", 400); 
    call_other(celk, "set_short", "A cow elk"); 
    call_other(celk, "set_ac", 5); 
    call_other(celk, "set_wc", 11);
    call_other(celk, "set_aggressive", 0); 
    horn = clone_object("obj/treasure");
    call_other(horn, "set_id", "tooth");
    call_other(horn, "set_alias", "elk's tooth");
    call_other(horn, "set_short", "An elk's tooth");
    call_other(horn, "set_long", "An elk's tooth, pure ivory.\n");
    call_other(horn, "set_weight", 2);
    call_other(horn, "set_value", random(400) + 50);
    move_object(horn, celk);
    move_object(celk, this_object()); 
    } 
  } 
}
 
weapon_hit(attacker) {
          return 11;
}
