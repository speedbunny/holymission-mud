
inherit "obj/monster";

object fur;

reset(arg) {
 ::reset(arg);
 if(arg) return;
 
	set_name("Grizzly Bear");
	set_alias("bear");
	set_short("Grizzly Bear");
	set_long("A over size bear just sitting around taken it easy after\n"+
      		 "eating a whole deer.\n");
 	set_level( 10 + random(3) );
	set_hp(700);
	set_gender(1);
	set_race("grizzly");
	set_ac(3);
	set_wc(10);
	set_number_of_arms(2);

    fur = clone_object("/players/apollo/guild/armour/bear_fur");
    	transfer(fur,this_object());

    init_command("powerup");
}
