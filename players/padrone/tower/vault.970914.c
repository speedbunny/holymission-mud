/*  vault.c
 *	Note: money is not put here, but in players/padrone/walker/cell.c
 */
/* Changed by Ethereal Cashimor, better anti-teleport, room/room, ect.,
   230293 */

inherit "room/room";
#include "../../../obj/door.h"

object thief1, thief2, lawbringer;

init() {
    ::init();
    /*
      log_file("padrone",ctime(time())+": "+this_player()->query_name()
	     + " entered the (stationary) vault.\n");
    */
}

reset(arg) {
    object temp;

    ::reset(arg);
    if(!arg) {
	short_desc="Treasury Vault";
	long_desc="This is the vault in the treasury in Padrone's Castle. The\n"
	+ "walls are made of steel, and to the south a steel door leads\n"
	+ "out. The floor has been engraved with anti-teleport runes. But\n"            + "despite these precautions, and the fierce guards outside,\n"                 + "criminals have managed to sneak in to steal the contents.\n";
	set_light(1);
	property = "no_teleport";
	smell="The air is very old here.";
    }
    if (check_for_players()) return 1;
    if(!thief1) {
	thief1=clone_object("obj/monster");
	thief1->set_name("big thief");
	thief1->set_alias("thief");
	thief1->set_male();
	thief1->set_level(16);
	thief1->set_hp(400);
	thief1->set_ac(10);
	thief1->set_al(-50);
	thief1->set_short("A big thief");
	thief1->set_long("This is an experienced and dangerous criminal. He has\n" 
	  + "He has managed to sneak into the vault, despite the\n"
	  + "Archers!\n");
	thief1->set_aggressive(1);
	thief1->set_spell_mess1("The thief throws a knife with astonishing accuracy.");
	thief1->set_spell_mess2("The thief throws a knife with astonishing accuracy at you.");
	thief1->set_chance(20);
	thief1->set_spell_dam(50);
	move_object(thief1, this_object());
	temp=clone_object("obj/weapon");
	temp->set_name("sword");
	temp->set_alias("sword of fire");
	temp->set_short("A sword of fire");
	temp->set_long("A sword of fire.\n");
	temp->set_class(18);
	temp->set_weight(3);
	temp->set_value(2000);
	move_object(temp, thief1);
	thief1->init_command("wield sword");
	temp=clone_object("players/padrone/obj/thing");
	temp->set_name("letter");
	temp->set_alias("official letter");
	temp->set_short("An official letter from Padrone");
	temp->set_long("It is witten on a sheet of high-quality paper\n" +
	  "with the official Castle of Padrone letterhead.\n" +
	  "Maybe you should try to read it?\n");
	temp->set_read_file("/players/padrone/tower/vault_letter.txt");
	temp->set_can_get(1);
	temp->set_weight(1);
	temp->set_value(10);
	move_object(temp, thief1);
    }
    if(!thief2) {
	thief2 = clone_object("obj/monster");
	thief2->set_name("small thief");
	thief2->set_alias("thief");
	thief2->set_level(5);
	thief2->set_male();
	thief2->set_hp(100);
	thief2->set_ac(15);
	thief2->set_al(-150);
	thief2->set_short("A small thief");
	thief2->set_long("This thief is small, weak and ugly, but very greedy and\n"
	  + "devious. He has taken almost all the valuables in the\n"
	  + "vault.\n");
	thief2->set_aggressive(1);
	thief2->set_spell_mess1("The small thief throws a knife.");
	thief2->set_spell_mess2("The small thief throws a knife at you.");
	thief2->set_chance(20);
	thief2->set_spell_dam(20);
	move_object(thief2,this_object());
	temp=clone_object("obj/weapon");
	temp->set_name("sword");
	temp->set_alias("sword of frost");
	temp->set_short("A sword of frost");
	temp->set_long("A sword of frost.\n");
	temp->set_class(18);
	temp->set_weight(3);
	temp->set_value(2000);
	move_object(temp,thief2);
	thief2->init_command("wield sword");
	temp=clone_object("players/padrone/obj/gravstone");
	temp->set_weight(-2);
	transfer(temp, thief2);
	temp=clone_object("obj/treasure");
	temp->set_id("jewel");
	temp->set_alias("gem");
	temp->set_short("A jewel");
	temp->set_long("A beautiful, glittering jewel.\n");
	temp->set_weight(3);
	temp->set_value(1000);
	move_object(temp,thief2);
	temp = clone_object("obj/treasure");
	temp->set_id("painting");
	temp->set_alias("picture");
	temp->set_short("A painting");
	temp->set_long("This painting shows a landscape. It is signed 'Gandalf',\n"
	  + "and on the backside it says 'Made in Mordor'.\n");
	temp->set_weight(3);
	temp->set_value(100);
	move_object(temp,thief2);
	temp=clone_object("obj/armour");
	temp->set_name("golden crown");
	temp->set_alias("crown");
	temp->set_short("A golden crown");
	temp->set_long("This is a golden crown. It is probably very expensive,\n" 
	  + "and has possibly once belonged to a great king. As a\n"
	  + "helmet, however, it would be worse than nothing.\n");
	temp->set_weight(3);
	temp->set_ac(-1);
	temp->set_type("helmet");
	temp->set_value(5000);
	move_object(temp, thief2);
	temp=clone_object("obj/weapon");
	temp->set_name("golden sword");
	temp->set_alias("sword");
	temp->set_short("A golden sword");
	temp->set_long("This is a sword made of gold. It is not very useful as a\n"
	  + "weapon, but hideously expensive.\n");
	temp->set_class(5);
	temp->set_weight(5);
	temp->set_value(3000);
	move_object(temp,thief2);
	temp = clone_object("obj/thing");
	temp->set_name( "panzer key" );
	temp->set_alias( "key" );
	temp->set_alt_name( "walkercell");
	temp->set_short( "A panzer key" );
	temp->set_long( "This is a panzer key.  You wonder where it fits.\n" );
	temp->set_value( 10 );
	move_object(temp,thief2);
	temp = clone_object("obj/weapon");
	temp->set_name("golden sword");
	temp->set_alias("sword");
	temp->set_short("A golden sword");
	temp->set_long("This is a sword made of gold. It is probably not very\n"
	  + "useful as a weapon, but it surely is hideously\n"
	  + "expensive!\n" );
	temp->set_class(5);
	temp->set_weight(5);
	temp->set_value(3000);
	move_object(temp,thief2);
    }
    if(!lawbringer) {
	lawbringer=clone_object("players/padrone/obj/lawbringer");
	if (thief2)
	    move_object(lawbringer, thief2);
	else if (thief1)
	    move_object(lawbringer, thief1);
	else
	    move_object(lawbringer, this_object());
    }
} /* extra_reset */

