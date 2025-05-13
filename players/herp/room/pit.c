/* pit.c 910305 Herp */
 
inherit "room/room";

reset(arg) { 
string chats,a_chats;
object pope,mitra,cx;

    tell_room("room/church","You hear someone farting from the pit below.\n");
    if (!arg) {
	set_light(0);
	dest_dir=({"room/church","up"});
	short_desc="In the pit";
	long_desc="You have entered the pit of the church.\n" +
		  "Everything is silent here, except ...\n";
}

    if (!chats) {
	chats = allocate(6);
	chats[0] = "You hear the page of a book being turned.\n";
	chats[1] = "Clemens murmurs in the darkness.\n";
	chats[2] = "Clemens the pope coughs noisly.\n";
	chats[3] = "Clemens says: Urbi et orbi.\n";
	chats[4] = "Clemens hisses: FRA DOLCINO ? Burn this heretic!\n";
	chats[5] = "Clemens says: Jesus did own his clothes.\n";
    }

    if (!a_chats) {
        a_chats = allocate(5);
        a_chats[0] = "His Evilness sits in Doomsday judgment over you!\n";
        a_chats[1] = "The holy father ejaculates to an unholy ecstatical choral song!\n";
        a_chats[2] = "Clemens the pope hits you with his crucifix!\n";
        a_chats[3] = "Clemens cuts your fingernails off and smokes them!\n";
	a_chats[4] = "Clemens chants: VADE RETRO, SATANUS!\n";
    }

    if ((pope=present("clemens")) && living(pope)) return;

    pope=clone_object("obj/monster");
    pope->set_name("clemens");
    pope->set_alias("pope");
    pope->set_race("human");
    pope->set_level(30);
    pope->set_hp(800);
    pope->set_sp(800);
    pope->set_ep(888888);
    pope->set_ac(50);
    pope->set_wc(50);
    pope->set_al(-1100);
    pope->set_gender(1); /* male */
 
    pope->set_spell_mess1("Pope Clemens absolutes you to hell.");
    pope->set_spell_mess2("The Inquisition Pope burns you at the fire-stake");
    pope->set_chance(80);
    pope->set_spell_dam(100);
    pope->load_chat(20,chats);
    pope->load_a_chat(80,a_chats);
    pope->set_short("Clemens the Inquisition Pope");
    pope->set_long("Clemens licks over a blood-red crucifix.\nIt seems he likes you.\n");
    pope->set_aggressive(0);
    pope->set_trapped(1); /* can't be 'feared' away */

    mitra=clone_object("obj/weapon");
    mitra->set_id("mitra");
    mitra->set_class(21);
    mitra->set_weight(4);
    mitra->set_value(6000);
    mitra->set_short("Golden Mitra");
    mitra->set_long("It looks valueable.\n");

    cx=clone_object("obj/treasure");
    cx->set_id("crucifix");
    cx->set_short("A blood red crucifix");
    cx->set_value(100);
 
    move_object(pope,this_object()); 
    move_object(mitra,pope);
    move_object(cx,pope);
/*  command("wield mitra",pope); */ /* DONT ... his hands hit harder !!! */
  return 1;
}
