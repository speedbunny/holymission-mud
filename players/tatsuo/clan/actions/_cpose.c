
#define TP this_player()
 
  int _cpose(string arg){
  
 if(present("poser",TP)) return printf("You certainly like to pose. Wait longer.\n"),1;
   

switch(random(6)+1){
  case 1 : shout( capitalize(TP->query_real_name())+
           " ties the Hachimaka of Clan Sunsu, of the Kokuryu Kai.\n");
           break;  
  case 2 : shout("Chariots of lighting blaze across the sky as "                        +capitalize(TP->query_real_name())+
           " calls on the names of "+TP->query_possessive()+" ancestors!\n");
           break;
  case 3 : shout("The setting sun shines upon the gleaming blade of "+
                 capitalize(TP->query_real_name())+"!\n");
           break;  
  case 4 : shout(capitalize(TP->query_real_name())+" shouts BANZAI!\n");
           break;
  
  case 5 :
          shout(capitalize(TP->query_name())+ " holds high the banner of the Kokuryu Kai!\n");
          break;
  case 6 : shout(capitalize(TP->query_real_name())+" raises "+TP->query_possessive()+
           " katana on high and declares "+TP->query_objective()+"self ruler of the "+
           "mud.\n");
           break;    }

 if(TP->query_real_name() != "tatsuo"){
 transfer(clone_object("/players/tatsuo/clan/actions/poser"),TP);
 }
return 1;
}






