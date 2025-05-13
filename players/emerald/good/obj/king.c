#define TPN this_player()->query_name()
inherit "obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("king Ralph");
  set_gender(1);
  set_alias("king");
  set_alt_name("ralph");
  set_short("The good King Ralph");
  set_long("This is the good king Ralph. He is a short and fat man.\n" +
           "He has an aura of good surrounding him that hurts to look\n" +
           "at. You notice that while he is fat, he looks strong.\n");
  set_level(17);
  set_wc(18);
  set_ac(12);
  set_al(1600);
  set_dead_ob(this_object());
  set_chance(25);
  set_spell_mess1("The king mutters some words and food flies from " +
                  "his fingertips");
  set_spell_mess2("The king summons food that hits you hard in the head");
  set_spell_dam(20);
  set_dead_ob(this_object());
}

monster_died() {
object head;
   head = clone_object("players/emerald/good/obj/head");
   tell_room(this_object(),TPN+ " hacks off the good king's head!\n");
  move_object(head, this_object());
  return 0;
}

