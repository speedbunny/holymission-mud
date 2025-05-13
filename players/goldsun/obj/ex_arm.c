inherit "obj/armour";
#define TP this_player()

reset(arg){
 ::reset(arg);

if (!arg){
 set_name("overall");
 set_short("Special overall");
 set_long("This is overall which you need for special actions.\n"
          +"It is gree-brown-yellow. There are many pockets.\n"
          +"Maybe you should examine it.\n");
 set_type("armour");
 set_size(0);/* I wanna it for every size */
 set_ac(2);
 set_value(7000);
 set_weight(7);
 }
} 

init(){
 ::init();
 add_action("exa","examine");
 add_action("exa","exa");
 add_action("do_get","get");
 add_action("do_get","take");
 add_action("do_cam","camouflage");
 }


int exa(string str){
 if (str="overall" || (!str) ){
   write("You find a small scroll :\n"
         +"()-----------------------------------------)\n"
         +" ! Contains: rope, knife, matchbox, dart. !\n"
         +" ! Actions: get those things from pocket  !\n"
	 +" !          camouflage                    !\n"
	 +"()----------------------------------------)\n");
   say(capitalize(this_player()->query_name())+" examines his overhall.");
   return 1;
  }
 }

int do_get(string str){
 if (str=="rope from pocket"){
  move_object(clone_object("/obj/rope"),TP);
  return 1;
 }
 if (str=="knife from pocket"){
  move_object(clone_object("/players/goldsun/obj/sknife"),TP);
  return 1;
 }
 if (str=="matchbox from pocket"){
  move_object(clone_object("/players/galadriel/fire/matchbox"),TP);
  return 1;
 }
 if (str=="dart from pocket"){
  move_object(clone_object("/players/patience/guild/nweap/dart"),TP);
  return 1;
 }
}

int do_cam(){
 write("Action not added yet.\n");
 return 1;
}
