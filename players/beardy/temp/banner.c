inherit "obj/treasure";

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_id("banner");
  set_short("a war banner");
  set_long("The famous Paladin's war banner.\n");

  set_weight(1);
}

void init()
{ ::init();
  add_action("pwr_shield","powershield");
}

int pwr_shield()
{ object shield;

  shield=clone_object("/players/beardy/obj/shield");
  shield->set_ac(this_player()->query_level()/8);

  transfer(shield,this_player());
  return 1;
}
