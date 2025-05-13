inherit "/obj/monster";

void reset(int arg) {
  if(arg) return;
  ::reset();
  set_name("pub owner");
  set_level(10);
  set_alias("owner");
  set_race("human");
  set_gender(1);
  set_short("The pub owner");
  set_long("The pub owner is a round, rather jolly fellow.  He is also " +
           "a bit inebriated.\n");
  set_wc(13);
  set_ac(8);
  load_chat(10,({
     "Owner says: Find the mystic!\n",
     "Owner says: Boy, I wish he was easier to find.\n",
     "Owner says: Say hi to the king if ya find him.\n",
     "Owner says: Boy the mountains are big and steep!\n",
  }));
}
