
#define TP this_player()
 
 int timit;
 int _mpose(string arg){
  
   if(TP->query_real_name()=="wilbie") timit = 0; 
   if(timit) return printf("You can't pose again so soon.\n"),1;


switch(random(6)+1){
  case 1 : shout( capitalize(TP->query_real_name())+
  " beckons the Old Gods to do his bidding...  Dark clouds cover the sun!\n");
           break;  case 2 : shout("Black storm clouds darken the sky as "                  +capitalize(TP->query_real_name())+
           " recites the names of "+TP->query_possessive()+" ancient gods!\n");
           break;
  case 3 : shout("The setting sun shines upon the gleaming blade of "+
                 capitalize(TP->query_real_name())+"!\n");
           break;  case 4 : shout(capitalize(TP->query_real_name())+" plots your demise.\n");
           break;
  
  case 5 :
          shout(capitalize(TP->query_name())+ " Summons the Gods of Darkness to do his bidding!\n");
          break;
  case 6 : shout(capitalize(TP->query_real_name())+" raises "+TP->query_possessive()+
           " hands in the air and proclaims "+TP->query_objective()+"self one with the "+
           "Darkness.\n");
           break;    }


timit = 1;
call_out("remove_timit",120);
return 1;
}

remove_timit(){ timit = 0; }




