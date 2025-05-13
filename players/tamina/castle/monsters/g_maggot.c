inherit "/obj/monster";

reset(arg) {
::reset(arg);
if(arg) return;

	set_name("giant maggot");
	set_alias("giant");
	set_level(12);
	set_short("A giant maggot");
	set_long("An enormous, creepy-crawly thing, that makes you positively\n"+
                  "sick looking at it!\n");
	set_al(0);
	set_aggressive(1);
	set_hp(250);
	set_wc(13);
	set_ac(4);
	set_spell_mess2("The Giant Maggot devours you!\n");
	set_spell_mess1("The Giant Maggot crushes "+name+" in its jaws!!\n");
	set_chance(5);
	set_spell_dam(10+random(21));
	}
