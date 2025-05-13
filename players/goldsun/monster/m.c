inherit "obj/monster";

 reset(arg) { 
  int i;
  string s;

  :: reset(arg);

 if (arg) return;
 set_name("pacho");
 set_alias("wanderer");
 set_race("humans");
 set_short("Wanderer Pacho");
 set_long("This is wanderer Pacho who has been everywhere.\n"+
	  " His clothes are very dusty.\n");
 set_level(1);
 set_al(-10);
 set_gender(1);
 set_aggressive(0);
 set_wc(1);
 set_ac(1);
 set_dead_ob(this_object());
/* move_object(clone_object("/players/goldsun/obj/purse"),this_object()); */
}

monster_died(ob){
 move_object(clone_object("/players/goldsun/obj/purse"),this_player());
 write("Ok.\n");
 say(capitalize(this_player()->query_name())+" takes a purse from the "
                  +"corpse.\n");
 }


