/*
 * Author : Uglymouth
 * Date   : 6-AUG-1993
 * original church.c by Herp.
 */
#define RELIGION "Illuvatar"
#include "/obj/lw.h"
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "The village church";
  long_desc = "You are in the church of the village. It is a craftly built wooden\n"
    + "building with many decorations. The aisle leads south to the altar. Several\n"
    + "colourful glass windows let through a serene light. Wooden benches for the\n"
    + "churchgoers to hear mass or to pray in stand in rows at both sides of the\n"
    + "aisle. This church provides the service of reviving the dead. The deceased\n"
    + "come to church and pray at the altar. The church portal to the north stands\n"
    + "always open. A small door in the east wall leads to the churchyard. You feel\n" 
    + "the peace and holiness of this place and you are sure the gods would punish\n" 
    + "the sacrilege of shedding blood here.\n\n";
  dest_dir=({ PATH+"square2","north",
        PATH+"churchyard1","east",
	PATH+"church2","south" });
  items=({
	"church","This is a church consecrated to " + RELIGION, 
	"building","The building isn't that big, but seems to be able to hold many people",
	"decorations","Holy paintings decorate the wall and roof is painded like the sky",
        "paintings","@@display_clock@@",
	"glass","It's real glass, painted in colourful patterns",
	"window","Tall but narrow windows, holding coloured glass",
	"light","The light fills the church serenely, but shines brighter at the paintings",
	"benches","Simple wooden benches",
	"rows","Two perfect rows of benches are separated by the aisle",
	"aisle","The aisle leads south to the altar",
	"altar","A beautiful altar, consecrated to "+ RELIGION +". Take a closed look at it",
	"portal","The thick wooden portal got stuck in its current position", 
	"door","A small wooden door engraved with skulls",
	"skulls","They all have a cynical grin about them",
	});
		
  property=({ "no_fight", "no_steal" });
  smell="The holy smell of burning incence from the altar is mixed with fresh\n"
      + "worldly air from outside.\n";
  }

void init() {
  object hat;
  ::init();
  
  if(this_player()->query_religion()==RELIGION) {
    if(hat=present("helmet",this_player())) {
      if(hat->query_worn()) call_out("remove_hat",1);
      }
    }
  
  add_action("pray_it","pray");
  }

void remove_hat() {
  write("You take off your hat, respecting "+RELIGION+".\n");
  say(lw(this_player()->query_name()+" takes off "
       + this_player()->query_possessive()+" hat in the church.\n"));
  command("remove helmet",this_player());
  }

int pray_it(string str) {
string belief;
  belief=this_player()->query_religion();
  if(!belief) {
    write("If you want to become a follower of "+RELIGION+", then send your\n"
	+ "prayers to heaven from the holiness of the altar.\n");
    return 1;
    }
  if(belief!=RELIGION) {
    notify_fail("You are not a follower of "+RELIGION+"!\n");
    return 0;
    }
  if(this_player()->query_ghost()) {
    write("Pray at the altar, so "+ RELIGION +" will be closer to your prayers.\n");
    return 1;
    }
  write("You feel that your prayers have reached "+ RELIGION +" in heaven.\n"
      + "Maybe one time you'll smile as you notice his reward to your devotion.\n");
  say(this_player()->query_name() + " sits down and prays.\n");
  return 1;
  }

int try_attack(object ob) {
  tell_object(ob,"You feel the eye of the gods burning angrily inside you.\n");
  say("A flash strikes "+ob->query_name()+".\n",ob);
  ob->reduce_hit_point(random(100)+1);
  return 1;
  }

string display_clock() {
string suffix,result;
int num,i,j,k;
	
  i = ("/obj/tick")->qry_timer_value();
  j = ("/players/uglymouth/castle")->query_max_clock();
  if(i<=0) {
    result =  "The only bright ray of light coming in shines mockingly at the last\n"
	   + "painting, showing sharply the ending of the world";
    return result;
    }
  num = j / 3600;
  k = num - ((num * i) / j);
  switch(k) {
    case 1: suffix = "st";
      break;
    case 2: suffix = "nd";
      break;
    case 3: suffix = "rd";
      break;
    default: suffix = "th";
      break;
    }
  result =  num + " Paintings show the eras of the world, from its creation\n"
    + "to its ending. A bright ray of light illuminates the " + k + suffix + " painting";
  return result;
  }

