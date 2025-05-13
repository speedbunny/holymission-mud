#define	TP	this_player()
#define TO	this_object()
#define env	environment

inherit "obj/monster";

enter_inventory(ob) {

  if (ob->id("king ralph's head")) {
	if(creator(ob)!="animal") {
            log_file("QUESTS.CHEAT",this_player()->query_real_name()+": by "+
            file_name(ob)+": lion: "+ctime(time())+"\n");
            destruct(ob);
            return 1;
        }
     env(TO)->gve(ob);
  }
  else {
    tell_room(env(TO),"\nThe Prince growls: DO NOT WASTE MY TIME "+
          "MORTAL!\n");
    tell_object(TP, "\nYou will pay for this!\n\n");
    call_out("attack_object",2,TP);
  }
}
 
query_no_steal() { return 1; }
