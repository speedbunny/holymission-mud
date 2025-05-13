inherit "obj/treasure";
#define TP this_player()
#define CN capitalize(TP->query_real_name())
int water,gems;

reset(arg){
::reset(arg);

 if (water==0){ 
  gems=5;
  water=10;
  set_long("An old well. It is full of fresh crystal water.\n");
  }

if (arg) return;
water=10;
gems=5;
set_id("well");
set_alias("spring");
set_short("An old well");
set_long("An old well. It is full of fresh crystal water.\n");
}

init(){
 ::init();
 add_action("search","search");
 add_action("get", "get");
 add_action("drink","drink");
 add_action("m_look","look");
 add_action("dip","dip");
}

dip(str){
 object bottle;

 if (str=="bottle in water" || str=="bottle in well"){
  if (water>0){
   if (present("special bottle",TP)){
       bottle=present("special bottle",TP);
       water--;
       if (bottle->is_my_bottle()) bottle->add_water();
   }
    write("You dip the bottle in the water.\n");
    say(CN+" dips the bottle in the water.\n");
  }  else write("There is no water in the well.\n");

  return 1;
 }
}

search(str){
 if ( (str=="well") || (str=="spring") ){
  if (water==0){
   if (gems>0){
   if (random(20) <= 1){
   if ( transfer(clone_object("/players/qclxxiv/obj/scoin"),this_player())) 
   {
     write("You can't carry that much.\n");
     return 1;
   }
    write("You search the well and find a silver coin.\n");
    say(CN+"searches the well.\n");
    }
    else{
     write("You search the well and find a gem.\n");
     if (transfer(clone_object("/players/goldsun/sherwood/obj/gem"),
         this_player()))
     {
       write("You can't carry that much.\n");
       return 1;
     }
     --gems;
     say(CN+" looks happy.\n");
    }
    } /* end of gems */
    else { write("The well is total empty.\n");}
   }   /*  end of water==0 */
   else{
    write("You put your fingers in the well and find water.\n");
    say(CN+" put finger in the well.\n");
    }
 }   /* end of str=="well" */
  else{ 
   write("You search and search but find nothing.\n");
   say(CN+" searches around.\n");
   }
return 1;
}

get(){
 return 0;
      }

drink(str){
 if (str=="water"){
  if (water>0){
    write("AAAhhh. This water is fresh and cold.\n");
    say(capitalize(this_player()->query_real_name())+
       " drinks the water from the well.\n");
    this_player()->heal_self(1);
    this_player()->restore_spell_points(2);  /*  complet heal: sp=3 and hp=1 */
    water--;
    if (water==0) { set_long("An old empty well.\n");}
   }
    else{
     write("There is no water in the well.\n");
    }
  return 1;
  }
  else{
   write("What do you want to drink ?\n");
   return 1;
  }
}

m_look(str){
 if (str=="at water"){
  if (water>0){
   write("The water is very clean.\n");
   return 1;
    }
  else{
   write("Where do you see water ?\n");
   return 1;
  }  }
}
