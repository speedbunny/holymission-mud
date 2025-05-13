id(str) {
 return (str=="scroll" || str=="polymorph" || str=="multi-colored scroll"
           || str == "scroll of polymorph");
}

long() {
	write("This multi-colored scroll is continualy shifting words and\n");
	write("form, making is very hard to read.\n");
	return 1;
}

short() {
 return "A Multi-colored Scroll";
}

init() {
	if(environment() != this_player()) return 1;
	add_action("read"); add_verb("read");
	add_action("read"); add_verb("cast");
}

query_value() { return 200; }
query_weight() { return 1; }
query_name() { return "Scroll of Polymorph"; }
query_info() {
	write("This is a scroll of random polymorph.\n");
	return;
}
drop() { return 0; }
get() { return 1; }

read(str) {
 int test;
 object newtitle, newrace, newwc;
 object junk;

  /* Polymorph removed by Cashimor, because it caused bugs */
  write("Unfortunately, this scroll is buggy at the moment.\n");
  return 1;
}
#if 0
 if(!id(str)) return 1;
 if(this_player()->query_polymorph()) {
	write("Sorry, you are already polymorphed.\n");
	return 1;
  }
  if(!newtitle) {
    newtitle = allocate(26);
    newrace = allocate(26);
    newwc = allocate(26);
    newtitle[0] = "the Centaur";
    newwc[0] = 17;
    newtitle[1] = "the Djinni"; 
    newwc[1] = 22;
    newtitle[2] = "the Dryad";  
    newwc[2] = 15;
    newtitle[3] = "the Efreeti"; 
    newwc[3] = 20;
    newtitle[4] = "the Sea Hag";
    newwc[4] = 17;
    newtitle[5] = "the Drow Strider";
    newwc[5] = 16;
    newtitle[6] = "the Drow Elf";
    newwc[6] = 14;
    newtitle[7] = "the Satyr";
    newwc[7] = 13;
    newtitle[8] = "the Gargoyle";
    newwc[8] = 20;
    newtitle[9] = "the Gnome";
    newwc[9] = 12;
    newtitle[10] = "the Goblin";
    newwc[10] = 11;
    newtitle[11] = "the Will O' wisp";
    newwc[11] = 10;
    newtitle[12] = "the Horned Devil";
    newwc[12] = 20;
    newtitle[13] = "the Ice Devil";
    newwc[13] = 21;
    newtitle[14] = "the Jackalware";
    newwc[14] = 17;
    newtitle[15] = "the Lizard Man";
    newwc[15] = 16;
    newtitle[16] = "the Minotaur";
    newwc[16] = 17;
    newtitle[17] = "the Ogre";
    newwc[17] = 15;
    newtitle[18] = "the Sylph";
    newwc[18] = 13;
    newtitle[19] = "the Troll";
    newwc[19] = 17;
    newtitle[20] = "the Sea Elf";
    newwc[20] = 15;
    newtitle[21] = "the Wareboar";
    newwc[21] = 15;
    newtitle[22] = "the Cacodemon";
    newwc[22] = 24;
    newtitle[23] = "the Demon";
    newwc[23] = 22;
    newtitle[24] = "the Spiked Devil";
    newwc[24] = 21;
    newtitle[25] = "the Bone Devil";
    newwc[25] = 21;

    newrace[0] = "centaur";
    newrace[1] = "elemental"; 
    newrace[2] = "dryad";  
    newrace[3] = "elemental"; 
    newrace[4] = "human";
    newrace[5] = "spider";
    newrace[6] = "drow";
    newrace[7] = "satyr";
    newrace[8] = "gargoyle";
    newrace[9] = "gnome";
    newrace[10] = "goblin";
    newrace[11] = "light";
    newrace[12] = "devil";
    newrace[13] = "devil";
    newrace[14] = "human";
    newrace[15] = "lizard man";
    newrace[16] = "minotaur";
    newrace[17] = "ogre";
    newrace[18] = "sylph";
    newrace[19] = "troll";
    newrace[20] = "sea elf";
    newrace[21] = "human";
    newrace[22] = "demon";
    newrace[23] = "demon";
    newrace[24] = "devil";
    newrace[25] = "devil";
  }
  test = random(26);
  junk = clone_object("players/ted/items/poly_shadow");
  junk->new_title(newtitle[test]);
  junk->new_race(newrace[test]);
  junk->set_owner(this_player());
  write("You turn into "+this_player()->short()+"\n");
  say(this_player()->query_name()+" suddenly changes shape!!!\n");
  if(this_player()->query_wielded())
    this_player()->stop_wielding();
  this_player()->set_wc(newwc[test]);
  destruct(this_object());
  call_other(this_player(), "recalc_carry");
  return 1;
}
#endif 0
