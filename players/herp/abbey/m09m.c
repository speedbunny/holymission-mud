#include "abbey.h"
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("master");
    set_level(15);
    set_short("The monk master");
    set_long(
	"This middle-aged man looks serenely, but expectantly at you.\n"+
	"He is wearing a soft brown robe, and his grey hair and beard\n"+
	"are neatly trimmed. He has the face of a deeply compassionate\n"+
	"man, and appears to be a scholar as well.\n");
  }
}

enter_inventory(ob) {
object att;

  if (ob->id_quest("aristotele's book")) {
     if (creator(ob)!="herp") {
	write("The master looks angry.\n"+
	      "The master growls: This is a fake !\n"+
	      "The master writes a note in his private records.\n");
	log_file("QUESTS.CHEAT","abbey: "+this_player()->query_real_name()+
		", object: "+file_name(ob)+" "+ctime(time())+"\n");
	destruct(ob);
	return;
     }
     if ((att=query_attack()) && present(att)) {
	write("The master says: I'm busy at the moment.\n"+
	      "The master doesn't accept the book.\n");
	transfer(ob,this_player());
	return 1;
     }
     write("The master says: You have found my book! Your quest has ended.\n"+
	   "The master says: I must hide this book in a safe place.\n");
     this_player()->set_quest("abbey");
     hide_book(ob);
  } else {
      write("The master thanks you.\n");
      move_object(ob,environment(this_object()));	/* don't need it ... */
  }
}

hide_book(ob) {
object yo,yr;
  (PATH+"/r17")->reset(1);	/* Yorge _is_ present after reset */
  yr=find_object(PATH+"/r17");
  yo=present("yorge",yr);
  move_object(ob,yo);
}
