inherit "room/room";

int puz,active,last;
string symb,stonestring;

reset(arg) {
  int i;
  if(arg) return;
  stonestring=allocate(6);
  set_light(1);
  property = ({ "no_teleport" });
  short_desc="A very strange room";
  puz=allocate(36);
  reset_stones();
  active=1;
  for(i=0;i<36;i++) puz[i]=random(6);
}

reset_stones() {
  int loop,loop2,flag,sym;
  string symbl;
  flag=1;
  loop=0;
  sym=allocate(6);
  symbl=({ "\\ /", "|-|", "/ \\", "...", "]+[", "<|>", "/ \\", "|-|", "\\ /", "'^`", "]+[", "<|>", });
  while(loop<6) {
    if(!flag) loop++;
    if(loop!=6) sym[loop]=random(6);
    flag=(loop==6);
    loop2=-1;
    if(loop) while(loop2++<loop-1 && !flag) if(sym[loop2]==sym[loop]) flag=1;
  }
  loop=0;
  flag=1;
  while(loop<6) {
    if(!flag) loop++;
    if(loop!=6) stonestring[loop]="stone " + (random(6)+1);
    flag=(loop==6);
    loop2=-1;
    if(loop) while(loop2++<loop-1 && !flag) if(stonestring[loop2]==stonestring[loop]) flag=1;
  }
  items=({ "stones", "Which stone, stone 1, stone 2, stone 3, stone 4, stone 5 or stone 6",
	"stone", "Which stone, stone 1, stone 2, stone 3, stone 4, stone 5 or stone 6",
	stonestring[0], "This stone seems cold to the touch",
	stonestring[1], "This stone seems cold to the touch",
	stonestring[2], "This stone seems cold to the touch",
	stonestring[3], "This stone seems cold to the touch",
	stonestring[4], "This stone seems cold to the touch",
	stonestring[5], "This stone glows in a cold blue light", });
  symb=({ symbl[sym[0]], symbl[sym[1]], symbl[sym[2]], symbl[sym[3]],
	symbl[sym[4]], symbl[sym[5]], symbl[sym[0]+6], symbl[sym[1]+6],
	symbl[sym[2]+6], symbl[sym[3]+6], symbl[sym[4]+6], symbl[sym[5]+6], });
}

id(str) { return str=="stones" || str=="stone" || str=="stone 1" || str=="stone 2" || str=="stone 3" || str=="stone 4" || str=="stone 5" || str=="stone 6" || str=="floor"; }

init() {
  ::init();
  add_action("push", "touch");
  add_action("push", "press");
  add_action("push", "push");
}

church() { 
  write("You feel the ground shaking, and you move to somewhere you know well.\n");
  this_player()->move_player("to a familiar place#room/church");
  destruct(this_object());
  return 1;
}

