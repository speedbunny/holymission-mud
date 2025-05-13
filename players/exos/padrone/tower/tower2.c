/* Modified by Ethereal Cashimor, 170293 */
inherit "room/room";

object the_guard;

reset(arg) {
object the_weapon,the_money;

  ::reset(arg);
  if(!arg) {
    dest_dir=({"players/padrone/tower/tower3","up",
	       "players/padrone/tower/tower1", "down"});
    short_desc="Inside Padrone's private tower";
    long_desc="You are approximately at the first floor of Padrone's private\n"
            + "tower. A stone staircase winds up and down from here.\n";
    smell="It's cold here.";
    items=({"tower","It looks very high",
            "staircase","It's made of solid stone"});
  }
  if (!the_guard) {
    the_guard=clone_object("obj/monster");
    the_guard->set_name("security guard");
    the_guard->set_alias("guard");
    the_guard->set_level(4);
    the_guard->set_hp(100);
    the_guard->set_wc(5);
    the_guard->set_al(-10);
    the_guard->set_short("A security guard");
    the_guard->set_long("This is a security guard in a dark suit, and he is\n"
                      + "proudly doing his job. He is responsible for the\n"
                      + "security here.\n");
    the_guard->set_aggressive(1);
    the_guard->set_male();
    the_guard->set_spell_mess1("The guard yells: This is a private area! Get out, terrorist!");
    the_guard->set_spell_mess2("The guard yells at you: This is a private area! Get out, terrorist!");
    the_guard->set_chance(50);
    move_object(the_guard, this_object());
    the_weapon=clone_object("players/padrone/obj/m16f");
    the_weapon->set_monsters_reload_at_reset(1);
    transfer(the_weapon, the_guard);
    the_guard->init_command("wield crossbow");
    the_money=clone_object("obj/money");
    the_money->set_money(random(50));
    transfer(the_money, the_guard);
  }
}
