#include "/players/gareth/define.h"
inherit "/obj/npc";

  reset(arg) {
   ::reset(arg);
   if (!arg) {   
   set_name("Greater Invid");
   set_alt_name("greater invid");
   set_alias("invid");
   set_short("A Greater Invid");
   set_race("invid");
   set_long("You see a damn ugly beast. It's has thick grey scaley \n"+
           " skin. It has no normal head. It's tall dark and freaking\n"+
	   "ugly! Just Like you !! \n");
   set_level(50);
   set_hp(3500);
   set_wc(50);
   set_ac(50);
   set_aggressive(1);
   set_chance(40);
   set_spell_mess1("The invid slices and dices through its oppenent");
   set_spell_mess2("The invid has you now, you're toast!!");
   set_spell_dam(50+random(20));
   set_dodge(35);
   set_attacks(2);
   set_attacks_change(40);
   add_money(3000);

   }
}
 
int i;
attack() {
object wep;
   wep=AO->QW;

    if(::attack()) {
    if(random(10)<3) {
    if(AO && living(AO)) {
    if(AO->QW){
    destruct(wep);
    tell_object(AO,
    "The Invid smashes your weapon!! YOU ARE NOW WEAPONLESS!!!\n");

    say("The Invid takes"+AO->N+" weapon in it's claws and breaks it!!!\n",AO);
}
    return 1;
}
    return 0;
}
 return 1;}
}

