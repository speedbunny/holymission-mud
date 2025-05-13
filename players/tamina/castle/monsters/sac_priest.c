inherit "/obj/monster";

#include "/players/tamina/defs.h"
object robe, knife;

reset(arg) {
  ::reset(arg);
  if(!arg) { 

	set_name("Sacrificial Priest");
        set_alt_name("sacrificial");
	set_alias("priest");
	set_race("human");
	set_gender(1);
	set_level(40);
	set_short("A Sacrificial Priest");
	set_long(
"A seven-foot tall, bald man with glowing red eyes, who wears a voluminous\n"+
"red robe.  His fingers are so long and spindly, and his neck so long that he\n"+
"has the look of a spider in human form...\n"+
"The occasional red spark that flashes from his fingers suggests that he knows\n"+
"a thing or two about sorcery\n");
	set_al(-900);
	set_aggressive(1);
	set_wc(35);
	set_ac(25);
	set_spell_mess2(
"Streaks of blood-red lightning crackles from the Priest's finger-tips...\n"+
"They smack into you thunderously!!!\n");
	set_spell_mess1(
"Blood-red lightning streak from the Priest's fingers and thud into his\n"+ 
"victim's body, frying him!\n");
	set_spell_dam(41 + random(59));
	set_chance(25);
        load_a_chat(30,
     ({"The Priest screams at your sacrilege!!\n",
       "The Priest mutters a quick prayer to his foul God for strength.\n",
       "The Sacrificial Priest says: What are you doing here?!  Get out!\n",
       "The Priest calls for his guards!\n"}) );
   
    robe  = CLO (COBJ + "sac_robe");
    knife = CLO (COBJ + "sac_knife2");

    MO (robe,  TO);
    MO (knife, TO);

    command("wield knife");
    command("wear robe");

	}

}
