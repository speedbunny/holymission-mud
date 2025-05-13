inherit "/obj/treasure";
#define TO this_object()
#define TP this_player()

int is_worked_up, is_cut;

reset(arg){

 if (arg) return;
 set_id("ebony tree");
 is_worked_up=0;
 is_cut=0;
 set_alt_name("tree");
 set_alias("ebony goldsun tree");
 set_short("An ebony tree");
 set_long("An ebony tree. It looks heavy and very strong even to break\n"+
          "something.....\n");
 set_value(0);
 set_weight(15);
 }

init(){
  ::init();
 add_action("work","work");
 add_action("cut","cut");
 add_action("cut","chop");
 }

int cut(string str){
 notify_fail("Cut what ?\n");
 if (str=="tree" || str=="down tree" || str=="ebony tree" ||
       str=="down ebony tree"){
     if (present("axe",TP)){
       if (is_cut) {
             write("The tree is already cut down.\n");
             return 1;
       }
       if (present("goldsun_quest_axe",TP)){
           write("You chop down the tree.\n");    /* proper axe */ 
           say(TP->query_name()+" chops down a tree.\n");
           is_cut=1;
           return 1;
      }                                       /* bad axe*/
      write("You try to chop down the tree but your axe breaks.\n");
      say(TP->query_name()+" tries to chop down a tree.\n"); 
      destruct(present("axe",TP));

     } else write("But you have no axe.\n");

  return 1;
 }
}

int get(){
 if (!is_cut){
   write("You catch the tree with your hands and try to take it.\n");
   say(TP->query_name()+" catches the tree and tries to take it.\n");
   write("Ufffff.\n");
   write("Oh. The tree is planted very well.\n");
   return 0;
  }
 if (!is_worked_up){
   write("This tree isn't worked up. It has many branches.\n"); 
   say(TP->query_name()+" tries to take a tree.\n");
   return 0;
  }
 return 1;
}

int work(string str){
 notify_fail("Work up what ?\n");
 if (str=="up tree" || str=="up ebony tree" ){
    if (present("axe",TP)){
      if (is_worked_up){
          write("The tree is already worked up.\n");
          return 1;
       }
      if (present("goldsun_quest_axe",TP)){
          write("You work up the ebony tree.\n");    /* proper axe */ 
          say(TP->query_name()+" works up a tree.\n");
          is_worked_up=1;
          return 1;
      }                                       /* bad axe*/
      write("You try to work up the tree but your axe breaks.\n");
      say(TP->query_name()+" tries to work up a tree.\n"); 
      destruct(present("axe",TP));

     } else write("But you have no axe.\n");

  return 1;
 }
return 0;
}

