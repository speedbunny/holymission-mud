inherit "obj/monster";

object wand,circlet;

reset(arg)
{
  object pot;
  int i;
  ::reset(arg);
  if (arg)
    return;
  set_race("human");
  set_alias("demeter");
  set_level(100);
  set_ac(10);
  set_short("demeter");
  set_name("demeter");
  set_long("This is the evil sorceress Demeter, she has been plotting to \n"
          +"to kill Ambrose for decades.  She is here to finally start her \n"
          +"plans to kill him.\n");
  set_gender(2);
  set_al(-1000);
  add_money(4000);
  set_aggressive(1);
  wand=clone_object("players/ambrose/avalon/weapons/wand");
  circlet=clone_object("players/ambrose/avalon/armour/circlet");
  move_object(wand,this_object());
  move_object(circlet,this_object());
  init_command("wield wand");
  init_command("wear circlet");
  

  set_language_skill(2,100);

  change_spell("fear",90,95,1);
  change_spell("chainlightning",65,80,1);
  change_spell("fireball",70,90,0);
 }
 int concentrate( object vic )
 {
   int rnd;
   if ( vic &&!query_concentrating()){

   rnd=random(100);
   if (rnd < 40)
      npc_process_spell("fear", vic->query_real_name());
   else if (rnd < 50)
      npc_process_spell("chainlightning", vic->query_real_name());
   else if (rnd < 70)
      npc_process_spell("fireball", vic->query_real_name());
   else
      return(0);
   return(1);
   }
  return(0);
  }
