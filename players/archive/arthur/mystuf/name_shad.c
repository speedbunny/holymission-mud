
/* barkskin */

inherit "/players/whisky/obj/std_shadow";

query_name() { return "Clinton"; }

   
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

int name_shad() { return 1; }

