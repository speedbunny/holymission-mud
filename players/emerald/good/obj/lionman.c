inherit "obj/monster";
 
#include "/obj/obj_defs.h"
 
string who_gave;
 
void set_who_gave(string str) {
  who_gave = str;
}
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("lionprince");
  set_alias("prince");
  set_alt_name("lion");
  set_race("cat");
  set_no_steal(1);
  set_level(19);
  set_al(-1095);
  set_hp(2000);
  set_short("The prince of lions");
  set_long("This creature rules the EVIL cat world.\n");
  set_wc(26);
  set_ac(15);
  set_aggressive(0);
  set_chance(30);
  set_trapped(1);
  set_dead_ob(this_object());
 
  set_spell_mess1("The lionprince attacks with his claws");
  set_spell_mess2("The claws tear you to shreds");
  set_dead_ob(this_object());
  load_chat(35,({
    "The prince growls: Bring me the head.\n",
    "The prince growls: Leave now mortal.\n",
    "The prince growls: I want his head!\n",
    "The prince growls: Kill the king!\n",
  }));
 
  load_a_chat(40,({
    "The prince screams in rage!\n",
    "The prince looks like the devil incarnate!\n",
    "The prince roars: You will not succeed!\n",
    "The prince growls: DIE SCUM!\n",
  }));
 
  who_gave = "no one";
}
 
enter_inventory(ob) {
  if(!ob->id("king ralph's head")) {
    tell_room(ENV(TO),"\nThe Prince growls: DO NOT WASTE MY TIME MORTAL!\n");
    tell_object(TP, "\nYou will pay for this!\n\n");
    call_out("attack_object", 2, TP);
  }
}
 
monster_died() {
  object met;
 
  if(met = present(who_gave, ENV(TO))) {
    if(!met || !met->query_player()) {
      return 1;
    }
    TELLR(ENV(TO),"\nGood job "+CAP(who_gave)+". See you"+
          " in HELL!!!! MUHAHAHAHA!\n\n");
    log_file("emerald.quest", who_gave+" solved LION quest on "+
             ctime()+".\n");
    if(met->query_quests("lion"))
      return 0;
    met->set_quest("lion");
    return 0;
  }
  else{
    write("The Lionprince chortles: You killed me, but you didn't " +
          "solve the quest!\n");
    return 0;
  }
  return 0;
}
