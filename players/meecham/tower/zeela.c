inherit "obj/monster";
  
  reset(arg) {
     ::reset(arg);
    
  if (!arg) {
  
    set_name("zeela");
    set_alt_name("elf");
    set_short("A blue-eyed, female elf");
    set_long("You see a small, but sexi female elf. She is Zeela the \n"+
             "brewer of the magetower. She looks quite busy and friendly.\n");
                      
    set_level(10);
    set_gender(2);
    add_money(800);
    load_chat(20,({"Zeela looks around.\n",
                   "Zeela prepares some kegs.\n",
                   "Zeela says: Isn't that all so beautiful.\n",
                   "Zeela shouts: Kegs for sale.\n",
                   "Zeela shouts: Whiskey, brandy, rum.\n",
                   "Zeela giggles happily.\n"})); 
                   
        }
      }
   
run_away() { return; }
 
catch_tell(arg) {
   object ob;
   string str1,str2;
     
   if (sscanf(arg,"%s arrives.",str1)==1) {
      write("Zeela smiles happily.\n");
   }
   else if (sscanf(arg,"%s curtseys %s",str1,str2)==2) {
      write("Zeela curtseys gracefully.\n");    
   }
    else if (sscanf(arg,"%s bows %s",str1,str2)==2) {
      write("Zeela curtseys gracefully.\n");
   }  
   else if (sscanf(arg,"%s fondles %s",str1,str2)==2) {
      write("Zeela slaps you.\n");
   }
   else if (sscanf(arg,"%s buy %s",str1,str2)==2) {
      write("Zeela starts to work.\n");
   }
  else if (sscanf(arg,"%s kisses %s",str1,str2)==2) {
      write("Zeela giggles happily.\n");
   }
  else if (sscanf(arg,"%s hugs %s",str1,str2)==2) {
      write("Zeela gasps in astonishment.\n");
   }
  else if (sscanf(arg,"%s gropes %s",str1,str2)==2) {
      write("Zeela snickers.\n");
   }  
   return 1;     
}
   
