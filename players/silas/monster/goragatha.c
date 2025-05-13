inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("goragatha");
  set_alias("basilisk");
  set_short("Goragatha, King of Basilisks");
  set_long("This is by far the ugliest monster you've ever seen. It has the\n"+
         "head of a chicken and the torso and legs of a toad. Normally this\n"+
         "wouldn't be much of a problem, but in this case the creature\n"+
         "towers over you at 100 feet and is angrily clawing in your\n"+
         "direction. Legend has it that basilisks have the power to petrify\n"+
         "their attackers, but this one seems content to eliminate its\n"+
         "would-be slayers in a more traditional fashion.\n");
  set_level(65);
  set_al(-5000);
  add_money(7000+random(1500));
  set_chance(33);
  set_spell_dam(100);
  set_spell_mess2("Goragatha rips chunks of flesh out of your torso with its claws.");
  set_aggressive(1);
  return 1;
}

init() {
 ::init();
 add_action("north","north");
}

north() {
   write("Goragatha is blocking the northern exit with its immense body.\n"+
         "You'll have to kill it first.\n");
   return 1;
}
int monster_died(object ob)
{
if(!this_player()->query_immortal())
{
shout("An unholy scream echoes across the land as "+this_player()->query_name()+" defeats Goragatha in battle!\n");
return 0;
} else {
tell_room(environment(this_object()), "You have defeated Goragatha!\n",this_player());
write ("Sorry you are immortal it will not echoall.\n");
return 0;
}
return 1;
}
