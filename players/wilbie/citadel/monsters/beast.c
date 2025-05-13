inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("beast");
    set_aggressive(1);
    set_walk_chance(20);
    set_walk_limit("/players/wilbie/citadel");
    
    set_level(40);
   set_wc(8);
   set_ac(5);

    set_al(-1000);
    set_gender(1);
    set_race("beast");
    set_long(
      "This rather manacing monster must have been put here to guard the "+
      "pit you find yourself in.  By the looks of the piles of bones, it "+
      "must be doing a good job!\n");
    set_size(3);
    return;
}
hit_player(dam){
switch(random(10)){
    case 0..1:
write("The beast pounds you with a massive fist!\n");
this_player()->
hit_player(random(20));
break;
    case 2:
write("The beast tears at you with its claws!!\n");
this_player()->
hit_player(random(40));
break;
    case 3:
write("The beast slams it's body into you!\n");
this_player()->
hit_player(random(30));
break;

   case 4:
write("The beast misses with a wild swing!\n");
break;

   case 5:
write("The beast roars!\n");
break;

   case 6:
write("The beast spits in your eye!\n");
break;

   case 7:
write("The beast bellows in rage!\n");
break;

   case 8:
break;

   case 9:
break;
default:
break;

return ::hit_player(dam);
    }}
