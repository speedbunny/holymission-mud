inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("ooze");
    set_alias("slimer");
    set_alt_name("green ghou");
    set_short("ooze the utter slime(slimey)");
    set_long("This is ooze, some left over from a wizzard experiment,\n"+
             "which utterly failed leaving this piece of DEADLY slime.\n");
    set_race("failed");
    set_gender(1);
    set_level(15);
    set_hp(1000);
    set_al(-1000);
    set_ep(60000);
    set_wc(30);
    set_aggressive(1);
    set_move_at_reset(0);
    add_money(random(10000));
    set_whimpy(0);
    set_spell_mess1("ooze strikes you with a piece of slime");
    set_spell_mess2("ooze slimed all over you");
    set_chance(20);
    set_spell_dam(50);
  }
}


attack() {
  object victim;


  if (::attack()) {  /* here we redefine the attacker function :*) */

     victim=this_object()->query_attack(); /* by any attack we check :*) */

     if (random(100) < 50 ) { /*this is the chance of hitting */
         victim->hit_player(random(20)); /*how hard the hit is */
         message(victim);
             }
     else {
         victim->hit_player(random(15));
         message(victim);
             }
     return 1;  /* if ok  our attacker function is called :*) */
   } /*end of if*/
 return 0;   /* if not ok the old attacker function is called :*) */
}



message(victim) {  /* here we call the spell_message */
string attacker_name;

   attacker_name = victim->query_name();
      if (random(10)<5) {
          say("Ooze tries to hit you with a piece o slime.\n"); /*to attacker*/
          write("Ooze tries to hit "+attacker_name+" with a piece o slime.\n");
        }
        else  {
          say("Ooze tries to slime you.\n");
          write("Ooze tries to slime"+attacker_name+".\n");
         }
 return 1;
}