push(str) {
  int loop,tmp;
  if(str=="stone" || str=="stones") return write("Which stone, stone 1, stone 2, stone 3, stone 4, stone 5 or stone 6?\n");
  if(str==stonestring[0]) {
    if(!active) return write("Nothing happens.\n");
    loop=-1;
    while(loop++<35) {
      tmp=-1;
      if(puz[loop]==0) tmp=3;
      if(puz[loop]==3) tmp=0;
      if(tmp!=-1) puz[loop]=tmp;
    }
    last=1;
    return check_finished();
  }
  if(str==stonestring[1]) {
    if(!active) return write("Nothing happens.\n");
    loop=-1;
    while(loop++<35) {
      tmp=-1;
      if(puz[loop]==1) tmp=4;
      if(puz[loop]==4) tmp=1;
      if(tmp!=-1) puz[loop]=tmp;
    }
    last=2;
    return check_finished();
  }
  if(str==stonestring[2]) {
    if(!active) return write("Nothing happens.\n");
    loop=-1;
    while(loop++<35) {
      tmp=-1;
      if(puz[loop]==1) tmp=2;
      if(puz[loop]==2) tmp=1;
      if(tmp!=-1) puz[loop]=tmp;
    }
    last=3;
    return check_finished();
  }
  if(str==stonestring[3]) {
    if(!active) return write("Nothing happens.\n");
    loop=-1;
    while(loop++<35) {
      tmp=-1;
      if(puz[loop]==0) tmp=2;
      if(puz[loop]==2) tmp=5 ;
      if(puz[loop]==5) tmp=0;
      if(tmp!=-1) puz[loop]=tmp;
    }
    last=4;
    return check_finished();
  }
  if(str==stonestring[4]) {
    if(!active) return write("Nothing happens.\n");
    loop=-1;
    while(loop++<35) {
      tmp=-1;
      if(puz[loop]==3) tmp=5;
      if(puz[loop]==5) tmp=3;
      if(tmp!=-1) puz[loop]=tmp;
    }
    last=5;
    return check_finished();
  }
  if(str==stonestring[5]) {
    object stone;
    stone=present("puzzle_quest_stone",this_player());
    if(!stone) return write("Your hand shies away from this stone, as if magically forced to do so.\n");
    if(stone->query_finder()!=this_player()->query_real_name()) {
      destruct(stone);
      return write("Suddenly the stone you are carrying crumbles to dust.\n"
	+ "You feel an electric jolt, and stop what you're doing.\n");
    }
    if(!active) return write("Nothing happens.\n");
    loop=0;
    tmp=puz[0];
    while(puz[loop]==tmp) loop++;
    if(last!=6 && tmp!=-1) puz[loop]=random(6);
    if(last==6 || !tmp || tmp==2 || tmp==4) {
      loop--;
      puz[loop]=random(6);
    }
    if(tmp=-1) loop--;
    while(loop++<35) {
      tmp=-1;
      if(puz[loop]==1 && tmp<10) tmp=5;
      if(puz[loop]==5 && tmp<10) tmp=3;
      if(puz[loop]==3 && tmp<10) tmp=1;
      if(tmp!=-1) puz[loop]=tmp;
    }
    last=6;
    return check_finished();
  }
}

check_finished() {
  int loop,flag;
  write("You " + query_verb() + " the stone.\n");
  say(this_player()->query_name() + " " + query_verb() + "es a stone.\n");
  tell_room(this_object(),"The floor shimmers and blurs.\n");
  write("The pattern takes on a new form.\n");
  loop=10;
  while(loop++<35 && !flag) if(puz[loop]!=puz[0]) flag=1;
  if(!flag) {
    shout(this_player()->query_name() + " freed the Good King Dmitri!\n");
    write("The Good King Dmitri suddenly emerges from in between the stones.\n"
	+ "He says: Thank you for freeing me from bondage. I must go now, and\n"
	+ "         save my kingdom from that upstart mage. But you, mighty\n"
	+ "         adventurer, will have a warm welcome at my castle if you\n"
	+ "         ever come there. So long, friend.\n"
	+ "Dmitri waves a staff and is gone.\n");
    if(this_player()->set_quest("moonchild_puzzle")) {
      this_player()->add_exp(5000+this_player()->query_level()*500);
    } else {
      write("You've already solved the quest before. Keen, aren't you!\n");
      this_player()->add_exp(2000+this_player()->query_level()*250);
    }
      log_file("moonchild.quest", ctime(time()) + ": " +
        this_player()->query_name() + " (level " + this_player()->query_level()
        + ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
        + "rescued King Dmitri.\n");
    active=0;
    return 1;
  }
  if(!random(120)) {
     int *tmp,i;
     write("You hear a sudden buzzing sound at your back.\n");
     reset_stones();
     tmp=allocate(36);
     for(i=0;i<36;i++) tmp[i]=puz[35-i];
     puz=tmp;
  }
  return(display());
}

display() {
  int loop,match;
  loop=0;
  write("+-----+-----+-----+-----+-----+-----+");
  while(loop<35) {
    loop--;
    match=loop+6;
    write("\n| ");
    while(loop++<match) write(symb[puz[loop]] + " | ");
    write("\n| ");
    loop-=7;
    while(loop++<match) write(symb[6+puz[loop]] + " | ");
    write("\n+-----+-----+-----+-----+-----+-----+");
  }
  write("\n");
  return 1;
}

long(str) {
  if(str=="floor") {
    write("The floor is covered in a shifting pattern.\n"
	+ "Currently, it looks something rather like\n\n");
    return display();
  }
  if(!str) {
    write("This is a strangely illuminated room, carved\n"
	+ "out of pure rock. You cannot see any way out,\n"
	+ "nor any roof to it. Six magical stones hang\n"
	+ "in the air and the floor is covered in a\n"
	+ "shifting pattern which looks rather like\n\n");
    return display();
  }
  ::long(str);
}
