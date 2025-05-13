
/* ############################ STORE (c) Rudi ############################# */

#define TO this_object()
#define TP this_player()
#define TPN TP->query_money()
#define TPM TP->query_money()




short() {
    return "At the "+trader()+".";
}

/* ##################################  sort ######################################### */

holy_sort() {   

   return( sort_array( all_inventory(TO), "less", this_object() ) );
}

less( obj1, obj2 )
{
   return( (obj1->short() <= obj2->short()) );
}

/* ################################## lister ######################################## */
    
         
         
read(arg) {
  object ob,item;
  int i,j,num,pieces;
  ob=holy_sort();
  num=0;j=0;
  
  
     if (!ob) {
        write("Sorry, but the store is empty, now !\n");
        return 1;
       }
       
     write("Nr:   Weapon:                         Coins:      In Stock:\n");
     write("-----------------------------------------------------------\n");
     i = 0;  
     while ( i < sizeof( ob ) ){
          pieces=1;
          num++;
          j=i+1;
          while (j< sizeof(ob) && ob[i]->short() == ob[j]->short()) {
             pieces++;
             j++;
             }
                         
              write("\n"+listing((num),4)+"  "+listing(ob[i]->short(),30)+"  "+
              listing((ob[i]->query_value()*2)+" coins",10)+"  "+pieces+" ");  
          
          i=j;
        }
     write("\n\n");       
     return ( 1 );  
 }
/* ##################################### format ###################################### */
  
 listing(arg,n) { return extract(arg+"                              ",0,n-1); }
 
/* #################################### buy ########################################## */
 
 
 buy(arg) {
   object ob;
   int value, no;   
     
   
   if (!arg) 
       return;
       
   if ( sscanf(arg, "%d", no) == 1 && no > 0 ) {
      arg = get_obj( no );
      if ( !arg )  {
        write("The "+trader()+" says: We don't have this object.\n");        
        return;
        }
   }
 /*  if ( sscanf(arg, "%s %d", no) == 2 && no > 0 )
      write( "NO" );*/

   if (present(arg,TO)) {
       ob=present(arg,TO);
       }
   else {
      write("The "+trader()+" says: We don't have this object.\n");
      return 1;
    }    
       
   value=ob->query_value();
   
   if ((ob) && (TPM>=value) && (!(TP->query_ghost())) && (!transfer(ob,TP))) { 
       write("You start to trade with the "+trader()+".\n");
       say(TPN+" starts to trade with the "+trader()+".\n");      
       write("The "+trader()+" gives you "+ob->short()+" for "+(value*8/(TP->query_chr()/5))+" gold coins.\n");
       say(TPN+" buys "+ob->short()+".\n");
       move_object(ob,TP);
       TP->add_money(-(value*8/(TP->query_chr()/5)));
       }
    else if (!ob) {
       write("The "+trader()+" says: Sorry we don't have "+arg+".\n");
       }
    else if (TP->query_ghost()) {
       write("The "+trader()+" says: Sorry I don't sell anything to ghosts.\n");
       }
    else if (TPM>=((value*4/(TP->query_chr()/10)))) {
       write("The "+trader()+" says: Sorry, but that would cost you "+(value*8/(TP->query_chr()/5))+" coins.\n");
       }
    else {
      write("You can't carry that much.\n");
    return ( 1 );
    }
    
  return 1;
  }
  
  sell(arg) {
   object ob;
   int value,weight;
   ob=present(arg,TP);
   
   if (ob) {
   value=ob->query_value();
   }
   
   
   if (!arg) 
       return;
       
   if (arg=="all") {
       write("The "+trader()+" says: Sorry thats too much for me !\n");
       return 1;
      }
    
    if ((ob) && (ob->check_allow()) && (value>0)) {
       write("You start to trade with the "+trader()+".\n");
       say(TPN+" starts to trade with the "+trader()+".\n");
       write("The "+trader()+" buys your "+arg+" for "+((value/10)+(value/28*TP->query_chr()))+" coins.\n");
       say(TPN+" sells "+arg+".\n");
       TP->add_money((value/10)+(value/28*TP->query_chr()));
       move_object(ob,TO); 
       }
     else if (!ob) {
       write("The "+trader()+" says: You don't have that object.\n");
       }
     else if (value<1) {
       write("The "+trader()+" says: We don't buy worthless items.\n");
       }
     else {
       write("The "+trader()+" says: I don't buy that.\n");
       return 1;
      }
      
    return 1;
    }
    
get_obj( no )
{
   object ob;
   int    i,j, num;
      
   ob = sort_array( all_inventory(TO), "less", this_object() );

    i = 0; num = 0;
     
     while ( i < sizeof( ob ) ) {
          num++;
          if ( num == no )
             return( ob[i] );
             
          j=i+1;
          while (j< sizeof(ob) && ob[i]->short() == ob[j]->short())
             j++;
                         
          i=j;
        }
    return( 0 );
}
     
 check_allow() {
        return query_weapon();
    }
    
 trader() {
    return "Smith";
    }      
      
