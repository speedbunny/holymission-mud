inherit "obj/treasure";
int t;
string victim;
object target;

reset(arg) {
if (arg) return;
  t=6;
  set_id("grenade");
  set_alias("grenade");
  set_weight(1);
  set_value(10000);
  set_short("A hi-powered grenade");
  set_long("A very strong grenade, capable of blowing holes in muds.\n"+
  "Arm grenade and throw <player>.\n");
  }
init()  {

   ::init();
   add_action("arm","arm");
   add_action("throw","throw");
 }
arm(str){
  if(this_player()->query_level() < 10)
   {
     write("Think a newbie like you can handle this weapon? GET REAL!!\n");
     return 1;
   }
   else if (!str)
   {
     tell_object(this_player(), "arms Arms and more arms!!"+  
     "Maybe you should learn more about it 1st?(dummy)\n");
     return 1;
   }
     else {  
     tell_object(this_player(),"You arm the grenade!!\n");
    call_out("timer",1);
     return 1;
}
}
timer(){
   if(t!=0){
   t=t-1;
   tell_room(environment(this_object()),"You have "+t+" seconds left!!!!\n");
   call_out("timer",1);
   return 1;
   }
   if(t==0){
   if(!target){
   tell_room(environment(this_player()),"KABOOOOMMMMMMMMMM!!!!!!!!!!!!!!!!!\n\n\nYou have been blown into "+
   "bloody pieces by a grenade!\n");
   destruct(this_object());
   return 1;
   }
   if(target){
   tell_room(environment(this_object()),"KABOOOOMMMMMMMMMM!!!!!!!!!!!!!!!!!\n\n\nYou have been blown into "+
   "bloody pieces by a grenade!\n");
    destruct(this_object());
   return 1;
   }
}
}
throw(str){
if (!present(find_living(str), environment(this_object())))
    {
      move_object(this_object(), environment(find_living(str)));
      write("You throw the grenade!\n");
      target=find_living(str);
      return 1;
    }
}
