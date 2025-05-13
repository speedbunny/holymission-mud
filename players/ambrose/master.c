void make_creatures()
{
  object po;
  object m,o;
  int i;
  po=previous_object();
  while(random(2))
    {
      m=clone_object("obj/monster");
      move_object(m,po);
      m->set_alt_name("forest_creature");
      m->set_move_at_reset(1);
      switch (random(4))
      {
      case 0:
	
	m->set_name("salamander");
	m->set_race("lizard");
	m->set_level(10);
	m->set_long("The salamander seems to be on fire, but the forest does not burn.\n");
	break;
      case 1:
	m->set_name("griffon");
	m->set_level(15);
	m->set_long("This griffon roars fiercely at you but seems not to want to fight.\n");
	o=clone_object("obj/weapon");
	o->set_name("claws");
	o->set_short("claws");
	o->set_long("These are the diamonds claws from one of Avalons Griffons.\n");
	o->set_class(12);
	o->set_value(500);
	move_object(o,m);
	command("wield claws", m);
	break;
      case 2:
	m->set_name("ogre");
	m->set_level(20);
	m->set_long("This Ogre seems extremely large, you aren't sure if you can kill him.\n");
	break;
      case 3:
	m->set_name("basilisk");
	m->set_level(25);
	m->set_long("This is one of the almost harmless neutered Basilisk.\n");
	break;
      }
    }
}
