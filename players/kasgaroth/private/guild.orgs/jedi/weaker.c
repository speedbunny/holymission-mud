#define ME environment()

int his_wc,his_ac;

init() {
  object all;
  int i;

  all=all_inventory(ME);
  for(i=0;i<sizeof(all);i++) {
    if(all[i]->id("weakerobj")) 
      all[i]->backtake();
  }    
}
 
id(str) { return str=="weakerobj"; }

drop() { return 1; }
 
start(time,percentage) {
  his_wc=ME->query_wc();
  his_ac=ME->query_ac();
  ME->set_wc(his_wc*percentage/100);
  call_out("takeback",time);
}

takeback() {
  remove_call_out("takeback");
  ME->set_wc(his_wc);
  destruct(this_object());
}


 
