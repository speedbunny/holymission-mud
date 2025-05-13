inherit "/obj/monster";
#define env(x) environment(x)
#define TP this_player()

void reset(int arg)
 {
 ::reset(arg);

 if (arg) return;

set_name("rutenos");
set_race("human");
set_short("Smith Rutenos");
set_gender(1);
set_long("Smith Rutenos.\n"+
	 "He is well build. He has masive muscless.\n");
set_wc(22);
set_ac(3);
set_al(700);
set_aggressive(0);
set_level(33);
set_size(3);
move_object(clone_object("/players/goldsun/nottingham/obj/hammer"),this_object());
command("wield hammer");
}

init(){
 ::init();
add_action("ask","ask");
}

int ask(string str){
 string what;
 int amount,class;
 object thing;

 if (str)
 if (sscanf(str,"rutenos to forge %s for %damount",what,amount)==2){

  switch(what) {

   case "sword" :
      thing=clone_object("/obj/weapon");
      thing->set_name("sword");
      thing->set_short("Steel sword");
      thing->set_long("Steel sword with Rutenos sign on it. It looks very powerfull.\n"+
            "This sword was made to order for "+TP->query_name()+".\n");
      class= (amount / 1250);

       /* He can forge only WC 1 to WC 18 (I don't want many weapons */
       /* with WC 19 and WC 20 					     */

      if (class > 18) class= 18;

      thing->set_class(class);
      thing->set_weight( (class / 3)+1 );
      thing->set_value(amount / 2);
      break;
	
   case "helmet" :
      thing=clone_object("/obj/armour");
      if (amount > 5000)  class=2;
	else class=1; 
      thing->set_class(class);
      thing->set_weight(class+1);
      thing->set_value(amount / 2);
      thing->set_short("Steel helmet");
      thing->set_long("Steel helmet with Rutenos sign on it. It looks sturdy.\n"+
         "This helmet was made to order for "+TP->query_name()+
	 ".\n");
      thing->set_type("helmet");
      break;
   case "boots" :
      thing=clone_object("/obj/armour");
      if (amount > 5000)  class=2;
	else class=1; 
      thing->set_class(class);
      thing->set_weight(class+1);
      thing->set_value(amount / 2);
      thing->set_short("Steel boots");
      thing->set_long("Steel boots with Rutenos sign on them. It looks sturdy.\n"+
         "Those boots were made to order for "+TP->query_name()+
	 ".\n");
      thing->set_type("boot");
      break;

   case "shield" :
      thing=clone_object("/obj/armour");
      if (amount > 5000)  class=2;
	else class=1; 
      thing->set_class(class);
      thing->set_weight(class*2);
      thing->set_value(amount / 2);	
      thing->set_short("Steel shield");
      thing->set_long("Steel shield with Rutenos sign on it. It looks sturdy.\n"+
         "This shield was made to order for "+TP->query_name()+
	 ".\n");
      thing->set_type("shield");
      break;
   
   case "platemail" :
      thing=clone_object("/obj/armour");
      switch( amount ){
        case 0..100 : 
	      class=0;
	      break;
        case 101..500 :
    	      class=1;
	      break;
        case 501..1400 :
      	      class=2;
	      break;
        case 1401..2000 :
	      class=3;
	      break;
        default: class=4;
		 break;
      }
      thing->set_name("platemail");
      thing->set_class(class);
      thing->set_weight(class*2+2);
      thing->set_value(amount / 2);	
      thing->set_short("Steel platemail");
      thing->set_long("Steel platemail with Rutenos sign on it. It looks sturdy.\n"+
         "This platemail was made to order for "+TP->query_name()+
	 ".\n");
      thing->set_type("armour");
      break;
   
   default : 
      write("Rutenos tells you: Well. I have never made "+what+", but\n"+
	    "I try to do it now.\n");
      thing=clone_object("/obj/treasure"); 
      thing->set_value(amount / 2);
       if (amount > 2000)  thing->set_weight(3);
        else if (amount > 1000) thing->set_weight(2);
	 else thing->set_weight(1);
      thing->set_short("A steel "+what);
      thing->set_long("A steel "+what+" with Rutenos sign on it.\n"+
         "This "+what+" was made to order for "+TP->query_name()+
	 ".\n");
      thing->set_name(what);
      break;
  }  /* end of switch(what)  */	
  tell_room(env(this_object()),"Rutenos takes a peace of steel and starts to "+
	"craft the "+what+".\n");
  tell_room(env(this_object()),"Rutenos finished his work.\n");
  if (TP->query_money() < amount) {
     tell_room(env(this_object()),"Rutenos says evilly: You are stupid "+
           TP->query_race()+". You haven't enough money !\n"+
	   "Rutenos says: I send this goods to the shop.\n"+
	   "Boy arrives.\nRutenos gives "+what+" to Boy.\nBoy leaves west.\n");
     thing->set_value(amount);
     transfer(thing,"/players/goldsun/workroom"); /* check where to trans. it */
  } else {
    TP->add_money(-amount);
    tell_room(env(this_object()),"Rutenos takes "+amount+" coins from "+
	TP->query_name()+".\n"); 
    transfer(thing,env(this_object()));
    tell_room(env(this_object ()),"Rutenos drops "+what+".\nRutenos says:"+
	     " have a nice day "+TP->query_name()+".\n");
    write_file("log/Rutenos.job",TP->query_real_name()+" ordered "+what+",WC "+
	  class+",WEIGHT "+thing->query_weight()+",VALUE "+thing->query_value()+
      ", AMOUNT "+amount+",TIME "+ctime(time())+"\n");
	
  } 
  return 1;
 }  /* end of if (sscanf .... */
 notify_fail("Ask whom to forge what for how much ?\n");
 return 0;
}

query_property(str){
  return str=="no_steal";
}
