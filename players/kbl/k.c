#include "/players/gareth/define.h"
inherit "/obj/npc";
object scimitar;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("knight");
	set_short("white knight");
	set_long(
	  "This is a White Knight of the White King.\n"+
	  "He is mumbling something about taking your head off.\n"+
	  "\n");
	set_level(45);        
	set_ac(55);
	set_wc(55);
	set_hp(4000);
	set_al(-1000);
	set_aggressive(1);
	set_chance(55);
	set_spell_dam(85);
        set_spell_mess1("White Knight tries to take your head off.");
	set_dodge(30);
        set_spell_mess2("White Knight tries to take your head off.");
	set_fol_change(65);
	set_rid_change(15);
	set_attacks(3);
	set_attacks_change(45);
	add_money(1500);


	scimitar= TR(CO(ITEM+"scimitar"), TO);
	init_command("wield scimitar");


    }

}
