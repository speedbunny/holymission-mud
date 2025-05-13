inherit "obj/treasure";

do_gd(string arg){
  object ob, guild_soul, dagger;
  if(!find_living(arg)){
    write("This player is not on the mud right now.\n");
    return 1;
  }
  ob = find_living(arg);
  if(ob){
    guild_soul = ob->query_guild_soul();
    if(guild_soul->query_righteous() == 1){
      write("This player is already a thief guide.\n");
      return 1;
    }
    guild_soul->set_righteous(1);
    tell_object(ob, "Congratulations, you are now a thief guide.\n");
    write("Log off and back on again to get your new dagger.\n");
  }
  return 1;
}

do_ga(string arg){
  object ob, guild_soul, dagger;
  if(!find_living(arg)){
    write("This player is not on the mud right now.\n");
    return 1;
  }
  ob = find_living(arg);
  if(ob){
   guild_soul = ob->query_guild_soul();
   if(guild_soul->query_righteous() == 1){
      tell_object(ob, "Your thief guide status has been revoked.\n");
      if(present("t_dagger", ob)){
	dagger == present("t_dagger", ob);
        destruct(dagger);
	return 1;
      }
   }
   else {
     write("This player is not a thief guide.\n");
     return 1;
   }
  }
}

shelp(){
  write("gadd         Adds a thief guide\n");
  write("grem         Removes a thief guide\n");
  return 1;
}

void reset(int arg){
  set_id("T_GM_staff");
  set_alias("staff");
  set_short("Thief GM's staff");
  set_long("Thief GM's staff.  Type shelp for info.\n");
  set_value(0);
  set_weight(0);
}

void init(){
  ::init();
  add_action("do_gd", "gadd");
  add_action("do_ga", "grem");
  add_action("shelp", "shelp");
}

