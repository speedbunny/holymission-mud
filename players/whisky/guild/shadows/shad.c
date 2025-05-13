

/* the combat shadow */

#define _partner "/players/sauron/guild/room"

inherit "/players/whisky/obj/std_shadow";

int mode;
object *bad_armours;
closure call;
 
int start_shadow(object who,int time,string type)
{
    call = #'call_other;
    return ::start_shadow(who,time,type);
}

/* the dodge depending from the fightingstyle */

mixed hit_player(int damage, int kind)
{
   int dam;
   int dex_boni;
   int lev_calc;
   string dir;
   object med;

   if (objectp(med = present("blocker",me)) )
   {
       destruct(med);
       if (living(this_player()) && environment(this_player()) ==
           environment(me) )
       apply(call,this_player(),"attack"); /* grin */
   }

   if (sizeof(bad_armours))  /* wearing armours which arn't allowed */
       return apply(call,me,"hit_player",damage,kind); 

    dex_boni = apply(call,me,"query_dex") - apply(call,me,"query_weight");
    lev_calc = (4 + apply(call,me,"query_level")) * 2;
    

        
    if (dex_boni < 0)
        dex_boni = 0;

    if ( (2*dex_boni) > lev_calc)
          dex_boni = lev_calc/2;

    if (!intp(mode))
        mode = 1;

    if (kind!=6 && kind!=5)
    {
       if (!random(2))
           dir = "right";
       else 
           dir = "left";

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
       return apply(call,me,"hit_player",dam,kind);
    }
    return apply(call,me,"hit_player",damage,kind);
 }

/* multiattacks */
mixed attack()
{
    int attack_boni;
    int i;
    int att_boni;
    object weap;
    mixed skill; /* attack skill */
    int get_attack;


   skill = funcall(call,me,"get_skill","monk_attack");

   if (!skill)
       skill = 1;
   else 
       skill = skill[0];

   if (random(100) < skill)
       get_attack = 1;
   else
   {
    }
    att_boni = apply(call,me,"query_dex") / 4;

    if (sizeof(bad_armours)) /* no attack boni */
        return apply(call,me,"attack");

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
         if ( objectp( weap = apply(call,me,"query_wielded") ) &&
              !apply(call,weap,"query_monk_weapon")) 
         {
           if (get_attack && (13 + apply(call,me,"query_dex")/3 > random(100)))
                apply(call,me,"attack");
         }
         else
         {
           if (get_attack && (39 + apply(call,me,"query_dex") > random(100)))
               apply(call,me,"attack");
         }
     }
     return apply(call,me,"attack");
}
