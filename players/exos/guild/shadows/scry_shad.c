// Scry
// give 'who' the possibility to look into the next room for 'time' secs
// id: scry
// attr-msg: scry
// no look-info
// non multiple

inherit "/obj/std_shadow";
start_shadow(who, time)
{
    set_effect_msg("scry");
    return ::start_shadow(who, time, "scry",0);
}

end_shadow(o)
{
    tell_object(me, "Your vision changes!\n");
    ::end_shadow(o);
}

look(arg)
{
  int idx;
  object o;
  string *dd;

  if(arg &&
     (dd=apply(call,environment(this_player()),"query_dest_dir")) &&
     (idx=member_array(arg,dd))!=-1 &&
     dd[idx][0]!='/')
  {
     catch(call_other(dd[idx-1],"???"));
     if(o=find_object(dd[idx-1]))
     {
         if(o->test_darkness())
         {
             tell_object(this_player(),"scrying "+arg+" your see ...\n\n");
             this_player()->mylook(0,o);
         }
         else write("It's pitch black!\n");
         return 1;
     }
  } 
  return apply(call,me,"look",arg);
}
