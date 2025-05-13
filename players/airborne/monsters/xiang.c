inherit "/obj/monster";
object katana;

reset(arg) {
	::reset(arg);
	if(arg)return 1;
	set_name("xiang jiao");
	set_race("human");
	set_gender(2);
	set_alias("xiang");
	set_short("Xiang Jiao");
	set_long("Before you stands an ominious shadowy figure.\n" + "She is calm and quiet but her hand is not far from her sword.\n");
	set_level(10);
	add_money(10 *(random(5)+1));
	set_whimpy();
	set_al(-10);
	set_aggressive();
	if(!present("katana")){
	   katana=clone_object("players/airborne/weapons/katana");
	   move_object(katana,this_object());
	   init_command("wield sword");
    }
   return 1;
}
