void make_creatures() {
  object po;
  po=previous_object();
  while(random(2)) {
    object m,o;
    int i;
    move_object(m=clone_object("obj/monster"),po);
    m->set_alt_name("forest_creature");
    m->set_move_at_reset(1);
    switch(random(6)) {
      case 0:
	m->set_name("fire-ant");
	m->set_race("ant");
	m->set_level(2);
	m->set_al(-50);
	m->set_aggressive(1);
	m->set_long("This fire-ant glows brightly on its' head.\n");
	break;
      case 1:
	m->set_name("deer");
	m->set_level(3);
	m->set_long("A sleek and rather pretty-looking deer. It looks a little afraid of you.\n");
	m->set_al(50);
	m->set_whimpy(50);
	o=clone_object("obj/weapon");
	o->set_name("antlers");
	o->set_short("Antlers");
	o->set_long("These are the antlers from a deer.\n");
	o->set_class(9);
	o->set_value(50);
	move_object(o,m);
	command("wield antlers", m);
	break;
      case 2:
	m->set_name("spider");
	m->set_level(1);
	m->set_long("A small and rather harmless-looking spider.\n");
	break;
      case 3:
	m->set_name("boar");
	m->set_level(6);
	m->set_long("An aggressive wild boar. It looks rather nasty.\n");
	m->set_al(-100);
	m->set_aggressive(1);
	o=clone_object("obj/weapon");
	o->set_name("tusk");
	o->set_short("Tusk");
	o->set_long("This is a wild boar's tusk.\n");
	o->set_class(12);
	o->set_value(200);
	move_object(o,m);
	command("wield tusk", m);
	break;
      case 4:
	m->set_name(({ "grey", "red" })[random(2)] + " squirrel");
	m->set_race("squirrel");
	m->set_level(2);
	m->set_long("A cute little " + (string)m->query_name() + ".\n");
	m->set_al(100);
	for(i=random(3);i<3;i++) {
	  o=clone_object("obj/food");
	  o->set_strength(2);
	  o->set_name("nut");
	  o->set_short("A small nut");
	  o->set_long("A small nut. It looks good to eat.\n");
	  o->set_value(10);
	  o->set_eater_mess("It tastes delicious.\n");
	  o->set_eating_mess(" eats a nut.\n");
	  move_object(o,m);
	}
	break;
      case 5:
	m->set_name("fox");
	m->set_long("A wily little fox.\n");
	m->set_level(4);
	break;
    }
  }
}
