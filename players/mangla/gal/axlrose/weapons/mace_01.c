/* Axlrose - Human Army */
/* Soldier's Footman's Mace */
inherit "obj/weapon";
object treasure, weapon;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("ferrous studded wooden club");
    set_alt_name("mace");
    set_alias("club");
    set_short("A regular footman's mace");
    set_long
    ("A harden wooden club approximately three feet in length.  The wide end \n"
      +"has sharp iron studs embedded in a haphazard order while the thin end \n"
      +"is leather wrapped for grip.\n");
    set_class(13);
    set_two_handed();
    set_value(80);
    set_weight(3);
    set_hit_func(this_object());
}

weapon_hit(attacker) {
    int rnd;
    if ( (rnd=random(500))>1) {
	if (2>rnd)
	    return 0;
    }
    else {
	write ("With a loud cracking sound, the footman's mace splinters and shatters, \n"
	  +"causing iron and wood bits to fly about.\n");
	tell_room(environment(this_player()),"Fragments of metal and wood explode through the air as \n"
	  + (this_player()->query_name()) + " watches " + (this_player()->query_possessive()) + " footman's mace fail!\n");
	command("unwield mace",(this_player()));
	call_out("dest_me",0);
	treasure = clone_object("/players/axlrose/objects/fragment_02");
	transfer(treasure,this_player());
	treasure = clone_object("/players/axlrose/objects/fragment_02");
	transfer(treasure,environment(this_player()));
	weapon = clone_object("/players/axlrose/weapons/mace_02");
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
    command("wield mace",(this_player()));
}
