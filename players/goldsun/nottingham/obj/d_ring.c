inherit "obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
 set_id("diamond ring");
 set_alias("special_d_ring");
 set_type("ring");
 set_short("Diamond ring");
 set_long("Diamond ring. It looks very expensive.\n");
 set_ac(1);
 set_value(1000);
 set_weight(1);
 }

string query_quest(){  return "white_tower"; }

int wear(string str){
 if (::wear(str)){
   write("The cold of the ring pulses through your hand.\n");
   return 1;
 }
}


int remove(string str){
object orb;

 if (::remove(str)){
   write("It seems the cold leaves your hand.\n"); 
   orb=present("bright orb",this_player());
    if (orb && orb->query_quest()=="white_tower"){
      write("OUCH. The orb burns you.\nYou drop the orb.\n");
      say(this_player()->query_name()+" drops suddenly a orb.\n");
      move_object(orb,environment(this_player()));
      this_player()->hit_player(17);
    }
   return 1;
  }
}
 
