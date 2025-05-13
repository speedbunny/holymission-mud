/* This room has been changed by Ethereal Cashimor to resemble a more fantasy
   like room. And changed it too room/room, like the rest! 170293 */
inherit "room/room";

object the_terrorist;

reset(arg) {
object weapon;

  ::reset(arg);
  if(!arg) {
    dest_dir=({"players/padrone/tower/tower4", "up",
	       "players/padrone/tower/tower2", "down"});
    short_desc="Inside Padrone's private tower",
    long_desc="You are approximately at the second floor of Padrone's private\n"
            + "tower. A stone staircase winds up and down from here.\n";
    items=({"tower","It looks very high",
            "staircase","Don't worry, it won't collapse"});
    smell="It's cold here.";
  }
  if (!the_terrorist) {
    the_terrorist=clone_object("obj/monster");
    the_terrorist->set_name("angry terrorist");
    the_terrorist->set_alias("terrorist");
    the_terrorist->set_level(6);
    the_terrorist->set_hp(120);
    the_terrorist->set_male();
    the_terrorist->set_al(-100);
    the_terrorist->set_race("human");
    the_terrorist->set_short("An angry terrorist");
    the_terrorist->set_long("This is a terrorist, wearing black clothes and a\n"
                          + "green jacket. He has long, unwashed hair, a mask\n"
                          + "over his eyes, and an angry look. He must have\n"
                          + "sneaked past the security! Maybe he has come to\n"
                          + "kill the wizard or blow up the castle?\n");
    the_terrorist->set_aggressive(1);
    the_terrorist->set_spell_mess1("The terrorist yells: Away with the nobility! Down with the castles!");
    the_terrorist->set_spell_mess2("The terrorist yells: Away with the nobility! Down with the castles!");
    the_terrorist->set_chance(20);
    the_terrorist->set_spell_dam(20);
    move_object(the_terrorist, this_object());
    weapon=clone_object("obj/weapon");
    weapon->set_name("spear");
    weapon->set_class(12);
    weapon->set_value(100);
    weapon->set_weight(1);
    weapon->set_short("A long iron spear");
    transfer(weapon,the_terrorist);
    the_terrorist->init_command("wield spear");
  }
}
