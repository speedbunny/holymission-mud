my_say(a,ex,who,ai)
{
   int i,j,k;
   object where;
   object *inv; 
   closure call,tell,txt;

   if(!who)
   { 
       who=previous_object();
       if(!living(who)) who=this_player();
       if(!who) who=previous_object();
   }
   where=environment(who);
   inv=all_inventory(where);
   inv-=({ who });
   if(ex) inv-=ex;
   j=sizeof(inv);
   tell=#'tell_object;
   call=#'call_other;
   i=0;
   txt = lambda( ({ 'a, 'ai, 'o }),
               ({ #'? , ({ call,who,"is_invis_for",'o}), 'ai, 'a }) );
   while(i<j) {
       funcall(tell,inv[i],funcall(txt,a,ai,inv[i++]));
   }
}
