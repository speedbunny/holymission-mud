
/* barkskin */

inherit "/players/whisky/obj/std_shadow";

catch_tell(str) {
     write(str+"");
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

int beep_shad() { return 1;}

init() {
      add_action("end_shadow","nobeep");
}
