
/* draketail */

inherit "obj/weapon";

void reset(int flag) 
{
   ::reset(flag);

  if (flag == 0)
  {
     set_name("tail");
     set_class(12);
     set_weight(2);
     set_value(600);
     set_alias("draketail");
     set_short("draketail");
     set_long(
     "You see the wonderful scale-covered tail of a big drake.\n"+
     "It's hard, sharp and stiff and is made of strong scales.\n"+
     "It looks like the proper weapon to fight drakes with.\n");
      set_hit_func(this_object());
    }
}

int weapon_hit(object ob) 
{
  if (ob->query_race() != "drake") 
     return 0;

     write("Your tail cuts big wounds into the body of the drake.\n");
     say(this_player()->query_name()+" thrusts "+
     this_player()->query_possessive()+
    " drake deep into "+ob->query_name()+"'s body.\n");
  return (20 + random(40));
}

