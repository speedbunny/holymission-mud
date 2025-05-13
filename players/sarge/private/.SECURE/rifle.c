inherit "obj/treasure";
int t;
string victim;
string where;

reset(arg) {
if (arg) return;

  set_id("rifle");
  set_alias("rifle");
  set_weight(3);
  set_value(15000);
  set_short("A sharpshooter's rifle");
  set_long("A very useful tool for a sniper. Who knows what it "+
           "could do in the hands of an expert?\n"+
           "Aim <player> and fire <player>\n");
  }
init()  {
   ::init();
   add_action("aim","aim");
   add_action("fire","fire");
 }
aim(str){
  object target;
  object obj;
  if(this_player()->query_level() < 10)
   {
     write("Think a newbie like you can handle this weapon? GET REAL!!\n");
     return 1;
   }
   if (!str)
   {
     tell_object(this_player(), "Trying to blow your foot off?"+  
     "Try aiming at a player! (dummy)\n");
     return 1;
   }
   if(str == "me" || str == "self")
   {
     str = this_player()->query_real_name();
   }
   if(!find_living(str)){
   write("They're not in the game, you fool!\n");
   return 1;
   }
   else {  
   t=1;
   victim=str;
   target=find_living(str);
   obj=environment(target);
   write("You aim the rifle at "+str+"\n"+"You find your target at:\n");
   where=obj->long();                           
   tell_object(target,"You feel a sudden menacing feeling, better hide!\n");  
     return 1;
   }
}
fire(str){
        object deader;
        if(str==victim){
        if(t!=0){
        deader=find_living(str);
        write("CRACK! You shoot "+victim +" in the head!\n");
        tell_object(deader, "You were just shot in the head by "+
        capitalize(this_player()->query_name())+"!\n");
        t=0;
        return 1;
        }
        if(t==0){
        write("Duh!!!Who you gonna fire it at?\n");
        return 1;
        }
}
        if(str!=victim){
        write("Hmmmmm be kinda stupid to shoot someone you haven't aimed at.\n");
        return 1;
        }
}
