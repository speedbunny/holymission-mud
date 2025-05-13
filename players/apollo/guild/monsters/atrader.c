/* Armour Trader */

inherit "obj/npc";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("kilrathi");
    set_short("Kilrathi");
    set_long("Kilrathi is the armour trader for this barbarian camp. He used\n"
      +"to be a rank barbarian until he lost his arm fighting a hundred orcs\n"
      +"at once. He is very muscular and sells the finest in skins and armour\n");
    set_level( 60 + random(20) );
    set_hp(3000);
    set_gender(1);
    set_race("crom");
    set_ac(10);
    set_wc(50);
    set_dodge(45);
    set_attacks(6);
    set_attacks_change(50);
    load_chat(20,({
	("Kilrathi sets up some of his finest armours.\n"),
	("Kilrathi looks at you with an evil eye.\n"),
	("Kilrathi sits behind the counter, cleaning his armour.\n"),
      }));
    load_a_chat (22,({
	("Kilrathi leaps up and yells something in a strange language !\n"),
	("Kilrathi unleashes his power !\n"),
	("Kilrathi growls: You are weak, you fucken fool !\n"),
      }));
}
