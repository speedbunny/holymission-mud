inherit "obj/monster";

reset(arg){
   ::reset(arg);
   if(arg) return 1;
	set_name("alexandra");
	set_gender(2);
	set_race("human");
	set_level(1);
	set_short("Alexandra");
	set_long("Alexandra knew better than to PK. Waylan will enjoy\n"+
		 "beating on her.\n");
	set_alias("bum");

load_chat(8, ({
  "Alexandra says: I've been bad, kill me.\n",
  "Alexandra says: Whip me, beat me, make me write bad checks!\n",
  "Alexandra says: Spank me, I deserve it.\n",
}));

}
