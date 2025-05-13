inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()

reset(arg)
{
    ::reset(arg);
    set_name("Flail of the Planes");
    set_alias("flail");
    set_hit_func(this_object());
    set_short("The Flail of the Planes");
    set_long(
      "The Flail shimmers with everchanging colors.  If you gaze at\n"+
      "long enough, you see views of other realms:  The fires of\n"+
      "Tarterus, the watery depths of Argo, the shifting rocks and dirt\n"+
      "of Denzilian, and the blowing winds of Bespin.  The chain clinks\n"+
      "knowingly, warning of menace and fury.  The shaft is of solid oak,\n"+
      "and looks well worn by the ages.  Those who know the planes, know\n"+
      "know this weapon.\n");
    set_weight(5);
    set_class(17);
    set_value(5000);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(20) <=5)
    {
	printf("You open channels to each plane, and summon bolts\n"+
	  "of earth, air, fire, and water to annihilate your opponent\n");
	say(" "+TP->NAME+" summons bolts of earth, air, fire, and water,\n"+
	  "completely smothering the opponent.\n",TP);
	if (guild == 9)
	    return(17+random(25));
	else
	    return (0+random(5));
    }
    if ( guild !=9)
    {
	write(
	  "The flail opens four planar portals at once, and you are\n"+
	  "bombarded by flames, winds, water, and mud.  The attacks\n"+
	  "are furious, and your life is in peril.\n");
	this_player()->hit_player(15 + random(85),10);
	return 0;
    }
    return 1;
}
int query_quest_object() {
    return 1;
}
query_summoner_wield() {
    return 1;
}
