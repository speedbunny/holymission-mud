inherit "obj/monster";
object plate,bow,helmet;


reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("red archer");
	set_alias("archer");
	set_short("A Red Archer");
    set_long("A trianed archer of cao Cao's red army. He growls at you and\n"+
" points his bow at you. You better becareful\n");
	set_level(25);
    set_gender(1);
	set_race("human");
	add_money(100+random(800));
	set_n_wc(7);
	set_n_ac(5);
	set_number_of_arms(2);
   plate=clone_object("/players/tinman/area/armors/plate");
    move_object(plate,this_object());
    bow=clone_object("/players/tinman/area/weapons/bow");
    move_object(bow,this_object());
   helmet=clone_object("/players/tinman/area/armors/helmet");
   move_object(helmet,this_object());
command("powerup");
}

