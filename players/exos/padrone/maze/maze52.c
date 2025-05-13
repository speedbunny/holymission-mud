/* In the mirrormaze: maze52.c, with the guard */

inherit "/players/padrone/maze/maze";

object guard;

MAZE_ROOM()
{
    return ({0, 0, "maze53", "maze51"});
}

reset(arg)
{
    object weapon;
    ::reset(arg);

    if (!guard || !living(guard)) {
	guard = clone_object("obj/monster");
	guard->set_name("guard");
	guard->set_alias("maze guard");
	guard->set_level(7);
	guard->set_hp(130);
	guard->set_al(100);
	guard->set_short("A maze guard is standing here, barring the way west");
	guard->set_long("He guards the maze. It's part of his job\n" +
			"to stop people from going west here.\n");
	guard->set_spell_mess1("The guard hits his opponent in the head with his wooden club. KLONK!");
	guard->set_spell_mess2("The guard hits you in the head with his wooden club. OUCH! That hurt!");
	guard->set_chance(20);
	guard->set_spell_dam(20);
	move_object(guard, this_object());

	weapon = clone_object("obj/weapon");
	weapon->set_name("wooden club");
	weapon->set_class(5);
	weapon->set_value(3);
	weapon->set_weight(2);
	weapon->set_alt_name("club");
	weapon->set_short("A wooden club");
	move_object(weapon, guard);
	guard->init_command("wield club");
    }
} 

move(str)
{
   if (!str)
       str = query_verb();
   if (str == "west" && guard && living(guard))
   {
       command("say there is no way to pass me "+
                this_player()->query_real_name(),guard);
       return 1;
    }
    return ::move(str);
}

