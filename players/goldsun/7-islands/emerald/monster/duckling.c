inherit "/obj/monster";

void reset(int arg)
 {
 load_chat(25,({"Duckling is walking around.\n",
	 	"Duckling ducks lovely.\n",
 		"Duckling runs to you.\n",
		"Duckling smiles at you.\n"}));
 ::reset(arg);
if (arg) return;
set_name("duckling");
set_race("duck");
set_short("A duckling");
set_long("A tiny yellow duckling. It looks lovely.\n");
set_level(1);
set_wc(1);
set_ac(1);
set_al(120);
set_size(1);          
set_dead_ob(this_object());
}

int monster_died(object ob){
  tell_room(environment(this_object()),"Mother duck arrives.\n");
  move_object(clone_object("players/goldsun/7-islands/emerald/monster/duck"),
              environment(this_object()));
  return 0;
}
