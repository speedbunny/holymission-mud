inherit "/obj/treasure";

int counter;

reset(arg){
 if (arg) return;
 set_id("paste");
 set_alias("glue");
 set_short("A flask of paste");
 set_long("A flask of paste.\n"
	  +"You can use it agains monsters.\n"
	  +"But you must know 'how' at first.\n");
 counter=3;  /*  use it 3 times */
 set_value(0);
 set_weight(1);
 }
init(){
  ::init();
 add_action("use","use");
 add_action("how","how");
 }

how(str){
 write("It is written in the Hern's magic book.\n");
 return 1;
}


use(str){
object shd,who;

 if (str)  who=present(str,environment(this_player()));
 else      who=this_player()->query_attack();
 if (who && living(who))
  {

      shd=clone_object("/players/goldsun/sherwood/obj/trap_shad");
      transfer(shd,who);
      if (!who->query_npc()) shd->start_shadow(who,(60-who->query_dex())/10,
    		"trap_shad");
        else  shd->start_shadow(who,0,"trap_shad");
      write("ok\n");
      write("You use your paste at "+str+"\n");
      say(this_player()->query_name()+" uses a paste.\n",who);
      tell_object(who,"You are pasted !!!\n");
      counter--;
      if (counter==0) destruct(this_object());
     return 1;
  }

}

