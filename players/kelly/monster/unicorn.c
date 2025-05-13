inherit "obj/monster";
 
object horn;
status arg;
 
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("unicorn");
 set_level(20);
 set_hp(1500);
 set_al(1000);
 set_race("unicorn");
 set_female();
 set_size(3);
 set_short("A unicorn");
 set_long("Unicorns are holy beings and have magic powers.\n");
 set_ac(15);
 set_wc(30);
 set_aggressive(0);
 set_spell_mess1("The Unicorn slashes the offender with its horn!");
 set_spell_mess2("You're slashed by the unicorn's horn.");
 set_chance(25);
 set_spell_dam(60);
 
 horn=clone_object("/obj/weapon");
 horn->set_name("horn");
#if 0 /* This is a rediculous wc, especially considering the hit_func. Bonzo. 22/07/92 */
 horn->set_class(30);
#endif
#if 1 /* Perhaps this is better. Bonzo. */
 horn->set_class(15);
#endif
 horn->set_weight(2);
 horn->set_short("A unicorn's horn");
 horn->set_long("This is the horn of a unicorn.\n");
 horn->set_value(5125);
 horn->set_hit_func(this_object()),
 move_object(horn,this_object());
 init_command("wield horn");
 
 
}
 
weapon_hit(attacker) {
#if 0 /* This is still too high. I'll lower the chance, then. Bonzo. 22/07/92 */
  if(!random(2)) {
#endif
#if 1 /* Perhaps this is better. Bonzo. 22/07/92 */
  if(!random(10)) {
#endif
    write("A blue flash crackles out of the horn and hits "+attacker->query_name() 
      +" hard.\n");
    say("A blue flash crackles out of the horn and hits "+attacker->query_name() 
      +" hard.\n");
    return 50;
  }
}
 
