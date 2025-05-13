inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
      set_name("wynn");
      set_short("Wynn");
      set_long(
        "You see a young woman with long brown, curly hair."+
        "  She is\nhumming a tune as she mixes a perfume.  "+
        "She is an expert at creating\nwonderful scents.\n"
      );
      set_race("human");
      set_level(100);
      set_ac(20);
      set_wc(20);
      set_gender(2);
      add_money(1000 + random(1000));
      load_chat(7,({
        "Wynn mixes a perfume.\n",
        "Wynn mixes a cologne.\n",
        "Wynn sprays herself with Romantic Rose.\n",
        "Wynn smiles at you.\n",
        "Wynn says: My scents can make you more attractive.\n",
       }));
  }
}

run_away() { return; }

catch_tell(arg) {

  object ob;
  string str1,str2;

  if (sscanf(arg,"%s arrives.",str1)==1) {
      ME("Wynn smiles happily.\n");
  }
  else 
  if (sscanf(arg,"%s curtseys %s",str1,str2)==2) {
      ME("Wynn curtseys gracefully.\n");
  }
  else 
  if (sscanf(arg,"%s bows %s",str1,str2)==2) {
     ME("Wynn curtseys gracefully.\n");
  }  
  else 
  if (sscanf(arg,"%s licks %s",str1,str2)==2) {
     ME("Wynn licks you seductively.\n");
  }
  else
  if (sscanf(arg,"%s buy %s",str1,str2)==2) {
     ME("Wynn starts to work.\n");
  }
  else
  if (sscanf(arg,"%s kisses %s",str1,str2)==2) {
     ME("Wynn kisses you back.\n");
  }
  else
  if (sscanf(arg,"%s hugs %s",str1,str2)==2) {
     ME("Wynn hugs you in return.\n");
  }
  else
  if (sscanf(arg,"%s gropes %s",str1,str2)==2) {
     ME("Wynn snickers.\n");
  }  
 return 1;     
}
