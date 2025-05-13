/* Axlrose - Human Army */
/* Soldier's Regular Glaive Polearm */
inherit "obj/weapon";
object treasure, weapon;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("bladed pine staff");
    set_alt_name("polearm");
    set_alias("glaive");
    set_short("A regular glaive polearm");
    set_long
      ("A slender single-edged iron blade mounted to a ten foot rough pine \n"
      +"staff by a dark leather cord.\n");
    set_class(10);
    set_value(60);
    set_weight(3);
    set_hit_func(this_object());
}

weapon_hit(attacker) {
    int rnd;
    if ( (rnd=random(250))>1) { 
	if (2>rnd)
	    return 0;
    }
    else {
	write ("Striking with a crushing blow, the glaive polearm splinters in your \n"
	  +"bewildered opponent's hands!\n");
	tell_room(environment(this_player()),"Suddenly the glaive polearm cracks and splinters approximately in the \n"
	  +"lower middle, resulting in a wielded shortened polearm and a discarded \n"
	  +"pine staff.\n");
	command("unwield polearm",(this_player()));
	call_out("dest_me",0);
	treasure = clone_object("/players/axlrose/objects/stick_01");
	transfer(treasure,environment(this_player()));
	weapon = clone_object("/players/axlrose/weapons/glaive_02");
	transfer(weapon,this_player());
	call_out("do_wield",1);
	return 1;
    }
}

void dest_me()
{
    destruct(this_object());
    return;
}

do_wield() 
{
    command("wield polearm",(this_player()));
}

