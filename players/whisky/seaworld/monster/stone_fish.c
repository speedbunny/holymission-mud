

/* filename: stone_fish.c last edit: 3.1.94 whisky uni-linz.ac.at */

inherit "/obj/monster";  /* the standardmonster */

 object fang;

void reset(int arg) 
{
   ::reset(arg);   /*  calling the old reset : reset of the monster */

    if (!fang)
    {
        fang = clone_object("/players/whisky/seaworld/obj/fang");
        move_object(fang,this_object());
    }
    if (arg) return;

      set_name("stone fish");
      set_no_steal();
      set_alias("fish");
      set_short("A stone fish");
      set_race("fish");
      set_long("It looks very dangerous so dare to attack it\n");
      set_level(15);
      set_has_gills();
      set_size(3);
      set_wc(15);
      set_ac(20);
 }

public int
query_no_steal() 
{ 
     return 1; 
}

/* ------------------------------------------------------------------
   Using the worse function from the living. The attack is called any
   time when the living is attacked with the heart_beat .. call_out 2.
   The heart_beat will never be removed not only called if there is an
   attack.
   ------------------------------------------------------------------- */
   
attack()
{
  if (attacker_ob && environment()==environment(attacker_ob) 
      && random(100) < 8 )
  {
     attacker_ob->catch_tell(
     "Suddenly the stone fish stingers you with it's poisonous fang.\n");
     attacker_ob->command("scream");
     attacker_ob->add_poison(8+attacker_ob->query_con()/2);
  }
  return ::attack();   /* calling the old attack from the living */
}
