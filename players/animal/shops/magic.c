#include "../../../room/std.h"
 
#undef EXTRA_INIT
#define EXTRA_INIT\
   add_action("buy"); add_verb("buy");\
   add_action("list"); add_verb("list");\
 
#undef EXTRA_RESET
#define EXTRA_RESET ex_reset();
 
status l,d,j;
 
ex_reset() {
          l = random(4) + 1;
          d = l;
	j = l;
}
 
ONE_EXIT("players/animal/shops/shop_street3", "west",
       "Magic shop",
          "The magic shop\n\n"+
          "    You are in a magic shop. This place sells magic items.\n"+
          "    The items here can be VERY useful to players. There will\n"+
          "    be new and exciting items sold here often, so enjoy\n"+
          "    this place.\n"+
          "    You may 'list' or 'buy item'.\n\n", 1)
list() {
     write("You may purchase any one of the following.\n\n");
	if(j > 0)
     write("    A portable Judger      500 coins\n");
#if 0
     write("    A black box            800 coins\n");
#endif
     write("    Ring of following     1000 coins\n");
	if(l >0)
     write("    A rusty lamp          5000 coins\n");
	if( d > 0)
     write("    A black diamond      10000 coins\n\n");
     return 1;
}
 
id_item(str) {
          str = lower_case(str);
          return (str == "diamond" || str == "black diamond" ||
               str == "rusty lamp" || str == "lamp" || str == "ring" ||
str == "ring of following" || str == "box" || str =="black box"
	|| str == "judge" || str == "judger");
}
 
buy(item) {
   object itemt;
   int value;
   string c_name, a_name;
 
   if (!item) {
     write("Buy what???\n");
     return 1;
     }
   if(!id_item(item)) {
     write("We do not sell that, sorry.\n");
     return 1;
     }
     if(l == 0 && (item == "lamp" || item == "rusty lamp")) {
     write("I am sorry but that item is sold out.\n");
     return 1;
     }
     if(d == 0 && (item == "diamond" || item == "black diamond")) {
     write("I am sorry but that item is sold out.\n");
     return 1;
     }
     if(j == 0 && (item == "judge" || item == "judger")) {
     write("I am sorry but that item is sold out.\n");
     return 1;
     }
   if (item == "ring" || item == "ring of following") {
      a_name = "ring of following";
      c_name = "follow";
      value = 1000;
   }
   if (item == "lamp" || item == "rusty lamp") {
      a_name = "rusty lamp";
      value = 5000;
      c_name = "lamp";
      l = l-1;
   }
   if (item == "judge" || item == "judger") {
      a_name = "Judger";
      value = 500;
      c_name = "judge";
      j = j-1;
   }
    if(item == "box" || item == "black box") {
      a_name = "black box";
      value = 800;
      c_name = "box";
     }
   if (item == "diamond" || item == "black diamond") {
      a_name = "black diamond";
      value = 10000;
      c_name = "diamond";
      d = d-1;
   }
   if (call_other(this_player(), "query_money", 0) < value) {
   write("That item costs " + value + " gold coins, which you don't"+
     " have.\n");
      return 1;
   }
   itemt = clone_object("players/animal/obj/"+c_name);
        if (!call_other(this_player(), "add_weight",
          call_other(itemt, "query_weight"))) {
          write("You can't carry more.\n");
          destruct(itemt);
          return 1;
   }
   move_object(itemt, this_player());
   call_other(this_player(), "add_money", - value);
   write("You pay " + value + " for a " + a_name + ".\n");
   say(this_player()->query_name()+" buys "+a_name+".\n");
   return 1;
}

/* Herp */

#if 0 
restore()  {
     int yea;
     object ob, me;
     me=this_player()->query_real_name();
     ob=present("black box",this_player());
     yea=restore_object("players/animal/alias/"+me);
     if(!yea) {
     write("Get real!!! You have never owned a box.\n");    
     return 1;
     }
     if(ob) {
     write("You already have one on you!\n");
     return 1;
     }
     write("You must have lost yer old box, sorry bout that.\n");
     write("You now have a new box with all your commands still there.\n");
     move_object(clone_object("players/animal/obj/box"),this_player());
     return 1;
}
#endif 
