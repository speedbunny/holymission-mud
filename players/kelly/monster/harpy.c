inherit "obj/monster";
 
object ball;
status arg;
 
reset() {
 ::reset();
 if(arg) return;
 arg=1;
 set_name("harpy");
 set_level(20);
 set_size(3);
 set_hp(1500);
 set_al(-1000);
 set_female();
 set_race("bird");
 set_short("A harpy");
 set_long("Harpys are the most evil creatures that live on earth.\n");
 set_ac(15);
 set_wc(30);
 set_aggressive(1);
 set_spell_mess1("The harpy strikes the attacker with its fangs!");
 set_spell_mess2("You're hit by the harpy's fangs");
 set_chance(25);
 set_spell_dam(60);
 
 ball=clone_object("/players/kelly/obj/crys_ball");
 move_object(ball,this_object());
 
}
 
 
init () {
 ::init();
}
 
