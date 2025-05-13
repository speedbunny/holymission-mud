inherit "room/room";

mixed *menu;

void reset(int arg) {
  if(!present("box"))
    move_object(clone_object("players/moonchild/misc/singer"), this_object());
  if(!present("monk")) {
    int i;
    for(i=random(3);i<6;i++) {
      object m,o;
      m=clone_object("obj/monster");
      m->set_level(12);
      m->set_name("black monk");
      m->set_alias("monk");
      m->set_short("A Black Monk");
      m->set_long("This is one of the many Black Monks who work in the chapel.\n");
      m->set_al(-100);
      m->add_money(100+random(401));
      o=clone_object("obj/armour");
      o->set_ac(1);
      o->set_value(300);
      o->set_name("monk's robe");
      o->set_alias("monks robe");
      o->set_type("robe");
      o->set_weight(1);
      o->set_long("A long and light monk's robe.\n");
      move_object(o,m);
      move_object(m,this_object());
      command("wear robe", m);
    }
  }
  if(arg)
    return;
  set_light(1);
  short_desc="A small restaurant";
  long_desc="This is a small restaurant just by the entrance to the chapel. It's where the\n"
	+ "Black Monks and their priests usually eat and drink during their times off\n"
	+ "work. A small menu is pinned up by the bar.\n";
  dest_dir=({ "players/moonchild/chapel/link", "south" });
  items=({ "menu", "You normally read these",
	"bar", "Just an ordinary bar" });
  menu=({
        ({ "light ale", "ale", 20, "drink_alco", 5, 5 }),
        ({ "whiskey", "whisky", 70, "drink_alco", 10, 14 }),
        ({ "scrumpy cider", "cider", 300, "drink_alco", 20, 40 }),
        ({ "holy wine", "wine", 750, "drink_alco", 36, 110 }),
        ({ "black coffee", "coffee", 25, "add_intoxination", -1, 0 }),
        ({ "ham salad", "salad", 70, "eat_food", 5, 10 }),
        ({ "t-bone steak", "steak", 225, "eat_food", 16, 32 }),
        ({ "glass of spring water", "water", 12, "drink_soft", 1, 2 }),
        ({ "milkshake", "shake", 100, "drink_soft", 7, 14 }),
  });
}

void init() {
  ::init();
  add_action("buy", "buy");
  add_action("buy", "order");
  add_action("read", "read");
}

int read(string str) {
  int i;
  if(str!="menu")
    return 0;
  for(i=0;i<sizeof(menu);i++)
    write((capitalize(menu[i][0]) + "                   ")[0..22]
	+ " cost: " + menu[i][2] + " gold coins.\n");
  return 1;
}

int buy(string str) {
  int i,j;
  i=0;
  j=-1;
  while(i<sizeof(menu)) {
    if(str==menu[i][0] || str==menu[i][1]) {
      j=i;
      i=100;
    }
    else
      i++;
  }
  if(j==-1) {
    write("No " + str + " for sale here.\n");
    return 1;
  }
  if((int)this_player()->query_money() < menu[j][2]) {
    write("You don't have that much money.\n");
    return 1;
  }
  if(!call_other(this_player(), menu[j][3], menu[j][4]) && menu[j][1]!="coffee")
    return 1;
  this_player()->add_money(-menu[j][2]);
  this_player()->heal_self(menu[j][5]);
  write("You " + query_verb() + " a " + menu[j][0] + ".\n");
  say((string)this_player()->query_name() + " " + query_verb() + "s a "
	+ menu[j][0]+ ".\n");
  return 1;
}
