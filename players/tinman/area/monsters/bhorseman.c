inherit "obj/monster";
object plate,pike,helmet;


reset(arg) {
    ::reset(arg);
    if(arg) return;
	set_name("blue horseman");
	set_alias("horseman");
	set_short("Blue Horseman");
    set_long("Liu Bei's horseman with great long pike charging toward the\n" +
" battlefield. He is suppose to cover for thefoot soldiers that are fighting" +
" here. He is very dedicated to his master's cause.\n");
    "change to a female if wet by cold water. He is a great material artist\n" +
    "trained to prefection with his father, Genma Saotome. You will\n" +
    "recognize him by his trademark black pigtail and chinese clothings.\n");
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

