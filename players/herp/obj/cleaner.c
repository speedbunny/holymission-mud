/* cleaner.c Herp 910321 */

string owner;
 
init() {
  add_action("clean","clean");
  add_action("clean","clear");
  add_action("throw","throw");
  owner = this_player()->query_name();
  if(environment(this_object()) == this_player()) { write("Object cleaner...\n"); }
}
 
id(str) { return str == "cleaner"; }
 
short() { return owner + "'s radical object cleaner"; }
 
long() {
    write("Commands available:\n");
    write("clean <player>\n");
    write("clean <room>\n");
    write("clean here\n");
    write("clean me\n");
    write("throw <what> on <whom>\n");
}
 
get() { return 1; }
 
drop() { return 1; }
 
query_value() { return 10; }
 
query_auto_load() { return "players/herp/obj/cleaner:normal"; }

do_clean_one(ob) {
    if (ob!=this_object()) {
	write("Destructed ");
	write(ob);
	write(" \t"+ob->short()+"\n");
	destruct(ob);
    }
}
 
do_clean(mark) {
   object ob,nob,inv;
   string name;

   map_array(all_inventory(mark),"do_clean_one",this_object());
#if 0
   ob = first_inventory(mark);
   while(ob) {
     nob = next_inventory(ob);
/*   if (!(ob == this_player())) { */
/* if (inv=first_inventory(ob)) do_clean(inv); /* Rekursive destruct */
     name = ob->query_real_name(); 
     if (!name || !find_living(name) || ob->query_npc()) {  
       write("Destructed ");
       write(ob);
       write(" \t"+ob->short()+"\n");
       destruct(ob);
     }
     ob = nob;
   }
#endif
   write("Ok.\n");
}
 
clean(str) {
  object mark;
  if (!(this_player()==environment(this_object()))) {
     write("You don't have the cleaner.\n");
     return 1;
  }
 
  if (this_player()->query_level() < 30) {
     write("You find it somehow difficult to handle this fine instrument.\n");
     return 1;
  }
 
  if (!str) { long(); return 1; }
  if (str=="here") { do_clean(environment(this_player())); return 1; }
  if (str=="me") { do_clean(this_player()); return 1; }
 
  mark = find_living(str);
  if (!mark) mark = find_object(str);
  if (!mark) { write("Couldn't find " + str + ".\n"); return 1; }
  do_clean(mark);
  return 1;
}
 
throw(str) {
  object player,thing,old_loc;
  string what,whom;
 
 if (!str) return;
 if (sscanf(str,"%s on %s",what,whom)!=2) return;
 if (!(player=find_player(whom))) {
    write(whom+" is not playing yet.\n");
    return 1;
 }
 
 thing=present(what,this_player());
 if (!thing) thing=present(what,environment(this_player()));
 if (!thing) {
    write("There is no "+what+" here.\n");
    return 1;
 }
 
 say("BOING!\nSuddenly "+thing->short()+" is kicked out"
   + " of the room.\n");
 move_object(thing,environment(player));
 tell_object(player,"BOING!\nFrom far away "
                  + thing->short()
                  + " has been thrown on your head!\n");
 old_loc=environment(this_player());
 move_object(this_player(),environment(player));
 say("BOING!\nFrom far away "
   + thing->short()
   + " has been thrown on "+player->query_name()+"'s head!\n",player);
 move_object(this_player(),old_loc);
 write("Ok.\n");
 return 1;
}
