inherit "room/room";

// 5.25.95: Kasgaroth: Once per reset eh.
status found;

reset(arg) {
    found=0;
    if(arg) return;
    set_light(1);
    short_desc="Waste ground";
    long_desc="This is some waste ground in the gnome city. There is a lot of rubble about.\n";
    dest_dir=({ "players/moonchild/gnome/alley1", "west" });
    items=({ "rubble", "It has come from broken down old buildings.\n"
      + "There might be something useful in it, possibly" });
    property=({ "no_teleport" });
}

init() {
    ::init();
    add_action("search", "search");
}

search(str) {
    if(str!="rubble") return;
    if(found) write("You search but find nothing.\n");
    else {
	object m;
	write("You search - as you do so, a serpent crawls out of the rubble.\n");
	say("A serpent crawls out of the rubble!\n");
	move_object(m=clone_object("obj/monster"),this_object());
	m->set_name("serpent");
	m->set_short("A quite large serpent");
	m->set_long("A moderately large serpent with glittering fangs.\n");
	m->set_level(14);
	m->set_hp(300);
	m->set_wc(18);
	m->set_ac(6);
	m->set_chance(50);
	m->set_spell_dam(52);
	m->set_spell_mess1("Serpent bites its attacker!");
	m->set_spell_mess2("Serpent bites you hard!");
	m->set_al(-100);
	m->set_aggressive(1);
	m->set_dead_ob(this_object());
	m->hit_player(0);

	found=1;
    }
    return 1;
}

monster_died(ob) {
    object f;
    write("As you kill the serpent, one of its fangs breaks off.\n");
    move_object(f=clone_object("obj/weapon"),ob);
    f->set_name("fang");
    f->set_short("A serpent's fang");
    f->set_long("A sharp serpent's fang. It looks like it could puncture any kind of skin.\n");
    f->set_class(8);
    f->set_weight(2);
    f->set_value(800);
    f->set_hit_func(this_object());
}

weapon_hit(ob) {
    if(ob->id("serpent")) {
	write("You feel the fang dig deep into the serpent's flesh!\n");
	return random(15);
    }
}
