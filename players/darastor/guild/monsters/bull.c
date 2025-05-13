
inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) return;
 
    	set_name("Black Bull");
    	set_alias("bull");
    	set_short("Black Bull");
    	set_long("This is an angry looking bull sitting in the plains.\n");
    	set_level( 15 + random(3) );
    	set_hp(2500);
    	set_gender(1);
    	set_race("bull");
    	set_aggressive(1);
    	set_ac(5);
    	set_wc(15);
    	set_number_of_arms(3);
}
