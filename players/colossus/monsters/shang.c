inherit "obj/monster";

#define AO attacker_ob

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("shang");
   set_alias("sorceror");
   set_short("Shang Tsung");
   set_long(
      "Shang Tsung the evil sorceror awaits you and grins at you demonically. He\n"+
      "calmly waits for the battle to commence. Say your prayers mortal!\n");
   set_level(50);
   add_money(3000);
   set_gender(1);
   set_race("human");
   set_hp(2000);
   set_wc(23);
   set_ac(12);
}
heart_beat(){
   ::heart_beat();
   if(AO && present(AO, environment()) ) {
      if(!random(5)) {
         tell_object(AO, "Shang Tsung hits you with a trio of MASSIVE fireballs.\n");
         say("Shang Tsung hits "+AO->query_name()+" with a trio of MASSIVE fireballs.\n", AO);
         AO->hit_player(35);
      }
   }
}
