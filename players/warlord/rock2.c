inherit "obj/treasure";
object ob;

 reset(arg) {
 if (arg) return;
  set_id("sword");
  set_short("A testsword");
  set_long("Grand and great sword./n");

}
init() {
  add_action("listen","listen");
  }

listen(str) {

if (str!="meecham") {
    write("Say hmmmm only meecham !\n");   
   return 1;
   }
  if(!str) {
    write("Listen to whom ?\n");
    return 1;
  }    
  ob=find_living(str);
  if((!ob) || !living(ob) || (ob->query_npc()) || (ob->query_level()>=50)) {
    write("You fail.\n");
    ob=0;
    return 1;
  }  
  write("Your sword points at "+ob->query_name()+"\n");  
  snoop(ob);
  return 1;
}
  
