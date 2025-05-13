/* LIGHT23.C - Programmed by Animal */
/* 200793: Ethereal Cashimor: Edited some minor problems */

inherit "room/room";
#include "/obj/lw.h"

int passage;
  
reset(arg) {
  ::reset(arg);
  if(!arg) {
    passage=0;
    set_light(1);
    short_desc="Cliff";
    long_desc="Base of the cliff. You have come to the base of a cliff rising "
            + "out of the forest floor. The cliff is extremely steep and it "
            + "looks impassable. At the base of the cliff, the dirt looks "
            + "soft. @@passage@@\n";
    items=({"cliff","The cliff is very steep and looks frightening",
            "dirt","The dirt looks as if someone was digging in it"});
    dest_dir=({"players/animal/light/light22","east"});
    smell="The smell of freshly digged earth hangs here.";
  }
  if(passage) {
    tell_room(this_object(),"The passage caves in upon itself.\n");
    passage=0;
  }
}

passage() {
  if(!passage) return "";
  return "There is a passage leading down here.";
}

query_light() {
  return 1;
}
 
init() {
  ::init();
  add_action("down","down");
  add_action("dig","dig");
}
 
 
dig(str) {
object ob;

  if(!str) {
    notify_fail("Dig where?\n");
    return 0;
  }
  if((str!="cliff")&&(str!="at cliff")&&(str!="under cliff")) {
    notify_fail("Dig where?\n");
    return 0;
  }
  if(!present("clean pick axe",this_player())) {
    if(!(ob=present("rusty pick axe",this_player()))) {
      write("You've got nothing to dig with!\n");
      return 1;
    }
    if(random(3)) {
      write("You can't dig with such a rusty pick axe!\n");
      return 1;
    }
    write("The rusty axe finally breaks and withers away from the abuse.\n");
    say(lw(this_player()->query_name()+" digs with a rusty axe and it breaks "
      + "and withers away to nothing.\n"));
    destruct(ob);
    return 1;
  }
  if(passage) {
    if(passage==this_player()->query_real_name()) {
      write("Why? There is already a passage there!\n");
      return 1;
    }
    write("You modify the passage leading down to fit someone like you.\n");
    say(this_player()->query_name()+" modifies the passage leading down.\n");
    passage=this_player()->query_name();
    return 1;
  }
  if(random(100)<35) {
    write(lw("You dig at the base of the cliff with the axe and find a passage"
        + " leading down.\n"));
    say(lw(this_player()->query_name()+" digs out a hidden path leading down "
      + "with the axe.\n"));
    passage=this_player()->query_real_name();
    return 1;
  }
  write("You dig, but find nothing.\n");
  say(this_player()->query_name()+" digs at the cliff base.\n");
  return 1;
}
 
down() {
  if(!passage) {
    notify_fail("You can't go down here!\n");
    return 0;
  }
  if(this_player()->query_real_name()!=passage) {
    write("The passage wasn't made by you, you don't fit into it!\n");
    return 1;
  }
  this_player()->move_player("down#players/animal/light/light24");
  return 1;
}
 
