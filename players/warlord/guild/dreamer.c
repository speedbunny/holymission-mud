inherit "/obj/treasure";

reset(arg) {
  if (arg) return;
  set_id("dreamer");
}

init() {
/*   object *ob;
   int i; 
   ob=all_inventory(environment(environment()));
   for (i=0;i<sizeof(ob);i++)
   if (living(ob) && ob->query_attack()) {
      ob=this_player()->query_attack();
      ob->stop_fight(); 
      ob->stop_fight(); 
      ob->stop_hunter(1); 
      }   */
        input_to("hold");
}

hold(str) {
         string str1,str2;
         object exempt;
         exempt=call_other(this_player(),"query_real_name");
         call_out("dest",98);
	 if ((exempt=="whisky")) {
           command(str,this_player()); 
	   return 1;
         }

         sscanf(str,"%s %s",str1,str2);
	  input_to("hold");
	  if(str!=""){
	}
          write("> ");
	  input_to("hold");
}
dest() {
  destruct(this_object());
 return 1;
 }

