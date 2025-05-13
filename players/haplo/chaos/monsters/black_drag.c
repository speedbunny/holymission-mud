
inherit "obj/monster"; /* we take the standardobj */
object bh;

    
reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("dragon");
    set_level(30); 
    set_hp(800); /* for a level 20 monster */
    set_al(-100); /*for a bad monster */
    set_alias("black dragon");
    set_race("dragon"); 
    set_short("A large black dragon");
    set_long("Black dragon with yellow teeth and red staring eyes.\n"+
             "The long sharp claws look VERY sharp.\n");
    set_wc(30);
    set_ac(15);
    set_aggressive(0); /* (1) would be aggressive */
    set_move_at_reset(); /*at every reset it moves one field */
    add_money(random(500)+750);
    load_chat(8,({
      "Dragon says: Ahh! Meat! Come closer little one...\n",
       "Dragon pokes you in the ribs and says: Healthy, I like that!\n",
       "Dragon sniffs: You smell tender and juicy!\n"}));
    set_dead_ob(this_object()); /* the command before the monst dies */
    set_spell_mess1("The dragon throws a fireball at you");
    set_spell_mess2("The dragon hurts you with its claw");
                          /*messages during the fight */
    set_chance(20); /*the chance of the monst to cast a spell*/
    set_spell_dam(40); /*the random damage of the spell */
  }
}

monster_died(ob)
{
  tell_room(environment(this_object()), "You see the body of the dragon dissolve in thin air! The skeleton\n"+
      "falls in a heap of bones, you see a reddish glowing object\n"+
      "in the remains...\n");
  bh = clone_object("players/kbl/objs/blackheart");
  transfer(bh,this_object());
  return 0;
}
