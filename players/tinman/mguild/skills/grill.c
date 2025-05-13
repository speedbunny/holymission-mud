

/* =============================================================== 
   Userdoc: Grill           /players/whisky/guild/skills/grill.c
   ---------------------------------------------------------------
   Art: Mac Donnals / snack producing
   Damage || Heal: foodheal depending on the playerslevel
   Cost: none
   Special: learnable by training or master / the player cuts out 
            a piece of meat from the dead victim and grills it /
            the amount of meat depends on the victims weight. 
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
        set_partner("/players/sauron/guild/room");
}


int grill(string arg)
{
  string name;
  int oweight, nweight;
  object what, slice, vic;
  mixed skill;

  if(!arg)
  {
      write("Grill what?\n");
      return 1;
  }
  else if((vic = apply(call,_tp,"query_attack")) && _e(vic) == _e(_tp))
  {
       write("No way you are fighting for your life!\n");
       return 1;
  }
  else if((what = present(arg,_e(_tp))) && living(what) &&
          !present("corpse of "+arg,_e(_tp)))
  {
     write("You try to grill "+arg+"!\n");
     tell_object(what,"Outch, "+_tpn+" tries to grill you!\n");
     say(_tpn+" tries to grill "+arg+" but fails!\n",what,_tp);
     return 1;
  }
  else if((!(what=present("corpse of "+arg,_e(_tp))) &&
           !(what=present(arg,_e(_tp)))) ||
          living(what) || explode(file_name(what),"#")[0]!="obj/corpse")
  {
      write("Grill what?\n");
      return 1;
  }
  if(apply(call,what,"query_decayed")!=4 ||
      apply(call,what,"query_race")=="undead" )
  {
      write("There is nothing, but bones.\n");
      return 1;
  }
  oweight = apply(call,what,"query_weight");
  if (oweight > 19)
      oweight = 19;
  nweight = oweight - 3;

  if (nweight <= 0)
  {
      write("There is not enough left for a barbeque.\n");
      return 1;
  }

  if (!chk_skill(_tp,"monk_grill",1))
  {
      write("Outch, you cut your fingers, blood all over!\n");
      return 1;
  }
  name=what->query_name();
  sscanf(name,"corpse of %s",name);
  write("You cut off a slice of "+name+" and grill the meat.\n");
  say(_tpn+" cuts a piece of meat from the "+name+
      " and makes a nice barbeque.\n",_tp);
  apply(call,what,"set_weight",nweight);
  
  slice = clone_object("/obj/food");
  apply(call,slice,"set_name","slice");
  apply(call,slice,"set_short","grilled slice of "+name);
  apply(call,slice,"set_alias",name);
  apply(call,slice,"set_long",
       "A tasteful looking slice of "+name+".\n");
  apply(call,slice,"set_eater_mess",
                   "You eat a grilled slice of "+name+".\n");
  apply(call,slice,"set_eating_mess",
                   " eats a grilled slice of "+name+".\n");
  apply(call,slice,"set_amount",1 + _tpl/5);
  apply(call,slice,"set_heal_amount", 5 + _tpl);
  apply(call,slice,"set_weight",1);

  if (transfer(slice,_tp))
  {
      write("You can't carry that much weight.\n");
      move_object(slice,_e(_tp));
  }
  return 1;
}
  
  


