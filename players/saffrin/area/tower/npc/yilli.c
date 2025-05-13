inherit "obj/monster";
#include "/players/saffrin/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
      set_name("yilli");
      set_alt_name("half-elf");
      set_short("Yilli");
      set_long(
        "You see a female half-elf with long brown, curly hair."+
        " She is\nsinging as she prepares the latest keg.  She "+
        "is the master brewer of\nthe mage tower.  She may look"+
        " busy but she is approachable.\n"
      );
      set_level(100);
      set_ac(20);
      set_wc(20);
      set_gender(2);
      add_money(1000 + random(1000));
      load_chat(10,({
        "Yilli looks around.\n",
        "Yilli prepares some kegs.\n",
        "Yilli says: How are you this fine day?\n",
        "Yilli shouts: Kegs for sale!!!\n",
        "Yilli shouts: Ale, cider, mead!!!\n",
        "Yilli sings a small tune.\n"}));
  }
}

run_away() { return; }

catch_tell(arg) {

  object ob;
  string str1,str2;

  if (sscanf(arg,"%s arrives.",str1)==1) {
      ME("Yilli smiles happily.\n");
  }
  else 
  if (sscanf(arg,"%s curtseys %s",str1,str2)==2) {
      ME("Yilli curtseys gracefully.\n");
  }
  else 
  if (sscanf(arg,"%s bows %s",str1,str2)==2) {
     ME("Yilli curtseys gracefully.\n");
  }  
  else 
  if (sscanf(arg,"%s licks %s",str1,str2)==2) {
     ME("Yilli licks you seductively.\n");
  }
  else
  if (sscanf(arg,"%s buy %s",str1,str2)==2) {
     ME("Yilli starts to work.\n");
  }
  else
  if (sscanf(arg,"%s kisses %s",str1,str2)==2) {
     ME("Yilli kisses you back.\n");
  }
  else
  if (sscanf(arg,"%s hugs %s",str1,str2)==2) {
     ME("Yilli hugs you.\n");
  }
  else
  if (sscanf(arg,"%s gropes %s",str1,str2)==2) {
     ME("Yilli snickers.\n");
  }  
 return 1;     
}
