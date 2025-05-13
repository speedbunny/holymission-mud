inherit"obj/monster";

reset (arg) {
    ::reset(arg);
    if (!arg) {
	set_name("claudius");
	set_level(40);
	set_gender(1);
	set_race("immortal");
	set_alias("gladiator");
	set_al(0);
	set_short("Claudius the Gladiator");
	set_long("An immortal stands before you, his name is Claudius.\n" +
	  "He gazes sadly at you.\n");
	set_wc(20);
	set_aggressive(1);
load_chat(10, ({
"Claudius says: Can you kill me?\n",
"You see in his eyes the weariness of living.\n"}));
	set_dead_ob(this_object());
	set_spell_mess2("Claudius catches you in his net and skewers you with his trident!\n");
set_spell_mess1(capitalize(previous_object()->query_name())+" is caught in Claudius' net and is skewered by his trident!\n");
	set_chance(99);
	set_spell_dam(25);
	set_ac(18);
    }
}
hit_player(dam) {
object ob;
if(ob=present("durandal",this_player 
if (ob->query_wielded()) {return :: hit_player (200);}}
return :: hit_player(0);}
monster_died(ob) {
    write("You have killed an immortal!\n" +
      "Electricity and lightning crackles around you and through you as power courses\n" +
      "through your being!\n");
    return 0;
}
