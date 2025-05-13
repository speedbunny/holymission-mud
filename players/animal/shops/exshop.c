#include "../../../room/std.h"
 
#undef EXTRA_INIT
#define EXTRA_INIT\
   add_action("buy"); add_verb("buy");\
   add_action("list"); add_verb("list");\
 
ONE_EXIT("players/animal/shops/shop_street2", "west",
       "Explosives shop",
          "The blow place\n\n"+
          "    You are in an explosives shop. This place sells explosives.\n"+
          "    These explosives are harmful to ALL creatures including\n"+
          "    yourself! So we be careful when using them! Just type in\n"+
         "    'throw bomb <direction> ' once you buy one, and the bomb will\n"+
          "    explode in the direction of which you throw it. There is NO\n"+
          "    insurance on these, so if ya die using them TOUGH!\n"+
          "    You may 'list' or 'buy item'.\n\n", 1)
list() {
     write("You may purchase any one of the following.\n\n");
     write("    Lady finger              50  coins  (NO damage done)\n");
     write("    Firecracker            1000  coins\n");
     write("    M-80                   1500  coins\n");
     write("    A stick of TNT         2500  coins\n");
     write("    Three sticks of TNT    4000  coins\n");
     write("    A nuke                10000  coins\n\n");
     return 1;
}
 
id_item(str) {
          return (str == "firecracker" || str == "m-80" || str == "M-80" ||
          str == "stick" || str == "stick of TNT" || str == "three" ||
          str == "three sticks" || str == "sticks" ||
          str == "three sticks of TNT" || str == "lady finger" ||
          str == "finger" || str == "nuke");
}
 
buy(item) {
   object grenade;
   int value,a_value, a_weight, d;
   string a_name, a_short, a_long, a_alias;
   if (!item) {
     write("Buy what???\n");
     return 1;
     }
   if(!id_item(item)) {
     write("We do not sell that, sorry.\n");
     return 1;
     }
   grenade = clone_object("players/animal/obj/grenade");
   if (item == "lady finger" || item == "finger") {
      a_name = "lady finger";
      a_short = "A lady finger";
      a_alias = "finger";
      a_long = "A small lady finger (harmless, but FUN!)\n";
      a_value = 25;
      value = 50;
      a_weight = 1;
      d = 0;
   }
   if (item == "firecracker") {
      a_name = "firecracker";
      a_short = "A firecracker";
      a_long = "A small fircracker.\n";
      a_value = 125;
      value = 1000;
      a_weight = 1;
      d = random(5)+15;
   }
   if (item == "m-80" || item == "M-80") {
      a_name = "m-80";
      a_short = "A M-80";
      a_long = "This is a M-80, it looks powerful!\n";
      a_value = 875;
      a_weight = 1;
      value = 1750;
      d = random(5)+30;
   }
   if (item == "stick" || item == "stick of TNT") {
      a_name = "TNT";
      a_alias = "stick";
      a_short = "A stick of TNT";
      a_long = "This looks a nice little explosive.\n";
      a_value = 1250;
      a_weight = 2;
      value = 2500;
      d = random(15)+35;
   }
   if (item == "three" || item == "three sticks" ||
          item == "sticks" || item == "three sticks of TNT") {
      a_name = "TNT";
      a_short = "Three sticks of TNT";
      a_alias = "three sticks";
      a_long = "This is deadly stuff! WATCH IT!\n";
      a_value = 2000;
      a_weight = 4;
      value = 4000;
      d = random(25)+55;
   }
   if (item == "nuke") {
      a_name = "nuke";
      a_short = "A thermonuclear device";
      a_alias = "nuclear bomb";
      a_long = "This bomb is BIG and VERY dangerous!!!!\n";
      a_value = 5000;
      a_weight = 7;
      value = 10000;
      d = random(50)+150;
   }
   call_other(grenade, "set_id", a_name);
   call_other(grenade, "set_name", a_name);
   call_other(grenade, "set_short", a_short);
   call_other(grenade, "set_long", a_long);
   call_other(grenade, "set_alias", a_alias);
   call_other(grenade, "set_value", a_value);
   call_other(grenade, "set_weight", a_weight);
   call_other(grenade, "set_damage", d);
   if (call_other(this_player(), "query_money", 0) < value) {
   write("That item costs " + value + " gold coins, which you don't"+
     " have.\n");
      destruct(grenade);
      return 1;
   }
   if (!call_other(this_player(), "add_weight",
      call_other(grenade, "query_weight"))) {
      write("You can't carry more.\n");
      destruct(grenade);
      return 1;
   }
   call_other(this_player(), "add_money", - value);
   write("You pay " + value + " for a " + a_name + ".\n");
   say(this_player()->query_name()+" buys "+a_name+".\n");
   move_object(grenade, this_player());
        return 1;
}
