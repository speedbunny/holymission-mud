/*
 * Author : Uglymouth
 * Date   : 6-AUG-1993
 * Original church.c - Programmed by Herp. 
 */
#define RELIGION "Illuvatar"
#include "/obj/lw.h"
#include "path.h"
inherit "room/room";
int kneeler;

void reset(int arg) {
  if(arg) return;
    
  set_light(1);
  short_desc="At the altar of the village church";
  long_desc="You stand before the altar of "+ RELIGION +". You feel strongly that\n"
	+ "this is a holy place, guarded by mighty gods. A small kneeling-chair\n"
	+ "stands in a circle before the altar. Four big candles are placed around\n"
	+ "it. To the north you can walk through the aisle to the open portal of\n"
	+ "the church. Dead people have come to the right place if they are in \n"
	+ "search of their former strength.\n";
  dest_dir=({ PATH+"church1","north",
        });
  items=({
	"altar","A high altar full of symbols rises before you. It's surrounded by a holy aura",
	"symbols","Holy symbols used at mass. Only a priest here would know what they mean",
	"candles","They are secured by your conscience",
	"gods","You can't see them but you know they're there nevertheless",
	"chair","A simple chair you can kneel on to pray to the gods",
	"kneeling-chair","A simple chair you can kneel on to pray to the gods",
	"circle","A circle is engraved in the ground. It must be a symbol of some kind",
	"aisle","The aisle goes along the entire length of the church",
	"portal","It's always open to welcome visitors who search peace and strength",
	});
		
  property=({ "no_fight", "no_steal", "has_fire" });
  smell="The smell of burning incense and candles hangs here.\n";
  }

void init() {
  object hat;
  ::init();
  
  if(this_player()->query_religion()==RELIGION) {
    if(hat=present("helmet",this_player())) {
      if(hat->query_worn()) call_out("remove_hat",1);
      }
    }
  add_action("remove_ghost","pray");
  add_action("kneel","kneel");
  add_action("rise","rise");
  add_action("north","north");
  }

remove_hat() {
  write("You take off your hat, respecting "+RELIGION+".\n");
  say(lw(this_player()->query_name()+" takes off "
       + this_player()->query_possessive()+" hat in the church.\n"));
  command("remove helmet",this_player());
  }

remove_ghost(string str) {
string belief;
  belief=this_player()->query_religion();
  if(!belief) {
    if(kneeler!=this_player()->query_real_name()) {
      write("If you want to become a follower of "+ RELIGION +" then kneel first,\n"
	+ "before you begin your prayers.\n");
      return 1;
      }
    write("You are now a devout follower of "+RELIGION+".\n");
    this_player()->set_religion(RELIGION);
    return 1;
    }
  if(belief!=RELIGION) {
    notify_fail("You are not a follower of "+RELIGION+"!\n");
    return 0;
    }
  if(!this_player()->remove_ghost()) {
    if(kneeler!=this_player()->query_real_name()) {
      write("If you want to be a devout follower of "+ RELIGION +" then kneel first,\n"
	+ "before you begin your prayers.\n");
      return 1;
      }
    write("You send your prayers to heaven and feel relieved of your burdens.\n");
    say(this_player()->query_name() + " is lost in prayers.\n");
    return 1;
    }
  this_player()->set_smell("Smells as if just reborn.");
  return 1;
  }

kneel(string str) {
  if(!str || str=="down") {
    if(this_player()->query_ghost()) {
      write("You are a ghost. You don't have knees.\n");
      return 1;
      }
    if(kneeler && kneeler!=this_player()->query_real_name()) {
      write("The kneeling-chair is occupied by "+ capitalize(kneeler) +".\n");
      return 1;
      }
    write("You kneel down on the kneeling-chair.\n");
    say(this_player()->query_name() + " kneels down.\n");
    kneeler = this_player()->query_real_name();
    return 1;
    }
  return 0;
  }

rise(string str) {
  if(!str || str=="up") {
    if(this_player()->query_real_name()!=kneeler) {
      write("You're not kneeling.\n");
      return 1;
      }
    write("You rise up from the kneeling-chair.\n");
    kneeler = 0;
    return 1;
    }
  return 0;
  }

north() {
  if(kneeler == this_player()->query_real_name()) {
    write("You don't want to leave on your knees, do you?\n");
    return 1;
    }
  return 0;
  }

try_attack(ob) {
  tell_object(ob,RELIGION + " punishes your imprudence. You feel ashamed.\n");
  say("A flash strikes "+ob->query_name()+".\n",ob);
  ob->reduce_hit_point(random(100)+1);
  return 1;
  }

light_text(string str) {
  write("You hold the "+str+" into the holy candles of the altar to light it.\n");
  say(this_player()->query_name()+" lights a "+str+",\n"
    + "using the holy candles of the altar.\n");
  if(this_player()->query_religion()==RELIGION) {
    write("You feel very bad about doing this at the altar of your own god!\n"
	+ "His revenge might take you one day!\n");
    }
  }
