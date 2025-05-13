/* FANG.C - Programmed by Whisky */
/* 300693: Ethereal Cashimor: Removed several bugs */
/* 090793: Ethereal Cashimro: Removed more bugs */
/* 210793: Moonchild: Major reduction in power & hit_player !reduce_hp */

#define TP this_player()
#define E environment
#include "/obj/lw.h"

object ob;

inherit "/obj/treasure";

  reset(arg) {
    if (arg) return 1;

    set_id("fang");
    set_alias("stone-fish fang");
    set_short("A stone-fish fang");
    set_value(100); /*wer den verkauft ist selber schuld */
    set_weight(1);
    set_long("This is stone fang of the dangerous stone-fish,\n"+
             "but it's also a great weapon against your enemies.\n"+
             "Just type <stinger> <name> * grin *, or just <stinger>\n"+ 
             "during the fight to inflict bad damage to your opponent.\n"+
             "But remember, it's only for a single use.\n");
    return 1; 
}

init() {
   ::init();
    add_action("stinger","stinger");
}

stinger(arg) {
  if(!arg) {
    notify_fail("Stinger what?\n");
    return 0;
  }
  if(ob) {
    notify_fail("You're already stinging someone!\n");
    return 0;
  }
  ob=present(arg,environment(this_player()));
  if(!ob) {
    notify_fail("That is not here.\n");
    return 0;
  }
  if(!living(ob)) {
    notify_fail("That isn't a living person.\n");
    return 0;
  }
  if(ob->query_invis()) {
    notify_fail("That is not here.\n");
    return 0;
  }
  call_out("do_it",1);
  return 1;
}

do_it() {
int i;

  say(lw(TP->query_name()+" sticks the dangerous fang happily into "
    + ob->query_name()+"'s skin! As the poison slowly warms "
    + ob->query_possessive()+" body, "+ob->query_name()
    + " growls from pain!\n"),ob);
  tell_object(ob,this_player()->query_name()
            + " sticks a fang into your body.\n");
  write("You stick the fang into "+ob->query_name()+".\n");
  TP->set_vis();
  if(ob->query_player()) {
    if(TP->query_wis()<14) {
      tell_room(environment(ob),"The attack fails, however.\n");
    }
    else {
      ob->hit_player(20);
/* Matt 8-1-93: What if object dies from hit_player?! Added "if" */
      if(ob) ob->add_poison(random(this_player()->query_level()/4));
    }
  }
  else {
    ob->hit_player(this_player()->query_level() * 2
	+ random(this_player()->query_level() * 4));
/* Matt 8-1-93: What if object dies from hit_player?! Added "if" */
    if(ob) ob->add_poison(random(this_player()->query_level()/2));
  }
  destruct(this_object());
  return 1;
}






