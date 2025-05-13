/* The little shop of horrors */

#define P "players/herp/room"
#define O "players/animal/obj"

#define TP	this_player()
#define TPN	TP->query_name()

inherit "room/room.c";

string fn;
int st,va;

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="The little horror shop";
     long_desc=
"You are in a small and dusty shop where spiderwebs\n"+
"build most of the inventory here.\n"+
"Above the counter you can see a small sign.\n";
     dest_dir=({ "room/plane4", "leave" });
     items=({ "sign", "It looks readable",
	      "spiderweb", "The spiderwebds look inhabitated"
	   });
     fn=({ "diamond", "eye", "fol" });
     va=({ 10000, 5000, 1000 });
  }
  st=({ 10,10,10 });	/* Stock of items */
}

init() {
  ::init();
  add_action("read","read");
  add_action("buy","buy");
  add_action("stock","stock");
}

stock() {
  write("diamond "+st[0]+"\n"+
	"eye "+st[1]+"\n"+
	"ring "+st[2]+"\n");
  return 1;
}

read(str) {
  if (str=="sign") {
     say(TPN+" reads the sign.\n");
     write(
" The sign reads:\n\n"+
" Hail, and well met, Cyberpunx ! We sell:\n"+
" +----------------------------------+\n"+
" + A black diamond:     10.000      +\n"+
" + A cat's eye:          5.000      +\n"+
" + A ring of following:  1.000      +\n"+
" +----------------------------------+\n");
     return 1;
  }
}

buy(str) {
object ob;
int i;

  i=0;
  switch(str) {
  case "ring":i++;
  case "eye":i++;
  case "diamond":i++;
  }
  if (!i) return;	/* player entered shit */
  i--;			/* to get the index */

  if (TP->query_money()<va[i]) {
    write("You don't have enough gold coins.\n");
    return 1;
  }
  if (!st[i]) {
     write("Sorry, that item is sold out.\n");
     return 1;
  }

  /* Do the transaction now */

  ob=clone_object(O+"/"+fn[i]);
  TP->add_money(-va[i]);
  st[i]--;
  say(TPN+" buys "+ob->short()+".\n");
  if (transfer(ob,TP)) {
     say(TPN+" dops "+ob->short()+".\n");
     write("You can't carry any more.\n");
     move_object(ob,environment(TP));
  }
  write("Ok.\n");
  return 1;
}
