#define SAY(x) tell_room(environment(),x)
inherit "obj/monster";

reset(a) 
{
    ::reset(a);
    if (a) return 0;
    set_name("sheriff");
    set_alias("");
    set_short("Sheriff of Nottingham");
    set_long("Sheriff of Nottingham. He is tall with black hair.\n"+
	     "He grins evilly at you and asks: 'What are you doing here ?'\n");
    set_gender(1);
    set_race("troll");
    set_size(3);
    set_level(40);
    set_wc(27);	
    set_ac(5);
    set_dead_ob(this_object());
    add_money(1000+random(500));
    move_object(clone_object("/players/goldsun/nottingham/obj/steelsword"),this_object());
    init_command("wield sword");
    move_object(clone_object("/players/goldsun/nottingham/obj/platemail"),this_object());
    init_command("wear platemail");
	
}

int monster_died(object ob)
{
    SAY("Nottingham Sheriff says: OUCH. Shit.\n");
    return 0;
}

