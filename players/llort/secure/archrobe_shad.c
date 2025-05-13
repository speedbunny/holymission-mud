object mon;

infravision() { return 5; }
detect_invis() { return 1; }

archrobe() { return 1; }

start(whom, how_long) {
    if(!whom) destruct(this_object());
    else {
        mon=whom;
        if(mon->archrobe())
        {
            destruct(this_object());
            return 1;
	}
        shadow(whom,1); 
    }
}

query_int()
{
   if(environment(mon)->stat_room()) return mon->query_int();
   return mon->query_int()+5;
}

query_stats(x)
{
   if(environment(mon)->stat_room()) return mon->query_stats(x);
   switch(x)
   {
      case 3:
         return mon->query_stats(x)+5;
         break;
      default:
         return mon->query_stats(x);
   }
}

restore_spell_points(sp)
{
    if(sp<0) sp=sp*3/4;
    if(sp==0) sp=-1;
    return mon->restore_spell_points(sp);
}

int hold(object o, int ti)
{
    if(random(20)) return mon->hold(o,ti);
    return 0;
}

int hit_player (int dam, int kind, mixed *elem)
{
    if(kind == 5 && !random(20))
    {
        return 0;
    }
    return mon->hit_player(dam,kind,elem);
}

int query_maxsp()
{
    return mon->query_max_sp()+30+5*mon->query_level();
}
