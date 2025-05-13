// copied and changed by Goldsun

/* -------------------------------------------------------------------------
   FILE: std_dragon.c
   FUNCTIONS:
   set_colour(string); ..red..pink..blue..green..brown..white..black..silver..
                       ..golden..yellow..copper..ametist..steel
   set_age(int);       1-12   1 = hatchling 12 = greater wyrm (rare)
   EXAMPLE:
                         inherit "/players/whisky/obj/std_dragon";

                         void reset(int flag)
                         {
                              ::reset(flag);
                              if (flag == 0)
                              {
                                set_colour("red");
                                set_age(8);
                              }
                         }
   done: the rest with breath .. works automatically :*)
   ------------------------------------------------------------------------- */

#define E environment
#define MaxAge 15
inherit "/obj/monster";

int age_base, pois, power, al;
int follow;
int silent;
int b, created;
string col, art, *enemies;
string home;

/* -------------------------------------------------------------------------
   Funktion: set_color 
   ------------------------------------------------------------------------- */

string set_colour(string which)
{
    if (!stringp(which)) col = "red";

    switch(which)
    {
      case "red":
        b = 1; art = "a blast of fire"; power = 5; al = -1000; break;
      case "blue":
        b = 2; art = "a cloud of electric bolts"; power = 4; 
        al = -800; break;
      case "green":
        b = 4; art = "a green gas cloud";  power = 2; pois = 1; 
        al = -600; break;
      case "copper":
        b = 9; art = "a cloud of cyanid";  power = 1; pois = 3; 
        al = 200; break;
      case "yellow":
        b = 4; art = "a blast of sulphuric acid"; power = 1; pois = 2; 
        al = -150;
        break;
      case "steel":
        b = 9; art = "a blast of glowing poisonous stones"; pois = 8; 
        power = 4; al = -100; break;
      case "brown":
        b = 0; art = "a sandstorm"; power = 5; al = 0; break;
      case "ametist":
        b = 0; art = "a blast of sharpened stones"; power = 3; al = 0; break; 
      case "white":
        b = 3; art = "a storm of ice crystals"; power = 1; al = -150; break;
      case "black":
        b = 4; art = "an acidic cloud"; power = 3; al = -600; break;
      case "pink": 
        b = 9; art = "a cloud of stinking rotten flesh"; pois = 8; power = 2;   
        al = -800;
        break;
      case "bronze":
        b = 9;  art = "a yellow cloud of chlorid gas"; power = 3; pois = 2;
        break;
      case "silver":
        b = 3; art = "a blast of ice crystals"; power = 5; al = 800; 
        break;
      default:
        b = 1; col = "golden"; art = "a blast of fire"; power = 6; 
        al = 1000;
        break;
    }
     if (!stringp(col)) col = which;
         return col;
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/* age 1 = hatchling MaxAge = greater wyrm */
int set_age(int age)
{
   if (intp(age) && age <= MaxAge)
       age_base = age;
   else
       age_base = 4;
   return age_base;
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
/* the dragonbreath */

int attack()
{
  object *inv;
  int i, sz, dam;

   if (member_array(attacker_ob,enemies)==-1)
       enemies = enemies + ({attacker_ob});

   i = age_base/4;
   
   while(i)
   {
      if (random(age_base))
         ::attack();
      i--;
   } 
   
  if (::attack() && !random(3))
   {
       inv = all_inventory(environment());
      
       tell_room(environment(),
       "The "+col+" dragon breathes "+art+" into the area !\n");

       dam = age_base * 5 / 2 * (power + 4);
       dam = dam/2 + random(dam/2);

       for ( sz = sizeof(inv), i = 0; i < sz; i++)
       {
           if (living(inv[i]) && inv[i]->query_race()!="dragon")
           {
               inv[i]->catch_tell("You are hit by "+art+"!\n");
               inv[i]->hit_player(dam, 5, ({b,10}) );
               if (pois > 0 && inv[i])
                   inv[i]->add_poison( (pois * age_base) );
           }
       }
     return 1;
   }
   return 0;
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
void catch_victim(object ob)
{
  if (objectp(ob) && interactive(ob) && (ob==this_object()->query_attack()) 
      && !ob->query_ghost() && E()!=E(ob))
  {
     if (E(ob)->query_property("no_fight"))
     {
        tell_object(ob,capitalize(col)+" dragon tells you:\n"+
        "     Would you care to step outside to settle this !\n");
        call_out("catch_victim",30,ob);
     }
     else 
     {
     tell_room(E(),"The "+art+" dragon flys angrily up into the air.\n");
     move_object(this_object(),E(ob));
     tell_room(E(),"You see a huge shadow, arriving just behind you.\n");
     }
  }
  if (!catch(call_other(home,"???")) && (!objectp(ob) || 
      !this_object()->query_attack() || this_object()->query_attack()!=ob) )
  {
     tell_room(environment(),
     capitalize(col)+" Dragon spreads it's wings and flys away.\n");
     move_object(this_object(),home);
  }
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
void catch_tell(string arg)
{
  int base;
   object vic;
   string who, where;


   base = 60 - (power * age_base);  /* the int of the dragon */

  if (random(base) <= 6 && follow)
   {
       if (sscanf(arg,"%s leaves %s.\n",who,where) == 2)
       {
          vic = find_living(lower_case(who));
          if (vic && !vic->query_npc() && member_array(vic,enemies)!=-1)
          {
             if (find_call_out("catch_victim") == -1)
                 call_out("catch_victim",4+random(20),vic);
          }
       }
   }
}


/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

void create_dragon()
{
   string age_str;
   int lv;

   
       if (age_base < 4) age_str = "small";
       else if (age_base < 8) age_str = "big";
       else age_str = "huge";

       lv = age_base * (power + 2);

       set_name(col+" dragon");
       set_no_steal();
       set_level(lv);
       set_hp( 40 + (lv * 30));
       set_wc(10+lv/2);
       set_alt_name("dragon");
       set_short("A "+age_str+", "+col+" dragon");
       set_long("You see a "+age_str+", "+col+" dragon.\n"+
                "It looks extremly dangerous.\n");
       set_race("dragon");
       set_size( 5 );
       set_gender(0);
       set_al(al);
       set_ac( 4 + (lv/ 9) );
       add_money( 2 * lv * lv );
       set_dead_ob(this_object());
       home = file_name(environment());
       experience=experience*2;
       if (objectp(E()) && !silent)
       {
       tell_room(E(),
       "Suddenly a big dark shadow lands next to you.\n");
       }
}


void reset(int flag)
{
     enemies = ({});
     ::reset(flag);
     if (flag == 0)
         created = 0;
     follow = 1;
}       

void set_silent(int s)
{
    silent = s;
}
int set_no_follow()
{
    follow = 0;
    return 1;
}
/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
int monster_died(object ob)
{
    object scale, scroll;
    int ac, val;
    
    ac = 1 + (power * age_base) / 15;
    val = 40 * power * age_base;

    scale = clone_object("/players/whisky/obj/scales/"+col+"_scale");
    move_object(scale,E());

/* scrolls */
/*
    if (col == "red" && age_base > 6)
       scroll = clone_object("/players/whisky/obj/firesh_scroll");
     else if (age_base > 9)
       scroll = clone_object("/players/whisky/obj/bark_scroll");
    else if (power > 1 && age_base > 6)
       scroll = clone_object("/players/whisky/obj/stone_scroll");
     else if (pois > 0 && age_base > 6)
       scroll = clone_object("/players/whisky/obj/pois_scroll");
    else if (age_base > 6)
       scroll = clone_object("/players/whisky/obj/res_scroll");
    else
       scroll = clone_object("/players/whisky/obj/recall_scroll");
    move_object(scroll,E());
 */
  return 0;
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
void init()
{
  int see_invis;
  object vic;

  see_invis = power * age_base;

  if (!created)
  {
      create_dragon();
      created = 1;
  }

   if (member_array(this_player(),enemies)!=-1)
   {
       if (this_player()->query_attack()!=this_object())
           enemies = enemies - ({this_player()});
   }
   ::init();
}

int run_away()
{
    return 0;
}

mixed hit_player(int dam, int kind, mixed *ele)
{
   if (ele && member_array(b,ele)!=-1)
       return ::hit_player(0,kind,ele);
	return ::hit_player(dam,kind,ele);
}

int query_ghost()
{
  return 0;
}

int detect_invis()
{
    return ( (random(age_base) - 5) > 0);
}

