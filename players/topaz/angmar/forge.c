/* 12.11.93 Airborne: Changed to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "The forge. The smith stands here.";
  long_desc = 
	"You are in Angmar's forge. Angmar's smith stands here, doomed to\n"+
	"serve him forever. The smith will value armours and weapons\n"+
	"for a reasonable fee.\n"+
	"'cost item'  shows what the smith would take to value the item.\n"+
	"'show item'  shows the item to the smith.\n";
  items = ({ "smith", "He is doomed to serve Angmar forever",
	"forge", "A hot and steamy forge" });
  dest_dir = ({ "players/topaz/angmar/inside", "east" });
}

init(){
 ::init();
   add_action("show", "show");
   add_action("cost", "cost");
}

cost(item) {
  object itemob;
  int val;
  if(!item) return 0;
  itemob=present(item, this_player());
  if(!itemob) {
    write("No such item here.\n");
    return 1;
  }
  val=itemob->query_value(0);
  val=val/5;
  if(val<30) val=30;
  if(val>800) val=800;
  write("The smith would take ");
  write(val);
  write(" coins to value "+itemob->short(0)+".\n");
  return 1;
}

show(item) {
  object itemob;
  int ac, wc, val, cost;
  if(!item) return 0;
  itemob=present(item, this_player());
  if(!itemob) {
    write("No such item here.\n");
    return 1;
  }
  ac=itemob->armour_class(0);
  if(!ac) ac=0;
  wc=itemob->weapon_class(0);
  if(!wc) wc=0;
  val=ac*4;

  if(wc>val) {
    val=wc; ac=0;
  }
  else wc=0;

  cost=itemob->query_value(0);
  cost=cost/5;
  if(cost<30) cost=30;
  if(cost>800) cost=800;

  if(val==0) {
    write("The smith is not interested in such items.\n");
    return 1;
  }

  if(cost>this_player()->query_money(0)) {
    write("You don't have enough money to pay the smith.\n");
    return 1;
  }

  if(itemob->id("doomsgiver")) {
    write("The smith nods. He says: 'I recognise this weapon. It was\n");
    write("made by Angmar himself.'  The smith seems to fall in deep\n");
    write("thougts and shudders at some memory. After a while he looks up\n");
    write("and says: 'Anyway, it is the most powerful weapon I know of,\n");
    write("but it can only be used by evil persons.'\n");
    }
    
  else if(val>20) {
    write("The smith gasps. He says: 'where did you get this?\n");
    write("The knowledge to make such fine handicraft is long\n");
    write("forgotten in this world, I'm sorry to say.\n");
    if(wc>0)
    write("It is an extremely powerful weapon! Use it with care.'\n");
    else
    write("It is an extremely good armour! Don't lose it!'\n");
    }
  else if(val>17) {
    write("The smith rises his eyebrows. He says: I'm impressed!\n");
    write("It would be hard to find a better ");
    if(wc>0) write("weapon than this one.\n");
    else write("armour than this one.\n");
    write("It should serve you well in your future battles.\n");
    }
  else if(val>13) {
    write("The smith nods appreciatively. He says: a very fine ");
  if(wc>0) write("weapon.\n");
    else write("armour.\n");
  write("It has been used in many battles, I can see, but it is\n");
  write("still fully functionable.\n");
  }
  else if(val>9) {
    write("The smith examines "+itemob->short(0)+".\n");
    write("It's good enough. He says finally.\n");
    write("It's not of the very best quality though, I wouldn't try\n");
    write("to do battle with any great warrior with it if I were you.\n");
    }
  else if(val>5) {
    write("The smith frowns. He says: Hmm... I hope you didn't pay\n");
    write("much for this? You should get yourself a better one.\n");
    write("You could easily get killed, if you should happen to\n");
    write("run into any big monsters, you know.\n");
  }
  else {
    write("The smith sighs and shakes his head. 'Cheap crap.' He says.\n");  
    write("Hardly worth anything. ");
    if(wc>0)   write("  I doubt you could even kill an orc with it.\n");
else write("It probably couldn't even stop\nthe blow from a small knife.\n");
  }

  this_player()->add_money(-cost);
  write("You give the smith ");
  write(cost);
  write(" coins.\n");
  return 1;
}

