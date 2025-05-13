/* Changed by Ethereal Cashimor, 230293, Room/room and no Rambo's */
inherit "room/room";
#include "../../../obj/door.h"

object rambo1, rambo2, rambo3;
object the_key;

rambo_block()
{
    if (rambo1 && present(rambo1, this_object()))
	write("Archer I bars the way.\n");
    if (rambo2 && present(rambo2, this_object()))
	write("Archer II bars the way.\n");
    if (rambo3 && present(rambo3, this_object()))
	write("Archer III bars the way.\n");

    if (   (rambo1 && present(rambo1, this_object()))
	|| (rambo2 && present(rambo2, this_object()))
	|| (rambo3 && present(rambo3, this_object())))
	return 1;
    else
	return 0;
}

north_it() {
  if(rambo_block()) return 1;
  this_player()->move_player("north#players/padrone/tower/treasury");
  return 1;
}

reset(arg) {
  ::reset(arg);
  if(!arg) {
    dest_dir=({"","north"});
    short_desc="Archer room in the treasury";
    long_desc="This is the Castle's treasury. Over the years, many of the\n"
            + "riches of the world have been collected here. In his youth the\n"
            + "Wizard travelled the world and collected numerous fantastic\n" 
	    + "and valuable items, and since he retired from his adventuring\n"
            + "and settled down in this comfortable castle, consultation fees\n"
            + "and royalties have contributed even more to his fortune. The\n"
            + "treasure is stored in the vault, north of this room.\n";
    set_light(1);
    smell="You smell gold!";
    items=({"treasury","The smell of great treasures is near",
            "vault","It's to the north"});
  }
  throw_out_players();
  if (!rambo3) {
    make_rambo(3);
    MAKE_KEY(the_key, "maximum-security", "vaultdoor")
    transfer(the_key, rambo3);
  }
  if(!rambo2) make_rambo(2);
  if(!rambo1) make_rambo(1);
}

init() {
  ::init();
  add_action("north_it","north");
}

make_rambo(nr) {
object rambo, weapon;
string roman;

      if (nr == 1)
	  roman = "I";
      else if (nr == 2)
	  roman = "II";
      else if (nr == 3)
	  roman = "III";
      rambo = clone_object("obj/monster");
      if (nr == 1) {
	  rambo1 = rambo;
	  rambo->set_alias("archer i");
      }
      else if (nr == 2) {
	  rambo2 = rambo;
	  rambo->set_alias("archer ii");
      }
      else if (nr == 3) {
	  rambo3 = rambo;
	  rambo->set_alias("archer iii");
	  move_object(clone_object("players/padrone/obj/immunity"), rambo);
      }
      rambo->set_name("archer"); 
      rambo->set_race("human");
      rambo->set_level(14 + nr);	/* 15, 16, and 17 */
      rambo->set_hp(200 + 100*nr); 
      rambo->set_ac(8 + 2*nr);
      rambo->set_al(40);
      rambo->set_short("Archer " + roman);
      rambo->set_long("This is Archer "+roman+". Wow! What bulging muscles!\n" 
                    + "He is employed by Padrone to guard the treasury. Which\n"
                    + "he does.\n");
      rambo->set_aggressive(1);
      rambo->set_male();
      weapon = clone_object("players/padrone/obj/m16f");
      if(nr==3) {
	weapon->set_max_bullets(40);
	weapon->set_bullets(40);
	weapon->set_wc_per_bullet(2);
	weapon->set_sound("TOK");
	weapon->set_value_per_bullet(2);
	weapon->set_value(40);
        weapon->set_info("This is the advanced repeater crossbow version");
      }
      weapon->set_monsters_reload_at_reset(1);
      transfer(weapon,rambo);
      rambo->init_command("wield crossbow");
      move_object(rambo, this_object());
      return rambo;
} /* make_rambo */

throw_out_players() {
object obj, this_obj;

    obj = first_inventory(this_object());
    while (obj) {
	this_obj = obj;
	obj = next_inventory(obj);
	if (living(this_obj) && !this_obj->query_npc()) {
	    tell_object(this_obj, "Suddenly, you have a feeling of disorientation.\n");
	    this_obj->move_player("out#players/padrone/tower/hall");
	}
    } /* while */
} /* throw_out_players */
