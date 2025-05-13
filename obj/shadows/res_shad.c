
/* resistance */

inherit "/obj/std_shadow";

int element;

varargs int hit_player(int dam,int kind,mixed elem)
{
   if (pointerp(elem) && sizeof(elem) && elem[0]==element)   
        return me->hit_player((dam/2),kind,elem);
   return me->hit_player(dam,kind,elem);
}

void end_shadow(object ob)
{
   if (stringp(effect))
       tell_object(me,"Your "+effect+" wears off.\n");
   ::end_shadow(ob);
}

