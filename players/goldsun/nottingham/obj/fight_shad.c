       /*  fighting shadow    */

// nice code just debugged it a bit Whisky

inherit "/players/whisky/obj/std_shadow";
#define MASTER "/players/goldsun/nottingham/monster/master"
object att;


hit_player(dam,kind,elem)
{
  if (dam > me->query_hp())
  {  
      tell_room(environment(me),"Fighter says: I could kill you my friend."+
		"I win this match.\n");
      att=me->query_attack();
      if (att && environment(att) == environment(me))
      {
        me->stop_fight();
        me->stop_fight();
        me->stop_hunter(1);
        att->stop_fight();
        att->stop_fight();
        att->stop_hunter(1);
      }

      if ( present(att,environment(me)) )
              transfer(att,"/players/goldsun/nottingham/room/f_school"); 
      transfer(me,"/players/goldsun/nottingham/room/f_school");
      catch(call_other(MASTER,"defeat"));
      call_out(mend_shadow(),1,att);
      return 1;

  }
  return me->hit_player(dam,kind,elem);
}

   
void mend_shadow(object att)
{
   if (att && environment(att) == environment(me)) 
   {
      me->stop_fight();
      me->stop_fight();
      me->stop_hunter(1);
      att->stop_fight();
      att->stop_fight();
      att->stop_hunter(1);
   }
   ::end_shadow(this_object());
}

int fight_shad() 
{ 
    return 1; 
}

