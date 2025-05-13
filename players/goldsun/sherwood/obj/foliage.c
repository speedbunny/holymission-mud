inherit "/obj/treasure";
#define OPN capitalize(this_player()->query_name())

status i;
object scroll;
reset(arg){
 if (i==0) {
  i=1;
 }
 if (arg) return;
 i=1;
 set_id("foliage");
 set_alias("heap");
 set_short("A foliage");
 set_long("An old large heap of foliage.\n"
	  +"It could be hiding something from you.\n");
 }

init(){
 ::init();
 add_action("search","search");
 add_action("move","move");
 }

get(){
 return 0;
 }

move(str){
 if (str=="foliage" || str=="heap of foliage"){
  write("You start to move the foliage with your leg.\n");
  say(OPN+" starts to move the foliage.\n");
  write("You move the foliage about ten feet further.\n");
  say(OPN+" moves the foliage about ten feet further.\n");
return 1;
  }
}

search(str){
 if (str=="foliage" || str=="heap"){
  write("You search the foliage");
  if (i==0){
   write(".\n");
   say(this_player()->query_name()+" searches the foliage.\n");
   }
  else{
   write(" and find a scroll !\n");
   say(this_player()->query_name()+" searches the foliage and finds a scroll.\n");
   scroll=clone_object("/players/goldsun/sherwood/obj/scroll");
   if (transfer(scroll,this_player())) {
    write("You can't carry that much.\n");
    transfer(scroll,environment(this_player()));
    }
   i=0;
  }
 return 1;
}
notify_fail("Search what ?\n");
return 0;
} 
