inherit "/obj/std_shadow";

int query_ac()
{ 
  return me->query_ac()+20;
}


void end_shadow(object ob)
{ tell_object(me,"You feel like a normal person again.\n" +
                 "What an ugly feeling.\n");
  ::end_shadow(ob);
}

