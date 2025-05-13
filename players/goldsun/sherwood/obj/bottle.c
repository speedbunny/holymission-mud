inherit "/obj/treasure";
#define TP this_player()
#define TO this_object()

int is_w, is_l, is_p;

void add_water(){
 if (!is_w){
  is_w=1;
  write("The water bulps in.\n");
 }  
}

void add_leaf(object ob){
 if (!is_l){
  is_l=1;
  destruct(ob);
  write("You put leaf in the bottle.\n");
 } else write("There is already one.\n");
}

void add_pitch(){
 if (!is_p){
  is_p=1;
  write("The pitch bulps in.\n");
 }
}

void long(){
string str;
 str="A glass bottle for mixing. You can put something in it.\n";
 if (is_p || is_l || is_w) str+="   Bottle contains:\n";
 if (is_p) str+="Some pitch\n";
 if (is_w) str+="Some water\n";
 if (is_l) str+="A blue leaf\n";
 write(str);
}

reset(arg){
  ::reset(arg);
 if (arg) return;
 set_name("special bottle");
 set_alias("bottle");
 set_short("A bottle");
/* set_long("@@query_long@@"); */
 set_value(10);
 is_l=0;
 is_p=0;
 is_w=0;
 set_weight(1);
 }

init(){
  ::init();
 add_action("do_shake","mix");
 add_action("do_put","put");
 }

int do_put(string str){

 if (str=="leaf in bottle" || str=="blue leaf in bottle"){
   if (present("blue leaf",TP)) { add_leaf(present("blue leaf",TP));}
   else write("You haven't the right leaf.\n");
  return 1;
 }
return 0;
}

int do_shake(string str){
  if (str=="bottle"){
      if ( is_l && is_p && is_w){
         write("You shake with bottle and make a paste.\n");
         say(TP->query_name()+" makes a paste.\n");
         move_object(clone_object("/players/goldsun/sherwood/obj/paste"),TP);
         destruct(TO);
     } else{
        write("You shake with bottle.\n");
        say(TP->query_name()+" shakes with bottle.\n");
    }
  return 1;
 }
}

int is_my_bottle(){ return 1; }

