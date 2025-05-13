       /*  defence shadow    */

inherit "/players/whisky/obj/std_shadow";

#define SA(x) say(x,me)
#define WR(x) tell_object(me,x)

hit_player(dam,kind)
{
  if (random(33)<9){
    switch(random(3)){
    case 0 : WR("You make Sa-the-mio tsuka hit.\n");
             SA(me->query_name()+" makes Sa-the-mio tsuka hit.\n");	
	     break;
    case 1 : WR("You make Snakes attack.\n");
	     SA(me->query_name()+" makes Snakes attack.\n");
	     break;
    case 2 : WR("You make Dragon defence.\n");
	     SA(me->query_name()+" makes Dragon defence.\n");
	     break;
 
    }
    return me->hit_player(dam / 2,kind);
  }
 return me->hit_player(dam,kind);
}

   
void end_shadow(object ob)
{
   ::end_shadow(ob);
}

int defen_shad() 
{ 
    return 1; 
}

