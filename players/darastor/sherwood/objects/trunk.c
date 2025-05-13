inherit "/obj/treasure";
object stick;
int i;
reset(arg){
 if (i<3) {i=10; }
 ::reset(arg);
if (arg) return;
 set_id("trunk");
 set_short("An old trunk");
 set_long("An old trunk with several dry branches.\n"
	  +"Maybe you could tear one of them.\n");
 i=10;
}
init(){
 ::init();
 add_action("get","get");
 add_action("tear","tear");
}
get(){
 return 0;
}
tear(str){
 if (i>0){
  if (str=="branch" || str=="branch from trunk"){
    write("CRACK. You tear a branch from the trunk.\n");
    say(this_player()->query_name()+" tears a branch.\n");
    stick=clone_object("/players/goldsun/sherwood/obj/stick");
    transfer(stick,this_player());
    --i;
    return 1;
   }
  else { notify_fail("Tear what ?\n"); return 0; }
  }
  else {
   write("The branches are too high for you.\n");
   say(this_player()->query_name()+" tries to tear a branch.\n");
   return 1;
 }
}
