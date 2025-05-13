inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()

reset(arg)
{
    ::reset(arg);
    set_name("Needledirk");
    set_alias("dirk");
    set_hit_func(this_object());
    set_short("The Needledirk");
    set_long(
      "This seems to be nothing but a short, EXTREMELY sharp piece of\n"+
      "mithril with a leather grip.  Simplicity itself...But, as you\n"+
      "brandish it around, you notice its almost non-existant weight,\n"+
      "and its incredible strength.  In fact, the more you hold it, the\n"+
      "more you feel like backstabbing something.  A very theifly weapon.\n");
    set_weight(1);
    set_class(5);
    set_value(5000);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(10) <=3)
    {
	printf("The Needledirk flashes with incredible speed, and you strike twice\n"+
	  "at once, impaling your opponent with much force.\n");
	say(" "+TP->NAME+"'s arm suddenly blurs with motion as the Needledirk\n"+
	  "strikes twice at once.\n",TP);
	if (guild == 1)
	    return(5+random(8));
	else
	    return (0+random(5));
    }
    if ( guild !=1)
    {
	write(
	  "The needledirk suddenly becomes supple, and bends backward...\n"+
	  "impaling your wrist with viscious ferocity.\n");
	this_player()->hit_player(20 + random(80),7);
	return 0;
    }
    return 1;
}
int query_quest_object() {
    return 1;
}
