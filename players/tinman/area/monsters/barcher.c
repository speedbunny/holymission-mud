inherit "obj/monster";
object plate,bow,helmet;


reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("blue archer");
	set_alias("archer");
	set_short("A Blue Archer");
    set_long("Highly trained archers of the Liu Bei's army. He is suppose to\n"+
    "stay back and protect the camp from enemy entrance.\n");
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

