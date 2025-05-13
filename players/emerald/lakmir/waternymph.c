#define TP this_player()
#define TO this_object()
#define ROOM "/players/emerald/lakmir/brooklet"
inherit "/obj/monster";

object giver;

reset(arg) {
  object ruby ;
  ::reset(arg);
  if (!arg) {
    set_name("water nymph");
    set_alias("nymph");
    set_short("A water nymph");
    set_long("A beautiful water nymph. She sits on the bank and weeps.\n");
    set_race("nymph");
    set_gender(2);
    set_level(30);
    set_al(800);
    set_wc(28);
    set_ac(15);
    set_aggressive(0);
    set_chance(30);
    set_spell_dam(23);
    set_spell_mess1("The water nymph dips you under the surface.");
    set_spell_mess2("The water nymph hits you with her tail.");
    set_dead_ob(this_object());
  }
  if (ruby = present ("ruby",this_object())) {
    destruct(ruby);
    set_long("A beautiful water nymph. She sits on the bank and weeps.\n");
  }
}

enter_inventory (ob) {
  object bottle;
  int i;
  if (ob->id("ruby") ) {
    for (i=0;bottle = present("bottle",TO);i++)
      transfer (bottle,environment(TO));
    if (!i)
      tell_room (environment(TO),"The water nymph smiles.\n");
    else if (i=1)
      tell_room (environment(TO), "The water nymph drops a bottle.\n");
    else if (i>0)
      tell_room (environment(TO),"The water nymph drops bottles.\n");
    set_long("A beautiful happy waternymph.\n"+
             "She is sitting on the bank and is playing with her ruby.\n");
  }
}

