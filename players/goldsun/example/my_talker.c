/*

In my opinion only this is problem in whole transport system,
 that talker is monster, and you can attack it, so i had to
 set property no_fight in the my_aboard.c

But i hope that one of you code more better talker.

The idea is: use heart_beat, but set_heart_beat(0) if no player here.
             you should code it as no_kill_possible object.

Good luck.
*/
inherit "obj/monster";


reset(arg){
 ::reset(arg);

 load_chat(40,({"A wind blows.\n","You see birds fly around the ship\n",
		     "Sea looks nice.\n"}));

 if (arg) return;
 set_level(1);
 set_name("invisible talker");
 set_short(0);
 set_long("Invisible talker.\n");
 is_invis=30;
 set_no_fight(1);
 set_ac(1000000);
 set_hp(1000000);
}

