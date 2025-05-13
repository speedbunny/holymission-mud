inherit "/obj/std_shadow";
#include "/spells/spell.h"

#define PO previous_object()
#define PON PO->query_name()
#define TS(x) tell_object(find_living("sourcer"),x)

object me;
object *allowed;

start_shadow( who, time)
{
	me = who;
	allowed = ({ });
	set_effect_msg("sanctuary");
	set_look_info("aura of power");
   return( ::start_shadow( who, time, "travel_shad", 1) );
}

end_shadow( o )
{
   tell_object( me, "You don't feel so powerful anymore!\n" );
   ::end_shadow( o );
}

allowed_attack(object ob)
{
int i;
	TS("ALLOED: "+ob->query_name()+" "+PON+"\n");
	if(member_array(ob,allowed) >= 0) return 1;
	
	i=ob->do_save(AGGRESSIVE,MINDEFFECTIVE);
	if(i=SAVE_FAILED)
	{
		tell_object(ob,"You don't dare to attack.\n ");
		tell_object(me,capitalize(ob)+" tried to attack you.\n");
		return 0;
	}
	else allowed += ({ob});
	return 1;
}
	
