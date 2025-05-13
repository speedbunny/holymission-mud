#define RELIGION "Illuvatar"

/*HERP: no Ohrring anymore. it's nonsense. */

inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
    dest_dir=({"room/church","west",
	       "players/patience/shadows/entergy","north"}); 
               /* Patience quest */
    short_desc="The fathers stool";
    long_desc="Everything is silent here. The only sound you hear comes from\n"
	    + "from the robe of the father, as he pages through the bible,\n"
            + "praying. Pray, pilgrim, pray for the mercy of god!\n";
    no_castle_flag=1;
  }
  if (!present("father",this_object())) {
     object ft,cx,rb;
     cx=clone_object("obj/treasure");
     cx->set_id("crucifix"); 
     cx->set_short("A small silver crucifix");
     cx->set_value(100);     
     rb=clone_object("obj/armour");
     rb->set_id("robe");
     rb->set_short("A priest's robe");
     rb->set_value(100);
     rb->set_weight(1);
     rb->set_ac(1);
     rb->set_type("robe");
     ft=clone_object("obj/monster");
     ft->set_name("priest");
     ft->set_alias("father");
     ft->set_race("human");
     ft->set_level(10);
     ft->set_al(1000);
     ft->set_short("A praying priest");
     ft->set_wc(10);
     ft->set_ac(3);
     ft->set_aggressive(0);
     ft->set_chance(40);
     ft->set_spell_mess1("The priest prays an Ave Maria.");
     ft->set_spell_mess2("The priest tries to calm down the fight.");
     ft->set_spell_dam(20);
     move_object(ft,this_object());
     transfer(cx,ft);
     transfer(rb,ft);
     command("wear robe",ft);
     return 1; 
  }
}

init() {
  ::init();
  add_action("pray","pray");
}

pray() {
string belief;

  belief=this_player()->query_religion();
  if((!belief)||(belief!=RELIGION)) {
    notify_fail("You're not a follower of "+RELIGION+"!\n");
    return 0;
  }
  write("You kneel down in prayer.\n");
  say(this_player()->query_name()+" kneels down in prayer.\n");
  return 1;
}
