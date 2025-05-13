

/* -----------------------------------------------------------------------
   filename: garschmirak last edit: 11.2.94 whisky uni-linz.ac.at
  ----------------------------------------------------------------------- */

inherit "/obj/monster";

public int area_spell(int dam,string kind);


void reset(int flag)
{
  ::reset(flag);
  if (flag == 0)
  {
     set_name("garschmirak");
     set_alt_name("dragon");
     set_short("garschmirak, the five-headed cromatic dragon");
     set_long(
     "You see a huge, five-headed cromatic dragon. It stares with it's\n"+
     "red eyes at you !\n");
     set_race("dragon");
     set_aggressive(1);
     set_level(80);
     set_hp(10000);
     set_ac(40);
     set_wc(150);
     set_gender(1);
     set_dead_ob(this_object());
     move_object(clone_object("/players/whisky/seaworld/obj/golden_star"),
                 this_object());
   }
}

int monster_died(object ob)
{
  object m, scale;

  m = clone_object("/obj/money");
  m->set_money(5000+random(10000));
  move_object(m,environment());

/*
  scale = clone_object("/players/whisky/obj/scale");
  scale->set_name("dragonhide");
  scale->set_alias("hide");
  scale->set_short("multicoloured dragonhide");
  scale->set_long("The hide of Garschmirak the multicoloured dragon.\n");
  scale->set_weight(2);
  scale->set_value(6000);
  scale->set_ac(2);
  move_object(scale,environment());

  */
  if (!this_player()->query_immortal())
     shout(this_player()->query_name()+" killed Garschmirak the Lacerator.\n");
  this_player()->catch_tell(
  "Oh, the Gods praise your deed and it begins to rain gold coins.\n");
  return 0;
}


int attack()
{
 if (::attack())
 {
    if (!random(2) && find_call_out("cast_spell")==-1)
    {
     tell_room(environment(),query_name()+" takes a DEEP BREATH.\n");
     call_out("cast_spell",3);
    }
    if (!random(2))
       ::attack();
    if (!random(3))
       ::attack();
   return 1;
  }
  return 0;
}

 
query_hit_msg(dam,name,att,def)
{
 string how, hit_art;
 int rnd;

  rnd = random(7);

  switch(rnd)
  {
     case 0: 
       how = "with his right foreleg";
     break;
     case 1: 
       how = "with his left foreleg";
     break;
     case 2: 
       how = "with his blue head";
     break;
     case 3: 
       how = "with his red head";
     break;
     case 4: 
       how = "with his white head";
     break;
     case 5: 
       how = "with his black head";
     break;
     default: 
       how = "with his green head";
     break;
 }

   if (rnd  < 2)
       hit_art = "claws";
   else 
       hit_art = "bites";

  return ({"",hit_art+" you "+how,hit_art+" "+name+" "+how});
}
  

public mixed 
cast_spell()    
{
     switch(random(5))
     {
      case 0:  return area_spell(50,"CONE OF FIRE");
      case 1:  return area_spell(80,"CONE OF COLD");
      case 2:  return area_spell(60,"ACID RAY");
      case 3:  return area_spell(100,"LIGHTNING BOLT");
      case 4:  return area_spell(30,"GAS CLOUD");
     }
}

          /* spelldamage kind of spell resistance */
public int
area_spell(int dam,string kind)
{
 int i;
 object *inv;

 inv = all_inventory(environment());

 for (i=0;i<sizeof(inv);i++)
 {
  if (living(inv[i]))
  {
       tell_object(inv[i],"You are hit by a "+kind+".\n");
       if (inv[i]!=this_object())
       inv[i]->hit_player(dam + random(dam) , 5);
       if (dam == 30 && inv[i] && inv[i]!=this_object())
           inv[i]->add_poison(random(dam));
   }
 }
 return 1;
}
 
      
 
hold(caller,time)
{
 if (time > 8) return ::hold(caller,random(8));
 return ::hold(caller,time);
}
