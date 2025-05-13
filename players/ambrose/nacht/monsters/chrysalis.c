inherit "obj/monster";

reset(arg)
  {
    ::reset(arg);
    if(!arg)
    {
    set_name("chrysalis");
    set_level(25);
    set_race("Destroyer");
    set_gender(2);
    set_short("Chrysalis of the Destoyers");
    set_long("You see a woman in a purpled hued armor.  She has strange aura\n"+
             "about her.  It as if she died and only part of her returned to\n"+
             "life.\n");
    set_wc(29);
    set_ac(20);
    add_money(1000 + random(500));
    }

  }
    init()
    {
     ::init();
     set_heart_beat(1);
    }

   heart_beat()
   {
    ::heart_beat();
    
    write("Heart Beat activated.\n");
 
  if(attacker_ob &&present(attacker_ob, environment()))
   {
    if(random(100)<40)
    {
    tell_object(attacker_ob, "Chrysalis has weaved a cocoon around you!\n");
    say("Chrysalis has cocooned "+attacker_ob->query_name()+".\n",attacker_ob);
    attacker_ob->hold(this_player(), random(7));
   }
   }
   }

 hold_end (obj)
 {
 tell_object(obj, "You break out of the cocoon!\n");
  return 1;
 }
