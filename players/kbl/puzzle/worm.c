inherit "obj/monster";

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("giant worm");
  set_race("worm");
  set_short("A giant worm");
  set_long("This giant worm is long and very fat and looks like he might be rather vicious!\n");
  set_level(14);
  set_wc(20);
  set_chance(20);
  set_spell_dam(50);
  set_spell_mess1("The giant worm bites!");
  set_spell_mess2("The giant worm bites you! Funny, you didn't think he would have teeth!");
  set_dead_ob(this_object());
}

monster_died(ob) {
  int loop;
  object worm;
  for(loop=random(4);loop<15;loop++) {
    worm=clone_object("obj/monster");
    worm->set_name("parasitic worm");
    worm->set_race("worm");
    worm->set_short("A small parasitic worm");
    worm->set_long("A small parasitic worm. It looks really disgusting!\n");
    worm->set_level(5);
    worm->set_wc(10);
    worm->set_aggressive(1);
    move_object(worm,environment(ob));
  }
  tell_room(environment(ob),"As the worm dies, you see something absolutely disgusting\n"
	+ "starting to crawl its way out of the corpse!\n");
  return 0;
}
