inherit "/obj/thing";
#define IN "players/goldsun/7-islands/topaz/room/pub_shop"

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("small hut");
 set_alias("hut");
 set_short("A small hut");
 set_long("A small hut with small windows. There is a sign over the door. "+
          "On the sign is written: < Zuzana's hut >.\n");
 set_can_get(0);
}

init(){
 ::init();
add_action("enter","enter");
}

int enter(string str)
{
 notify_fail("Enter what?\n");
 if (str=="hut" || str=="door")
 {
  this_player()->move_player("in#"+IN);
  return 1;
 }
}
