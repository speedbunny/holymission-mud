inherit "/obj/monster";
reset(arg)
 {
 ::reset(arg);
 load_chat(20,({"Hern says: Bring me the Silver arrow and\n"+
	        "           I'll give you mystery book.\n",
	        "Hern says: I need the Silver arrow. It is magic.\n"}));


 load_a_chat(40,({"Hern says: You poor mortal creature !\n",
	          "Hern grins at you.\n",
	 	  "Hern says: I'll send you in the dark city !\n"}));

 if (arg) return;
set_name("hern");
set_race("human");
set_short("Wizard Hern");
set_long("This is wizard Hern the master of time and destiny.\n"
          +"the patron of sherwood forest.\n"
         +"He looks very sadly. Maybe he needs something.\n");
set_wc(12);
set_ac(3);
set_gender(1);
set_aggressive(0);
set_level(30);
set_spell_mess1("");
set_spell_mess2("\nHern casts MAGIC STORM !\n");
set_spell_dam(70);
set_chance(30);
set_size(3);
}

enter_inventory(object ob){
 object att;

 if (!(ob->id_quest("help_hern"))){
   write("Hern grins evilly.\nHern says: I don't need it.\n");
   transfer(ob,this_player());
   return;
 }
 if (ob->id_quest("help_hern")){
  if (creator(ob) != "goldsun"){
   write("Wizard Hern looks angry.\n"+
	 "Hern growls: This is a fake !\n"+
 	 "Hern writes a note in the fog and blow it up.\n");
   log_file("QUESTS.CHET","arrow_for_hern "+this_player()->query_real_name()+
	    " object: "+file_name(ob)+" "+ctime(time())+"\n");
   destruct(ob);
   return;
  }
  if ((att=query_attack()) && (present(att))){  
   write("Hern says: I am busy at the moment.\n"+
	 "Wizard Hern doesn't accept the arrow.\n");
   transfer(ob,this_player());
   return 1;
  }

  write_file("log/help_hern",this_player()->query_real_name()+" "+ctime(time())+"\n");

  write("Hern says: You have bring me the arrow which I need !\n");
  shout("The evil will be defeated !\n");
  write("Hern says: Your quest has ended.\n");
  write("The wheel of the live goes on and on !!!\n");
  write("Hern gives a book to you.\n");  
  transfer(clone_object("/players/goldsun/sherwood/obj/book"),this_player());
  say("Hern gives a book to "+this_player()->query_name()+".\n");
  write("Hern disapears in the fog.\n");
  this_player()->set_quest("help_hern");
  transfer(this_object(),"/players/goldsun/castle");
  destruct(ob);
  if (find_player("goldsun"))
   tell_object(find_player("goldsun"),"Hern tells you friendly: "+
	     this_player()->query_name()+" solved your quest. Bye.\n");
  destruct(this_object());
  return 1;
  }
 }	
