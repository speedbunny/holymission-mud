
inherit "obj/monster";

object fur;

reset(arg) {
 ::reset(arg);
 if(arg) return;

    	set_name("Golden Lion");
    	set_alias("lion");
    	set_short("Golden Lion");
    	set_long("A golden lion watching over the land for trouble and food.\n");
    	set_level( 10 + random(3) );
    	set_hp(700);
    	set_gender(1);
    	set_race("feline");
    	set_ep(40000);
    	set_ac(7);
    	set_wc(6);
    
	fur = clone_object("/players/darastor/guild/armour/lion_fur");
    		transfer(fur,this_object());
    
	init_command("powerup");
}
