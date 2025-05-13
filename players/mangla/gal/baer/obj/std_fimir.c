/* -------------------------------------------------------------------------
   FILE: std_fimir.c
   FUNCTIONS:
   set_belief(string);   arthredian .. ametriest .. imlardian .. bornation
                         delevium .. mondion .. paradial
   set_class(int);       1-12   1 = believer 12 = lord
   EXAMPLE:
                         inherit "/players/baer/obj/std_fimir";
                         int n = 6, nn = 13;

                         void reset(int flag)
                         {
                              ::reset(flag);
                              if (flag == 0)
                              {
                                set_belief("arthredian");
                                set_class(random(nn));
                              }
                         }
   ------------------------------------------------------------------------- */

#define E environment
inherit "/obj/monster";

int class_base, al;
int created;
string belief, art, spl;

/* -------------------------------------------------------------------------
   Function: set_belief 
   ------------------------------------------------------------------------- */
string set_belief(string which)
{
    if (!stringp(which)) belief = "arthredian";

    switch(which)
    {
      case 0:
        belief = "arthredian"; spl = "magic missile"; al = 100; break;
      case 1:
        belief = "ametriest";
        spl = "harm" al = -300; break;
      case 2:
        belief = "imlardian";
        spl = "freeze"; al = -600; break;
      case 3:
        belief = "bornation";
        spl = "magic missile";  al = 200; break;
      case 4:
        belief = "delevium";
        spl = "acid blast"; al = 0; break;
      case 5:
        belief = "mondion";
        spl = "cause critic"; al = 0; break;
      default:
        belief = "paradial"; spl = "slay living"; al = 1000; break;
    }
         return belief;
  }
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
int set_class(int class)
{
   if (intp(class) && class <= 12)
       class_base = class;
   else
       class_base = 4;
   return class_base;
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */

void create_fimir()
{
   string class_str;
   int lv;
   
       if (class_base < 3) class_str = "Believer";
       else if (class_base < 6) class_str = "Defender";
       else if (class_base < 9) class_str = "Warrior";
       else if (class_base < 12) class_str = "Master";
       else class_str = "Lord";

       lv = 5 + (5 * class_base);

       set_name(belief+" "+class_str" fimir");
       set_no_steal();
       set_level(lv);
       set_hp(lv * 35);
       set_wc(10+lv/2);
       set_alt_name("fimir");
       set_short("A "+belief+" "+class_str+".");
       set_long("You see a "+belief+", "+class_str+" fimir.\n"+
                "Master of Might and Magic, it looks very deadly.\n");
       set_race("fimir");
       set_size( 4 );
       set_gender(0);
       set_al(al);
       set_ac( 4 + (lv/ 9) );
       set_language_skill( 2, 100);
       change_spell( spl ,(50+(3*class_base)), 95, 1); 
       add_money( lv * lv * 3/2);
       set_dead_ob(this_object()); /* Do I need this ? */
       if (objectp(E())
       {
       tell_room(E(),
       "A "+belief+" "+class_str+" enters the rooms and eyes you" +
       + "suspiciously.\n");
       }
}


void reset(int arg)
 {
     ::reset(arg);
     if (arg == 0)
         created = 0;
}
/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
int monster_died(object ob)
/* Reward the players with some appropriate treasures */
{
    object scroll;

    if (class_base > 11)
       scroll = clone_object("/players/baer/obj/recall_scroll");
     else if (class_base > 9)
       scroll = clone_object("/players/baer/obj/recall_scroll");
    else if (class_base > 6)
       scroll = clone_object("/players/baer/obj/recall_scroll");
     else if (spl == "fire storm" && class_base > 6)
       scroll = clone_object("/players/baer/obj/recall_scroll");
    else if (class_base > 3)
       scroll = clone_object("/players/baer/obj/recall_scroll");
    else
       scroll = clone_object("/players/baer/obj/dummy_scroll");
    move_object(scroll,E());

  return 0;
}

/* -------------------------------------------------------------------------
   ------------------------------------------------------------------------- */
void init()
{

  if (!created)
  {
      create_fimir();
      created = 1;
  }
/* We want to know if it is there or not */
int concentrate( object vic )
/* Casting the spells */
{
   int rnd;

   if ( vic && !query_concentrating() ) { 
      rnd = random( 100 );
      if ( rnd < 40 ) 
/* Attempts to cast spell */
         npc_process_spell( spl, vic->query_real_name() );
/* Casts spell according to belief */
      else
         return( 0 );

      return( 1 );
   }

   return( 0 );
}

   ::init();
}

int detect_invis()
{
    return ( (random(class_base) - 5) > 0);
}
/* Limited detect invisibility according to level ??? */
