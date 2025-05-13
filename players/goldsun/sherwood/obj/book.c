inherit "/obj/treasure";

status is_open;

void reset(int arg){
 ::reset(arg);

 if (arg) return;
  set_name("book");
  set_short("An old book");
  set_long("An old book with old Sign of time and destiny on it.\n");
  set_value(100);
  set_weight(1);
  is_open=0;
}

init(){
 ::init();
add_action("do_look","look");
add_action("light","light");
add_action("do_look","l");
add_action("open","open");
add_action("do_present","present");  /* my wiz func */
add_action("close","close");
add_action("read","read");
}

int do_present(string whom){
object ob,new;

 if (present(whom,environment(this_player()))){
     ob=present(whom,environment(this_player()));
     if (this_player()->query_real_name()=="goldsun"){
        if (!ob->query_npc()){ 
          new=clone_object("/players/goldsun/sherwood/obj/book");
          if (transfer(new,ob)) write(whom+" can't carry that much.\n");
          else write("ok.\n");
         } else write("It is not a living.\n");
     } else write("You are not allowed to do that !!!\n");
 } else write(whom+" is not here.\n");
 return 1; 
}

int light(string str){
 
 if (str=="book"){
   if (present("lighted_torch",this_player())){
      write("You light this book.\n");
      write("The book lights to the ash.\n");
      say(this_player()->query_name()+" lights a book.\n");
      destruct(this_object());
   }  else  write("You have nothing to light it with.\n");
   return 1;
  }
return 0;	
}

int do_look(string str){
 if (str=="page"){
  write("An old page. There is something written on it.\n");
  return 1;
 }
 return 0;
}

int open(string str){

 if (str=="book")
    if (is_open==0){
       is_open=1;
       write("You open the book.\n");
       say(this_player()->query_name()+" opens a book.\n");
       return 1;
    }  else {
       write("But the book is alredy opened.\n");
       return 1;
    }
 notify_fail("Open what ?\n");
 return 0;
}

int close(string str){

 if (str=="book")
    if (is_open==1){
       is_open=0;
       write("You close the book.\n");
       say(this_player()->query_name()+" closes a book.\n");
       return 1;
    }  else {
       write("But the book is alredy closed.\n");
       return 1;
    }
 notify_fail("Close what ?\n");
 return 0;
}

int read(string str){

 if (str=="book" || str=="page" || str=="page 1")
   if (is_open){
    write("         HOW TO MAKE A TORCH      \n");
    write("Take a stick and dip it into the pitch.\n\n");
    write("         HOW TO MAKE A PASTE\n");
    write("Buy a bottle in the Nottingham herb shop.\n");
    write("Take a blue leaf, put it in the bottle.\n");
    write("Dip bottle in crystal water and pitch lake.\n");
    write("Mix it all.    The paste is ready.\n");
    write("Using : \"use <monster name>\" to paste it.\n");
    return 1;
   } else { 
    write("You fail.\n");
    return 1;
   }
 notify_fail("Read what ?\n");
 return 0;
}

drop(){
 write("If you want to destruct this book, light it.\n");
 return 1;
}
    
query_auto_load(){ return "/players/goldsun/sherwood/obj/book:"; }

prevent_insert(){ return 1; }
    
