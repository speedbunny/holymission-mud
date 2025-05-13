inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()

reset(arg)
{
    ::reset(arg);
    set_name("The Staff of the Ages");
    set_alias("staff");
    set_hit_func(this_object());
    set_short("The Staff of the Ages");
    set_long(
      "This hard, teak staff feels sturdy in your grasp.  The wood is\n"+
      "quite ancient, and has been worn to the point of feeling almost\n"+
      "wet to the touch.  Firmly attached to the staff are two handgrips,\n"+
      "which are made from the hide of an astral dragon.  The staff\n"+
      "eminates great power, and, peculiarly, wisdom.  You sense that\n"+
      "only those who travel through time can tap the secrets of this\n"+
      "strange weapon.\n");
    set_weight(7);
    set_class(15);
    set_value(5000);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(20) <=5)
    {
	printf("You summon a dimensional rift, and the temporal tidal\n"+
	  "forces rip and shred your opponent.\n");
	say(" "+TP->NAME+" opens a dimensional rift, whose violent temporal\n"+
	  "eddies tear the opponent apart.\n",TP);
	if (guild == 10)
	    return(35+random(80));
	else
	    return (0+random(5));
    }
    if ( guild !=10)
    {
	write(
	  "The staff pulses in your hands, and your body ages at an\n"+
	  "accelerated rate.  Your bones become brittle, and your\n"+
	  "teeth fall out, along with your hair.\n");
	this_player()->hit_player(8 + random(100),3);
	return 0;
    }
    return 1;
}
int query_quest_object() {
    return 1;
}
