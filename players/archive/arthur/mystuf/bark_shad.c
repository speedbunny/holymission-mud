
/* barkskin */

inherit "/players/whisky/obj/std_shadow";

hit_player(dam,kind)
{
  if (kind == 0 || kind == 7)
     return me->hit_player( (dam/2), kind);
   return me->hit_player( dam, kind);
}

   
void end_shadow(object ob)
{
   tell_object(me,"Your barkskin wears off.\n");
   ::end_shadow(ob);
}

#define _spell "barkskin"

string *effects()
{
   string *eff;
   return ((eff = me->effects()) ? eff+=({_spell}) : ({_spell}));
}

int bark_shad() { return 1; }

