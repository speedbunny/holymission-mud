
/* armour */

inherit "/players/whisky/obj/std_shadow";

hit_player(dam,kind)
{
  if (kind == 0 || kind == 7)
     return me->hit_player( (dam/2), kind);
   return me->hit_player( dam, kind);
}

   
void end_shadow()
{
   tell_object(me,"Your protection wears off.\n");
   ::end_shadow();
}

int armour()
{
    return 1;
}

