inherit "obj/monster";

  reset(arg) {
   ::reset(arg);
   if (!arg) {   
   set_name("serpent");
   set_alt_name("deadly serpent");
   set_short("A Deadly Serpent");
   set_race("dragon");
   set_long("you see a sleek and powerful dragon lying on the sand.\n"+
            "it is long and slender.\n");
   set_level(30);
   set_hp(1800);
set_wc(10000000);
   set_ac(10);
   set_aggressive(1);
   set_chance(40);
   set_spell_mess1("The serpent blasts you with it's golden fire");
   set_spell_mess2("The serpent's golden fire burns you badly, you're toast!!");
   set_spell_dam(20+random(20));
     
}}
int i;
attack() {
object wep;
   wep=attacker_ob->query_wielded();

    if(::attack()) {
    if(random(10)<3) {
    if(attacker_ob && living(attacker_ob)) {
    if(attacker_ob->query_wielded()){
    destruct(wep);
    tell_object(attacker_ob,
    "The serpent grabs your weapon with it's jaw!! YOU ARE NOW WEAPONLESS!!!\n");

    say("The serpent grabs"+attacker_ob->query_name()+" weapon in it's jaw!! YOU ARE NOW WEAPONLESS!!!\n",attacker_ob);
}
    return 1;
}
    return 0;
}
 return 1;}
}
