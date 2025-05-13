inherit "/obj/treasure";
object who;
status old;

reset(arg){
 if (arg) return;
 set_id("paste");
 set_alias("glue");
 set_short("A flask of paste");
 set_long("A flask of paste.\n"
	  +"You can use it agains monsters.\n"
	  +"But you must know 'how' at first.\n");
 set_value(0);
 set_weight(1);
 }
init(){
  ::init();
 add_action("use","use");
 add_action("how","how");
 }

how(str){
 write("Ask Hern.\n");
 return 1;
}


use(str){
object shd;

 if (str)  who=present(str,environment(this_player()));
 else      who=this_player()->query_attack();
 if (who)
  {

         /*    if (who->query_str()< 4 +random(30)) */
  
      shd=clone_object("/players/goldsun/sherwood/obj/trap_shad");
      transfer(shd,who);
      shd->start_shadow(who,0,"trap_shad");
      write("ok\n");
      write("You use your paste at "+str+"\n");
     return 1;
  }

}

