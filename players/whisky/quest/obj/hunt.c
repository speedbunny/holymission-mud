
inherit "obj/monster";

  reset(arg) {
  
    ::reset(arg);
    
  if (arg) return;
  
    set_name("wolf");
    set_alt_name("hunt");
    set_alias("black wolf");
    set_short("A big black wolf");
    set_long("You see a big black wolf, the biggest wolf you can imagine.\n"+
             "His eyes are glowing in a red light and he seems so strong,\n"+
             "that no even the best adventurer would try to attack him.\n");
    set_gender(1);
    set_chance(10);
    set_spell_dam(random(120));
    set_spell_mess2("bites you in your neck");   
    set_level(20);
    set_race("hellhound");
    set_dead_ob(this_object());
    set_wc(80);
    set_hp(2400);
    set_ac(40);
    set_aggressive(1);
   
    }
    
   monster_died() {
      object ob;
    move_object(clone_object("players/whisky/quest/obj/wolftail"),this_object());
    if (ob = present("burst",this_player()))
        destruct(ob);
    return;
    }
     
    
  
  run_away() { return; }
  
