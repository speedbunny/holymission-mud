#define DIRS ({ "north", "east", "southeast", "south", "west", "northwest" })

inherit "obj/monster";

int ct;

query_property(str) { return str=="no_clean_up"; }
reset(arg) {
  ::reset(arg);
  if(arg) return;
  ct=0;
  set_name("gnome");
  set_short("A greedy little gnome");
  set_long("This a small but rather alert-looking little gnome.\n"
	+ "It's definitely a rather malicious type though.\n");
  set_level(10);
  set_hp(300);
  set_wc(14);
  set_ac(8);
  set_chance(20);
  set_spell_dam(40);
  set_spell_mess1("The gnome bites!");
  set_spell_mess2("The gnome bites you hard!");
  load_chat(10, ({ "Gnome giggles inanely.\n",
	"Gnome peers suspiciously at you.\n",
	"Gnome rubs its hands with glee.\n",
	"Gnome looks in its pockets and smiles.\n",
	"Gnome falls down laughing.\n",
	"Gnome throws back its head and cackles with glee!\n" }));
  set_al(-125);
  set_whimpy();
  msgin="sneaks in";
  msgout="sneaks off";
  set_dead_ob(this_object());
}

heart_beat() {
  object *allinv;
  int rndm;
  if(dead) return;
  if(!environment()) return;
  allinv=all_inventory(environment());
  rndm=random(sizeof(allinv));
  if(interactive(allinv[rndm])) {
    if(random(2)) steal_money(allinv[rndm]);
    else steal_item(allinv[rndm]);
  }
  if(ct++>6) {
    command(DIRS[random(6)]);
    ct=0;
  }
  ::heart_beat();
}

catch_tell(str) {
  string who,dir;
  object victim;
  if(sscanf(str,"%s arrives.\n",who)==1) {
    victim=present(who,environment());
    if(!victim || !interactive(victim)) return;
    if(random(2)) steal_money(victim); else steal_item(victim);
    return 1;
  }
  if(sscanf(str,"%s leaves %s.\n",who,dir)==2) init_command(dir);
  return 1;
}

steal_money(ob) {
  int cns;
  cns=ob->query_money();
  if(cns<1) return;
  if(cns>500) cns=random(501);
  ob->add_money(-cns);
  add_money(cns);
  tell_object(ob,"You feel a soft touch on your pocket.\n");
}

steal_item(ob) {
  object *items;
  int choose;
  string sh;
  items=all_inventory(ob);
  if(!sizeof(items)) return;
  choose=random(sizeof(items));
  sh=items[choose]->short();
  if(!sh) return;
  if(items[choose]->query_wielded() || items[choose]->query_worn()) return;
  if(items[choose]->drop(1) || !items[choose])
	tell_object(ob,"Gnome tried to steal " + sh + " from you.\n");
  else {
    ob->add_weight(-items[choose]->query_weight());
    move_object(items[choose],this_object());
    tell_object(ob,"You feel that something in your inventory is missing.\n");
  }
}

monster_died() { "players/moonchild/castle"->prepare_gnomes(); }
