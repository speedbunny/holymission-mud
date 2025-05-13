/*
  A beautiful rose just for some friends of mine no damage can be done with
  it to anyone.
*/
inherit "/obj/treasure";

object remembered ;

reset(arg){
   set_id("lovers rose");
   set_alias("rose");
   set_short("A red rose");
   set_long("A beautiful red rose. You must mean a lot to the person you\n"+
            "got this from. Type <rosehelp> to get more info.\n");
   set_value(1000);
   set_weight(1);
   set_read("With love, from Gladdy.\n");
}

init()
{  ::init() ;
   add_action("rose_help","rosehelp");
   add_action("send_rose","sendrose");
   add_action("show_odour","odour");
   add_action("tell_me","romeo");
   add_action("show_rose","rshow");
   add_action("danny_glad","gladdy");
   add_action("danny_back","back");
   add_action("eat_rose","eat");
}

eat_rose(str){
object me ;
  if(str!="rose" && str!="Rose") return 0 ;
  write("You eat the rose, it taste delicious.\n");
  say(this_player()->query_name()+" eats a rose, you gasp in astonishment.\n",
      this_player());
  me = find_player("gladiator");
  if (me) tell_object(me,this_player()->query_name()+" ate the rose.\n");
  destruct(this_object());
  return 1 ;
}

danny_glad(){
 if(this_player()->query_real_name() != "Daniella") { return 1 ; }
 remembered = environment(this_player());
 move_object(this_player(),"/players/gladiator/workroom");
 write("You drift throught space and time to the workroom of Gladdy.\n");
 write("The rose whispers : This one is only available to you.\n");
 return 1 ;
}

danny_back(){
 if(this_player()->query_real_name() != "Daniella") { return 1 ; }
 move_object(this_player(),remembered);
 write("You drift throught space and time back.\n");
 return 1 ;
}

show_odour(){
  write("You wave the rose around and a wonderful odour spreads through the room.\n");
  say(this_player()->query_name()+
      " waves with a rose and a wonderful odour spreads through the room.\n",
      this_player());
  return 1 ;
}

tell_me(arg){
object me ;
   me = find_player("gladiator");
   if (!me) { write("Gladiator is not around now, try later.\n"); return 1 ; }
   tell_object(me,"<< "+this_player()->query_name()+" >> : "+arg+"\n");
   write("You tell Gladdy : "+arg+"\n");
   return 1 ;
}

show_rose(){
  write("You show the rose to all the people in the room.\n");
  say(this_player()->query_name()+
      " shows you the most beautiful rose you have ever seen.\n",
      this_player());
  return 1 ;
}

rose_help(){
  write("The features of this special rose:\n");
  write(" odour    - Let everyone in the room enjoy the smell of the rose.\n");
  write(" romeo    - Tell something to gladiator without losing sp.\n");
  write(" rshow    - Show the rose to everyone.\n");
  write(" eat rose - To destroy the rose.\n");
  if (this_player()->query_real_name() == "Daniella")
   {  write(" gladdy   - To go to Gladiators home.\n");
      write(" back     - To go back to church.\n");
   }
  write("These are the only features for now,\n");
  write("              Your lovable, Gladdy\n");
  return 1 ;
}

send_rose(arg){
object destination ;
    if(this_player()->query_real_name() != "gladiator") { return 1 ; }
    destination = find_living(arg);
    if (!destination) { write("Not Present.\n"); return 1 ; }
    write("Sending rose to "+arg+".\n");
    move_object(this_object(),destination);
    tell_object(destination,"Gladiator sends you a beatiful red rose.\n");
    return 1 ;
}

query_auto_load()
{
	return "/players/gladiator/rose:";
}

drop() { return 1 ; }
prevent_insert() { return 1 ; }
