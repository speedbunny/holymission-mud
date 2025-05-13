inherit "room/room";

object victim;

void do_faller(){
object test, *inv;
int i;
 
 test=clone_object("/obj/thing");
 test->set_name("tester");
 transfer(test,this_object());
 inv=all_inventory(environment(test));
 for(i=0;i<sizeof(inv);i++)
  if (living(inv[i]) && random(2)<1){
    tell_object(inv[i],"You see a huge boulder falling on your head.\n"+
	          "Ouch. It hurts you.\n");
    say("A huge boulder falls down.\nIt falls on "+
	  inv[i]->query_name()+"'s head\n",inv[i]);
    inv[i]->hit_player(random(20)+30);
    return;
  }
}

int reset(int arg){
 ::reset(arg);
 if (arg) return;
  set_light(1);
  short_desc="A test";
  long_desc="This is a test ravine.\n";

}

heart_beat(){
 ::heart_beat();
 if (!test_if_any_here()) set_heart_beat(0);
 if (random(10)<1 ){
  do_faller();
  return;
 }
}

init(){
 ::init();
 set_heart_beat(1);
}
