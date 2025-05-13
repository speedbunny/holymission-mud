#include "/players/qclxxiv/mymonster.h"
object coat, boots, gloves;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ 
"Serpent hisses: slslslsllslslslslslslsl.\n",
"Serpent drips slime on the floor.\n",
"Serpent eyes you evilly.\n",
"Serpent curls its tail.\n",
"Serpent burps, as if it had a heavy meal just before.\n",
	}));
	load_a_chat(10,({ 
"Serpent hisses: SLSLSLSLLSLSLSLSLSLSLSL.\n",
"Serpent spits slime towards you.\n",
"Serpent tries to curl its tail around your legs.\n",
"Serpent shows its poison teeth.\n",
	}));
	set_name("serpent");
	set_race("skum");
	set_level(24);
   	set_wc(17);
	set_ac(8);
   	set_hp(1400);
	set_sp(90);
   	set_spell_mess1("Serpent spits acidic slime on its enemy.");
   	set_spell_mess2("Serpent spits acidic slime on you.");
	set_chance(20);
	set_spell_dam(30);
	set_al(-22);
   	set_aggressive(0);
   	set_short("Slime serpent");
	set_gender(0);
   	set_long( "A hideous slime serpent. Its belly shows strange bubbles.\n" );
	set_size(3);
}

notify(str) {
    say(str);
    write(str);
}

second_life() {
	if (!boots) {
		notify("Serpent rattles: sssslllssss.\n");
		PLACE_IN_THIS(boots,HOME+"leaf6/serpboots");
		PLACE_IN_THIS(gloves,HOME+"leaf6/serpgloves");
		PLACE_IN_THIS(coat,HOME+"leaf6/serpcoat");
	}
	return 0;
}
