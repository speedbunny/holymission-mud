
inherit "obj/monster";
#include "/players/gambit/defs2.h"
object weapon;

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("wolverine");
	set_alias("wolverine");
	set_alt_name("wolverine");
	set_level(60);
	set_hp(6000);
	add_money(15000);
	set_gender(1);
	set_race("mutant");
	set_short("Wolverine (watching you with glowing red eyes)");
	set_dead_ob(this_object());
	set_long(BS("This half beast, half man creature is a messed up "+
	    "experiment of some evil Sorcerors. The Wolverine stands at about five "+
	    "feet tall with a rebuilt muscular body and is wearing a weird looking "+
	    "helmet with red glowing eyes and tubes that attach into his body. "+
	    "He doesn't look very happy to see you."));
	set_spell_dam(30);
	set_chance(8);
	set_spell_mess1(BS("Wolverine slices and rips you with his claws."));
	set_spell_mess2(BS("Wolverine rips out chunks of flesh from your body!"));
	weapon = clone_object("/players/whisky/hole/obj/claws");
	move_object(weapon,this_object());
	init_command("wield claws");
    }
}

mixed look_info(int flag)
{
    if (flag)
	return 0;
    return (" (watching you with glowing red eyes)");
}

void init()
{
    if (objectp(this_player()) && living(this_player()) 
      && !this_player()->query_npc() && this_player()->query_level() > 15)
	attack_object(this_player());
    ::init();
}
monster_died(ob)
{
    return 0;
}
mixed attack()
{
    if (::attack() && random(100) < 8)
    {
	tell_room(environment(),
	  "Wolverine critically slices "+attacker_ob->query_name()+".\n");
	attacker_ob->add_poison(20+random(8));
	return 1;
    }
    return 0;
}

query_str()
{
    return 150;
}

query_dex()
{
    return 150;
}
