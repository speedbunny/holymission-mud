
inherit "/obj/monster";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

	set_name("Loch Ness Monster");
	set_alt_name("loch ness");
        set_alias("monster");
	set_short(query_name());
	set_level(50);
	set_hp(20000);
	set_number_of_arms(2);
	set_race("drake");
	set_size(3);
	set_gender(1);
	set_al(-2000);

     load_chat(2, ({ 
        "The Loch Ness monster takes a breathe of air.\n",
        "The Loch Ness monster peers through the fog looking straight at you. \n",
       }));

  set_long(
       "You see a big, long, sleek prehistoric monster. He is very well \n"+
       "known because he is one of the most sought after to study in \n"+
       "this world. You feel like he is as afraid of you as you are of \n"+
       "him and wonder who will run away first. \n");

  set_spell_mess1("Nessie attacks with his tail!\n");
  set_spell_mess2("Nessie whips you with his tail.\n");
  set_chance(75);
  set_dead_ob(this_object());
  set_spell_dam(85); 
  set_no_steal();

  add_money(45000 + random(5000));
       
  move_object(clone_object("/players/apollo/area2/obj/loch_scale"),
       this_object());
  move_object(clone_object("/players/apollo/area2/weapons/tail"),
	this_object());
  move_object(clone_object("/players/apollo/area2/obj/bag_of_holding"),
        this_object());  

  init_command("wield tail");
  init_command("wear dragonhide");
  }
}

            
int query_str() { return 75; }
int query_con() { return 100; }
int query_dex() { return 150; }
int query_int() { return 50; }
int query_wis() { return 50; }
int query_chr() { return 50; }

int monster_died(object mob) {
   object ob;

   if (!this_player()->query_immortal()) {
      shout(capitalize(this_player()->query_real_name()) +
		" defeated the Loch Ness Monster !\n");
    }

   if (ob)
       destruct(ob);
  return 0;
}
