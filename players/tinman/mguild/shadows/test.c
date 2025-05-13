

/* the combat shadow */

inherit "/players/whisky/obj/std_shadow";

int mode;

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
       this_player()->attack(); /* grin */
   }

    dex_boni = me->query_dex() - me->query_weight();
    lev_calc = (4 + me->query_level()) * 2;
    
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
       return me->hit_player(dam,kind);
    }
    return me->hit_player(damage,kind);
 }

/* multiattacks */
mixed attack()
{
    int attack_boni;
    int i;
    int att_boni;
    object weap;

   if (objectp(me) && me->query_invis())
     me->set_vis();
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
         if ( objectp( weap = me->query_wielded() ) &&
              !weap->query_monk_weapon()) 
         {
            if (random(100) < 20) /* wielded weapon 1/5 attacks */
                me->attack();
         }
         else
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

int combat_shad()
{
    return 1;
}
     
/* the special score */
int score()
{
   string ret;
   string aik;
   string cn;
   int sz;
   int is_conc;
   string size;
   string stat;
   string victim;
   object att_ob;
   string mode_str;
   string religion;

   sz = me->query_size();
   is_conc = "/players/whisky/guild/shadows/aik_test"->aik_test(me);
   cn = capitalize(me->query_real_name());
 
   mode_str = query_mode();
 
   if (objectp(att_ob = me->query_attack()))
       victim  =  att_ob->query_name();
   else 
       victim = "none";

   switch(sz)
   {
     case 0: size = "any"; break;
     case 1: size = "tiny"; break;
     case 2: size = "small"; break;
     case 3: size = "medium"; break;
     case 4: size = "large"; break;
     default: size = "x-large"; break;
   }
    stat = "";

    if (me->query_poisoned())
        stat = stat + "poisoned ";
    if (me->query_intoxination())
        stat = stat + "drunken ";
    if (me->query_soaked())
        stat = stat + "soaked ";
    if (me->query_stuffed())
        stat = stat + "stuffed ";

    if (stringp(me->query_religion()))
       religion = me->query_religion();
    else
      religion = "Atheist";

     if (is_conc == 1) 
        aik = "concentrated";
     else 
        aik = "not concentrated";
    
   
     ret = ( 
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "              "+cn+" IN HOLY MISSION                    \n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  guild: MONK\t\t\t"+
     "  race: "+me->query_race()+"\n"+
     "  religion: "+religion+"\t\t"+
     "  current weight: "+to_string(me->query_weight())+"\n"+ 
     "  level: "+to_string(me->query_level())+"\t\t\t"+
     "  money: "+to_string(me->query_money())+"\n"+
     "  size: "+size+"\t\t\t"+
     "  experience: "+to_string(me->query_exp())+"\n"+
     "  command for info: help guild\t"+
     "  alignment: "+to_string(me->query_al_title())+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  health: \t\t\t  "+to_string(me->query_hp())+" "+
     "["+to_string(me->query_max_hp())+"]\n"+
     "  power: \t\t\t  "+to_string(me->query_sp())+" "+
     "["+to_string(me->query_max_sp())+"]\n"+
     "  vitals: \t\t\t  "+stat+"\n"+
     "  mood: \t\t\t  "+mode_str+"\n"+
     "  aikido: \t\t\t  "+aik+"\n"+
     "  wimpy set to: \t\t  "+to_string(me->query_wimpy())+"%\n"+
     "  wimpydir is : \t\t  "+me->query_wimpydir()+"%\n"+
     "  attacked by: \t\t\t  "+victim+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
     "  DEX: "+to_string(me->query_dex())+"  "+
     "WIS: "+to_string(me->query_wis())+"  "+
     "CON: "+to_string(me->query_con())+"  "+
     "INT: "+to_string(me->query_int())+"  "+
     "STR: "+to_string(me->query_str())+"  "+
     "CHR: "+to_string(me->query_chr())+"\n"+
     "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

     tell_object(me,ret);
   return 1;
}

/* the poison resistance */
mixed add_poison(int p)
{ 
   int res;
   
   res = me->query_con() * 2;
 
   if (p < random(res))
      return me->add_poison(0);
   return me->add_poison(p/5);
}

   
    

 object combat_ob()
 {
      return this_object();
}
mixed set_guild(mixed n)
{
  object soul;

  if (n != 7 && soul = present("monksoul",me) )
  {
      destruct(soul);
      call_out("dest_me",0);
   }
    return me->set_guild(n);
}
void dest_me()
{
   destruct(this_object());
   return; 
}

/* checking the allowance to wear an armour */

#define _ARM ({"ring","cloak","robe","amulet","boot","boots","other"})


mixed wear(object ob)
{
     if (objectp(ob) && ob->armour_class() > 0 && !ob->query_monk_wear()
         && member_array(ob->query_type(),_ARM)==-1)
     {
         tell_object(me,
         "Your vows forbit you to wear this armour !\n");
         call_out("unwear",0,ob);
      }
   return me->wear(ob);
}

void unwear(object ob)
{
   tell_object(me,"You remove your worn armour.\n");
   command("remove "+ob->query_name(),me);
}
/* monks cant join other religions */
mixed set_religion(string arg)
{
  if (arg!= "Illuvatar" && arg!="illuvatar")
  {
   tell_object(me,"Illuvatar growls: For you I am the one and only god !\n");
  return 1;
  }
  return me->set_religion(arg);
}

/* checking the allowance to wear an armour */

#define _ARM ({"ring","cloak","robe","amulet","boot","boots","other"})

inherit "/players/whisky/obj/std_shadow";

mixed wear(object ob)
{
     if (objectp(ob) && ob->armour_class() > 0 && !ob->query_monk_wear()
         && member_array(ob->query_type(),_ARM)==-1)
     {
         tell_object(me,
         "Your vows forbit you to wear this armour !\n");
         call_out("unwear",0,ob);
      }
   return me->wear(ob);
}

void unwear(object ob)
{
   tell_object(me,"You remove your worn armour.\n");
   command("remove "+ob->query_name(),me);
}
int arm_shad()
{
    return 1;
}
object arm_obj()
{
      return this_object();
}
