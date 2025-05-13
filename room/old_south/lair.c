object wyrm;

reset(started)
{
     if (!started)
	 set_light(0);
     extra_reset();
}

init()
{
    add_action("up"); add_verb("up");
}

short()
{
    return "The bottom of the well";
}

long()
{
    write("You are standing at the bottom of the well, about thirty feet below the\n" +
	  "surface. Bones lie strewn about in a random fashion, many of them broken\n" +
	  "or shattered.\n" +
	  "\tThe only way out is the way in, back up the ladder.\n");
}

up()
{
    call_other(this_player(), "move_player", "up the ladder#room/south/sislnd17");
    return 1;
}

extra_reset()
{
     if (!wyrm)
	 {
	     object coins, jem;
	     int jemnum;
	     wyrm = clone_object("obj/monster");
	     wyrm->set_name("wyrm");
	     wyrm->set_level(30);
             wyrm->set_race("dragon");
             wyrm->set_size(5);
	     wyrm->set_al(-900);
	     wyrm->set_short("The Wyrm of Arcanarton");
	     wyrm->set_long(
"The giant undead dragon you see before you is the result of one of\n"+
"Arcanarton's magic experiments.\n");
	     wyrm->set_wc(25);
	     wyrm->set_ac(15);
	     wyrm->set_no_steal();
	     wyrm->set_chance(50);
	     wyrm->set_spell_dam(100);
	     wyrm->set_spell_mess1(
"Arcanarton's wyrm turns his head and breathes death at his attacker.");
	     wyrm->set_spell_mess2(
"Arcanarton's wyrm turns his head and breathes death at you.");
	     wyrm->add_money(random(500));
	     jem = clone_object("obj/treasure");
             jemnum = random(3);
	     if (jemnum == 0)
		 {
		     jem->set_id("diamond");
		     jem->set_short("A diamond");
		 }
	     if (jemnum == 1)
		 {
		     jem->set_id("emerald");
		     jem->set_short("An emerald");
		 }
	     if (jemnum == 2)
		 {
		     jem->set_id("sapphire");
		     jem->set_short("A sapphire");
		 }
 	     jem->set_alias("gem of arcanarton");
 	     jem->set_long("The famous gem of Arcanarton.\n");
	     jem->set_value(random(250) + 1000);
	     move_object(jem, wyrm);
	     move_object(wyrm, this_object());
	 }
}
object wyrm;

reset(started)
{
     if (!started)
	 set_light(0);
     extra_reset();
}

init()
{
    add_action("up"); add_verb("up");
}

short()
{
    return "The bottom of the well";
}

long()
{
    write("You are standing at the bottom of the well, about thirty feet below the\n" +
	  "surface. Bones lie strewn about in a random fashion, many of them broken\n" +
	  "or shattered.\n" +
	  "\tThe only way out is the way in, back up the ladder.\n");
}

up()
{
    call_other(this_player(), "move_player", "up the ladder#room/south/sislnd17");
    return 1;
}

extra_reset()
{
     if (!wyrm)
	 {
	     object coins, jem;
	     int jemnum;
	     wyrm = clone_object("obj/monster");
	     wyrm->set_name("wyrm");
	     wyrm->set_level(30);
             wyrm->set_race("dragon");
             wyrm->set_size(5);
	     wyrm->set_al(-900);
	     wyrm->set_short("The Wyrm of Arcanarton");
	     wyrm->set_long(
"The giant undead dragon you see before you is the result of one of\n"+
"Arcanarton's magic experiments.\n");
	     wyrm->set_wc(25);
	     wyrm->set_ac(15);
	     wyrm->set_no_steal();
	     wyrm->set_chance(50);
	     wyrm->set_spell_dam(100);
	     wyrm->set_spell_mess1(
"Arcanarton's wyrm turns his head and breathes death at his attacker.");
	     wyrm->set_spell_mess2(
"Arcanarton's wyrm turns his head and breathes death at you.");
	     wyrm->add_money(random(500));
	     jem = clone_object("obj/treasure");
             jemnum = random(3);
	     if (jemnum == 0)
		 {
		     jem->set_id("diamond");
		     jem->set_short("A diamond");
		 }
	     if (jemnum == 1)
		 {
		     jem->set_id("emerald");
		     jem->set_short("An emerald");
		 }
	     if (jemnum == 2)
		 {
		     jem->set_id("sapphire");
		     jem->set_short("A sapphire");
		 }
 	     jem->set_alias("gem of arcanarton");
 	     jem->set_long("The famous gem of Arcanarton.\n");
	     jem->set_value(random(250) + 1000);
	     move_object(jem, wyrm);
	     move_object(wyrm, this_object());
	 }
}
