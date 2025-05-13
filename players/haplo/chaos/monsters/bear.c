/* Standard bear */

inherit "obj/monster"; /* we take the standardobj */
#define CLAW "/players/kbl/objs/bear_claw"

object bh;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("bear");
    set_level(40); 
    set_al(-100); /*for a bad monster */
    set_alias("bear");
    set_race("bear"); 
    set_alt_name("hugebear");
    set_short("HUGE black bear");
    set_long("Huge black bear with yellow teeth and red staring eyes.\n"+
             "The long sharp claws look VERY sharp.\n");
    set_wc(19);
    set_ac(25);
    set_aggressive(random(2)); /* (1) would be aggressive */
    set_move_at_reset(); /*at every reset it moves one field */
    load_chat(8,({
                  "Bear paces around looking at you.\n",
                  "Bear snorts loudly.\n", "Bear scratches its side.\n",
                  "Bear licks its front paws.\n","Bear growls at you.\n",
                  "Bear paces backwards and bumps into the wall.\n",
                  "Bear stretches its body out and gives a big yawn.\n",
                 }));
    set_dead_ob(this_object()); /* the command before the monst dies */
    set_spell_mess1("The bear bats you with its paws");
    set_spell_mess2("The bear hurts you with its claw");
                          /*messages during the fight */
    set_chance(20); /*the chance of the monst to cast a spell*/
    set_spell_dam(40); /*the random damage of the spell */
    add_money(random(500)+200);
    transfer(clone_object(CLAW),this_object());
    init_command("wield claw");
  }
}

monster_died(ob)
{
  tell_room(environment(this_object()), "You see the body of the bear dissolve in thin air! The skeleton\n"+
      "falls in a heap of bones, you see a reddish glowing object\n"+
      "in the remains...\n");
  bh = clone_object("players/kbl/objs/blackheart");
  transfer(bh,environment(this_player()));
  this_player()->add_exp(10000);
  return 0;
}
