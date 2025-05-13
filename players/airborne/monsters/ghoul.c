inherit "obj/monster";
object cloak;

reset(arg){
	::reset(arg);
   if(arg) return 1;
	set_name("ghoul");
	set_race("undead");
	set_short("Ghoul");
	set_long("A very nasty looking ghoul.  Its hands are topped with vicious claws.\n" + "Its body is wrapped in a torn black cloak.\n");
	set_level(11);
	set_aggressive(1);
	add_money(50 *(random(6)+1));
	set_whimpy();
     cloak=clone_object("players/airborne/armours/ghlcloak");
     move_object(cloak,this_object());
     init_command("wear cloak");
	  	return 1;
}
