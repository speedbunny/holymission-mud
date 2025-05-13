inherit "obj/weapon";

#include "lw.h"
#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;
 
  set_name("sacrificial knife");
  set_alias("knife");
  set_short("Sacrificial Knife");
  set_long(
"A wickedly curving blade with a blood-red stained, ivory hilt.  The light\n"+
"reflecting from the blade seems to be tainted red.  You definitely feel a\n"+
"powerful surge of magic course through the enchanted blade.  When you hold\n"+
"it in your hand, you suddenly feel an unnatural urge you spill oodles of \n"+ 
"blood... There must be some sort of magical power involed with this weapon.\n");
  set_class(17);
  set_type(3);
  set_value(2500);
  set_weight(3);

}

string* query_hit_msg(int dam, string name, string att, string def) 
{
   if (dam < 1) return ({
 lw("swipe grandly at nothing."),
 lw("swipes at you with all the skill of a novice."),
 lw("shows just how inexperienced "+previous_object()->QPRO+" really is."),
    });

   else if (dam < 2) return ({
 lw("scratch "+name+"'s arm, drawing a trail of blood."),
 lw("scratches your arm with the Sacrificial Knife, drawing a trail of blood."),
 lw("scratches the Sacrificial Knife along "+name+"'s arm, drawing blood."),
    });

   else if(dam < 4) return ({
 lw("plunge the Sacrificial Knife deep into the exposed flesh of "+name+"."),
 lw("plunges the Sacrificial Knife into your exposed flesh."),
 lw("plunges the Sacrificial knife deep into "+name+"'s juicy, exposed flesh."),
    });

   else if(dam < 9) return ({
 lw("swipe viciously at "+name+", spraying blood over the room !!"),
 lw("sends your blood spraying across the room, with the Sacrificial Knife!!"),
 lw("sprays the whole room with "+name+"'s blood !!"),
    });

   else if(dam < 14) return ({
 lw("hear a slurping as the Sacrificial Knife sucks blood greedily from "+name+"."),
 lw("hear disgusting slurping noises as the Sacrificial Knife drinks your blood."),
 lw("has excess blood oozing from "+name+"'s body, running down "+previous_object()->QPRO+" arm."),
     });

   else if(dam < 19) return ({
 lw("gouge out a pound of flesh from "+name+", with the Sacrificial Knife!!"),
 lw("gouges out a pound of flesh from your body, with the Sacrificial Knife!!"),
 lw("gouges out a pound of flesh from "+name+" with the Sacrificial Knife!!"),
     });
  
   else if(dam < 27) return ({
  lw("perform a neat labotomy on "+name+"."),
  lw("performs a precise labotomy on you."),
  lw("performs a delicate labotomy on "+name+"."),
     });

   else if(dam < 36) return ({
  lw("make "+name+" into a pile of shredded mince-meat."),
  lw("makes mince-meat of you, with the Sacrificial Knife."),
  lw("makes mince-meat of "+name+", with the Sacrificial Knife."),
     });

   else return ({
  lw("completely drain "+name+"'s body of vital blood, leaving a dried-out husk."),
  lw("drains you completely of blood, leaving you feeling totally weak."),
  lw("drains "+name+"'s body of vital blood, till "+previous_object()->QPRO+" looks like a dried-out husk!!"),
    });

}
