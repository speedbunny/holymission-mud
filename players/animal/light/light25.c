#include "std.h"
 
#define me capitalize(this_player()->query_real_name())
 
object king;
object head;
 
#undef EXTRA_RESET
#define EXTRA_RESET make_king();
 
ONE_EXIT("players/animal/light/light24", "north",
      "King's room",
         "The King's room\n\n" +
         "    The king of the good world makes his home here.\n"+
         "    He is a jolly and rotund fellow with a gleam in his eyes.\n"+
         "    You notice the king is not at all surprised to see you.\n"+
         "    He is sitting at his table eating (as usual). You feel\n"+
         "    very relaxed in his presence.\n\n", 1)
 
make_king() {
  if (!king || !living(king)) {
    object money;
    king=clone_object("obj/monster");
    call_other(king, "set_name", "ralph");
    king->set_alt_name("king");
    call_other(king, "set_alias", "king ralph");
    call_other(king, "set_short", "The good King Ralph");
    call_other(king, "set_long", 
    "This is the good king Ralph. He is a short and fat man.\n" +
    "He has an aura of good surrounding him that hurts to look\n" +
    "at. You notice that while he is fat, he looks strong.\n");
    call_other(king, "set_level", 17);
    call_other(king, "set_hp", 400 + random(150));
    call_other(king, "set_wc", 18);
    call_other(king, "set_ac", 12);
    call_other(king, "set_al", 1600);
    call_other(king, "set_dead_ob", this_object());
    call_other(king, "set_chance", 25);
    call_other(king, "set_spell_mess1",
    "The king mutters some words and food flies from his fingertips");
    call_other(king, "set_spell_mess2",
    "The king summons food that hits you hard in the head");
    call_other(king, "set_spell_dam", 20);
    money = clone_object("obj/money");
    call_other(money, "set_money", (random(1000)+1000));
    move_object(money, king);
    move_object(king, this_object());
    }
}
 
monster_died() {
   head = clone_object("players/animal/obj/head");
   tell_room(this_object(),me+ " hacks off the good king's head!\n");
   move_object(head, this_object());
   write_file("/players/animal/quest",me+" killed the King on "+
	ctime(time())+".\n");
  return 0;
}
 
realm() { return "NT"; }
