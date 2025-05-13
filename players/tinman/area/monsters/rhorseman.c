inherit "obj/monster";
object plate,pike,helmet;


reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("red horseman");
	set_alias("horseman");
	set_short("Red Horseman");
    set_long("Cao Cao's red horseman riding into the battlefield. They all\n" +
" have this resigned look. They are not afraid of dying or killing\n");
	set_level(25);
    set_gender(1);
	set_race("human");
	add_money(400);
	set_wc(13);
	set_ac(5);
	set_number_of_arms(2);
    plate=clone_object("/players/tinman/area/armors/plate");
    move_object(plate,this_object());
    pike=clone_object("/players/tinman/area/weapons/pike");
    move_object(pike,this_object());
    helmet=clone_object("/players/tinman/area/armors/helmet");
    move_object(helmet,this_object());
command("powerup");
}

