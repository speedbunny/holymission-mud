

/* the fighter shadow */

inherit "/players/whisky/obj/std_shadow";

int mode;

/* the dodge depending from the fightingstyle */

mixed hit_player(int damage, int kind)
{
   int dam;      /* the damage the fighter gets */
   int dex_boni; /* the dexterity bonus */
   int lev_calc; /* the level bonus */

    dex_boni = me->query_dex() - me->query_weight();
    lev_calc = (4 + me->query_level()) * 2;
    
    if (dex_boni < 0)
        dex_boni = 0;

    if ( (2*dex_boni) > lev_calc)
          dex_boni = lev_calc/2;

    if (!intp(mode))
        mode = 1;

        switch(mode)
        {
          /* defence mode : dodging every 4th attack */
          case 0:
            if (random(lev_calc) < random( dex_boni/2 ) )
                dam = 0;
            else 
                dam = damage;
            break;
          /* standard mode : dodging any 8th attack */
          case 1: 
            if (random(lev_calc) < random( dex_boni/4 ) )
                dam = 0;
            else 
                dam = damage;
            break;
          /* aggressive mode : no dodge at all */
          default:
              dam = damage;
            break;
        }
   return me->hit_player(dam,kind);
}

/* multiattacks of the fighter */
mixed attack()
{
    int attack_boni;
    int i;
    int att_boni;
    object weap;
    int get_attack;


    att_boni = me->query_dex() / 17;

    switch(mode)
    {
     /* defence mode  maximum +1 attacks  to 30 dex */
      case 0:
       attack_boni = att_boni;     
       break;
     /* standard  maximum +2 attacks  to 30 dex */
      case 1:
       attack_boni = att_boni + 1;
       break;
     /* aggressive maximum +3 attacks */
      default:
       attack_boni = att_boni + 2;
       break;
     }

     for ( i=0 ; i < attack_boni; i++)
     {
           if ( 10 + me->query_dex()/2 > random(100) )
                me->attack();
      }
     return me->attack();
}

/* setting the combat mode */
        
int set_mode(string arg)
{
  string *art;
  string ret;
  int i;
  
   art = ({"defensive","moderate","aggressive"});

   if (!intp(mode))
        mode = 1;

   if (!arg || member_array(arg,art)==-1)
   {
      ret = "Mode set to:\n\n";
      i = 0;
      while (i < 3)
      {
          ret = ret + art[i];
       if (i == mode)
              ret = ret + " *";
          ret = ret + "\n";
          i++;
      }
      tell_object(me,ret);
      return 1;
    }
     tell_object(me,"Mode now set to: "+arg+" !\n");     
     mode = member_array(arg,art);
     return 1;
}   

string query_mode()  /* just for checking */
{
  string ret;

  if (mode == 0)
      ret = "defensive";
  else if (mode == 2)
      ret = "aggressive";
  else 
      ret = "moderate";

   return ret;
}

int fighter_shad()
{
    return 1;
}
     
object fighter_ob()
{
      return this_object();
}

/* here the shadow is destructed, when the player changes the guild */

mixed set_guild(mixed n)
{
  object soul;

  if (n != 3)
      call_out("dest_me",0);
   return me->set_guild(n);
}

void dest_me()
{
   destruct(this_object());
   return; 
}
