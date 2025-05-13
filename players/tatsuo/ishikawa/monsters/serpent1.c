/*coded by tatsuo for ishikawa*/

/* serpent */

inherit "/obj/monster";
object pscroll;

void reset(int flag) 
{
   ::reset(flag);

   if(flag == 0) 
   {
   
      set_name("serpent");
      set_alt_name("deadly serpent");
      set_short("A Deadly Serpent");
      set_race("dragon");
     set_long("You see a sleek and powerful serpent from the mighty\n"+
      "Shou-Ti clan. It's green and gold scales glow with there\n"+
              "own inner light. Two colomuns of green smoke drift from\n"+
              "it's nostrils.  From it's teeth you know it is not to be messe\n"+
              "with; or bothered! BEWARE!!\n");
      set_level(30);
     set_hp(1000);
      set_wc(85);
      set_ac(10);
      set_aggressive(1);
      set_chance(40);
      set_spell_mess1("The serpent blasts you with it's golden fire");
      set_spell_mess2("The serpent's golden fire burns you badly, you're toast!!");
      set_spell_dam(40+random(40));
     
     pscroll=clone_object("players/tatsuo/ishikawa/obj/pscroll");
     move_object(pscroll, this_object());
   }
 }



int attack() 
{
  int i, sz;
  object *inv;

    if(::attack() && !random(3))
    {
        if(attacker_ob && living(attacker_ob))
        {
          inv = all_inventory(attacker_ob);

          for(sz = sizeof(inv), i=0; i < sz; i++)
          {
              if (inv[i]->query_wielded())   /* a wielded weapon */
              {
                tell_object(attacker_ob,
                "The serpent grabs your weapon with it's jaw!! "+
                "YOU ARE NOW WEAPONLESS!!!\n");
                attacker_ob->stop_wielding(inv[i]); /* don't destruct :*) */
                move_object(inv[i],this_object());
                say("The serpent grabs "+attacker_ob->query_name()+
                " weapon in it's jaw !!\n",attacker_ob);
               return 1;
              } /* endif */
         } /* endfor */
      }   /* endif */
    return 1;   /* (success) */
    }  /* endif */
  return 0;
 }

