inherit "obj/monster";

reset(arg){
   ::reset(arg);
   if(arg) return 1;
	set_name("lizabeth");
	set_gender(2);
	set_race("human");
	set_level(1);
	set_short("Liz E. Ball");
	set_long("Liz is my best friend and should be included in all aspects of my life.\n"+"So here she is!\n");
	set_alias("liz");

load_chat(8, ({
	"Liz says: Willie loves me.  What a sucker!\n",
	"Liz says: Yo babe!\n",
	"Liz says: I am the anti-gamer!\n"
}));
	}

monster_died(ob){
	say(""+this_player()->query_name()+"killed Liz.\n");
	return 0;
}
