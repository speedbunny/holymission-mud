object mon;

true_sight() { return 1; }
infravision() { return 5; }
detect_invis() { return 1; }

query_visor() { return 1; }

start_shadow(whom, how_long) {
    object shad;

    if(!whom) destruct(this_object());
    else {
        mon=whom;
        shad=mon;
	while(shad) {
	    shad=shadow(shad,0);
	    if(shad && shad->query_visor()) {
		destruct(this_object());
                return 1;
	    }
	}
        shadow(whom,1); 
    }
}

look_info(flag) {
    if(flag) return 0;
    return ("(humming powerfully)");
}

short(flag)
{
    string tmp;

    tmp = mon->short(flag);
    if (!tmp) return 0;
    if(flag) return tmp;
    return tmp+look_info();
}

hit_player(x,kind) { 
    if(kind==6) return 0;
    if(kind==7) return mon->hit_player(x,kind);
    return mon->hit_player(x*2/3,kind);
}

query_n_wc()
{
    if(environment(mon)->stat_room()) return mon->query_n_wc();
    return 10;
}

query_str()
{
   if(environment(mon)->stat_room()) return mon->query_str();
   return mon->query_str()+10;
}

query_dex()
{
   if(environment(mon)->stat_room()) return mon->query_dex();
   return mon->query_dex()+10;
}

query_con()
{
   if(environment(mon)->stat_room()) return mon->query_con();
   return mon->query_con()+10;
}

query_int()
{
   if(environment(mon)->stat_room()) return mon->query_int();
   return mon->query_int()-5;
}

query_wis()
{
   if(environment(mon)->stat_room()) return mon->query_wis();
   return mon->query_wis()-5;
}

query_chr()
{
   if(environment(mon)->stat_room()) return mon->query_chr();
   return mon->query_chr()+10;
}

query_stats(x)
{
   if(environment(mon)->stat_room()) return mon->query_stats(x);
   switch(x)
   {
      case 0:
      case 1:
      case 2:
      case 5:
         return mon->query_stats(x)+10;
      case 3:
      case 4:
         return mon->query_stats(x)-5;
   }
}
