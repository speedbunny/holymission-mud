       /*   shadow for horse   */

inherit "/players/whisky/obj/std_shadow";

#define SA(x) say(x,me)
#define WR(x) tell_object(me,x)

hit_player(dam,kind,elem)
{
string mess;
  switch (random(3)){
     case 0: mess="makes step back";
	     break;
     case 1: mess="makes step to the left";
 	     break;
     case 2: mess="makes step to the right";
 	     break;
  }
 WR(me->query_attack()->query_name()+" tries to hit you but your horse "+mess+" and parries the main attack.\n");
  SA(me->query_attack->query_name()+" tries to hit "+
           capitalize(me->query_real_name())+" but "+me->query_possessive()+
           " horse "+mess+" and parries the main attack.\n");
  return me->hit_player(dam / 2,kind,elem);

}

   
move_player(mixed dir_dest, mixed optional_dest_ob, mixed raw, string income_msg)
{
 return me->move_player(dir_dest, optional_dest_ob, raw, "arrives on his horse.");
}


void end_shadow()
{
 destruct(this_object());
}

int horse_shad() 
{ 
    return 1; 
}

object query_horse_shad()
{
   return this_object(); 
}
