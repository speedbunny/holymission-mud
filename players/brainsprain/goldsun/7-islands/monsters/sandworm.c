inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("sandworm");
set_race("worm");
set_short("A sandworm");
set_long(
"A huge, yellow sandworm swims in and out of the sand thrashing about "+
"as it goes.  Small spikes shoot in and out of its hide as its jaws "+
"open and shut, swallowing sand and gleening nutrients from it.\n");
set_level(20);
set_wc(18);
set_ac(5);
set_size(4);
set_aggressive(1);
set_spell_mess1("Sandworm bites you with its body.\n");
set_spell_mess2("");
set_chance(33);
set_spell_dam(50);
set_al(-80);
}

