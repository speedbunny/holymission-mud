/*coded by tatsuo for ishikawa*/

/* serpent */

inherit "/obj/monster";
object pscroll;

void reset(int flag) 
{
   ::reset(flag);

   if(flag == 0) 
   {
   
	set_name("Lung wang, The sea serpent");
	set_alt_name("lung");
	set_short("Lung Wang");
      set_race("dragon");
set_long("A great eastern dragon resembling a turtle.\n");
      set_level(30);
     set_hp(1000);
	set_wc(26);
      set_ac(10);
      set_aggressive(1);
      set_chance(40);
      set_spell_mess1("The Lung Wang breathes HOT steam at you!");
set_spell_mess2("The Lung Wang breathes HOT steam at you!");
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

