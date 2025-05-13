
/* wotan the germanic father of gods and the god of death */

inherit "/obj/monster";
int act;

void reset(int flag)
{
  object shad, item;
    ::reset(flag);
    if (flag == 0)
    {
       act = 0;
       set_name("wotan the human");
       set_alt_name("human");
       set_race("god");
       set_short(query_name());
       set_long(
       "You see an old, long bearded man. He looks a bit like a beggar.\n"+
       "His long hair is gray and his skinny body looks very weak.\n"+
       "His head is fixed to the ground and he looks like he is thinking\n"+
       "hard. In his right hand he holds a small oak wooden stick and his\n"+
       "body is covered with a dirty, old cloak made of wool. On his head\n"+
       "he wears an old outworn strawhat. He just stands here like an old\n"+
       "oak, forgotten and not watered, one with the nature and one with\n"+
       "death, no sense but still alive.\n"); 
// oki that people are warned when the consider him 
       set_level(100);  
       set_wc(10);
       set_ac(0);
       set_hp(400);
       set_no_steal();
       set_dead_ob(this_object());
// the shadows
       shad = clone_object("/players/whisky/obj/sanct_shad");
       shad->start_shadow(this_object(),0,"sanct_shad");
       shad = clone_object("/players/whisky/obj/bark_shad");
       shad->start_shadow(this_object(),0,"bark_shad");
       shad = clone_object("/players/whisky/obj/freeact_shad");
       shad->start_shadow(this_object(),0,"freeact_shad");
       shad = clone_object("/players/whisky/obj/stone_shad");
       shad->start_shadow(this_object(),0,"stone_shad");
       shad = clone_object("/players/whisky/obj/firesh_shad");
       shad->start_shadow(this_object(),0,"firesh_shad");
       shad = clone_object("/players/whisky/obj/pois_shad");
       shad->start_shadow(this_object(),0,"pois_shad");
// here the items
       item = clone_object("/players/whisky/obj/hearo_potion");
       transfer(item,this_object());
       item = clone_object("/players/whisky/obj/hearo_potion");
       transfer(item,this_object());
// the equip
       item = clone_object("/players/whisky/quest/obj/hat");
       transfer(item,this_object());
       item = clone_object("/players/whisky/quest/obj/cloak");
       transfer(item,this_object());
       item = clone_object("/players/whisky/quest/obj/staff");
       transfer(item,this_object());
// wearing btw wielding
       init_command("wear hat");
       init_command("wear cloak");
       init_command("wield staff");
    }
}


int monster_died(object ob)
{
   object *inv;
   int i, sz;

   inv = all_inventory(environment(ob));

    tell_room(environment(),"You are enveloped in an icy storm as "+ob->query_name()+ 
             " vanishes !\n");
    tell_object(this_player(),"You feel more experienced.\n");
// for the hmm lets call it a kill
    this_player()->add_exp(80000);
    for(sz = sizeof(inv),i = 0; i < sz; i++)
    {
        if (inv[i]!=this_object())
            inv[i]->hit_player(50 + random(100),5,({3,12}));
    }
    destruct(this_object());
  return 1;
}

    
int attack()
{
  object att;
  object mob;

// default to avoid bugs
   att = attacker_ob;

// cloudkill
   if (!present("killing cloud",environment()))
   {
       tell_room(environment(),query_name()+" summons a strange yellow dust from nowhere !\n");
       mob = clone_object("/players/whisky/obj/killing_cloud");
       mob->set_caster(this_object());
       transfer(mob,environment());
   }
   if (::attack() && att && living(att) && random(4))
   {
      (act > 3 ? act=0 : act++);
      switch(act)
      {
// darkness
        case 0: 
        if (!present("globe",this_object()))
        {
           tell_room(environment(),query_name()+" creates a globe of Darkness !\n");
           mob = clone_object("/players/whisky/obj/globe");
           move_object(mob,this_object());
        }
// weaken
        break;
        case 1: 
         if (!att->weaken_shad())
         {
            say(query_name()+" touches "+att->query_name()+" !\n",att);
            tell_object(att,query_name()+" touches you !\n");
            mob = clone_object("/players/whisky/obj/weaken_shad");
            mob->start_shadow(att,100,"weaken_shad");
            tell_object(att,"You feel weaker !\n");             
         }
        break;
// psychonics 
        case 2: 
          if (mob = this_player()->query_wielded())
          {
             say(query_name()+" looks conzentrated !\n",att);
             tell_object(att,"Your weapon leaves your hand and levitates to "+query_name()+".\n");
             att->stop_wielding(mob);
             transfer(mob,this_object());
           }
        break;
// and when that not helps !!! lightning 
        default: 
          say(query_name()+" raises his hands and summons a flash from the sky !\n");
          tell_object(att,"You are hit badly !\n");
          if (living(att)) 
              att->hit_player( random(300),5,({2,12}) );
          break;
      }
    return 1;
  }
  return 0;
}


int query_str()
{
    return 10;
}

int query_dex()
{
    return 10;
}

int run_away()
{
    return 0;
}

int stop_fight()
{
    return 0;
}

varargs mixed hit_player(int dam,int kind,mixed elem)
{
// dont hit more than 25 hp the round
  if (dam > 25)
      dam = 25;

      if (query_hp() < 200 && present("potion",this_object()))
          command("quaff potion",this_object());
   return ::hit_player(dam,kind, elem);
}

