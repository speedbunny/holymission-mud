inherit "/obj/treasure";
object p;
reset(arg){

if (arg) return;
 set_id("pp");
set_weight(5);
set_value(0);
set_short("A pp");
set_long("A pp\n");
}

init(){
 ::init();
add_action("set","set");
add_action("tr","tr");
add_action("test","test");
add_action("do_file","file");
add_action("enter_it","into");
add_action("dest","dest");
}

int dest(object ob){
 if (present(ob,environment(this_object()) )){ destruct(ob);
  return 1;
 }
}

int enter_it(){
   transfer(this_player(),p);
   return 1;
}

int do_file(string str){
 if (present(str,environment(this_player()))){
  write(file_name(present(str,environment(this_player())))+" is file of "+
	   str+".\n");
  return 1;
 }
 return 0;
}

int test(string str){
 object ob;
 if (present(str,environment(this_player()))){
   ob=present(str,environment(this_player()));
   write(ob->query_name()+".\n");
   write(ob->query_hp());
   write(" hit points.\n");
   write(ob->query_ac());
   write(" armour class.\n");
   write(ob->query_wc());
   write(" weapon class.\n");
   return 1;
  }
  write("It is not here.\n");
  return 1;
 }


int set(string str){
 p=present(str,environment(this_player()));
 write(p->query_name());
 write(" OK.\n");
 return 1;
 }

tr(){
 object ow;
 ow=environment(this_player());
 transfer(p,ow);
 return 1;
 }
