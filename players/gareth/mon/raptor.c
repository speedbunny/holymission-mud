#include "/players/gareth/define.h"
inherit "/obj/npc";

  reset(arg) {
   ::reset(arg);
   if (!arg) {   
   set_name("raptor");
   set_alt_name("deadly raptor");
   set_short("A Deadly Raptor");
   set_race("dragon");
   set_long("You see a sleek and powerful dinosaur. The most dangerous\n"+
           "all ceatures. It jaws are are laced with dagger size teeth,\n"+
	   "and razor sharp claws extend from it's hands. He's gonna get Ya\n");
   set_level(50);
   set_hp(4800);
set_wc(70000000);
   set_ac(10);
   set_aggressive(1);
   set_chance(40);
   set_spell_mess1("The raptor slices and dices through its oppenent");
   set_spell_mess2("The raptor has you now, you're toast!!");
   set_spell_dam(50+random(20));
   set_dodge(35);
   set_attacks(2);
   set_attacks_change(40);

     
}}
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
    "The raptor smashes your weapon!! YOU ARE NOW WEAPONLESS!!!\n");

    say("The raptor takes"+AO->N+" weapon in it's jaw and breaks it!!!\n",AO);
}
    return 1;
}
    return 0;
}
 return 1;}
}

