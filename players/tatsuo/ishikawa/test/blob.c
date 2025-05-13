/*coded by tatsuo for ishikawa*/
inherit "/obj/monster";
void reset (int flag)
{
    ::reset(flag);
    if (flag==0)   /*the creation can be 0 || 1 */
    {
	set_name("blob");
	set_alt_name("gelatinous blob");
	set_short("A Gelatinous Blob");
	set_long("You see a horrid, reeking, green blob. It is somewhat transparent and\n"+
	  "you can see what appears to be bones inside of it's body. You can smell a\n"+
	  "reeking stench coming from the blob. It is so horrid you just want to puke.\n");
	set_level(35);
	set_hp(5000);
	set_wc(25);
	set_ac(20);
	set_aggressive(1);
    }
}
int attack()
{
    if (::attack() && !random(2))
    {
	if ( attacker_ob && living(attacker_ob))
	{
	    tell_object(attacker_ob,
	      "The blob hurls a reeking fluid at you. AAARRGGHHH YOU PUKE!!!!!!\n");
	    say ("The blob hurls a reeking fluid at "+attacker_ob->query_name()+
	      " AAARRGGHHH YOU PUKE!!!!!!\n",attacker_ob);
	    attacker_ob->hit_player(40 +random(40),5);
	}
	return 1;
    }
    return 0;
}