return_lawbringer()
{
    return lawbringer;
}

check_for_players() {
    object obj, junk;
    status found;

    found = 0;
    obj = first_inventory(this_object());
    while (obj) {
	if (living(obj) && !obj->query_npc()) {
	    tell_object(obj, "Suddenly, you get a feeling that no new treasure\n" +
	      "will be put in the vault as long as you are here...\n");
	    found = 1;
	}
	obj = next_inventory(obj);
    } /* while */
    junk = clone_object("obj/treasure");
    move_object(junk, "players/padrone/tower/rambo_room");
    obj = first_inventory(environment(junk));
    destruct(junk);
    while (obj) {
	if (living(obj) && !obj->query_npc()) {
	    tell_object(obj, "Suddenly, you get a feeling that no new treasure\n" +
	      "will be put in the vault as long as you are here...\n");
	    found = 1;
	}
	obj = next_inventory(obj);
    } /* while */
    return found;
} /* check_for_players */


put_back_lawbringer(lb) {
    if (lb != lawbringer)
	/* Not the real Lawbringer! */
	move_object(lb, "players/padrone/store");
    else if (thief2 && living(thief2) && present(thief2))
	/* Yes, ignore any weight limits. He can carry everything. */
	move_object(lb, thief2);
    else if (thief1 && living(thief1) && present(thief1))
	/* Yes, ignore any weight limits. He too can carry everything. */
	move_object(lb, thief1);
    else
	/* Yes, just put it there on the floor! */
	move_object(lb, this_object());
} /* put_back_lawbringer */


/* The vault is teleport-safe */
realm() { return "NT"; }

