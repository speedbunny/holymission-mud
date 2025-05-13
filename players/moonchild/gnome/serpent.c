inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  set_name("serpent");
  set_short("A giant serpent");
  set_long("A massive giant serpent that lives in damp caves.\n");
  set_level(30);
  set_hp(2000);
  set_al(-500);
  set_dead_ob(this_object());
  move_object(this_object(),"players/moonchild/gnome/cave");
}

hit_player(dam) {
  object ob;
  if((ob=present("fang",this_player())) && ob->query_wielded()) dam=dam*2;
  else dam=dam/5;
  return ::hit_player(dam);
}

monster_died(ob) {
  object c;
  tell_room(environment(ob),
	"As the serpent dies, one of its eyes falls out and proves to be a crystal!\n");
  move_object(c=clone_object("players/moonchild/gnome/crystal"), environment(ob));
  c->set_type(3);
}
