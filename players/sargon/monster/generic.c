inherit "/obj/npc"; 

reset(arg){
    ::reset(arg); 
    if(!arg) { 
	set_name("stormtrooper"); 
	set_short("Stormtrooper"); 
	set_long(".\n"+ 
	  ".\n" + 
	  "\n"+  
	  "\n"+  
	  ".\n") ; 
	set_level(45);         
	set_ac(55); 
	set_wc(55); 
	set_hp(4000); 
	set_al(-1000); 
	set_aggressive(1); 
	set_chance(55); 
	set_spell_mess1(); 
	set_spell_mess2(); 
	set_spell_dam(85); 
	set_dodge(30); 
	set_fol_change(65); 
	set_rid_change(15); 
	set_attacks(3); 
	set_attacks_change(45); 
	add_money(1500); 
    }
}

