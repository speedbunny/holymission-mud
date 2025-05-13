/* SCALPER.C - Programmed by Moonchild */
/* 201094: Ethereal Cashimor: Modified query_name to query_real_name */

inherit "obj/weapon";

object dead;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("scalping knife");
  set_alias("knife");
  set_value(30);
  set_class(6);
  set_weight(2);
  set_short("A scalping knife");
  set_long("This is a scalping knife. Not ideal for combat,\n"
	+ "but perfect for scalping corpses with!\n"
	+ "There is something written on it.\n");
  set_read("Designed by Korvar. Another product of Swashbuckler Inc.\n");
}

init() { ::init(); add_action("scalp", "scalp"); }

scalp(str) {
  object new, scalp;
  string who, tmp, tmp2;
  int wt;
  if(str!="corpse" && !sscanf(str, "corpse of %s", tmp)) {
	write("You can't scalp that!\n");
	return 1;
  }
  dead=present(str,this_player());
  if(!dead) {
	write("You are not carrying " + str + ".\n");
	return 1;
  }
  if(sscanf(dead->short(), "%s remains of %s", tmp, tmp2)) {
	write("This corpse has decayed too much to scalp it.\n");
	return 1;
  }
  if(dead->query_scalped()) {
	write("This corpse has already been scalped.\n");
	return 1;
  }
  tmp=dead->query_real_name();
  wt=dead->query_weight();
  move_object(new=clone_object("players/moonchild/goblins/sc_corpse"),this_player());
  trans(new);
  who=dead->query_real_name();
  new->set_name(who);
  new->set_weight(wt-1);
  move_object(scalp=clone_object("players/moonchild/goblins/scalp"),this_player());
  scalp->name_it(who);
  destruct(dead);
  this_player()->add_weight(wt);
  write("You scalp the corpse.\n");
  say(this_player()->query_name() + " scalps a corpse.\n");
  return 1;
}

trans(arg) {
  object ob;
  object next_ob;
  ob = first_inventory(dead);
  while(ob) {
    next_ob = next_inventory(ob);
    move_object(ob, arg);
    ob = next_ob;
  }
}
