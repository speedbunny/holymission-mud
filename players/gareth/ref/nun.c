inherit "/players/whisky/tmp/npc";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("nun");
      set_alt_name("young nun");
      set_short("A young nun");
      set_long("A young beautiful nun.\n");
      set_gender(2);
       set_level(14);
       set_al(400);
      set_spell_mess1("The nun makes a hit with her feets");
      set_spell_mess2("The nun hits you with her feets");
       set_chance(18);
       set_spell_dam(random(20));
      add_money(100+random(50));
      set_dodge(20);
      set_fol_change(100);
      set_rid_change(50);
      set_attacks(3);
      set_attacks_change(50);
      add_property("has_answers",([
      "sex":"I cant deal with it"]));
      move_object(clone_object("/players/whisky/guild/obj/mace"),
      this_object());
      command("wield mace");
      }
void init()
{
     tell_object(find_living("whisky"),"INIT\n");
   ::init();
}
