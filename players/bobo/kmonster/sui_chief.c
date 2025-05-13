inherit "obj/monster";
 
object corpse,pal1,comm;
 
reset(arg) {
::reset(arg);
if (arg) return;
 set_name("leader");
 set_race("human");
 set_male();
 set_size(3);
 set_short("The Leader of the Palestinian suicide commando");
 set_long("The Leader is an big black bearded man "+
     "who won't excuse any attack!\n");
 set_ac(12);
 set_level(15);
 set_al(-50);
 set_wc(11);
 set_aggressive(0);
 set_heart_beat(1);
 set_move_at_reset(1);
 set_random_pick(20);
 
}
 
attack() {
  object pal;
  ::attack();
  notify("The leader says : You will regret it !\n");
  notify("The leader shouts : Come on boys, here's a job for us!\n");
  rand=random(3)+1;
  say("The leader summons help.\n");
  while (rand>=0) {
    pal=clone_object("/players/kelly/obj/fighter2");
    pal->attacked_by(attacker_ob);
    move_object(pal,environment(this_object()));
    rand--;
  }
  return 1;
 
}
