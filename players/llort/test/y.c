/*
void _say(string txt, object ob, object ob2) {
      if(ob)
	 return efun::say(txt, ob);
      else
	 return efun::say(txt);
}
*/

void say(string txt, object ex, object who, string inv_txt)
{
   int i,j,k;
   object where;
   object *inv; 
   closure call,tell,text;

   if(!who || !inv_txt)
   {
       if(ex) return efun::say(txt,ex);
       else   return efun::say(txt); 
   }

   if(!environment(who)) return;
   where=environment(who);
   inv=all_inventory(where);
   inv-=({ who });
   if(ex) inv-= ({ ex }); 
   j=sizeof(inv);
   tell=#'tell_object;
   call=#'call_other;
   i=0;
   text = lambda( ({ 't, 'ti, 'o }),
               ({ #'? , ({ call,who,"is_invis_for",'o}), 'ti, 't }) );
   while(i<j) {
       funcall(tell,inv[i],funcall(text,txt,inv_txt,inv[i++]));
   }
}
