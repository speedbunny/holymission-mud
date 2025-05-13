inherit "obj/treasure";

int raz;

 reset(arg){
  if (arg) return;
  set_id("heart");
  set_alt_name("heart");
  set_alias("Seducer`s heart");
  set_short("Heart of Seducer");
  set_long("This heart is beating only for you \n");
  set_value(0);
  set_weight(0);
 }
init(){
  
  ::init();
     add_action("skoc","touch");
     add_action("daj","give");
     add_action("pust","drop");
   }
get(){ return 1;}
pust(string str){
          if(this_object()->id(str)){
              write("Heart vanishes after you drop it. \n");
              destruct(this_object());
            return 1;
           }
       return 0;
      }
short(){
   return ::short();
  }
skoc(string str){
   if ((!str) || (str !="heart")) {
         return 0;
        }
     else { this_player()->move_player("X#players/seducer/workroom");
        return 1;
      }
    }
daj(string str){
         string str1,str2;
         object ob;

      if( sscanf(str,"%s to %s",str1,str2) != 2) return 0;

        else { str2 = lower_case(str2);
         if ((str1 =="heart") && (ob = find_living(str2))){
           if (raz){ write("You cant give it to anyone. \n");
                     destruct(this_object());
                     return 1;
                   }
              else{ write("You give the heart to " + ob->query_name() +".\n");
                  tell_object(ob,this_player()->query_name() + 
                               " gives you heart. \n");
                  transfer(this_object(),ob);
                  raz = 1;
                  return 1;
                 }
             }
         else {return 0;}
    }
  }
         
