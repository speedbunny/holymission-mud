inherit "obj/monster";

object head;

reset(){
::reset();
set_name("lamtrashara");
set_race("dragon");
set_short("Lamtrashara");
// set_ac(10);
set_alias("dragon");
set_long("This evil dragon his huge claws and fangs. He is the ruler of\n"+
         "all dragons. As you look at him, your knees become weak. You\n"+
         "want to run away!\n");
set_level(60);
set_hp(5000);
set_gender(1);
set_heart_beat(1);
set_dead_ob(this_object());
}

heart_beat()
{
 ::heart_beat();
}

monster_died(ob)
{
 write("You have slain Lamtrashara, the Dragonlord!\n");
  shout(this_player()->query_name()+" has slain Lamtrashara, the Dragonlord!\n");
 head = clone_object("/players/iishima/quest/head.c");
 move_object(head, environment(this_object())); 
 return 0;
}
