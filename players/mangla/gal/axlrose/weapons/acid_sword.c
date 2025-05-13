/* Axlrose - Barbarian Guild */
/* Severance's Weapon */
inherit "obj/weapon";
object treasure, weapon;

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("acid blasted bastard sword");
    set_alias("sword");
    set_short("Rune Inscribed Bastard Sword");
    set_long
      ("A dual edged single or two-handed bastard sword with dwarven runes \n"
      +"inscribed along its hilt.  Acid burns are prominent along the other- \n"
      +"wise polished blade.\n");
    set_class(15);
    set_value(2500);
    set_weight(1);
    set_hit_func(this_object());
}

weapon_hit(attacker) {
    int rnd;
    if ( (rnd=random(1000))>1) {
	if (2>rnd)
	    return 0;
    }
    else {
	write ("Suddenly the bastard sword shatters into various acid burnt pieces, \n"
	  +"ruining it forever.\n");
	tell_room(environment(this_player()),"Flashes of sparkling steel glitter through the air as \n"
	  + (this_player()->query_name()) + " ponders " + (this_player()->query_possessive()) + " sudden turn of fate.\n");
	command("unwield sword",(this_player()));
	call_out("dest_me",0);
	treasure = clone_object("/players/axlrose/objects/fragment");
	transfer(treasure,this_player());
	treasure = clone_object("/players/axlrose/objects/fragment");
	transfer(treasure,environment(this_player()));
	weapon = clone_object("/players/axlrose/objects/handle");
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

do_wield() {
    command("wield handle",(this_player()));
}

void init()
{
    ::init();
    add_action ("read", "read");
}

int read (string str)
{
    if(str != "runes")
    {
	if (this_player()->query_race() == "dwarf")
	    write ("The dwarven runes read 'Slicer' before the acid burns ruin the rest.\n");
	return 1;
    }
    else
	write ("The dwarven runes are incomprehensible.\n");
    return 1;
}

