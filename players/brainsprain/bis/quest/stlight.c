inherit "/obj/quest_obj";

void reset(int arg){
  if(arg) return;

  set_name("stlight");
  set_hint("Go to Bismarck Castle and Bismarck Archive to find clues.\n"+
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
           "Return Count Bismarck's powerful staff to him and you will\n"+
           "be rewarded.  This quest is fairly easy but will take some\n"+
           "true hack and slash and a bit of brains.\n");
  set_short_hint("Steal the Light from the Dark.");
  set_weight(20);
  set_killing(5);
  add_quest();
}
