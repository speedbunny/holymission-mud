inherit "obj/monster";
 
object hammer,bag,sword;

reset(arg) {
 ::reset(arg);
 set_name("sean");
 set_alias("o'connor");
 set_alt_name("sean o'connor");
 set_size(3);
 set_level(20);
 set_hp(750);
 set_al(100);
 set_race("human");
 set_short("Sean O'Connor");
 set_long("Sean O'Connor is a thief. He must be very dextrous, because"+
          " he has managed\nto steal Thor's hammer.\n");
 set_male();
 set_ac(8);
 set_wc(20);
 set_dex(30);
 set_aggressive(0);
 set_spell_mess1("Sean slashes his opponent with his sword.");
 set_spell_mess2("Sean slashes you with his sword.You're hurt very bad.");
 set_chance(15);
 set_spell_dam(50);
 set_move_at_reset();
 stats[1]=50;
 guild=1;
 
 bag=clone_object("obj/bag");
 move_object(bag,this_object());
 
 hammer=clone_object("/players/kelly/obj/hammer");
 
 
 sword=clone_object("/obj/weapon");
 sword->set_name("katana");
 sword->set_alias("sword");
 sword->set_short("A katana");
 sword->set_long("This is a wonderfully worked out katana.\n"+
     "It must have been made by a Japanse smith.\n");
 sword->set_value(2000);
 sword->set_weight(2);
 sword->set_class(19);
 sword->set_hit_func(this_object());
 move_object(sword,this_object());
 init_command("wield sword");
}
 
weapon_hit(atta) {
  if(atta->query_level()<10 && !random(5)) {
    write("The katana slices through the flesh of "+atta->query_name()
    +" and lets "+atta->query_possesive()+" guts fall to the ground.\n");
    say(sword->wielded_by()->query_name()+"'s"+
    "katana slices through the flesh of"+atta->query_name()+
    " and lets "+atta->query_possessive()+" guts fall to the ground.\n");
    return 100;
  }
  return 19;
}
 
init () {
 ::init();
 add_action("steal","steal");
}
 
steal(str) {
  string what,who;
  sscanf(str,"%s from %s",what,who);
  if(id(who)) {
    if(this_player()->query_guild()==1)  
      write("Sean smiles and says: Hey, guy! I'm a thief, too.\n");
    else
      write("Sean says: No dude is able to steal from me.\n");
    return 1;
  }
  return;
}
