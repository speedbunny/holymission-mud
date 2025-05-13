
/* dragontail */

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
     set_alias("dragontail");
     set_short("dragontail");
     set_long(
     "You see the wonderful scalecovered tail of a big dragon.\n"+
     "It's hard, sharp and stiff and is made of strong scales.\n"+
     "It looks like the proper weapon to fight a dragon.\n");
      set_hit_func(this_object());
    }
}

int weapon_hit(object ob) 
{
  if (ob->query_race() != "dragon") 
     return 0;

     write("Your tail cuts big wounds into the body of the dragon.\n");
     say(this_player()->query_name()+" thrusts "+
     this_player()->query_possessive()+
    " dragontail deep into "+ob->query_name()+"'s body.\n");
  return (20 + random(40));
}

