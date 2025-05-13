inherit "/obj/treasure";
#define OPN capitalize(this_player()->query_name())
#define NUMBER 12 /* number of leaves from this bush */

int num;


int long(){
 if (num>0)  write("An old strange bush with blue leaves.\n"
	  +"The leaves on this bush looks fresh.\n");
  else write("An old strange bush. It looks very poor.\n"+
               "Someone tears many leaves from it.\n");
 return 1;
}

void reset(int arg){
 ::reset(arg);
   num=NUMBER;
 if (arg) return;
 set_name("blue bush");
 set_alias("bush");
 set_short("A blue bush");
 }

init(){
 ::init();
 add_action("tear","tear");
 }

get(){
 return 0;
 }

int tear(string str){
 object leaf;

 notify_fail("Tear what from where?\n");
 if (num<0) return 0;                /* call tear_action in room */
 if (str=="leaf from blue bush" || str=="leaf from bush" || str=="leaf"){
  num--;
  write("You tear a blue leaf.\n");
  say(OPN+" tears a blue leaf.\n");
  leaf=clone_object("/players/goldsun/sherwood/obj/b_leaf");
  if (transfer(leaf,this_player())){
    write("You can't carry that much.\n");
    transfer(leaf,environment(this_object()));
  }
  return 1;
 }
}
