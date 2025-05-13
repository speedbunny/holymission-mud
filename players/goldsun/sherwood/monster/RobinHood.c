inherit "/obj/monster";
#define env(x) environment(x)
#define TO this_object()

void go_to_win_it(){
 tell_room(env(TO),"Robin leaves suddenly.\n");
 transfer(this_object(),"/players/goldsun/castle");
 tell_room(env(TO),"Hello.\n");
 call_out("give_it",10);
}

void give_it(){
object ob;

 write("Robin arrives.\nRobin leaves into the cave.\nRobin tells you: Arrow is in the cave.\n");
 ob=clone_object("/players/goldsun/sherwood/quest/m_arrow");
 transfer(ob,"/players/goldsun/sherwood/room/cave");
 say("Robin arrives.\nRobin leaves into the cave.\n"); 
 destruct(TO);
}

 reset(arg){
 ::reset(arg);

if (arg) return;
set_name("robin Hood");
set_alt_name("robin hood");
set_race("outcasthood");
set_alias("robin");
set_gender(1);
set_short("Robin from Locksley");
set_long("This is Robin Hood. He is tall and strong. He is known\n"
        +"as the best archer. Maybe he could win something for you.\n");
set_wc(50);
set_ac(4);
set_aggressive(0);
set_level(80);
set_size(3);
move_object(clone_object("/players/goldsun/sherwood/obj/Long_bow"),
             this_object());
command("wield bow");
}
init(){
 ::init();
 tell_object(this_player(),"Robin tells you: Hi. I am very good archer.\n"+
          "I can win an arrow for you, but I need magic feathers and\n"+
          "a small tooth from a small animal to make a special arrow.\n");
}



enter_inventory(ob) {
  string str;
  if (!(ob->id_quest("help_hern"))) { 
    write("Robin tells you: Ugh, thanks. But I don't need it.\n"); 
    transfer(ob,this_player());
    return;
  } 
  if (creator(ob)!="goldsun") {
    log_file("QUESTS.CHEAT",this_player()->query_real_name()+" "+
            file_name(ob)+" "+ctime(time())+"\n"); 
    destruct(ob); 
    return; 
  }
  str = "Robin tells you: Thank you for bringing this ";
  if (ob->id("tooth")) {
    str += "tooth.\n";
  } else if (ob->id("feathers")) {
    str += "feathers.\n";
  }
  
  if ( present("feathers") && present("tooth")
    && !this_player()->query_quests("help_hern")) {
    str += " I have all equipment which I need. I go to win the silver\n"+
    "arrow. Wait for me here !\n";
   go_to_win_it();
   clear_inventory();
  }
  write(str);
}

clear_inventory() {
  object ob,next;
  command ("remove all");
  for (ob = first_inventory(this_object());ob;ob=next) {
    next = next_inventory(ob);
    destruct(ob);
  }
  local_weight = 0;
}

